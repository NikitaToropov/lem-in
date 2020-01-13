/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_graph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:59:15 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/13 22:20:36 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			free_graph(t_graph *graph)
{
	free_vertex(&(graph->rooms));
	free_input_struct(&(graph->input));
	free(graph);
	// free_vertex(&(*graph)->rooms);
	// free_input_struct(&(*graph)->input);
	// free(*graph);
	// *graph = NULL;
}

void			print_graph(t_graph *graph)
{
	printf("\n||||||||||||||||||||||||||| START GRAPH PRINTING |||||||||||||||||||||||||||\n");
	tree_traversal(graph->rooms, *print_vertex);
	printf("\nlen    = %i\n", graph->length);
	printf("start  = %i\n", graph->start);
	printf("finish = %i\n", graph->finish);
	printf("ants   = %i\n\n\n", graph->num_of_ants);
	// print_input_struct(graph->input);
	printf("||||||||||||||||||||||||||| END GRAPH PRINTING |||||||||||||||||||||||||||\n\n\n\n");
}

t_graph			*init_graph(char *line)
{
	t_graph		*graph;

	if (!(graph = malloc(sizeof(t_graph))) ||
	!(graph->input = malloc(sizeof(t_input))))
		exit(1);
	if ((graph->num_of_ants = ft_atoi(line)) <= 0)
	{
		free(line);
		return (NULL);
	}
	graph->start = -1;
	graph->finish = -1;
	graph->length = -1;
	graph->rooms = NULL;
	graph->input->line = line;
	graph->input->next = NULL;
	return (graph);
}
