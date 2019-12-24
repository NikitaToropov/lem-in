#include <lem_in.h>

t_path		*make_new_way(t_path *way, int *new_path)
{
	t_path		*new;

	if (!(new = malloc(sizeof(t_path))))
		exit(1);
	if (!(new->path = malloc(sizeof(int*) * (way->num_of_paths + 1))))
		exit(1);
	
}


void		free_way(t_path **way)
{
	int		i;

	i = 0;
	while (i < (*way)->num_of_paths)
		free((*way)->path[i++]);
	free((*way)->path);
	free(*way);
	way = NULL;
}

int			output_line_length(t_path *way, int num_of_ants)
{
	int		arr_len[way->num_of_paths];
	int		result;
	int		i;

	i = 0;
	result = way->path[0];
	while (i < way->num_of_paths)
	{
		if (way->path[i][0] < result)
			result = way->path[i][0];
		arr_len[i] = way->path[i][0];
		i++;
	}
	while (num_of_ants)
	{
		i = 0;
		while (i < way->num_of_paths && num_of_ants)
		{
			if (arr_len[i] <= result)
			{
				arr_len[i]++;
				num_of_ants--;
			}
			i++;
		}
		result++;
	}
	return (result);
}

void		modify_matrix(t_matrix *matrix, int *arr)
{
	int		i;

	i = 1;
	while (i < arr[0])
	{
		matrix->mtrx[i + 1][i] = '1';
		matrix->mtrx[i][i + 1] = '0';
		i++;
	}
}

t_path		*bhandari(t_matrix *matrix, int num_of_ants)
{
	t_path		*way;
	t_path		*tmp_way;
	int			*new_arr;

	if (!(way = malloc(sizeof(t_path))))
		exit(1);
	if (!(way->path = malloc(sizeof(int*))))
		exit(1);
	way->num_of_paths = 1;
	way->path[1] = dijkstra;
	modify_matrix(matrix, way);
	while ((new_arr = dijkstra))
	{
		modify_matrix(matrix, new_arr);
		tmp_way = make_new_way(way, new_arr);
		if (output_line_length(way, num_of_ants) < output_line_length(tmp_way, num_of_ants))
		{
			free_way(&tmp_way);
			break ;
		}
		free(&way);
		way = tmp_way;
	}
	return(way);
}