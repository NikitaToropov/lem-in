#include <lem_in.h>

void		print_vertex(t_verts *vert)
{
	t_edges		*tmp_edge;

	printf("\n================ROOM #%i======================\n",  vert->key);
	printf("name  =              %s\n", vert->name);
	printf("visit =              %i\n", (int)vert->visit);
	if (vert->parent)
		printf("paret num = %i\n", vert->parent->key);
	else
		printf("paret num =          NO PARENT\n");
	if (vert->edge)
	{
		tmp_edge = vert->edge;
		printf("REAL edges to:      ");
		while (tmp_edge)
		{
			printf(" %i,", tmp_edge->to->key);
			tmp_edge = tmp_edge->next;
		}
		printf("\n");
	}
	else
		printf("REAL edges to:       NOBODY\n");
	if (vert->reserve)
	{
		tmp_edge = vert->reserve;
		printf("RSRVD edges to:     ");
		while (tmp_edge)
		{
			printf(" %i,", tmp_edge->to->key);
			tmp_edge = tmp_edge->next;
		}
		printf("\n");
	}
	else
		printf("RSRVD edges to:      NOBODY\n");
	printf("==============================================\n");
}

void		free_vertex(t_verts **node)
{
	if ((*node)->name)
		free((*node)->name);
	free_edges_struct(&(*node)->edge);
	free_edges_struct(&(*node)->reserve);
	if ((*node)->left)
		free_vertex(&(*node)->left);
	if ((*node)->right)
		free_vertex(&(*node)->right);
	free(*node);
	*node = NULL;
}

t_verts		*new_vertex(int key, char *str)
{
	t_verts		*node;

	if (!(node = malloc(sizeof(t_verts))))
		exit (1);
	node->key = key;
	node->height = 1;

	node->name = str;

	node->visit = 0;
	node->parent = NULL;

	node->edge = NULL;
	node->reserve = NULL;

	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_verts		*find_vertex(t_verts *root, int num)
{
	t_verts		*vertex;

	vertex = root;
	while(vertex && vertex->key!= num)
	{
		if (vertex->key < num)
			vertex = vertex->right;
		else
			vertex = vertex->left;
	}
	return (vertex);
}

void		tree_traversal(t_verts *root, void f(t_verts *vertex))
{
	if(root != NULL)
	{
		tree_traversal(root->left, f);
		tree_traversal(root->right, f);
	}
	if (f && root)
		f(root);
}