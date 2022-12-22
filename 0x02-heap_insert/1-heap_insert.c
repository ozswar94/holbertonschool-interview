#include "binary_trees.h"

/**
 * height - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * to measure the size
 * Return: size of the tree
 */
unsigned int height(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += height(tree->left);
	size += height(tree->right);

	return (size);
}


/**
 * swap - swap two value
 * @parent : 1st value
 * @val_node : 2sd value
 */
void swap(int *parent, int *val_node)
{
	int tmp;

	tmp = *val_node;
	*val_node = *parent;
	*parent = tmp;
}


/**
 * find_parent - find the parent of the node to insert
 * @tree : tree to search
 * @index : index of the tree
 * @size : size of the tree
 *
 * Return: the parent of the node to insert
 */
heap_t *find_parent(heap_t *tree, int index, int size)
{
	heap_t *left, *right;

	if (index == size)
		return (tree);

	if (index > size)
		return (NULL);

	left = find_parent(tree->left, 2 * index + 1, size);
	right = find_parent(tree->right, 2 * index + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);

}

/**
 * insert_node - insert the node
 * @tree : tree into insert the node
 * @new : node to insert
 *
 * Return: tree
 */
heap_t *insert_node(heap_t *tree, heap_t *new)
{
	int size = height(tree);
	heap_t *parent = find_parent(tree, 0, ((size - 1) / 2));

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	return (parent);

}

/**
 * heap_insert - create node on tree
 * @root: pointer of root tree
 * @value: value of new node
 *
 * Return: new node or NULL if failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = binary_tree_node(NULL, value), *parent;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = new;
		return (new);
	}
	parent = insert_node(*root, new);
	new->parent = parent;

	while (new->parent && new->n > new->parent->n)
	{
		swap(&new->parent->n, &new->n);
		new = new->parent;
	}
	return (new);
}
