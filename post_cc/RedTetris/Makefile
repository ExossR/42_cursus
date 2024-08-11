NAME = redtetris

all: up

help:
	@ echo "\033[0;31m  You need help ? Try with one of these commands :\033[0;39m"
	@ echo ""
	@ awk 'BEGIN {FS = ":.*##";} /^[a-zA-Z_0-9-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)
	@ echo ""

up: ## Launch in background
	@ docker compose -f ./docker-compose.yml up -d

down: ## Stop
	@ docker compose -f ./docker-compose.yml down

# initDB: ## Init database
# 	@ docker cp init.sql redtetris_db:/init.sql
# 	@ docker exec -it redtetris_db psql -U redtetrisUser -d redtetrisDB -f /init.sql

restart: down up ## Restart

status: ## Display  status
	@ docker ps

logs: ## See  logs
	@ docker compose -f ./docker-compose.yml logs

logsb: ## See backend logs
	@ docker compose -f ./docker-compose.yml logs backend

logsf: ## See frontend logs
	@ docker compose -f ./docker-compose.yml logs frontend

clean: down ## Stop  & Clean  docker (prune -f)
	@ docker system prune -f
	@ sudo rm -rf ./src/frontend/node_modules
	@ sudo rm -rf ./src/backend/node_modules

prune: down ## Remove all dockers on this system (prune -a)
	@ docker system prune -a
	@ docker volume prune -a

.PHONY: fclean prune clean logs status down rebuild up help all
