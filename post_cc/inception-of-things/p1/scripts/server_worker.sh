#!/bin/bash

apt update -y
apt-get install -y curl

TIMEOUT=10
while [ ! -f "/vagrant_shared/token" ]; do
    sleep 1
    TIMEOUT=$((TIMEOUT - 1))
    if [ "$TIMEOUT" -eq 0 ]; then
        echo "Token file not found."
        exit 1
    fi
done

echo "[LOG] - Install k3s"
echo "[LOG] - Master node: $1"
export K3S_TOKEN_FILE=/vagrant_shared/token
export K3S_URL=https://$1:6443
# This variable set makes this node a worker one (and not a server one).
# 6443 is the standard Kuburnetes API port for agent connecting to server

export INSTALL_K3S_EXEC="--flannel-iface=eth1"
curl -sfL https://get.k3s.io | sh -
if [ $? -ne 0 ]; then
    echo "Failed to install k3s. Exiting."
    exit 1
fi

echo 'export PATH="/sbin:$PATH"' >> $HOME/.bashrc
echo "alias k='kubectl'" | sudo tee /etc/profile.d/00-aliases.sh > /dev/null
