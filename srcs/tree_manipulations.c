#include <lem_in.h>

void		reverse_the_way_in_graph(t_verts *root, t_edges *way)
{
	t_edges		*current;
	t_edges		*tmp;
	t_verts		*from;
	t_verts		*psevdo;
	t_verts		*to;

	current = way;
	psevdo = NULL;
	from = current->to;
	while (current && current->next)
	{
		to = current->next->to;
		if (psevdo)
			tmp = pull_edge(&psevdo->edge, to); // tmp = from->to
		else
			tmp = pull_edge(&from->edge, to); // tmp = from->to
		push_edge_front(&from->reserve, tmp);
		if (!(tmp = pull_edge(&to->edge, from)))
		{
	// printf("\n\n\nproblems with taking to->from\n\n\n\n");
	print_vertex(to);
	print_vertex(from);
	// print_vertex(psevdo);
	
	printf("\n\n\nTHIS SHIT\n\n\n\n");
	print_edges_struct(way);

			exit(1);
		}
		push_edge_front(&to->reserve, tmp); // take edge "to -> from"
		// push_edge_front(&to->reserve, pull_edge(&to->edge, from)); // take edge "to -> from"
		if (!current->next->next)
			break ;
		if (!psevdo)
			tmp = new_edge(from, -1); // tmp = from->to
		else
			tmp = new_edge(psevdo, -1); // tmp = from->to
		psevdo = find_vertex(root, (to->key + 1));
		push_edge_back(&psevdo->edge, to->edge);
		// psevdo->edge->next = to->edge; // add all edges from "from" to "psevdo" edge "from -> to" excluded
		// push_edge_front(&to->edge, tmp);
		to->edge = tmp;
		from = to;
		current = current->next;
	}
	push_edge_front(&to->edge, new_edge(psevdo, -1));
}

void		restore_vertex(t_verts *vert)
{
	vert->visit = 0;
	vert->distance = MAXIMUM;
	vert->parent = NULL;
}

void		restore_graph(t_graph *graph)
{
	t_verts		*start;
	t_verts		*finish;
	t_edges		*real;
	t_edges		*for_del;

	start = find_vertex(graph->rooms, graph->start);
	push_edge_back(&start->edge, start->reserve);
	start->reserve = NULL;
	finish = find_vertex(graph->rooms, graph->finish);
	real = finish->edge;
	if (finish->edge->to->key % 2)
	{
		while (real && real->next && (real->next->to->key % 2))
			real = real->next;
		for_del = finish->edge;
		finish->edge = real->next;
		real->next = NULL;
		free_edges_struct(&for_del);
	}
	push_edge_back(&finish->edge, finish->reserve);
	finish->reserve = NULL;
	tree_traversal(graph->rooms, *restore_vertex);
}

void		custom_graph(t_graph *graph, t_ways *ways)
{
	int		i;

	i = 0;
	print_ways_struct(ways);
	while (i < ways->num_of_ways)
	{
		// print_edges_struct(ways->way[i]);
		reverse_the_way_in_graph(graph->rooms, ways->way[i]);

		i++;
	}
	// tree_traversal(graph, print_vertex);
}