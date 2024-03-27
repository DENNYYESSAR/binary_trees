#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Maintains the Max Heap property by moving a node upwards.
 * @new_node: The node to be moved upwards.
 *
 * Return: A pointer to the new root node of the tree after insertion.
 */
heap_t *heapify_up(heap_t *new_node)
{
	heap_t *current = new_node;

	while (current->parent != NULL && current->n > current->parent->n)
	{
		int temp = current->n;

		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}

	return (current);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	parent = *root;
	while (parent->left != NULL && parent->right != NULL)
	{
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	return (heapify_up(new_node));
}
