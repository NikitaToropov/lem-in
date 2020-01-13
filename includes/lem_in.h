#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2
// # define INT_MAX	2147483647
typedef struct		s_edges
{
	// t_verts			*to;
	struct s_verts	*to;
	struct s_edges	*next;
}					t_edges;

typedef struct		s_verts
{
	int				key;
	int				height;
	char			*name;
	t_edges			*edge;
	t_edges			*reserve;
	struct s_verts	*left;
	struct s_verts	*right;
}					t_verts;

typedef struct		s_graph
{
	int				start;
	int				finish;
	int				length; // including virtual
	int				num_of_ants;
	char			*input;
	t_verts			*rooms;
	struct s_match	*lines;
}					t_graph;

typedef struct		s_match
{
	int				number_of_room;
	char			*name_of_room;
	struct s_match	*next;
}					t_match;

typedef struct		s_line
{
	char			*line;
	struct s_match	*next;
}					t_line;

t_graph		*ft_read_input(void);
t_graph			*init_graph(char *line);

t_verts		*insert(t_verts *node, int key, char *str);
void 		pre_order(t_verts *root);




#endif