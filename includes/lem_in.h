#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2
# define MAXIMUM	2000000000

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

/* avl tree for collect REAL_ROOMS + PSEVDO_ROOMS */
typedef struct		s_verts
{
	int				key; // === number of room
	int				height;

	char			*name;

	char			visit:1; // yes or no
	int				distance; // shortea distance
	struct s_verts	*parent; // for restore shortest path

	struct s_edges	*edge;
	struct s_edges	*reserve;

	struct s_verts	*left;
	struct s_verts	*right;
}					t_verts;

/* structure for collect ways */
typedef struct		s_ways
{
	int				num_of_ways;
	struct s_edges	**way;
}					t_ways;

/* structure for collect input data */
typedef struct		s_input
{
	char			*line;
	struct s_input 	*next;
}					t_input;

/* temporary structure for edges parsing */
typedef struct		s_match
{
	int				number_of_room;
	char			*name_of_room;
	struct s_match	*next;
}					t_match;

///////////////* TESTING */////////////////////

void	suurballe(t_graph *graph);
void		upgrade_ways(t_ways *new_ways, t_ways *old_ways);


///////////////* TESTING */////////////////////



t_graph		*read_input(void);
t_verts		*insert(t_verts *node, int key, char *str);
t_edges		*dijkstra(t_graph *graph);


/* tree_manipulations: */
/* psevdo->edge:			psevdo->real(to) | to->all(to->from excluded) */
/* to(real)->edge:			new_edge(to->psevdo(froom))     !!!PSEVDO */
/* to(real)->reserved:		to->from | to(next_from)->next_to */
/* from(real)->edge:		new_edge(to->psevdo(froom)) | to-> | */
void	reverse_the_way_in_graph(t_verts *root, t_edges *way);
void		restore_graph(t_graph *graph);
void		clean_the_way(t_edges *way);

/* t_graph: */
t_graph		*init_graph(char *line);
void		free_graph(t_graph **graph);
void		print_graph(t_graph *graph);


/* t_verts: */
t_verts		*new_vertex(int key, char *str);
t_verts		*find_vertex(t_verts *root, int num);
void		free_vertex(t_verts **node);
void		tree_traversal(t_verts *root, void f(t_verts *vertex));
void		print_vertex(t_verts *vert);
void		restore_vertex(t_verts *vert);


/* t_edges: */
t_edges		*pull_edge(t_edges **first_edge, t_verts *vertex);
void		push_edge_front(t_edges **first_edge, t_edges *new_edge);
void		push_edge_back(t_edges **first_edge, t_edges *new_edge);
t_edges		*copy_edges_struct(t_edges *srcs);
void		free_edge(t_edges **edge); 
void		free_edges_struct(t_edges **first_edge);
t_edges		*new_edge(t_verts *vertex);


/* t_input: */
void		push_line_back(t_input *first_line, char *new_line);
void		free_input_struct(t_input **first_line);
void		print_input_struct(t_input *first_line);


/* t_ways: */
t_ways		*new_ways_struct(t_edges *new, t_ways *old_struct, int number);
void		copy_ways_by_the_edges(t_ways *old, t_ways *new);
void		free_ways_struct(t_ways **old_struct);	
void		print_ways_struct(t_ways *way_struct);


/* t_match: */
void		push_back_t_match(t_match **room, char *name, int num_room);
int			number_and_name_match(t_match *rooms, char *name);
void		free_t_match(t_match **rooms);





	// printf("\n\n\nTHIS SHIT\n\n\n\n");


#endif