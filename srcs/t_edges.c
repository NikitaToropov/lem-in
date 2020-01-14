/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_edges.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:00:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/14 15:22:06 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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
		push_edge_back(&new, tmp);
		tmp = tmp->next;
	}
	return (new);
}

void		push_edge_back(t_edges **first_edge, t_verts *vertex)
{
	t_edges		*new_edge;
	t_edges		*tmp;

	if (!(new_edge = malloc(sizeof(t_edges))))
		exit(1);
	new_edge->to = vertex;
	new_edge->next = NULL;
	if (!*first_edge)
		*first_edge = new_edge;
	else
	{
		tmp = *first_edge;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_edge;
	}
}
