COMPOSE_FILE = ./srcs/docker-compose.yml
IMAGES = nginx mariadb wordpress
VOLUMES = srcs_wordpress_data srcs_db_data
DATA = /Users/keokim/data

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

up :
	@echo "$(BLUE)docker compose up ... $(RESET)"
	@mkdir -p /Users/keokim/data/wordpress
	@mkdir -p /Users/keokim/data/mysql
	@echo "$(BLUE)Building containers ... $(RESET)"
	@docker-compose -f $(COMPOSE_FILE) up --build -d

down :
	@echo "$(RED)docker compose down ... $(RESET)"
	@docker-compose -f $(COMPOSE_FILE) down

fclean :
	$(MAKE) down
	@echo "$(RED)remove all data ... $(RESET)"
	@docker image rm -f $(IMAGES)
	@docker volume rm -f $(VOLUMES)
	@sudo rm -rf $(DATA)

.PHONY : up down clean fclean
