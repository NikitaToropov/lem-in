#include <stdio.h>
#include <stdlib.h>

void	print_int_arr(int *arr, int len)
{
	int		i = 0;

	while (i < len)
		printf(" %i", arr[i++]);
	printf("\n");
}

int		swap_tails(int *new, int *old)
{
	int		i;
	int		j;
	int		*tail_for_new;
	int		*tail_for_old;
	int		*cut_new;
	int		*cut_old;
	int		*tmp;

	tail_for_new = NULL;
	tail_for_old = NULL;
	i = 2;
	while (i < old[0])
	{
		j = 2;
		while (j < new[0])
		{
			if (old[i] == new[j])
			{
				if (!tail_for_old)
				{
					tail_for_old = &new[j] + 1;
					cut_old = &old[i];
				}
				else
				{
					tail_for_new = &old[i] + 1;
					cut_new = &new[j];
				}
			}
			j++;
		}
		i++;
	}
	if (!tail_for_new || !tail_for_old)
	{
		if (!tail_for_new)
			printf("no tail_for_new\n");
		if (!tail_for_old)
			printf("no tail_for_old\n");
		return (0);
	}
	printf("tail_for_old = %i%i\n", tail_for_old[0], tail_for_old[1]);
	printf("tail_for_new = %i%i\n", tail_for_new[0], tail_for_new[1]);


	tmp = new;
	i = cut_new - new + (old[0] - (cut_old - old));
	printf("len of new = %i  vs  7\n", i);
	new = malloc(sizeof(int) * i);
	new[0] = i - 1;
	j = 1;
	while (j < i)
	{
		if (&tmp[j] <= cut_new)
			new[j] = tmp[j];
		else
		{
			new[j] = *tail_for_new;
			tail_for_new++;
		}
		j++;
	}
	print_int_arr(new, new[0] + 1);


	i = cut_old - old + (tmp[0] - (cut_new - tmp));
	tmp = old;
	old = malloc(sizeof(int) * i);
	old[0] = i - 1;
	j = 1;
	while (j < i)
	{
		if (&tmp[j] <= cut_old)
			old[j] = tmp[j];
		else
		{
			old[j] = *tail_for_old;
			tail_for_old++;
		}
		j++;
	}
	print_int_arr(old, old[0] + 1);



	// printf("len of old = %i  vs  6\n", i);
	return (1);
}

int		main()
{
	int		a[] = {5, 0, 2, 6, 8, 13};
	int		b[] = {8, 0, 1, 4, 7, 8, 6, 11, 13};
	int		*old;
	int		*new;

	old = a;
	new = b;
	swap_tails(new, old);
	return (0);
}