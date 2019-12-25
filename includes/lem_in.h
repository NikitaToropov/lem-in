#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2
# define INT_MAX	2147483647

	// typedef struct		s_graph
	// {
	// 	char			**mtrx;
	// 	int				num_of_rooms;
	// 	int				start;
	// 	int				finish;
	// 	int				num_of_links;
	// 	struct s_verts	*rooms;
	// }					t_graph;

// typedef struct		s_graph
// {
// 	int				room;
// 	int				level;
// 	int				num_of_links;
// 	struct s_path	**next_rooms;
// }					t_graph;

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
	char			*pair[2];
	struct s_edges	*next;
}					t_edges;

typedef struct		s_matrix
{
	int			**mtrx;
	int				len;
	int				start;
	int				finish;
}					t_matrix;

// typedef struct		s_path
// {
// 	int				step;
// 	int				room;
// 	struct s_path	**next;
// }					t_path;

int			*dijkstra(t_matrix *matrix);
int		*bellman_ford(t_matrix *matrix);



void	print_matrix(t_matrix *m_list);

void		modify_matrix(t_matrix *matrix, int *arr);





t_matrix			*ft_read_input(t_verts **rooms);

void				ft_free_mtrx(t_matrix **m_list);
t_matrix			*ft_make_matrix(t_verts *rooms, t_edges *links);
t_matrix			*ft_copy_matrix(t_matrix *first);


void				ft_free_links(t_edges **links);
void				ft_push_link_back(t_edges **links, t_edges *link);
t_edges				*ft_make_link(char *name1, char *name2);

void				ft_free_rooms(t_verts **first);
void				ft_push_room_back(t_verts **first, t_verts *room);
t_verts				*ft_make_room(char *name, int x, int y, char mark);

#endif