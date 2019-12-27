#include <lem_in.h>

void		modify_matrix(t_matrix *matrix, t_path *way)
{
	int		i;
	int		j;
	int		*arr;

	j = 0;
	while (j < way->num_of_paths)
	{
		i = 1;
		arr = way->path[j];
		while ((i + 1) <= arr[0])
		{
			matrix->mtrx[arr[i]][arr[i + 1]] = 0;
			matrix->mtrx[arr[i + 1]][arr[i]] = 1;
			i++;
		}
		j++;
	}
	print_matrix(matrix);
}

void	fill_parents(int *parents, t_path *way, t_matrix *matrix)
{
	int		i;
	int		j;
	// int		*arr;

	i = 0;
	while (i < matrix->len)
		parents[i++] = -1;
	i = 0;
	while (way && i < way->num_of_paths)
	{
		j = way->path[i][0] - 1;
		while (j > 1)
		{
			parents[way->path[i][j]] = way->path[i][j - 1];
			j--;
		}
		i++;
	}
	printf("\n!!!!!!!!!!!!!!  NEW PARENTS  !!!!!!!!!!!!!!\n");
	i = 0;
	while (i < matrix->len)
	{
		printf(" %d", parents[i++]);
	}
	
	printf("---------------------------------------------\n\n");
}

// int			output_line_length(t_path *way, int num_of_ants)
// {
// 	int		arr_len[way->num_of_paths];
// 	int		result;
// 	int		i;

// 	i = 0;
// 	result = way->path[0][0];
// 	while (i < way->num_of_paths)
// 	{
// 		if (way->path[i][0] < result)
// 			result = way->path[i][0];
// 		arr_len[i] = way->path[i][0];
// 		i++;
// 	}
// 	while (num_of_ants)
// 	{
// 		i = 0;
// 		while (i < way->num_of_paths && num_of_ants)
// 		{
// 			if (arr_len[i] <= result)
// 			{
// 				arr_len[i]++;
// 				num_of_ants--;
// 			}
// 			i++;
// 		}
// 		result++;
// 	}
// 	return (result);
// }

t_path		*bhandari(t_matrix *matrix, int num_of_ants)
{
	t_path		*way;
	// t_path		*tmp_way;
	int			*new_arr;
	int			parents[matrix->len];

	if (!num_of_ants)
		return(NULL);

	if (!(way = malloc(sizeof(t_path))))
		exit(1);
	if (!(way->path = malloc(sizeof(int*))))
		exit(1);
	way->num_of_paths = 1;
	fill_parents(parents, NULL, matrix);
	way->path[0] = dijkstra(matrix, parents);
	fill_parents(parents, way, matrix);
	modify_matrix(matrix, way);
	new_arr = dijkstra(matrix, parents);
// 	while ((new_arr = bellman_ford(matrix)))
// 	{
// 		tmp_way = make_new_way(way, new_arr);
// 		if (output_line_length(way, num_of_ants) < output_line_length(tmp_way, num_of_ants))
// 		{
// 			free_way(&tmp_way);
// 			break ;
// 		}
// 		free(&way);
// 		way = tmp_way;
// 	}
	// return(way);
	return(NULL);
}