/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/27 19:04:24 by cmissy           ###   ########.fr       */
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
	t_verts		*current_vert;
	t_verts		*psevdo;
	t_verts		*prev_vert;
	t_edges		*for_del;
	int			weight;

	current_vert = find_vertex(graph->rooms, graph->finish);
	if (!(current_vert->parent))
		return (0);
	// del all rev edges for change the weights
	while (current_vert->parent)
	{
		prev_vert = current_vert->parent;
		if ((for_del = pull_edge(&current_vert->edge, prev_vert)))
			free_edge(&for_del);
		current_vert = prev_vert;
	}



	// current_vert = find_vertex(graph->rooms, graph->finish);
	// prev_vert = current_vert->parent;
	// for_del = pull_edge(&prev_vert->edge, current_vert);
	// free_edge(&for_del);
	// push_edge_front(&current_vert->edge, new_edge(prev_vert, -1));
	// current_vert = prev_vert;
	current_vert = find_vertex(graph->rooms, graph->finish);
	weight = 1;
	psevdo = NULL;
	prev_vert = current_vert->parent;
	while (prev_vert->parent)
	{
		// if (for_del->weight == 0)
		// 	weight = 0;
		// else if (for_del->weight == -1)
		// 	weight = -1;
		// else
		// 	weight = 1;
		for_del = pull_edge(&prev_vert->edge, current_vert);
		free_edge(&for_del);

		if (it_is_real(current_vert) && it_is_real(prev_vert))
		{
			psevdo = find_vertex(graph->rooms, (prev_vert->key + 1));
			psevdo->edge = prev_vert->edge;
			prev_vert->edge = NULL;
			push_edge_back(&psevdo->edge, new_edge(prev_vert, 0));
			push_edge_back(&current_vert->edge, new_edge(psevdo, -1));
		}
		else if (it_is_real(current_vert) && !it_is_real(prev_vert))
		current_vert = prev_vert;
		prev_vert = current_vert->parent;
	}
	for_del = pull_edge(&prev_vert->edge, current_vert);
	free_edge(&for_del);
	push_edge_front(&current_vert->edge, new_edge(prev_vert, -1));
	
printf("\n\n\nTHIS SHIT\n\n\n\n");

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

int			belman_ford_for_reverse_way_in_graph(t_graph *graph)
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
	if (!reverse_way_in_graph(graph))
		return (0);
	tree_traversal(graph->rooms, *print_vertex);
	return (1);
}
