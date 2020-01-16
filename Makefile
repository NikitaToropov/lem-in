NAME = lem-in

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a

INCLUDES = ./includes
HEADER = $(INCLUDES)/lem_in.h

# dirs
DIR_S = srcs
DIR_O = objs

# files
C_FILES = lem_in.c\
		avl.c\
		read_input.c\
		dijkstra.c\
		t_graph.c\
		t_input.c\
		t_verts.c\
		t_edges.c\
		t_match.c\
		t_ways.c\
		suurballe.c\
		tree_manipulations.c\
		ways_manipulations.c\

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(INCLUDES) -I $(LIB_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) $(INC_LIBS) -o $@

$(DIR_O):
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIB_DIR) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_CH)

re: fclean all