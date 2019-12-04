#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE		0
# define START		1
# define FINISH		2

typedef struct		s_edges
{
	char			*pair[2];
	struct s_edges	*next;
}					t_edges;

typedef struct		s_vert
{
	// int				num;
	char			*name;
	int				x;
	int				y;
	char			marker; // 0/1/2
	struct s_vert	*next;
}					t_vert;

void				ft_read_input(t_vert **rooms);

void				ft_free_links(t_edges **links);
void				ft_push_link_back(t_edges **links, t_edges *link);
t_edges				*ft_make_link(char *name1, char *name2);

void				ft_free_rooms(t_vert **first);
void				ft_push_room_back(t_vert **first, t_vert *room);
t_vert				*ft_make_room(char *name, int x, int y, char mark);

#endif