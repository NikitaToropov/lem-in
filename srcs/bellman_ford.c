#include <lem_in.h>

void		modify_matrix(t_matrix *matrix, int *arr)
{
	int		i;

	i = 1;
	while ((i + 1) < arr[0])
	{
		matrix->mtrx[arr[i]][arr[i + 1]] = -1;
		matrix->mtrx[arr[i + 1]][arr[i]] = 0;
		i++;
	}
}

int		*make_arr(int num_of_vertices, int *ver)
{
	int		*way;
	int		i;
	int		j;

	if (!(way = malloc(sizeof(int) * (num_of_vertices + 1))))
		exit(1);
	way[0] = num_of_vertices;
	i = 1;
	j = num_of_vertices - 1;
	while (i <= num_of_vertices)
	{
		way[i++] = ver[j--];
	}
	printf("\nВывод кратчайшего пути\n");
	printf("num_of_vertices = %i\n", way[0]);
	for (int i = 1; i <= num_of_vertices; i++)
		printf("%d ", way[i]);
	return (way);
}

int		*restore_the_path(t_matrix *matrix, int *distance)
{
	int		ver[matrix->len]; // массив посещенных вершин
	int		end; // индекс конечной вершины
	int		k; // индекс предыдущей вершины
	int		weight; // вес конечной вершины
	int		i;

	end = matrix->finish;
	ver[0] = end;
	k = 1;
	weight = distance[end];
	while (end != matrix->start) // пока не дошли до начальной вершины
	{
		i = 0;
		while (i < matrix->len)
		{
			if (matrix->mtrx[end][i] == 1)   // если связь есть
			{
				if ((weight - 1) == distance[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight -= 1; // сохраняем новый вес
					end = i;       // сохраняем предыдущую вершину
					ver[k++] = i; // и записываем ее в массив
				}
			}
			i++;
		}
	}
	return (make_arr(k, ver));
}

int		*bellman_ford(t_matrix *matrix)
{
	int		distance[matrix->len]; // минимальное расстояние
	int		visit[matrix->len]; // посещенные вершины
	int		min_index;
	int		min_dist;
	int		i;

	i = 0;
	while(i < matrix->len)
	{
		distance[i] = INT_MAX;
		visit[i] = 1;
		i++;
	}
	
	distance[matrix->start] = 0;
	min_index = 0;
	while (min_index < INT_MAX)
	{
		min_index = INT_MAX;
		min_dist = INT_MAX;
		i = 0;
		while (i < matrix->len)
		{
			if (visit[i] == 1 && distance[i] < min_dist)
			{
				min_dist = distance[i];
				min_index = i;
			}
			i++;
		}
		if (min_index != INT_MAX)
		{
			i = 0;
			while (i < matrix->len)
			{
				if (matrix->mtrx[min_index][i] > 0)
					if ((min_dist + 1) < distance[i])
						distance[i] = min_dist + 1;
				i++;
			}
			visit[min_index] = 0;
		}
	}
	if (distance[matrix->finish == INT_MAX])
		return (NULL); // важно для случая когда все пути найдены
	// Вывод кратчайших расстояний до вершин
	printf("\nКратчайшие расстояния до вершин: \n");
	i = 0;
	while (i < matrix->len)
		printf("%d ", distance[i++]);

	return (restore_the_path(matrix, distance));
}