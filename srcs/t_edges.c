/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_edges.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:00:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/23 15:45:15 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_edges_struct_reverse(t_edges *tail)
{
	t_edges		*edge;

	edge = tail;
	while (edge)
	{
		printf(" %i", edge->to->key);
		edge = edge->prev;
	}	
}

t_edges		*cut_there(t_edges *vertex)
{
	if (vertex && vertex->prev)
	{
		vertex->prev->next = NULL;
		vertex->prev = NULL;
	}
	return (vertex);
}

void		print_edges_struct(t_edges *head)
{
	t_edges		*edge;

	edge = head;
	printf("\n----------------PRINT EDGES STRUCT----------------\n");
	while (edge->next)
	{
		printf(" %i", edge->to->key);
		edge = edge->next;
	}
	printf(" %i", edge->to->key);
	printf("\n\n");
	print_edges_struct_reverse(edge);
	printf("\n----------------PRINT EDGES STRUCT----------------\n");
}

void		free_edge(t_edges **edge)
{
	free(*edge);
	*edge = NULL;
}

void		free_edges_struct(t_edges **first_edge)
{
	if (!*first_edge)
		return ;
	if ((*first_edge)->next)
		free_edges_struct(&((*first_edge)->next));
	free_edge(first_edge);
}

t_edges		*copy_edges_struct(t_edges *srcs)
{
	t_edges		*new;
	t_edges		*tmp;

	new = NULL;
	tmp = srcs;
	while (tmp)
	{
		push_edge_back(&new, new_edge(tmp->to, tmp->weight));
		tmp = tmp->next;
	}
	return (new);
}

t_edges		*pull_edge(t_edges **first_edge, t_verts *vertex)
{
	t_edges		*edge;
	t_edges		*tmp;

	edge = *first_edge;
	if (edge->to == vertex)
	{
		*first_edge = (*first_edge)->next;
		if (*first_edge && (*first_edge)->next)
			(*first_edge)->next->prev = NULL;
		edge->next = NULL;
		return (edge);
	}
	while (edge && edge->next)
	{
		if (edge->next->to == vertex)
		{
			tmp = edge->next;
			edge->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = edge;
			tmp->prev = NULL;
			tmp->next = NULL;
			return (tmp);
		}
		edge = edge->next;
	}
	return (NULL);
}

void		push_edge_front(t_edges **first_edge, t_edges *new_edge)
{
	if (*first_edge && new_edge)
	{
		new_edge->next = *first_edge;
		(*first_edge)->prev = new_edge;
	}
	*first_edge = new_edge;
}


void		push_edge_back(t_edges **first_edge, t_edges *new_edge)
{
	t_edges		*tmp;

	if (!*first_edge)
		*first_edge = new_edge;
	else
	{
		tmp = *first_edge;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_edge;
		if (new_edge)
			new_edge->prev = tmp;
	}
}

t_edges		*new_edge(t_verts *vertex, int w)
{
	t_edges		*new_edge;

	if (!(new_edge = malloc(sizeof(t_edges))))
		exit(1);
	new_edge->to = vertex;
	new_edge->next = NULL;
	new_edge->prev = NULL;
	new_edge->weight = w;
	return (new_edge);
}
