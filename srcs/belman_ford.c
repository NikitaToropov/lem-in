/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:29:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/28 18:05:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		it_is_real(t_verts *vertex)
{
	if (vertex->key % 2)
		return (0);
	return (1);
}

// void	reverse_common_part(t_graph *graph, t_verts *curr, t_verts *prev, t_verts *psevdo)
// {
// 	t_verts		*real;
// 	t_edges		*tmp;

// 	if (!prev->parent)
// 		return ;
// 	real = prev->parent;
// 	push_edge_front(&real->reserve , pull_edge(&psevdo->edge, prev));
// 	tmp = pull_edge(&psevdo->edge, real);
// 	tmp->weight = -1;
// 	push_edge_back(&psevdo->edge, tmp);

// ////////////////////////////// test it later
// 	curr = real;
// 	prev = curr->parent;

// 	while (!it_is_real(prev) && prev->parent)
// 	{
// 	}
// }

// void	reverse_original_part(t_graph *graph, t_verts *curr, t_verts *prev, t_verts *psevdo, t_verts *real)
void	reverse_original_part(t_graph *graph, t_verts **curr, t_verts **prev, t_verts **psevdo)
{
	t_edges		*tmp;

	if (!(*prev)->parent)
		return ;
	while ((*prev)->parent && it_is_real(*prev))
 	{

// check it later for good working with "reverse_common_part" mby want add "real" vars
		push_edge_back(&(*prev)->reserve, pull_edge(&(*prev)->edge, (*curr)));


		if (*psevdo)
			tmp = pull_edge(&(*psevdo)->edge, (*prev));
		// else if (real)
		// 	tmp = pull_edge(&real->edge, prev);
		else
			tmp = pull_edge(&(*curr)->edge, (*prev));
		push_edge_back(&(*curr)->reserve, tmp);
		(*psevdo) = find_vertex(graph->rooms, (*prev)->key + 1);
		push_edge_back(&(*psevdo)->edge, (*prev)->edge);
// same shitn like earlier
		// if (real)
		// {
		// 	// push_edge_back(&real->edge, new_edge(psevdo, -1));
		// 	real = NULL;
		// }
		// else
		push_edge_back(&(*curr)->edge, new_edge((*psevdo), -1));
		(*prev)->edge = NULL;
		(*curr) = (*prev);
		(*prev) = (*curr)->parent;
	}
	push_edge_back(&(*prev)->reserve, pull_edge(&(*prev)->edge, (*curr)));
	tmp = pull_edge(&(*psevdo)->edge, (*prev));
	tmp->weight = -1;
	push_edge_back(&(*curr)->edge, tmp);
}

int		reverse_way_in_graph(t_graph *graph)
{
	t_verts		*curr;
	t_verts		*psevdo;
	t_verts		*prev;

	curr = find_vertex(graph->rooms, graph->finish);
	prev = curr->parent;
	if (!prev)
		return (0);
	psevdo = NULL;
	while (prev && prev->parent)
	{

		print_vertex(prev);
		reverse_original_part(graph, &curr, &prev, &psevdo);
	}
	tree_traversal(graph->rooms, *print_vertex);
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
