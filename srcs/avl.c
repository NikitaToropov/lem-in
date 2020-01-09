#include <lem_in.h>

// A utility function to get the height of the tree 
int			height(t_verts *node)
{
	if (node == NULL)
		return 0;
	return (node->height);
}

// A utility function to get maximum of two integers 
int			max(int a, int b)
{
	return ((a > b)? a : b);
}

/* Helper function that allocates a new node with the given key and 
	NULL left and right pointers. */
t_verts		*new_node(int key, char *str)
{
	t_verts		*node;

	if (!(node = malloc(sizeof(t_verts))))
		exit (1);
	node->key = key;
	node->name = str;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf 
	return (node);
}

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
t_verts		*right_rotate(t_verts *y)
{
	t_verts		*x = y->left;
	t_verts		*T2 = x->right;

	// Perform rotation 
	x->right = y;
	y->left = T2;

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root 
	return (x);
}

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
t_verts		*left_rotate(t_verts *x)
{
	t_verts		*y = x->right;
	t_verts		*T2 = y->left;

	// Perform rotation 
	y->left = x;
	x->right = T2;

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root 
	return (y);
}

// Get Balance factor of node N 
int			get_balance(t_verts *node)
{
	if (node == NULL)
		return 0;
	return (height(node->left) - height(node->right));
}

// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
t_verts		*insert(t_verts *node, int key, char *str)
{
	int		balance;

	if (node == NULL)
		return(new_node(key, str));
	if (key < node->key)
		node->left = insert(node->left, key, str);
	else if (key > node->key)
		node->right = insert(node->right, key, str);
	else
		return (node);
	node->height = 1 + max(height(node->left), height(node->right));
	balance = get_balance(node);
	if (balance > 1 && key < node->left->key)
		return (right_rotate(node));
	if (balance < -1 && key > node->right->key)
		return left_rotate(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = left_rotate(node->left);
		return (right_rotate(node));
	}
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return (node);
}

// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 
void 		pre_order(t_verts *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		pre_order(root->left);
		pre_order(root->right);
	}
}

/* Drier program to test above function*/
int main() 
{ 
struct Node *root = NULL; 

/* Constructing tree given in the above figure */
root = insert(root, 10); 
root = insert(root, 20); 
root = insert(root, 30); 
root = insert(root, 40); 
root = insert(root, 50); 
root = insert(root, 25); 

/* The constructed AVL Tree would be 
			30 
		/ \ 
		20 40 
		/ \	 \ 
	10 25 50 
*/

printf("Preorder traversal of the constructed AVL"
		" tree is \n"); 
preOrder(root); 

return 0; 
}
