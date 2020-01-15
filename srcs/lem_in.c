/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:59:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/15 15:02:14 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_graph		*graph;
	// t_ways		*shortest_ways;

	if (!(graph = read_input()))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	suurballe(graph);
	
	
	
	// dijkstra(graph);
	// print_graph(graph);
	// tree_traversal(graph->rooms, *restore_vertex);
	// print_graph(graph);
	free_graph(&graph);
	return (0);
}
