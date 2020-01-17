/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/17 19:08:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_edges		*restore_shortest_path(t_graph *graph)
{
	t_edges		*path;
	t_verts		*vert;

	path = NULL;
	vert = find_vertex(graph->rooms, graph->finish);
	while (vert && vert->parent && vert->key != graph->start)
	{




		printf("vert->key = %i\n", vert->key);



		
		push_edge_front(&path, new_edge(vert));
		vert = vert->parent;
	}
	if (vert && vert->key == graph->start)
	{
		push_edge_front(&path, new_edge(vert));
		return (path);
	}
	// printf("\n\n\nTHIS SHIT\n\n\n\n");
	free_edges_struct(&path);
	return (NULL);
	

	// print_edges_struct(path);
	// tree_traversal(graph->rooms, *print_vertex);
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
		// if (!edge->to->visit && (dist = from->distance + 1) < edge->to->distance)
		if (!edge->to->visit && (dist = from->distance + 1) < edge->to->distance)
		{
			if (from->key % 2 && from->key = (edge->to->key - 1))
				dist = from->distance + 0
			edge->to->distance = dist;
			edge->to->parent = from;
		}
		edge = edge->next;
	}
}

t_edges		*dijkstra(t_graph *graph)
{
	t_verts		*vertex;

	vertex = find_vertex(graph->rooms, graph->start);
	vertex->distance = 0;
	while (vertex)
	{
		vertex->visit = 1;
		relaxation_by_edges(vertex);
		vertex = next_vert(graph->rooms);
	}
	return (restore_shortest_path(graph));
}
