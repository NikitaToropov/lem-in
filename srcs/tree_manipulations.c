#include <lem_in.h>

void	turn_back_the_way(t_verts *root, t_edges *way)
{
	t_edges		*current;
	t_edges		*tmp;
	t_verts		*from;
	t_verts		*to;

	current = way;
	from = current->to;
	while (current && current->next)
	{
		to = current->next->to;
// take edge "from - to" and push_back to "from->reserve"
		tmp = pull_edge(&from->edge, to);
		
		
		// tmp = pull_edge(&to->edge, from); // take edge "to -> from"
		to->reserve = pull_edge(&to->edge, from); // take edge "to -> from"
		
		
		from = current->to;

		push_edge_back(&from->reserve, tmp);

// take edge "to - from" and push to "to->reserve"
		tmp = copy_edges_struct(tmp);

// take all edges from "to" and push to "psevdo->edge"
		from = find_vertex(root, (to->key + 1));
		from->edge->next = to->edge; // add all edges from "from" to "psevdo" edge "from -> to" excluded
		to->edge = tmp;







		current = current->next;
	}
	
}

// psevdo->edge:			psevdo->real(to) | to->all(to->from excluded)

// to(real)->edge:			new_edge(to->psevdo(froom))     !!!PSEVDO
// to(real)->reserved:		to->from | to(next_from)->next_to

// from(real)->edge:			new_edge(to->psevdo(froom)) | to-> |