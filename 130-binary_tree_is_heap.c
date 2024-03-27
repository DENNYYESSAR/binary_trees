#include "binary_trees.h"

int is_heap_util(const binary_tree_t *tree, size_t index, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);

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
 * is_heap_util - Utility function to check if a binary tree is a valid Max Heap.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @size: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is a valid Max Heap, 0 otherwise.
 */
int is_heap_util(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_heap_util(tree->left, 2 * index + 1, size) &&
		is_heap_util(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (is_heap_util(tree, 0, size));
}
