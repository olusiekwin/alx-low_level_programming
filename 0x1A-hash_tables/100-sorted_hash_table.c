#include "hash_tables.h"

/**
 * shash_table_create - function that creates a hash table
 *
 * Description: function that creates a hash table
 *
 * @size: the size of the array
 *
 * Return: return NULL or Hash Table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int index;

	new_table = (shash_table_t *) malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->shead = NULL;
	new_table->stail = NULL;
	new_table->array = (shash_node_t **) malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (index = 0; index < size; index++)
		(new_table->array)[index] = NULL;
	return (new_table);
}

/**
 * shash_sorted_list_update - update
 *
 * @ht: sorted
 * @new_node: node
 * @key: key
 * @value: value
 *
 * Return: 1 or 0
 */
int shash_sorted_list_update(shash_table_t **ht, shash_node_t **new_node,
		const char *key, const char *value)
{
	shash_node_t *old_head = NULL;

	old_head = (*ht)->shead;
	while (old_head)
	{
		if (strcmp(old_head->key, key) == 0)
		{
			free(old_head->value);
			old_head->value = (char *) strdup(value);
			free((*new_node)->key);
			free((*new_node)->value);
			free((*new_node));
			return (1);
		}
		old_head = old_head->snext;
	}
	return (0);
}

/**
 * shash_sorted_list_insert - insert
 *
 * @ht: sorted
 * @new_node: node
 * @key: key
 *
 * Return: 1 or 0
 */
int shash_sorted_list_insert(shash_table_t **ht, shash_node_t **new_node,
		const char *key)
{
	shash_node_t *old_head = NULL;

	old_head = (*ht)->shead;
	while (old_head)
	{
		if (strcmp(old_head->key, key) > 0)
		{
			(*new_node)->snext = old_head;
			(*new_node)->sprev = old_head->sprev;
			if (old_head->sprev != NULL)
				old_head->sprev->snext = *new_node;
			else
				(*ht)->shead = *new_node;
			old_head->sprev = *new_node;
			return (1);
		}
		old_head = old_head->snext;
	}
	(*new_node)->sprev = (*ht)->stail;
	(*ht)->stail->snext = *new_node;
	(*ht)->stail = *new_node;
	return (1);
}

/**
 * shash_insert_into_sorted_list - inserts into sorted list
 *
 * @ht: Sorted hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success 0 if failure
 */
int shash_insert_into_sorted_list(shash_table_t *ht, const char *key,
		const char *value)
{
	shash_node_t *new_node = NULL;

	new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = (char *) strdup(key);
	new_node->value = (char *) strdup(value);
	new_node->next = new_node->snext = new_node->sprev = NULL;
	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		return (1);
	}
	else
	{
		if (!shash_sorted_list_update(&ht, &new_node, key, value))
			return (shash_sorted_list_insert(&ht, &new_node, key));
		else
			return (1);
	}
}

/**
 * shash_insert_into_array - inserts into array
 *
 * Description: inserts into buckets
 *
 * @ht: Sorted hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success 0 if failure
 */
int shash_insert_into_array(shash_table_t *ht, const char *key,
		const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL, *old_head = NULL;

	new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	new_node->key = (char *) strdup(key);
	new_node->value = (char *) strdup(value);
	new_node->next = new_node->snext = new_node->sprev = NULL;

	if ((ht->array)[index] == NULL)
	{
		(ht->array)[index] = new_node;
		return (1);
	}
	else
	{
		old_head = (ht->array)[index];
		while (old_head)
		{
			if (strcmp(old_head->key, key) == 0)
			{
				free(old_head->value);
				old_head->value = (char *) strdup(value);
				free(new_node->key);
				free(new_node->value);
				free(new_node);
				return (1);
			}
			old_head = old_head->next;
		}
		old_head = (ht->array)[index];
		new_node->next = old_head;
		(ht->array)[index] = new_node;
		return (1);
	}
}

/**
 * shash_table_set - short description
 *
 * Description: long description
 *
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: return description
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	if (key == NULL || value == NULL || ht == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	if (!shash_insert_into_array(ht, key, value))
		return (0);
	return (shash_insert_into_sorted_list(ht, key, value));
}

/**
 * shash_table_get - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 * @key: argument_2 description
 *
 * Return: return description
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current_node;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *) key, ht->size);
	if ((ht->array)[index] == NULL)
		return (NULL);
	current_node = (ht->array)[index];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}


/**
 * shash_table_print - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int is_first_hash;

	if (ht == NULL)
		return;
	printf("{");
	is_first_hash = 1;
	current_node = ht->shead;
	while (current_node)
	{
		if (!is_first_hash)
			printf(", ");
		is_first_hash = 0;
		printf("\'%s\': \'%s\'", current_node->key,
				current_node->value);
		current_node = current_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int is_first_hash;

	if (ht == NULL)
		return;
	printf("{");
	is_first_hash = 1;
	current_node = ht->stail;
	while (current_node)
	{
		if (!is_first_hash)
			printf(", ");
		is_first_hash = 0;
		printf("\'%s\': \'%s\'", current_node->key,
				current_node->value);
		current_node = current_node->sprev;
	}
	printf("}\n");
}


/**
 * shash_table_delete_arr - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void shash_table_delete_arr(shash_table_t *ht)
{
	shash_node_t *current_node, *previous_node;
	unsigned long int array_index, has_nodes;

	for (array_index = 0; array_index < ht->size; array_index++)
	{
		has_nodes = 0;
		current_node = (ht->array)[array_index];
		while (current_node)
		{
			has_nodes = 1;
			previous_node = current_node;
			current_node = current_node->next;
			free(previous_node->key);
			free(previous_node->value);
			free(previous_node);
		}
		if (!has_nodes)
			free((ht->array)[array_index]);
	}
	free(ht->array);
	free(ht);
}

/**
 * shash_table_delete_slist - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void shash_table_delete_slist(const shash_table_t *ht)
{
	shash_node_t *current_node, *previous_node;

	if (ht == NULL)
		return;
	current_node = ht->shead;
	previous_node = NULL;
	while (current_node)
	{
		previous_node = current_node;
		current_node = current_node->snext;
		free(previous_node->key);
		free(previous_node->value);
		free(previous_node);
	}
}

/**
 * shash_table_delete - short description
 *
 * Description: long description
 *
 * @ht: argument_1 description
 *
 * Return: return description
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_delete_slist(ht);
	shash_table_delete_arr(ht);
}
