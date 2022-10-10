NAME = inception

all : $(NAME)

$(NAME) : docker-compose -f srcs/docker-compose.yaml up --force-recreate --build

install : docker-compose -f srcs/docker-compose.yaml up --force-recreate --build

clean : docker-compose -f srcs/docker-compose.yaml down

fclean : clean

.PHONY : all install clean fclean
