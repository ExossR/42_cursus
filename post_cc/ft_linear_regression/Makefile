all: up
	@ clear
	@ echo "Docker is up, you can now join it using 'make join'"

help:
	@ echo "Usage: make [command]"
	@ echo ""
	@ echo "Commands:"
	@ echo "  up           Build & start the docker container"
	@ echo "  all          Build and start the docker container"
	@ echo "  re           Restart the docker container"
	@ echo "  join         Join the docker container"
	@ echo "  down         Stop the docker container"
	@ echo "  status       Show the docker container's status"
	@ echo "  logs         Show the docker container's logs"
	@ echo "  clean        Stop & clean the docker (prune -f)"
	@ echo "  prune        Remove all dockers on system (prune -a)"
	@ echo "  help         Show this help message"

up:
	@ docker compose -f ./docker-compose.yml up -d

join:
	@ docker exec -it ft_linear_regression bash

down:
	@ docker compose -f ./docker-compose.yml down

status:
	@ docker ps

re: down up

logs:
	@ docker compose -f ./docker-compose.yml logs

clean: down
	@ docker system prune -f

prune: down
	@ docker system prune -a
	@ docker volume prune -a

.PHONY: help up all join down status clean prune logs re

