#include <lem_in.h>

int		*dijkstra(t_matrix *matrix)
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
		j = 0;
		while (j < matrix->len && !(!u[j] && d[j] != INT_MAX))
			j++;
	}


	i = 0;
	while (i < matrix->len)
		printf(" %d", d[i++]);
	printf("\n");


	if (d[matrix->finish] == INT_MAX)
		printf("NO PATH BRO! NO PATH! SORRY\n");
	else
	{
		i = matrix->finish;
		while (i != matrix->start)
		{
			printf(" %d", i);
			i = p[i];
		}
		printf(" %d", matrix->start);
	}
	return (NULL);
}
