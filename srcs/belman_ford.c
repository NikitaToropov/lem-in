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

void	reverse_wo_psevdo(t_graph *graph, t_verts *curr, t_verts *psevdo,
							t_verts *real)
{
	t_verts		*prev;
	t_edges		*tmp;

	prev = curr->parent;
	while (prev && prev->parent && it_is_real(prev) && it_is_real(curr))	
	{
		// достал из 16 связь 14-16 положил в резерв 14
		push_edge_back(&prev->reserve, pull_edge(&prev->edge, curr));

		
		// достал из 17 связь 17-14 положил сделал вес -1 положил обратано
		if (psevdo)
			tmp = pull_edge(&psevdo->edge, prev);
		else
			tmp = pull_edge(&curr->edge, prev);
		tmp->weight = -1;
		push_edge_front(&curr->edge, tmp);

		// нашел 15, положил в нее все вершины из 14
		psevdo = find_vertex(graph->rooms, prev->key + 1);
		push_edge_back(&psevdo->edge, prev->edge);
		// в 14 положил вершщину к 15 весом 0
		prev->edge = new_edge(psevdo, 0);
		

		psevdo = find_vertex(graph->rooms, prev->key + 1);






		psevdo = find_vertex(graph->rooms, (prev->key + 1));
		psevdo->edge = prev->edge;
		prev->edge = new_edge(psevdo, 0);
		curr = prev;
		prev = curr->parent;


		prev = curr->parent;
	}
}

void	reverse_common_part(t_graph *graph, t_verts *curr, t_verts *prev, t_verts *psevdo)
{
	t_verts		*real;
	t_edges		*tmp;

	if (!prev->parent)
		return ;
	real = find_vertex(graph->rooms, prev->key - 1);
	tmp = cut_there(prev->edge->next);
	push_edge_back(&real->edge, tmp);
	tmp = pull_edge(&psevdo->edge, real);
	tmp->weight = -1;
	push_edge_front(&psevdo->edge, tmp);
	while (!it_is_real(prev) && prev->parent)
	{
	}
}

int		reverse_way_in_graph(t_graph *graph)
{
	t_verts		*curr;
	t_verts		*psevdo;
	t_verts		*prev;
	t_edges		*for_del;

	curr = find_vertex(graph->rooms, graph->finish);
	if (!(curr->parent))
		return (0);
	curr = find_vertex(graph->rooms, graph->finish);
	prev = curr->parent;
	while (prev && prev->parent)
	{
		reverse_wo_psevdo(curr);
		// reverse_w_psevdo()
		while (prev && prev->parent && it_is_real(prev))
		{
			if (psevdo)
				push_edge_back(&psevdo->edge, new_edge(prev, -1));
			else
				push_edge_back(&curr->edge, new_edge(prev, -1));
			psevdo = find_vertex(graph->rooms, (prev->key + 1));
			psevdo->edge = prev->edge;
			prev->edge = new_edge(psevdo, 0);
			curr = prev;
			prev = curr->parent;
		}

		// if (prev && prev->parent && prev->key == prev->parent->key + 1 && psevdo)
		// {
		// 	curr = prev;
		// 	prev = prev->parent;
		// 	if (for_del = pull_edge(&psevdo->edge, prev))
		// 		free_edge(&for_del);
		// 	push_edge_back(&psevdo->edge, new_edge(prev, -1));
		// 	push_edge_back(&prev->edge, new_edge(curr, 0));
		// 	psevdo = NULL;
		// 	if (!prev->parent)
		// 	{
		// 		printf("problems  reverse_way_in_graph/reverse \n");
		// 		exit(1);
		// 	}
			
		// 	prev = curr;
		// 	prev = prev->parent;
		// 	push_edge_back(&prev->edge, new_edge(curr, 1));
			
		// 	prev = curr;
		// 	prev = prev->parent;
		// }

		// while (prev && prev->parent && !it_is_real(curr) &&
		// prev->key == curr->key - 1 && !it_is_real(prev->parent))
		// {
		// }
		
	}
	push_edge_back(&psevdo->edge, new_edge(prev, -1));
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
