#!/bin/bash

apt update -y
apt-get install -y curl


echo "[LOG] - Removing previous K3s installation (if any)"
/usr/local/bin/k3s-uninstall.sh || true

echo "[LOG] - Install k3s"
export K3S_KUBECONFIG_MODE="644"
# Defines a variable which will be used by k3s. Makes k3s.yaml readable by every user.

export INSTALL_K3S_EXEC="server --bind-address=$1 --flannel-iface=eth1 --disable-cloud-controller"
# Another variable used by k3s:
# - installs it in server mode, making this node a master one
# - defines which address it listens (where agent nodes will connect and communicate)
# - defines which connection interface will be used for making VMs communicate eachother.

curl -sfL https://get.k3s.io | sh -
if [ $? -ne 0 ]; then
    echo "Failed to install k3s. Exiting."
    exit 1
fi

echo "[LOG] - Share token"
TIMEOUT=30
while [ ! -f /var/lib/rancher/k3s/server/node-token ]; do
    sleep 1
    TIMEOUT=$((TIMEOUT - 1))
    if [ "$TIMEOUT" -eq 0 ]; then
        echo "Token file not generated."
        exit 1
    fi
done
# Now that the token is generated...
cp /var/lib/rancher/k3s/server/node-token /vagrant_shared/token
# Copies it from the master node VM file system, to the Vagrantshared directory
# in order to make it available to every other nodes.

echo 'export PATH="/sbin:$PATH"' >> $HOME/.bashrc
# Necessary for being able to use kubectl command

echo "alias k='kubectl'" | sudo tee /etc/profile.d/00-aliases.sh > /dev/null
# I thought echo "..." | sudo cat > /etc/.../00-aliases.sh
# could be cleaner and enough,
# but even though cat is run with sudo rights, > is not.
# It will then lead to an error.
# kubetcl is a CLI to manage nodes from the master one
