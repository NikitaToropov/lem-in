/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/21 19:22:06 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		loop_check(t_edges *way)
{
	t_edges		*edge1;
	t_edges		*edge2;

	edge1 = way;
	while (edge1->next)
	{
		edge2 = edge1->next;
		while (edge2)
		{
			if (edge2 == edge1)
			{
				printf("LOOOOOOOP");
				exit(1);
			}
			edge2 = edge2->next;
		}
		edge1 = edge1->next;
	}
}

t_edges		*restore_shortest_path(t_graph *graph)
{
	t_edges		*path;
	t_verts		*vert;

	path = NULL;
	vert = find_vertex(graph->rooms, graph->finish);
	while (vert && vert->parent)
	{
		if (vert->key % 2)
			push_edge_front(&path, new_edge(vert->edge->to, 1));
		else if (!(vert->key % 2) && (vert->parent->key % 2) &&
		vert->key == vert->parent->key - 1)
		{
			push_edge_front(&path, new_edge(vert, 1));
			vert = vert->parent;
		}
		else
			push_edge_front(&path, new_edge(vert, 1));
		vert = vert->parent;
	}
	if (path)
	{
		push_edge_front(&path, new_edge(vert, 1));
	print_edges_struct(path);
	loop_check(path);

	}
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
		if (!edge->to->visit && (dist = from->distance + edge->weight) < edge->to->distance)
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
	// while (vertex->key != graph->finish)
	while (vertex)
	{
		vertex->visit = 1;
		relaxation_by_edges(vertex);
		vertex = next_vert(graph->rooms);
	}
	// relaxation_by_edges(vertex);
	return (restore_shortest_path(graph));
}
