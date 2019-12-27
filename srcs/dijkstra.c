#include <lem_in.h>

int		*make_arr(t_matrix *matrix, int num_of_verts, int *p)
{
	int		*arr;
	int		i;
	int		j;

	if (!(arr = malloc(sizeof(int) * (num_of_verts + 1))))
		return (arr);

	arr[0] = num_of_verts;
	arr[1] = matrix->start;
	i = matrix->finish;
	j = num_of_verts;
	while (i != matrix->start && j > 1)
	{
		arr[j--] = i;
		i = p[i];
	}
	i = 0;
	while (i <= num_of_verts)
		printf(" %d", arr[i++]);
	return (arr);
}

int		*dijkstra(t_matrix *matrix, int *parents)
{
	int		d[matrix->len];
	int		p[matrix->len];
	char	u[matrix->len]; // visited edges
	int		i = 0;
	int		j = 0;

	while (i < matrix->len)
	{
		d[i] = INT_MAX;
		u[i++] = 0;
	}
	d[matrix->start] = 0;
	j = matrix->start;
	while (j != matrix->finish)
	{
		if (j > matrix->len || d[j] == INT_MAX)
			return (NULL);
		u[j] = 1;
		if (parents[j] != -1 && matrix->mtrx[parents[j]][parents[parents[j]]])
		{
			i = parents[j];
			d[i] = matrix->mtrx[j][i] + d[j];
			p[i] = j;
			parents[parents[j]] = -1;
		}
		else
		{
			i = 0;
			while (i < matrix->len)
			{
				if (matrix->mtrx[j][i] && d[i] > matrix->mtrx[j][i] + d[j])
				{
					d[i] = matrix->mtrx[j][i] + d[j];
					p[i] = j;
				}
				i++;
			}
		}
		j = 0;
		while (j < matrix->len && !(!u[j] && d[j] != INT_MAX))
			j++;
	}
	if (d[matrix->finish] == INT_MAX)
		return (NULL);


	i = 0;
	while (i < matrix->len)
		printf(" %d", d[i++]);
	printf("\n");


	return (make_arr(matrix, d[matrix->finish] + 1, p));
}
