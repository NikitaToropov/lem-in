#include <lem_in.h>

void	print_int_arr(int *arr, int len)
{
	int		i = 0;

	printf("\n\n==================== ARR_LEN = %i ====================\n", len);
	while (i < len)
		printf(" %i", arr[i++]);
	printf("\n=======================================================\n\n");
}

int			*int_arr_copy(int *old)
{
	int		i;
	int		len;
	int		*new;

	i = 0;
	len = old[0];
	if (!(new = malloc(sizeof(int) * (len + 1))))
		exit(1);
	while (i <= len)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}



static void		make_new_arr(int **new, int *old_tail, int *new_tail, int new_tail_len)
{
	int		j;
	int		len;
	int		*tmp;

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
}

int		swap_tails(int **new, int **old)
{
	int		i;
	int		j;
	int		*new_arr;
	int		*old_arr;
	int		*new_tail;
	int		*old_tail;
	int		*tmp;

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
		*old = int_arr_copy(*old);
		return (0);
	}
	tmp = *new;
	make_new_arr(new, old_tail, new_tail, (old_arr[0] + 1 - (new_tail - old_arr)));
	free(tmp);
	return (1);
}