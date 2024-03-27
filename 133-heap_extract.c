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
 * heapify_down - Adjusts the heap downwards from a given node.
 * @root: A pointer to the root node of the heap.
 */
void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temp_value;

	if (root == NULL)
		return;

	while (1)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;

		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp_value = root->n;
		root->n = largest->n;
		largest->n = temp_value;

		root = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last_node, *temp = *root;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = binary_tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = *root;
	while (last_node->left != NULL || last_node->right != NULL)
	{
		if (last_node->right == NULL || last_node->left->n >= last_node->right->n)
			last_node = last_node->left;
		else
			last_node = last_node->right;
	}

	temp->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify_down(temp);

	*root = temp;
	return (value);
}
