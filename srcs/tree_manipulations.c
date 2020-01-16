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
	if (current)
		from = current->to;
	while (current && current->next)
	{
		to = current->next->to;
		if (psevdo)
			tmp = pull_edge(&psevdo->edge, to); // tmp = from->to
		else
			tmp = pull_edge(&from->edge, to); // tmp = from->to
		push_edge_back(&from->reserve, tmp);
		to->reserve = pull_edge(&to->edge, from); // take edge "to -> from"
		if (!current->next->next)
			break ;
		if (!psevdo)
			tmp = new_edge(from); // tmp = from->to
		else
			tmp = new_edge(psevdo); // tmp = from->to
		psevdo = find_vertex(root, (to->key + 1));
		psevdo->edge->next = to->edge; // add all edges from "from" to "psevdo" edge "from -> to" excluded
		to->edge = tmp;
		from = to;
		current = current->next;
	}
	push_edge_front(&to->edge, new_edge(psevdo));
}

void		restore_vertex(t_verts *vert)
{
	if (vert->reserve)
	{
		free_edges_struct(&vert->edge);
		vert->edge = vert->reserve;
		vert->reserve = NULL;
	}
	vert->visit = 0;
	vert->distance = MAXIMUM;
	vert->parent = NULL;
}

void		restore_graph(t_graph *graph)
{
	t_verts 	*start;
	t_verts 	*finish;
	t_edges 	*real;
	t_edges 	*for_del;

	start = find_vertex(graph->rooms, graph->start);
	push_edge_back(&start->edge, start->reserve);
	start->reserve = NULL;

	finish = find_vertex(graph->rooms, graph->finish);
	real = finish->edge;
	while (real)
	{
		if (real->to->key % 2)
		{
			for_del = pull_edge(&finish->edge, real->to);
			free_edge(&for_del);
		}
		real = real->next;
	}
	push_edge_back(&finish->edge, finish->reserve);
	finish->reserve = NULL;

	tree_traversal(graph->rooms, *restore_vertex);
	tree_traversal(graph->rooms, *print_vertex);
	
}	