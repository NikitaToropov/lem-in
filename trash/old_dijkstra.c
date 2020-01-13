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
<<<<<<< HEAD
		printf("THETRTETRT     j = %i\n", j);
=======
		// printf("THETsRTETRT     j = %i\n", j);
		// if (j == 546)
			// exit(1);
>>>>>>> matrix
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
<<<<<<< HEAD
	while (j < matrix->len)
=======
	// while (j < matrix->len)
	while (j != matrix->finish)
>>>>>>> matrix
	{
		u[j] = 1;
<<<<<<< HEAD
		if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
=======
		i = children[j];
		// if (i != -1 && p[j] != -1 && children[p[j]] == -1)
		if (i != -1 && p[j] != -1 && (children[p[j]] == -1 || (p[p[j]] != -1 && children[p[p[j]]] != -1)))
>>>>>>> matrix
		{
			p[children[j]] = j;
			d[children[j]] = matrix->mtrx[j][children[j]] + d[j];
		}
		else
		{
			i = 0;
			while (i < matrix->len)
			{
<<<<<<< HEAD
				// if (children[j] != -1 && p[j] != -1 && children[p[j]] == -1)
				// {
				// 	p[children[j]] = j;
				// 	d[children[j]] = matrix->mtrx[j][children[j]] + d[j];
				// }
				if (!u[i] && matrix->mtrx[j][i] && d[i] > matrix->mtrx[j][i] + d[j] &&
				(children[j] == -1 || (p[j] != -1 && p[p[j]] != -1 && children[p[p[j]]] == p[j])))
=======
				if (matrix->mtrx[j][i] && d[i] > matrix->mtrx[j][i] + d[j]
				&& (u[i] == 0 || children[p[i]] == i))
				// && (p[i] == -1 || children[p[i]] == j))
				// && (children[i] == -1 || (p[i] != -1 && children[p[i]] != -1)))
>>>>>>> matrix
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
<<<<<<< HEAD
=======


	// i = 0;
	// while (i < matrix->len)
	// 	printf(" %d", p[i++]);
	// printf("\n");

	// i = 0;
	// while (i < matrix->len)
	// {
	// 	if (children[i] == 911)
	// 		break ;
	// 	i++;
	// }
	// printf("\n\np[911] = %i\n", p[911]);
	// printf("p[p[911]] = %i\n", p[p[911]]);
	// printf("p[%i] = %i\n", i, p[i]);


	// printf("\n\nmatrix 1163 x 911 = %i\n", matrix->mtrx[1163][911]);
	// printf("\n\nmatrix 1163 x 911 = %i\n", matrix->mtrx[1163][911]);
	// printf("xmatrix 911 x 1163 = %i\n", matrix->mtrx[911][1163]);
	// printf("children[911] = %i\n", children[911]);
	// printf("p[children[911]] = %i\n", p[children[911]]);
	// printf("p[911] = %i\n", p[911]);
	// printf("p[1163] = %i\n", p[1163]);
>>>>>>> matrix
	return (make_arr(matrix, p));
}