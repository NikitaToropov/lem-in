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


void		modify_matrix(t_matrix *matrix, int *new)
{
	int		i;
	// int		j;

	i = 1;
	while ((i + 1) <= new[0])
	{
		matrix->mtrx[new[i]][new[i + 1]] = 0;
		matrix->mtrx[new[i + 1]][new[i]] = 1;
		i++;
	}
}

void	fill_parents(int *parents, t_path *way, t_matrix *matrix)
{
	int		i;
	int		j;

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
	// printf("\n--------------------  NEW PARENTS  --------------------\n");
	// i = 0;
	// while (i < matrix->len)
	// {
	// 	printf(" %d", parents[i++]);
	// }
	
	// printf("\n-------------------------------------------------------\n\n");
}

int			num_of_output_lines(t_path *way, int num_of_ants)
{
	int		arr_len[way->num_of_paths];
	int		result;
	int		i;

	i = 0;
	result = way->path[0][0];
	while (i < way->num_of_paths)
	{
		arr_len[i] = way->path[i][0] - 1;
		if (result > arr_len[i++])
			result = arr_len[i - 1];
		// i++;
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
	printf("\n\nres = %i\n", (result - 1));
	return (result - 1);
}

t_path		*bhandari(t_matrix *matrix, int num_of_ants)
{
	t_path		*way;
	t_path		*tmp_way;
	int			*new_arr;
	int			parents[matrix->len];
	// int			*parents;

	way = NULL;
	tmp_way = NULL;
	
	// if(!(parents = malloc(sizeof(matrix->len))))
	// 	exit(1);
	fill_parents(parents, tmp_way, matrix);
	
	while (num_of_ants > 0 && (new_arr = dijkstra(matrix, parents)))
	{
		modify_matrix(matrix, new_arr);
		printf("\nnew_arr = ");
		print_int_arr(&new_arr[1], new_arr[0]);
		tmp_way = make_new_way(way, new_arr);
			print_all_ways(tmp_way);
		if (way &&
		num_of_output_lines(tmp_way, num_of_ants) >= num_of_output_lines(way, num_of_ants))
		{
			// print_all_ways(way);
			// print_all_ways(tmp_way);
			
			// free_way(&tmp_way);
			break ;
		}
		fill_parents(parents, tmp_way, matrix);
		// print_matrix(matrix); ////////////////////////////////////////////////////////////
		// modify_matrix(matrix, tmp_way);
		
		
		// if (way)
		// 	free_way(&way);
		way = tmp_way;

	}
	if (way)
	{
		 	// free_way(&way);
		print_all_ways(way);

	}
	return(way);
}