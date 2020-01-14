#include <lem_in.h>

void		restore_shortest_path(t_graph *graph)
{
	t_verts		*vert;

	printf("\n*********************PRINT SHORTEST PATH*********************\n");
	vert = find_vertex(graph->rooms, graph->finish);
	while (vert && vert->key != graph->start)
	{
		printf(" %s,", vert->name);
		vert = vert->parent;
	}
	printf(" %s,", vert->name);
	printf("\n*********************PRINT SHORTEST PATH*********************\n\n");
}

t_verts		*next_vert(t_verts *root)
{
	t_verts		*vertex;

	if (!root)
		return (NULL);
	if (!root->visit && root->distance < MAXIMUM)
		return (root);
	else if ((vertex = next_vert(root->left)) ||
	(vertex = next_vert(root->right)))
		return (vertex);
	return (NULL);
}

void		relaxation_by_edges(t_verts *from)
{
	t_edges		*edge;
	int			dist;

	edge = from->edge;
	while (edge)
	{
		if (!edge->to->visit && (dist = from->distance + 1) < edge->to->distance)
		{
			edge->to->distance = dist;
			edge->to->parent = from;
		}
		edge = edge->next;
	}
}

void		dijkstra(t_graph *graph)
{
	t_verts		*vertex;

	vertex = find_vertex(graph->rooms, graph->start);
	vertex->distance = 0;
	while (vertex)
	{
		printf("YO\n");
		printf("vert_num = %i\n", vertex->key);
		vertex->visit = 1;
		relaxation_by_edges(vertex);
		vertex = next_vert(graph->rooms);
		printf("NO\n");
		// vertex = find_vertex(graph->rooms, 0);
		// j = 1;
		// while (j < graph->length && !vertex->visit &&
		// vertex->distance < MAXIMUM)
		// 	vertex = find_vertex(graph->rooms, j++);
	}
	restore_shortest_path(graph);
}