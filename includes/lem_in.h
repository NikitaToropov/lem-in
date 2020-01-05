#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE			0
# define START			1
# define FINISH			2
# define DUPLICATED		3

# define INF			2000000000

# define DELETE			0
# define WORKS			1

typedef struct		s_path
{
	int				num_of_paths;
	int				**path;
}					t_path;

typedef struct		s_verts
{
	char			*name;
	int				num;
	int				x;
	int				y;
	char			marker; // 0/1/2/(3 - if fill)
	struct s_verts	*next;
}					t_verts;

typedef struct		s_edges
{
	int				a;
	int				b;
	// or:
	// t_verts			*from;
	// t_verts			to;
	char			marker; // DELETE, WORKS
	struct s_edges	*next;
}					t_edges;

typedef struct		s_adjacency
{
	int				len;
	int				start;
	int				finish;
	t_edges			*edge;
}					t_adjacency;

#endif