#include <lem_in.h>

void	change_common_edges(t_path *old, t_path *new)
{
	int		*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < old->num_of_paths)
	{
		if (old)
	}
}

int			*int_array_copy(int *arr)
{
	
	if (!())
	return (new);
}

t_path		*make_new_way(t_path *way, int *new_path)
{
	t_path		*new;
	int			i;
	int			j;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	if (!(new->path = malloc(sizeof(int*) * (way->num_of_paths + 1))))
		exit(1);
	new->num_of_paths = way->num_of_paths + 1;
	i = 0;
	new->path[new->num_of_paths - 1] = new_path
	while (i < way->num_of_paths)
	{
		new[i] = ft_memccpy(int);
	}
}

void	free_way(t_path **way)
{
	int		i;

	i = 0;
	while (i < (*way)->num_of_paths)
		free((*way)->path[i++]);
	free((*way)->path);
	free(*way);
	way = NULL;
}