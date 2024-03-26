#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	bst_t *new_node, *current, *parent;

	current = *tree;
	parent = NULL;

	/* Traverse the tree to find the appropriate position */
	while (current != NULL)
	{
		if (value == current->n)
			return (NULL); /* Value already exists, ignore */

		parent = current;

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create a new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Insert the new node */
	if (parent == NULL)
		*tree = new_node; /* New node becomes the root */
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
