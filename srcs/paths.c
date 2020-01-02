#include <lem_in.h>

void	change_common_edges(t_path *way)
{
	int		**tmp;
	int		i;

	tmp = &(way->path[way->num_of_paths - 1]);
	i = way->num_of_paths - 2;
	while (i >= 0)
	{
		if (swap_tails(tmp, &(way->path[i])))
		{
			tmp = &(way->path[i]);
		}
		i--;
	}
}

t_path		*make_new_way(t_path *way, int *new_path)
{
	t_path		*new;
	int			i;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	if (!(new->path = malloc(sizeof(int*) * (way->num_of_paths + 1))))
		exit(1);
	new->num_of_paths = way->num_of_paths + 1;
	i = 0;
	while (i < way->num_of_paths)
	{
		new->path[i] = way->path[i];
		i++;
	}
	new->path[i] = new_path;
	change_common_edges(new);
	return (new);
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