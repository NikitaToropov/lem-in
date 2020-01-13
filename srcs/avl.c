/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:01:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/13 21:02:39 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			height(t_verts *node)
{
	if (node == NULL)
		return (0);
	return (node->height);
}

t_verts		*right_rotate(t_verts *y)
{
	t_verts		*x;
	t_verts		*tmp;

	x = y->left;
	tmp = x->right;
	x->right = y;
	y->left = tmp;
	y->height = ft_max(height(y->left), height(y->right)) + 1;
	x->height = ft_max(height(x->left), height(x->right)) + 1;
	return (x);
}

t_verts		*left_rotate(t_verts *x)
{
	t_verts		*y;
	t_verts		*tmp;

	y = x->right;
	tmp = y->left;
	y->left = x;
	x->right = tmp;
	x->height = ft_max(height(x->left), height(x->right)) + 1;
	y->height = ft_max(height(y->left), height(y->right)) + 1;
	return (y);
}

int			get_balance(t_verts *node)
{
	if (node == NULL)
		return (0);
	return (height(node->left) - height(node->right));
}

t_verts		*insert(t_verts *node, int key, char *str)
{
	int		balance;

	if (node == NULL)
		return (new_vertex(key, str));
	if (key < node->key)
		node->left = insert(node->left, key, str);
	else if (key > node->key)
		node->right = insert(node->right, key, str);
	else
		return (node);
	node->height = 1 + ft_max(height(node->left), height(node->right));
	balance = get_balance(node);
	if (balance > 1 && key < node->left->key)
		return (right_rotate(node));
	if (balance < -1 && key > node->right->key)
		return (left_rotate(node));
	if (balance > 1 && key > node->left->key &&
	(node->left = left_rotate(node->left)))
		return (right_rotate(node));
	if (balance < -1 && key < node->right->key &&
	(node->right = right_rotate(node->right)))
		return (left_rotate(node));
	return (node);
}
