# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 22:30:43 by mmaaouni          #+#    #+#              #
#    Updated: 2019/06/24 17:18:17 by zchatoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = lem-in
FILES1 = src/auxfunc.c src/avlfunc.c src/avlinsert.c\
		src/bfs.c src/cancel_room_edge.c src/carry_over.c src/check_combination.c\
		src/choos_sol.c src/choose_node.c src/concatenation.c src/dijkstra.c \
		src/dijkstra_inter.c src/dijkstra_yen.c src/error.c src/find_kth_path.c\
		src/find_room.c src/find_shortest.c src/finding_funcs.c src/freeing_routines.c\
		src/get_input.c src/graph.c src/heap_operations.c src/heap_swap.c\
		src/input_check.c src/lem_in.c src/minheap.c src/parser.c src/path_routines.c\
		src/potential_path.c src/result.c src/scoring.c src/unmark_funcs.c src/utilfunc.c\
		src/visualization.c src/yen.c src/yen_sol.c src/make_null.c
OBJECTS1 = $(FILES1:.c=.o)
LIB = libft/libft.a
DIR = libft
FLAG = -Wall -Werror -Wextra

RESET = "\x1b[0m"
CYAN = "\x1b[36m"
GREEN = "\x1b[32m"
YELLOW = "\x1b[33m"
RED = "\x1b[31m"
DELETE = "\033[A"

all: $(NAME1)

$(NAME1): $(LIB) $(OBJECTS1)
		@echo $(CYAN)
		@gcc $(FLAG) -I ../includes/lem_in.h $(OBJECTS1) $(LIB) -o $(NAME1)
		@clear
		@printf $(GREEN)
		@echo "\n Lem-in is Ready \n"
		@printf $(RESET)

$(OBJECTS1): %.o : %.c
		@printf $(GREEN)
		@printf $(DELETE)
		gcc $(FLAG) -I ../includes/lem_in.h -c $< -o $@

$(LIB):
		@printf $(YELLOW)
		@echo "\nCompiling Libft\n"
		@make -C $(DIR)
		@printf $(YELLOW)
		@echo "\nCompiling Lem-in\n"
		@printf $(RESET)

clean:
		@printf $(YELLOW)
		@echo "\nCleaning\n"
		@make -C $(DIR) clean
		rm -f $(OBJECTS1)
		@printf $(RESET)

fclean: clean
		@printf $(RED)
		rm -f $(NAME1)
		@make -C $(DIR) fclean
		@printf $(RESET)

re: fclean $(NAME1)
