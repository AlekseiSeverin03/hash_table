
// hash_func.cpp


#include "hash_func.h"



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
hash_t HashRegionMemory (const void *ptr_reg_mem, size_t size_mem)
{
    hash_t hash = 0, hash_coef = HASH_COEF;

    for (int i = 0; i < size_mem; i++)
    {
        hash += (*(hash_t *)((char *) ptr_reg_mem + i) + hash_coef) * hash_coef;
        hash_coef = hash;
    }

    return hash;
}





