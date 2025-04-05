# ============================================================
#                           MAKEFILE						 #
# ============================================================


# ========================= VARIABLES ========================

MAKEFLAGS += --no-print-directory
USERNAME := nstoutze
SSH := vagrant ssh $(USERNAME)
SERVER_SUFFIX := S
WORKER_SUFFIX := SW
S := $(SSH)$(SERVER_SUFFIX)
SW := $(SSH)$(WORKER_SUFFIX)


# ========================= RULES =========================

.PHONY: kub_ls s sw tests start


start:
	vagrant up


kub_ls:
	$(S) -c "kubectl get nodes -o wide"


s:
	$(S)


sw:
	$(SW)


tests:
	@echo "Test 1: $(SW) -c \"ip a show eth1\""
	$(SW) -c "ip a show eth1"
	@echo "\n\n"

	@echo "Test 2: $(SW) -c \"ping -c 4 192.168.56.110\""
	$(SW) -c "ping -c 4 192.168.56.110"
	@echo "\n\n"

	@echo "Test 3: $(S) -c \"systemctl status k3s | grep Active\""
	$(S) -c "systemctl status k3s | grep Active"
	@echo "\n\n"

	@echo "Test 4: $(SW) -c \"systemctl status k3s-agent | grep Active\""
	$(SW) -c "systemctl status k3s-agent | grep Active"
	@echo "\n\n"

	@echo "Test 5: $(S) -c \"kubectl version --client\""
	$(S) -c "kubectl version --client"
	@echo "\n\n"

	@echo "Test 6: $(S) -c \"kubectl get pods -A\""
	$(S) -c "kubectl get pods -A"
	@echo "\n\n"

	@echo "Test 7: $(S) -c \"journalctl -u k3s --no-pager | tail -50\""
	$(S) -c "journalctl -u k3s --no-pager | tail -50"
	@echo "\n\n"

	@echo "Test 8: $(S) -c \"cat /vagrant_shared/token\""
	$(S) -c "cat /vagrant_shared/token"
	@echo "\n\n"

	@echo "Test 9: $(S) -c \"curl -Is https://www.google.fr | head -n 1\""
	$(S) -c "curl -Is https://www.google.fr | head -n 1"
	@echo "\n\n"
#	to prove Vm accesses internet without any external IP


# ========================= VAGRANT REMINDER =========================

# vagrant commands (and their consequences)
# after vagrant halt: `vagrant up` restarts VMs, same state, not any reload.
# `vagrant reload`: restarts VMs + reload Vagrantfile
# `vagrant provision`: run again provision scripts (server.sh, agent.sh),
#	without recreating Vms
# `vagrant destroy -f`: delete everything, except the OS if cached
