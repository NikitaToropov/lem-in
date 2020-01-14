/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/14 16:34:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_edges		*restore_shortest_path(t_graph *graph)
{
	t_edges		*path;
	t_edges		*tmp;
	t_verts		*vert;

	path = NULL;
	vert = find_vertex(graph->rooms, graph->finish);
	while (vert && vert->parent && vert->key != graph->start)
	{
		push_edge_back(&path, vert);
		vert = vert->parent;
	}
	printf("\n*********************PRINT SHORTEST PATH*********************\n");
	tmp = path;
	while (tmp)
	{
		printf(" %s,", tmp->to->name);
		tmp = tmp->next;
	}
	printf("\n*************************************************************\n\n");
	return (path);
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
