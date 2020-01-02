#include <lem_in.h>

int		*make_arr(t_matrix *matrix, int *p)
{
	int		*arr;
	int		len;
	int		j;
	int		i;

	len = 1;
	j = matrix->finish;
	while (j != matrix->start)
	{
		j = p[j];
		len++;
		write(1, "THETRTETRT\n", 11);
	}
	if (!(arr = malloc(sizeof(int) * (len + 1))))
		return (arr);

	arr[0] = len;
	arr[1] = matrix->start;
	i = matrix->finish;
	j = len;
	while (i != matrix->start && j > 1)
	{
		arr[j--] = i;
		i = p[i];
	}
	i = 0;
	while (i <= len)
		printf(" %d", arr[i++]);
	return (arr);
}

int		*dijkstra(t_matrix *matrix, int *children)
{
	int		d[matrix->len];
	int		p[matrix->len];
	char	u[matrix->len]; // visited edges
	int		i = 0;
	int		j = 0;

	// children[matrix->start] = -1;

	while (i < matrix->len)
	{
		d[i] = INT_MAX;
		u[i++] = 0;
		p[j] = -1;
	}
	d[matrix->start] = 0;
	j = matrix->start;
	while (j != matrix->finish)
	{
			printf(" %d", j);
		if (j >= matrix->len || d[j] == INT_MAX)
			return (NULL);
		u[j] = 1;
		i = 0;
		write (1, "AFTER THAT MAYBE???\n", 20);
		while (i < matrix->len)
		{
			printf("j = %i\n", j);
			printf("matrix->len = %i\n", matrix->len);
		write (1, "HOW MUCH TIMES???\n", 18);
			if (matrix->mtrx[j][i] && d[i] > matrix->mtrx[j][i] + d[j])
			{
				d[i] = matrix->mtrx[j][i] + d[j];
				p[i] = j;
			}
			i++;
		}
		if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
			p[children[j]] = j;
		j = 0;
		while (j < matrix->len && !(!u[j] && d[j] != INT_MAX))
			j++;
	}
					printf("\n");
	if (d[matrix->finish] == INT_MAX)
		return (NULL);


	i = 0;
	while (i < matrix->len)
		printf(" %d", d[i++]);
	printf("\n");
	i = 0;
	while (i < matrix->len)
		printf(" %d", p[i++]);
	printf("\n");


	return (make_arr(matrix, p));
	// return (make_arr(matrix, p));
}