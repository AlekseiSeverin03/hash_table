
// hash_table.cpp


#include "hash_table.h"

//-------------------------------------------------------------
//-------------------------------------------------------------
int TableCtor (hash_table_t *table, 
			   hash_t (*hash_func) (const void *ptr_mem, size_t size_mem))
{
	assert (table != NULL);
	assert (1);

	table->size = N_CELL;
	table->hash_func = hash_func;

	for (int count = 0; count < table->size; count++)
	{
		table->list[count].size = -1;
	}

	return 0;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
int TableDtor (hash_table_t *table)
{
	assert (table != NULL);

	for (int count = 0; count < table->size; count++)
	{
		if (table->list[count].size != -1)
		{
			ListDelete (table->list + count);
		}
	}

	table->size = 0;
	table->hash_func = NULL;

	return 0;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
int AddElement (hash_table_t *table, key_t key_ptr, 
				int size_key, info_t *info)
{
	assert (table != NULL);
	assert (info  != NULL);
	assert (key_ptr != NULL);

	hash_t hash_key = (*table->hash_func) (key_ptr, size_key);

	int index = abs (hash_key) % N_CELL;
	
	if ((table->list[index].size == -1) || (table->list[index].size == 0))
	{
		ListCtor (&(table->list[index]));
	}

	CurAfterInsert (&(table->list[index]), info->data);

	return 0;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
int GetInfo (hash_table_t *table, key_t key_ptr, 
			 int size_key)
{
	assert (table != NULL);
	assert (key_ptr != NULL);

	hash_t hash_key = (*table->hash_func) (key_ptr, size_key);

	int index = abs (hash_key) % N_CELL;

// remake next strings
	printf ("For key: \"%s\" find infomations: ", key_ptr);
	PrintElementsList (&(table->list[index]));
	printf ("\n");
// remake prev strings

	return 0;
}



//-------------------------------------------------------------
//-------------------------------------------------------------




