#include <stdio.h>
#include <stdlib.h>

void	print_int_arr(int *arr, int len)
{
	int		i = 0;

	while (i < len)
		printf(" %i", arr[i++]);
	printf("\n");
}

void	make_new_arr(int **new, int *old_tail, int *new_tail, int new_tail_len)
{
	int		j;
	int		len;
	int		*tmp;

	tmp = *new;
	// printf("len before old_tail = %i\n", (old_tail - tmp));
	// printf("new_tail_len = %i\n", new_tail_len);
	len = old_tail - tmp + (new_tail_len);
	// printf("len = %i\n", len);
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
}

int		swap_tails(int **new, int **old)
{
	int		i;
	int		j;
	int		*new_arr;
	int		*old_arr;
	int		*new_tail;
	int		*old_tail;

	new_tail = NULL;
	old_tail = NULL;
	new_arr= *new;
	old_arr = *old;
	i = 2;
	while (i < old_arr[0])
	{
		j = 2;
		while (j < new_arr[0])
		{
			if (old_arr[i] == new_arr[j])
			{
				if (!new_tail)
				{
					old_tail = &old_arr[i + 1];
					new_tail = &new_arr[j + 1];
					make_new_arr(old, old_tail, new_tail, (new_arr[0] + 1 - (new_tail - new_arr)));
					// print_int_arr(*old, (*old)[0] + 1);
				}
				else
				{
					old_tail = &new_arr[j + 1];
					new_tail = &old_arr[i + 1];
				}
			}
			j++;
		}
		i++;
	}
	if (!new_tail)
	{
		return (0);
	}
	make_new_arr(new, old_tail, new_tail, (old_arr[0] + 1 - (new_tail - old_arr)));
	return (1);
}

int		main()
{
	int		a[] = {5, 0, 2, 6, 8, 13}; // old
	int		b[] = {8, 0, 1, 4, 7, 8, 6, 11, 13}; // new
	int		*old;
	int		*new;

	old = a;
	new = b;
	print_int_arr(old, old[0] + 1);
	print_int_arr(new, new[0] + 1);
	printf("after swap\n");
	swap_tails(&new, &old);
	print_int_arr(old, old[0] + 1);
	print_int_arr(new, new[0] + 1);
	return (0);
}