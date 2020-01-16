#include <lem_in.h>

int		*make_arr(t_matrix *matrix, int *p)
{
	int		*arr;
	int		len;
	int		j;
	int		i;


	// print_int_arr(p, matrix->len);
	len = 1;
	j = matrix->finish;
	while (j != matrix->start)
	{
		j = p[j];
		len++;
		printf("THETRTETRT     j = %i\n", j);
	}
	if (!(arr = malloc(sizeof(int) * (len + 1))))
		return (NULL);

	arr[0] = len;
	arr[1] = matrix->start;
	i = matrix->finish;
	j = len;
	while (i != matrix->start && j > 1)
	{
		arr[j--] = i;
		i = p[i];
	}
	// i = 0;
	// while (i <= len)
	// 	printf(" %d", arr[i++]);
	return (arr);
}

int		*dijkstra(t_matrix *matrix, int *children)
{
	int		d[matrix->len];
	int		p[matrix->len];
	char	u[matrix->len]; // visited edges
	int		i = 0;
	int		j = 0;

	while (i < matrix->len)
	{
		d[i] = INT_MAX;
		u[i] = 0;
		p[i] = -1;
		i++;
	}
	d[matrix->start] = 0;
	j = matrix->start;
	while (j < matrix->len)
	{
		u[j] = 1;
		if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
		{
			p[children[j]] = j;
			d[children[j]] = matrix->mtrx[j][children[j]] + d[j];
		}
		else
		{
			i = 0;
			while (i < matrix->len)
			{
				// if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
				// {
				// 	p[children[j]] = j;
				// 	d[children[j]] = matrix->mtrx[j][children[j]] + d[j];
				// }
				if (!u[i] && matrix->mtrx[j][i] && d[i] > matrix->mtrx[j][i] + d[j] &&
				(children[j] == -1 || (p[j] != -1 && p[p[j]] != -1 && children[p[p[j]]] == p[j])))
				{
					d[i] = matrix->mtrx[j][i] + d[j];
					p[i] = j;
				}
					i++;
			}
		}
		
		// if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
		// {
		// 	p[children[j]] = j;
		// 	d[children[j]] = matrix->mtrx[j][children[j]] + d[j];
		// }
		j = 0;
		while (j < matrix->len && !(!u[j] && d[j] != INT_MAX))
			j++;
		
	}
	if (d[matrix->finish] == INT_MAX)
		return (NULL);
	return (make_arr(matrix, p));
}

int		swap_tails(int **new, int **old)
{
	int		i;
	int		j;
	int		*old_arr;
	int		*new_arr;
	// int		*new_tail;
	// int		*old_tail;

	old_arr = *old;
	new_arr = *new;
	i = 2;
	while (i < old_arr[0])
	{
		j = 2;
		while (j < new_arr[0])
		{
			if (old_arr[i] == new_arr[j])
			{
				// old_tail = &old_arr[i + 1];
				// 	new_tail = &new_arr[j + 1];
				// 	make_new_arr(old, old_tail, new_tail, (new_arr[0] + 1 - (new_tail - new_arr)));
				make_new_arr(old, &old_arr[i + 1], &new_arr[j + 1], (new_arr[0] + 1 - (&new_arr[j + 1] - new_arr)));
				break ;
			}
			j++;
		}
		if (j < new_arr[0])
			break ;
		i++;
	}
	if (i >= old_arr[0])
		return (0);
	while (j > 1 && i < old_arr[0] && old_arr[i] == new_arr[j])
	{
		j--;
		i++;
	}
		i--;
		j++;
	// if (j == 2 || i == (old_arr[0] - 1) )
	// {
	// 	if (old_arr[i] == new_arr[j])
	// 		printf("ZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPAZALZUPA\n");
	// 	print_int_arr(&new_arr[1], new_arr[0]);
	// 	print_int_arr(&old_arr[1], old_arr[0]);
	// }
	// old_tail = &new_arr[i + 1];
	// new_tail = &old_arr[j + 1];
	// make_new_arr(new, old_tail, new_tail, (old_arr[0] + 1 - (new_tail - old_arr))); // (old_arr[0] + 1 - (new_tail - old_arr)
	make_new_arr(new, &new_arr[j + 1], &old_arr[i + 1], (old_arr[0] + 1 - (&old_arr[i + 1] - old_arr))); // (old_arr[0] + 1 - (new_tail - old_arr)
	// free(new_arr);
	return (1);
}