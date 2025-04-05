#!/bin/bash

# sudo apt-get update

export INSTALL_K3S_EXEC="--write-kubeconfig-mode=644 --tls-san asahonetS --node-ip 192.168.56.110  --bind-address=192.168.56.110 --advertise-address=192.168.56.110"

curl -sfL https://get.k3s.io | sh - > /dev/null 2>&1

sudo ln -s /usr/local/bin/kubectl /usr/bin/kubectl

# echo "alias k=kubectl" >> /etc/profile
# echo "alias k=kubectl" >> ~/.bashrc

until kubectl cluster-info > /dev/null 2>&1; do
    sleep 1
done
echo "[SCRIPT] Install k3s done..."

sudo ln -s /usr/local/bin/kubectl /usr/bin/kubectl

echo "[SCRIPT] Deploying app-one..."
kubectl apply -f /vagrant/confs/app-one.yml
echo "[SCRIPT] App-one deployed !"

echo "[SCRIPT] Deploying app-two..."
kubectl apply -f /vagrant/confs/app-two.yml
echo "[SCRIPT] App-two deployed !"

echo "[SCRIPT] Deploying app-three..."
kubectl apply -f /vagrant/confs/app-three.yml
echo "[SCRIPT] App-three deployed !"

#sudo kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/main/deploy/static/provider/kind/deploy.yaml

echo "[SCRIPT] Deploying ingress..."
kubectl apply -f /vagrant/confs/ingress.yml
echo "[SCRIPT] Ingress deployed !"

echo "[SCRIPT] Waiting for pods to be running..."
while [ $(kubectl get pods --all-namespaces --field-selector=status.phase=Running 2>/dev/null | grep app- | wc -l) -ne 5 ]; do
    sleep 3
done
echo "[SCRIPT] Pods are running !"

echo "[SCRIPT] You can access the apps at http://app1.com, http://app2.com or http://192.168.56.110 (don't forget to add the entries in your /etc/hosts file (host.sh script))"
