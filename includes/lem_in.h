#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2

typedef struct		s_matrix
{
	char			**mtrx;
	int				len;
}					t_matrix;

typedef struct		s_edges
{
	char			*pair[2];
	struct s_edges	*next;
}					t_edges;

typedef struct		s_verts
{
	char			*name;
	int				num;
	int				x;
	int				y;
	char			marker; // 0/1/2
	struct s_verts	*next;
}					t_verts;

void				ft_read_input(t_verts **rooms);

void				ft_free_mtrx(t_matrix **m_list);
t_matrix			*ft_make_matrix(t_verts *rooms, t_edges *links);

void				ft_free_links(t_edges **links);
void				ft_push_link_back(t_edges **links, t_edges *link);
t_edges				*ft_make_link(char *name1, char *name2);

void				ft_free_rooms(t_verts **first);
void				ft_push_room_back(t_verts **first, t_verts *room);
t_verts				*ft_make_room(char *name, int x, int y, char mark);

#endif