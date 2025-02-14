NAME = philosophers

SRC = 	src/begin_dinner.c src/check_args.c src/init.c src/monitor.c \
		src/philo_routine.c src/utils.c src/main.c

INCLUDE = include/philosophers.h

OBJT = $(SRC:.c=.o)

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJT) $(INCLUDE)
		cc -Wall -Werror -Wextra $(OBJT) -o $(NAME)
		@echo "${GREEN}Philosophers compilation OK${RESET}"

clean:
		-rm -f $(OBJT)
		@echo "${YELLOW}All objects removed${RESET}"

fclean:		clean
		-rm -f $(NAME)
		@echo "${RED}Philosophers removed${RESET}"

re:			fclean all

.PHONY:		all clean fclean re