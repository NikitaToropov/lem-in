#include <lem_in.h>

// void		modify_matrix(t_matrix *matrix, int *arr)
// {
// 	int		i;

// 	i = 1;
// 	while ((i + 1) < arr[0])
// 	{
// 		matrix->mtrx[arr[i]][arr[i + 1]] = -1;
// 		matrix->mtrx[arr[i + 1]][arr[i]] = 0;
// 		i++;
// 	}
// 	print_matrix(matrix);
// }

void		modify_matrix(t_matrix *matrix, int *arr)
{
	int		i;

	i = 1;
	while ((i + 1) <= arr[0])
	{
		matrix->mtrx[arr[i]][arr[i + 1]] = 0;
		matrix->mtrx[arr[i + 1]][arr[i]] = 1;
		i++;
	}
	print_matrix(matrix);
}

// int		*make_arr(int num_of_vertices, int *ver)
// {
// 	int		*way;
// 	int		i;
// 	int		j;
// 	printf("\n====================================================");
// 	printf("\nBalman-Ford run\n");

// 	if (!(way = malloc(sizeof(int) * (num_of_vertices + 1))))
// 		exit(1);
// 	way[0] = num_of_vertices;
// 	i = 1;
// 	j = num_of_vertices - 1;
// 	while (i <= num_of_vertices)
// 	{
// 		way[i++] = ver[j--];
// 	}
// 	printf("\nВывод кратчайшего пути\n");
// 	printf("num_of_vertices = %i\n", way[0]);
// 	for (int i = 1; i <= num_of_vertices; i++)
// 		printf("%d ", way[i]);
// 	return (way);
// }

int		*bellman_ford(t_matrix *matrix)
{
	int		d[matrix->len];
	int		p[matrix->len];
	int		i = 0;

	while (i < matrix->len)
	{
		d[i] = INT_MAX;
		p[i++] = -1;
	}
	d[matrix->start] = 0;
	while (i)
	{
		i = 0;
		for (int j = 0; j < matrix->len; ++j)
		{
			if (d[j] < INT_MAX)
			{
				for (int k = 0; k < matrix->len; ++k)
				{
					if (matrix->mtrx[j][k] && d[k] > matrix->mtrx[j][k] + d[j])
					{
						d[k] = matrix->mtrx[j][k] + d[j];
						p[k] = j;
						i = 1;
					}
				}
			}
		}
	}
	i = 0;
	while (i < matrix->len)
		printf(" %d", d[i++]);
	printf("\n");

	if (d[matrix->finish] == INT_MAX)
		printf("NO PATH BRO! NO PATH! SORRY\n");
	else
	{
		// for (int cur = matrix->finish; cur!=-1; cur=p[cur])
		i = matrix->finish;
		while (i != -1)
		{
			printf(" %d", i);
			i = p[i];
		}
			// path.push_back (cur);
		// reverse (path.begin(), path.end());
 
		// cout << "Path from " << v << " to " << t << ": ";
		// for (size_t i=0; i<path.size(); ++i)
		// 	cout << path[i] << ' ';
	}
	return (NULL);
}