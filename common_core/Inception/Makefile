NAME = inception
COMPOSE_FILE = srcs/docker-compose.yml

FLAGS = -f ${COMPOSE_FILE} -p ${NAME}

all: build

build: volumes
	@docker compose ${FLAGS} up -d --build

stop:
	@docker compose ${FLAGS} stop

down:
	@docker compose ${FLAGS} down

status:
	@docker compose ${FLAGS} ps

logs:
	@docker compose ${FLAGS} logs

clean:
	@docker system prune -a

cleanv:
	@sudo rm -rf /home/asahonet/data/

fclean: down clean cleanv

volumes:
	@mkdir -p /home/asahonet/data/wordpress
	@mkdir -p /home/asahonet/data/mariadb

re: stop fclean all

