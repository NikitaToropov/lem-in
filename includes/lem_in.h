#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

// # define NONE		0
// # define START		1
// # define FINISH		2
// # define INT_MAX	2147483647
typedef struct		s_graph
{
	int				start;
	int				finish;
	int				len;
	// int				latest;
	t_verts			*rooms;
}					t_graph;

typedef struct		s_verts
{
	int				key;
	int				height;
	char			*name;
	t_edges			*edge;
	struct s_verts	*left;
	struct s_verts	*right;
}					t_verts;

typedef struct		s_edges
{
	t_verts			*to;
	struct s_edges	*next;
}					t_edges;



#endif