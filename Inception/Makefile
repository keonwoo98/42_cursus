COMPOSE_FILE = ./srcs/docker-compose.yml

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

up :
		@echo "$(BLUE)Building files for volumes ... $(RESET)"
		@mkdir -p /home/keokim/data/wordpress
		@mkdir -p /home/keokim/data/mysql
		@echo "$(BLUE)Building containers ... $(RESET)"
		@docker-compose -f $(COMPOSE_FILE) up --force-recreate --build

clean :
		@echo "$(RED)Stopping containers ... $(RESET)"
		@docker-compose -f $(COMPOSE_FILE) down

fclean :
		clean
		@-docker stop `docker ps -qa`
		@-docker rm `docker ps -qa`
		@-docker image rm -f `docker images -qa`
		@-docker volume rm -f `docker volume ls -q`
		@-docker network rm -f `docker network ls -q`
		@sudo rm -rf /home/keokim/data/wordpress
		@sudo rm -rf /home/keokim/data/mysql

.PHONY : all install clean fclean
