#include <lem_in.h>

void	turn_back_the_way(t_verts *root, t_edges *way)
{
	t_edges		*current;
	t_edges		*tmp;
	t_verts		*from;
	t_verts		*psevdo;
	t_verts		*to;

	current = way;
	psevdo = NULL;
	if (current)
		from = current->to;
	while (current && current->next)
	{
		to = current->next->to;
		if (psevdo)
		{
			tmp = pull_edge(&psevdo->edge, to); // tmp = from->to
		}
		else
		{
			tmp = pull_edge(&from->edge, to); // tmp = from->to
		}
		push_edge_back(&from->reserve, tmp);
		to->reserve = pull_edge(&to->edge, from); // take edge "to -> from"


		if (!psevdo)
		{
			tmp = new_edge(from); // tmp = from->to
		}
		else
		{
			// psevdo = find_vertex(root, (to->key + 1));
			tmp = new_edge(psevdo); // tmp = from->to
		}
			psevdo = find_vertex(root, (to->key + 1));
		psevdo->edge->next = to->edge; // add all edges from "from" to "psevdo" edge "from -> to" excluded

		to->edge = tmp;

		from = to;







		current = current->next;
	}
	
}

// psevdo->edge:			psevdo->real(to) | to->all(to->from excluded)

// to(real)->edge:			new_edge(to->psevdo(froom))     !!!PSEVDO
// to(real)->reserved:		to->from | to(next_from)->next_to

// from(real)->edge:			new_edge(to->psevdo(froom)) | to-> |