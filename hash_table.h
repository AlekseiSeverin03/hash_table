
// hash_table.h



#include "list.h"
#include "hash_func.h"


const int             N_CELL   = 1000;
// const int             SIZE_KEY = 10;


typedef  struct hash_table_t  hash_table_t;
typedef  struct info_t        info_t;
typedef  char*                key_t;



struct hash_table_t
{
	info_list_t  list[N_CELL];
	int          size;
	hash_t       (*hash_func) (const void *ptr_mem, size_t size_mem);
};


struct info_t
{
	int data;
};



int TableCtor (hash_table_t *table, 
			   hash_t (*func_ptr) (const void *ptr_mem, size_t size_mem));
int TableDtor (hash_table_t *table);
int AddElement (hash_table_t *table, key_t key_ptr, int size_key, info_t *info);
int GetInfo    (hash_table_t *table, key_t key_ptr, int size_ptr);



