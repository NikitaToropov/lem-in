#include <lem_in.h>

void	restore_the_path(t_matrix *matrix, int *dist)
{
	int		ver[matrix->len]; // массив посещенных вершин
	int		end = matrix->finish; // индекс конечной вершины
	int		k = 1; // индекс предыдущей вершины
	int		weight = dist[end]; // вес конечной вершины
	int		i;
	int		temp;

	ver[0] = end;
	while (end != matrix->start) // пока не дошли до начальной вершины
	{
		i = 0;
		while (i < matrix->len)
		{
			if (matrix->mtrx[end][i] == '1')   // если связь есть
			{
				// write(1, "WHYYYYYY\n", 9);
				temp =  weight - 1;
				if (temp == dist[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохраняем новый вес
					end = i;       // сохраняем предыдущую вершину
					ver[k] = i; // и записываем ее в массив
					k++;
				}
			}
			i++;
		}
	}

	printf("\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--)
		printf("%3d ", ver[i]);
}


void	dijkstra(t_matrix *matrix)
{
	int		dist[matrix->len];
	int		visit[matrix->len];
	int		temp;
	int		minindex;
	int		min;
	int		i;

	
	i = 0;
	while(i < matrix->len)
	{
		dist[i] = INT_MAX;
		visit[i] = 1;
		i++;
	}
	dist[matrix->start] = 0;
	printf("\n\n\n\nstart = %i\n", matrix->start);
	printf("finish = %i\n", matrix->finish);

	
	minindex = 0;
	while (minindex < INT_MAX)
	{
		minindex = INT_MAX;
		min = INT_MAX;
		i = 0;
		for (int i = 0; i < matrix->len; i++)
		{
			if (visit[i] == 1 && dist[i] < min)
			{
				min = dist[i];
				minindex = i;
			}
		}
		if (minindex != INT_MAX)
		{
			for (int i = 0; i<matrix->len; i++)
			{
				if (matrix->mtrx[minindex][i] > '0')
				{
					temp = min + 1;
					if (temp < dist[i])
						dist[i] = temp;
				}
			}
			visit[minindex] = 0;
		}
	}
	// Вывод кратчайших расстояний до вершин
	printf("\nКратчайшие расстояния до вершин: \n");
	i = 0;
	while (i < matrix->len)
		printf("%d ", dist[i++]);

	restore_the_path(matrix, dist);
}