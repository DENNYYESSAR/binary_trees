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

	bst_t *new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	bst_t *current = *tree;
	bst_t *parent = NULL;

	while (current != NULL)
	{
		parent = current;
		if (value == current->n)
		{
			free(new_node);
			return (NULL);
		}
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	return (new_node);
}
