#include <lem_in.h>

void	turn_back_the_way(t_verts *root, t_edges *way)
{
	t_edges		*current;
	t_edges		*tmp;
	t_verts		*from;
	t_verts		*to;
	t_verts		*psevdo;

	current = way;
	while (current && current->next)
	{
		from = current->to;
		to = current->next->to;
		psevdo = find_vertex(root, (to->key + 1));
 
// take edge "from - to" and push_back to "from->reserve"
		tmp = pull_edge(from->edge, to);
		push_edge_back(&from->reserve, tmp);

// take all edges from "to" and push to "psevdo->edge"
		psevdo->edge->next = from->edge; // add all edges from "from" to "psevdo" edge "from -> to" excluded
		from->edge = NULL;

// take edge "to - from" and push to "to->reserve"
		tmp = pull_edge(psevdo->edge, from); // take edge "to -> from"
		to->reserve = tmp;
		if (current == way)
		{

		}
		else
		{
			tmp = pull_edge(psevdo->edge, from); // take edge "to -> from"

		}







		current = current->next;
	}
	
}

// psevdo->edge:			psevdo->real(to) | to->all(to->from excluded)

// to(real)->edge:			new_edge(to->psevdo(froom)) | to-> |
// to(real)->reserved:		to->from | to-> |