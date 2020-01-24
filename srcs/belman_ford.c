/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/24 20:51:11 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		it_is_real(t_verts *vertex)
{
	if (vertex->key % 2)
		return (0);
	return (1);
}

int		reverse_way_in_graph(t_graph *graph)
{
	t_verts		*vert;
	t_edges		*tmp;
	t_verts		*from;
	t_verts		*new_psevdo;
	t_verts		*to;

	vert = find_vertex(graph->rooms, graph->finish);
	if (!(vert->parent))
		return (0);
	to = vert;
	new_psevdo = NULL;
	while (vert->parent)
	{
		from = vert->parent;
		push_back(&from->reserve, pull_edge(&from->edge, to));
		if (it_is_real(to) && it_is_real(from))
		{
			new_psevdo = find_vertex(graph->rooms, from->key + 1);
			push_edge_back(&new_psevdo->edge, from->edge);
			push_edge_back(&to->edge, new_edge(new_psevdo, -1));
		}
		else if (!it_is_real(vert)
		{
			
		}
		
	}
	return (1);
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

int			belman_ford_for_reverse_way(t_graph *graph)
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
	return (reverse_way_in_graph(graph));
}
