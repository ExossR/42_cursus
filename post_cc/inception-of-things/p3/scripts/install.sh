#!/bin/bash

echo "[SCRIPT] Installing all tools..."

sudo apt-get update > /dev/null 2>&1
# sudo apt-get upgrade -y > /dev/null 2>&1

echo "[SCRIPT] Installing curl..."
sudo apt-get install -y curl > /dev/null 2>&1
echo "[SCRIPT] Done."

echo "[SCRIPT] Installing docker..."
sudo apt-get install -y docker docker.io > /dev/null 2>&1
sudo usermod -aG docker $(whoami) > /dev/null 2>&1
echo "[SCRIPT] Done."

echo "[SCRIPT] Installing k3d..."
sudo curl -s https://raw.githubusercontent.com/k3d-io/k3d/main/install.sh | bash > /dev/null 2>&1
echo "[SCRIPT] Done."

echo "[SCRIPT] Installing kubectl..."
sudo curl -LO "https://dl.k8s.io/release/$(curl -L -s https://dl.k8s.io/release/stable.txt)/bin/linux/amd64/kubectl" > /dev/null 2>&1
sudo chmod +x kubectl > /dev/null 2>&1
sudo mv kubectl /usr/local/bin/ > /dev/null 2>&1
echo "[SCRIPT] Done."

echo "[SCRIPT] Everything is installed !"
