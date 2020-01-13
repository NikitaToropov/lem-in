#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2
// # define INT_MAX	2147483647


typedef struct		s_graph
{
	int				start;
	int				finish;
	int				length;
	int				num_of_ants;
	struct s_verts	*rooms;
	struct s_input	*input;
}					t_graph;

typedef struct		s_edges
{
	struct s_verts	*to;
	struct s_edges	*next;
}					t_edges;

typedef struct		s_verts
{
	int				key; // === number of room
	int				height;

	char			*name;

	char			visit; // yes or no
	struct s_verts	*parent; // for restore shortest path

	struct s_edges	*edge;
	struct s_edges	*reserve;

	struct s_verts	*left;
	struct s_verts	*right;
}					t_verts;

// structure for collect input data
typedef struct		s_input
{
	char			*line;
	struct s_input 	*next;
}					t_input;

// temporary structure for edges parsing:
typedef struct		s_match
{
	int				number_of_room;
	char			*name_of_room;
	struct s_match	*next;
}					t_match;






t_graph		*read_input(void);

t_verts		*insert(t_verts *node, int key, char *str);
// void 		pre_order(t_verts *root);

// t_graph:
t_graph		*init_graph(char *line);
void		free_graph(t_graph **graph);
void		print_graph(t_graph *graph);


// t_verts:
t_verts		*new_vertex(int key, char *str);
t_verts		*find_vertex(t_verts *root, int num);
void		free_vertex(t_verts **node);
void		tree_traversal(t_verts *root, void f(t_verts *vertex));
void		print_vertex(t_verts *vert);



// t_edges:
void		push_edge_back(t_edges **first_edge, t_verts *vertex);
void		free_edge(t_edges **edge);
void		free_edges_struct(t_edges **first_edge);

// t_input:
void		push_line_back(t_input *first_line, char *new_line);
void		free_input_struct(t_input **first_line);
void		print_input_struct(t_input *first_line);

// t_match:
void		push_back_t_match(t_match **room, char *name, int num_room);
int			number_and_name_match(t_match *rooms, char *name);
void		free_t_match(t_match **rooms);



#endif