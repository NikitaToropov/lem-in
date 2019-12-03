#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define NONE			0
# define START			1
# define FINISH			2

typedef struct					s_vert
{
	int				num;
	char			*name;
	int				x;
	int				y;
	char			indicator; // 0/1/2
	struct s_vert	*next;
}								t_vert;

typedef struct					s_links
{
	int				link[2];
	struct s_vert	*next;
}								t_links;

void		ft_read_input(t_vert **verts, int *ants);


void		ft_free_vert_sruct(t_vert **first);
t_vert		*ft_make_vert(int number, char *name, int x_cord, int y_cord);

#endif