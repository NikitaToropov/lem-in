#include <lem_in.h>


// void		loop_check(t_edges *way)
// {
// 	t_edges		*edge1;
// 	t_edges		*edge2;

// 	edge1 = way;
// 	while (edge1->next)
// 	{
// 		edge2 = edge1->next;
// 		while (edge2)
// 		{
// 			if (edge2->to == edge1->to)
// 			{
// 				print_edges_struct(way);
// 				print_edges_struct(edge1);

// 				printf("LOOOOOOOP");
// 				exit(1);
// 			}
// 			edge2 = edge2->next;
// 		}
// 		edge1 = edge1->next;
// 	}
// }

// void		check_valid(t_ways *ways)
// {
// 	int		i = 0;
// 	int		n = 0;

// 	while (i < ways->num_of_ways)
// 	{
// 		loop_check(ways->way[i]);
// 		n = 0;
// 		while (i != n && n < ways->num_of_ways)
// 		{
// 			printf("\n\nn = %i, i = %i\n\n", n, i);
// 			common_vertex(ways->way[i], ways->way[n]);
// 			n++;
// 		}
// 		i++;
// 	}
// }

void		print_ways_struct(t_ways *way_struct)
{
	int			i;
	t_edges		*tmp;

	i = 0;
	printf("\n****||****||****|| PRINT WAY STRUCT ||****||****||****||***\n");
	printf("num_of_ways = %i\n", way_struct->num_of_ways);
	while (i < way_struct->num_of_ways)
	{
		printf("edge #%i    = ", i);
		tmp = way_struct->way[i];
		while (tmp)
		{
			// printf(" %s,", tmp->to->name);
			printf(" %i", tmp->to->key);
			tmp = tmp->next;
		}
		printf("\n");
		i++;
	}
	printf("*****||****||****||****||****||****||****||****||****||****\n");
}

void		free_ways_struct(t_ways **old_ways)
{
	int		i;

	if (old_ways && *old_ways)
	{
		i = 0;
		while (i < (*old_ways)->num_of_ways)
		{
			free_edges_struct(&(*old_ways)->way[i]);
			i++;
		}
		free((*old_ways)->way);
		(*old_ways)->way = NULL;
		free(*old_ways);
		*old_ways = NULL;
	}
}

void		fill_the_way(t_edges **way, int start)
{
	t_edges		*neg_edge;

	while ((*way)->to->key != start)
	{
		neg_edge = (*way)->to->edge;
		while (neg_edge && neg_edge->weight != -1)
			neg_edge = neg_edge->next;
		if (!neg_edge)
		{
			neg_edge = (*way)->to->edge;
			while (neg_edge && neg_edge->weight != 0)
				neg_edge = neg_edge->next;
		}
		if (!neg_edge)
		{
			printf("fill_the_wauy/neg_edge\n");
			exit(1);
		}
		push_edge_front(way, new_edge(neg_edge->to, (*way)->weight + 1));

	}
		print_edges_struct(*way);
}

t_ways		*new_ways_struct(t_graph *graph, int number)
{

	t_verts		*end;
	t_ways		*ways;
	t_edges		*last_lvl;
	int			i;

	ways = ft_memalloc(sizeof(t_ways));
	ways->way = ft_memalloc(sizeof(t_edges) * number);
	ways->num_of_ways = number;
	end = find_vertex(graph->rooms, graph->finish);
	last_lvl = end->edge;
	i = 0;
	while (i < number)
	{
		ways->way[i] = new_edge(end, 0);
		while (last_lvl && last_lvl->weight != -1)
			last_lvl = last_lvl->next;
		if (!last_lvl)
		{
			printf("new_ways\n");
			exit(1);
		}
		push_edge_front(&ways->way[i], new_edge(last_lvl->to, ways->way[i]->weight + 1));
		last_lvl = last_lvl->next;
		fill_the_way(&ways->way[i], graph->start);
		if (ways->way[i]->to->key != graph->start)
		{
			print_edges_struct(ways->way[i]);
			printf("new_ways/fill_the_way\n");
			exit(1);
		}
		i++;
	}
	print_ways_struct(ways);

	return (ways);
}
