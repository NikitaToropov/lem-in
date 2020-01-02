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
	int			len;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	len = 1;
	if (way)
		len += way->num_of_paths;
	if (!(new->path = malloc(sizeof(int*) * len)))
		exit(1);
	new->num_of_paths = len;
	i = 0;
	while (way && i < way->num_of_paths)
	{
		new->path[i] = way->path[i];
		i++;
	}
	new->path[i] = new_path;
	if (new->num_of_paths > 1)
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