#include <lem_in.h>

void	print_int_arr(int *arr, int len)
{
	int		i = 0;

	printf("\n\n==================== ARR_LEN = %i ====================\n", len);
	while (i < len)
		printf(" %i", arr[i++]);
	printf("\n=======================================================\n\n");
}

static void		make_new_arr(int **new, int *old_tail, int *new_tail, int new_tail_len)
{
	int		j;
	int		len;
	int		*tmp;

	// printf("\n\n ----------- MAKE NEW ARR ----------- MAKE NEW ARR ----------- MAKE NEW ARR ----------- MAKE NEW ARR ----------- \n");
	// print_int_arr (new_tail, new_tail_len);
	tmp = *new;	
	len = old_tail - tmp + (new_tail_len);
	*new = malloc(sizeof(int) * len);
	*new[0] = len - 1;
	j = 1;
	while (j < len)
	{
		if (&tmp[j] < old_tail)
			(*new)[j] = tmp[j];
		else
		{
			(*new)[j] = *new_tail;
			new_tail++;
		}
		j++;
	}
	// printf("\n ============== MAKE NEW ARR ============== MAKE NEW ARR ============== MAKE NEW ARR ============== MAKE NEW ARR ============== \n");
	// print_int_arr(&tmp[1], tmp[0]);
	// printf("16464646464644 16464646464644 16464646464644 16464646464644 16464646464644 16464646464644 \n");
	// print_int_arr(&(*new)[1], (*new)[0]);
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

// int		swap_tails(int **new, int **old)
// {
// 	int		i;
// 	int		j;
// 	int		*new_arr;
// 	int		*old_arr;
// 	int		*new_tail;
// 	int		*old_tail;
// 	int		*tmp;

// 	new_tail = NULL;
// 	old_tail = NULL;
// 	new_arr= *new;
// 	old_arr = *old;
// 	i = 2;
// 	while (i < old_arr[0])
// 	{
// 		j = 2;
// 		while (j < new_arr[0])
// 		{
// 			if (old_arr[i] == new_arr[j])
// 			{
// 				if (!new_tail)
// 				{
// 					old_tail = &old_arr[i + 1];
// 					new_tail = &new_arr[j + 1];
// 					make_new_arr(old, old_tail, new_tail, (new_arr[0] + 1 - (new_tail - new_arr)));
// 				}
// 				else
// 				{
// 					old_tail = &new_arr[j + 1];
// 					new_tail = &old_arr[i + 1];
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (!new_tail)
// 	{
// 		*old = int_arr_copy(*old);
// 		return (0);
// 	}
// 	tmp = *new;
// 	make_new_arr(new, old_tail, new_tail, (old_arr[0] + 1 - (new_tail - old_arr)));
// 	free(tmp);
// 	return (1);
// }