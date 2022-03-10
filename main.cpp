
// main.cpp


#include "hash_table.h"


int main ()
{
	hash_table_t table;
	TableCtor (&table, HashRegionMemory);

	info_t test_data;
	test_data.data = 1;

	AddElement (&table, "seq", 3, &test_data);

	GetInfo (&table, "seq", 3);

	TableDtor (&table);
	return 0;
}
