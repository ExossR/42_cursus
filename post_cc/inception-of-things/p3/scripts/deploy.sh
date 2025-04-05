#!/bin/bash

echo "[SCRIPT] Deploying all tools..."

echo "[SCRIPT] Creating cluster..."
sudo mkdir -p ~/.kube
sudo k3d cluster create iot --api-port 6500 -p 8888:8888@loadbalancer -p 30000:30000@loadbalancer --agents 2 >>log.log 2>>error.log
sudo k3d kubeconfig get iot > ~/.kube/config
# sudo k3d kubeconfig get iot | sudo tee ~/.kube/config > /dev/null 2>&1

echo "[SCRIPT] Creating namespaces argocd & dev..."
sudo kubectl create namespace argocd >>log.log 2>>error.log
sudo kubectl create namespace dev >>log.log 2>>error.log

echo "[SCRIPT] Installing ArgoCD..."
sudo kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml >>log.log 2>>error.log

echo "[SCRIPT] Waiting for ArgoCD to be ready..."
sudo kubectl wait --for=condition=ready pods --all -n argocd --timeout=300s >>log.log 2>>error.log

echo "[SCRIPT] Parametring ArgoCD..."
kubectl patch svc argocd-server -n argocd --type='json' -p='[{"op": "replace", "path": "/spec/type", "value": "NodePort"}]' >>log.log 2>>error.log
kubectl patch svc argocd-server -n argocd --type='json' -p='[{"op": "replace", "path": "/spec/ports/0/nodePort", "value": 30000}]' >>log.log 2>>error.log
sudo kubectl -n argocd patch secret argocd-secret -p '{"stringData": {"admin.password": "$2y$10$k9LdmGWqEE8.pxl2ij3VZ.aHaF8NSfw8vCapqMCCee.U56XhKcao.", "admin.passwordMtime": "'$(date +%FT%T%Z)'"}}'
sudo kubectl apply -n argocd -f ../confs/application.yaml >>log.log 2>>error.log
echo "[SCRIPT] ArgoCD is ready!"

echo "http://localhost:30000 pour ArgoCD et http://localhost:8888 pour l'application de wil"

# Avoir l'ip de la vm pour connection ssh
# VBoxManage guestproperty get "iot" "/VirtualBox/GuestInfo/Net/0/V4/IP"
