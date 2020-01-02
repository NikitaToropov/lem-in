#include <lem_in.h>

void	print_all_ways(t_path *way)
{
	int			i;
	int			j;

	printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!! THIS ONE PATH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	i = 0;
	while (i < way->num_of_paths)
	{
		j = 1;
		printf("way #%i ---- ", i);
		while (j <= way->path[i][0])
			printf(" %i", way->path[i][j++]);
		printf("\n");
		i++;
	}
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}


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
	// print_matrix(matrix);
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
	// printf("\n!!!!!!!!!!!!!!  NEW PARENTS  !!!!!!!!!!!!!!\n");
	// i = 0;
	// while (i < matrix->len)
	// {
	// 	printf(" %d", parents[i++]);
	// }
	
	// printf("---------------------------------------------\n\n");
}

int			num_of_output_lines(t_path *way, int num_of_ants)
{
	int		arr_len[way->num_of_paths];
	int		result;
	int		i;

	// printf("00000000000000000000000000000000000000s00000000000000000000000000000000000000000000000000000000000000\n");
	i = 0;
	result = way->path[0][0] - 1;
	while (i < way->num_of_paths)
	{
		if ((way->path[i][0] - 1) < result)
			result = way->path[i][0] - 1;
		arr_len[i] = way->path[i][0] - 1;
		i++;
	}
	while (num_of_ants)
	{
		i = 0;
		while (i < way->num_of_paths && num_of_ants)
		{
			if (arr_len[i] == result)
			{
				arr_len[i]++;
				num_of_ants--;
			}
			i++;
		}
		result++;
	}
	printf("\n\nres = %i\n", (result - 1));
	return (result - 1);
}

t_path		*bhandari(t_matrix *matrix, int num_of_ants)
{
	t_path		*way;
	t_path		*tmp_way;
	int			*new_arr;
	// int			i;
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
	print_all_ways(way);

	// way = make_new_way(way, dijkstra(matrix, parents));

	// modify_matrix(matrix, way);
	// fill_parents(parents, way, matrix);
	// tmp_way = make_new_way(way, dijkstra(matrix, parents));
	// print_all_ways(way);
	// print_all_ways(tmp_way);
	// printf("num of ants = %i\n", num_of_ants);
	// printf("new path is shorter?\n way = %i\n tmp_way = %i\n", output_line_length(way, num_of_ants), output_line_length(tmp_way, num_of_ants));

	while ((new_arr = dijkstra(matrix, parents)))
	{
		tmp_way = make_new_way(way, new_arr);
		if (num_of_output_lines(tmp_way, num_of_ants) >= num_of_output_lines(way, num_of_ants))
		{
			free_way(&tmp_way);
			break ;
		}

		fill_parents(parents, tmp_way, matrix);
		modify_matrix(matrix, tmp_way);
		free_way(&way);
		way = tmp_way;

	}
	print_all_ways(way);










	// while ((new_arr = dijkstra(matrix, parents)))
	// {
	// 	tmp_way = make_new_way(way, new_arr);
	// 	if (output_line_length(way, num_of_ants) < output_line_length(tmp_way, num_of_ants))
	// 	{
	// 		// free_way(&tmp_way);
	// 		break ;
	// 	}

	// 	// free(&way);
	// 	way = tmp_way;
	// 	fill_parents(parents, way, matrix);
	// 	modify_matrix(matrix, way);
	// 	write (1, "AFTER THAT???\n", 14);
	// }
	// i = way->num_of_paths - 1;
	// while (i >= 0)
	// {
	// 	print_int_arr(way->path[i], way->path[i][0] + 1);
	// 	i++;
	// }
	
	// return(way);
	return(NULL);
}