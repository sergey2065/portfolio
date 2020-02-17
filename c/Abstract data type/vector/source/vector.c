#include <stdio.h>
#include <stdlib.h>/* size_t , malloc, calloc, realloc*/
#include "../include/vector.h"

/*------------- defines ------------*/
#define TRUE 1
#define FALSE 0

#define SET 1
#define RESET 0

/*---------- declarations of privet functions --------*/
static void ReAlloc(Vector *a_vector, size_t a_newSize);

/*---------- struct --------*/
struct Vector{
	void **m_item;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nItems;
    size_t m_blockSize;
};

/*.......................vector public functions.....................................*/
Vector *VectorCreate(size_t a_initialCapacity, size_t a_extensionBlockSize)
{
	Vector *ptr;
	if (a_initialCapacity == 0 && a_extensionBlockSize == 0)
	{
		return NULL;
	}

	if ((ptr = (Vector*)malloc(sizeof(Vector))) == NULL)
	{
		return NULL;
	}

	if ( (ptr-> m_item = (void**)calloc(a_initialCapacity, sizeof(void*)  ) ) == NULL)
	{
		free(ptr);
		return NULL;	
	}

	ptr-> m_originalSize = a_initialCapacity;
	ptr-> m_size = a_initialCapacity;
	ptr-> m_nItems = 0;
	ptr-> m_blockSize = a_extensionBlockSize;
	return ptr;
}	


void VectorDestroy(Vector** a_vector, void (*a_elementDestroy) (void* a_item))
{
	int i;
	if (a_vector == NULL || *a_vector == NULL)
	{
		return;
	}

	if (a_elementDestroy != NULL)
	{
		for (i = 0; i < (*a_vector) -> m_nItems; ++i)
		{
			a_elementDestroy((*a_vector)-> m_item[i]);
		}
	}

	free((*a_vector)-> m_item);
	free(*a_vector);
	*a_vector = NULL;
}

Vector_Result VectorAppend(Vector* a_vector, void* a_item)
{
	if (a_vector == NULL ||  a_item == NULL)
	{
		return   VECTOR_UNITIALIZED_ERROR;
	}
	/*check if vector is full*/
	if (a_vector-> m_size == a_vector-> m_nItems)
	{
		if (a_vector-> m_blockSize == 0){
			return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
		}

		ReAlloc(a_vector, (a_vector-> m_size + a_vector-> m_blockSize) );
		
	}

	/* insert the data to the vector in last place */
	a_vector-> m_item[a_vector-> m_nItems] = a_item;
	++a_vector-> m_nItems;
	return VECTOR_SUCCESS;
}

Vector_Result VectorRemove(Vector* a_vector, void** a_pValue)
{
	if (a_vector == NULL || a_pValue == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}

	/*check if the array is empty*/
	if ( 0 == a_vector-> m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}

	/*deleting the last */
	else
	{
		*a_pValue = a_vector-> m_item[a_vector-> m_nItems - 1];
		--(a_vector-> m_nItems);
	}

	/*realloc to smaller size if nedded*/
	if (a_vector-> m_nItems <= (a_vector-> m_size - (a_vector-> m_blockSize * 2)) &&
	   				(a_vector-> m_size > a_vector-> m_originalSize ))
	{
		ReAlloc(a_vector, a_vector-> m_size - a_vector-> m_blockSize);
	}

	return VECTOR_SUCCESS;
}

Vector_Result VectorGet(const Vector* a_vector, size_t a_index, void** a_pValue)
{
	/* check input */
	if (a_vector == NULL || a_pValue == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}

	/* check if index is in range */
	if (a_index >= a_vector-> m_nItems || a_index < 0)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}

	*a_pValue = a_vector-> m_item[a_index];
	return VECTOR_SUCCESS;
}

Vector_Result VectorSet(const Vector* a_vector, size_t a_index, void* a_value)
{
	/* check input */
	if (a_vector == NULL || a_value == NULL)
	{
		return VECTOR_UNITIALIZED_ERROR;
	}

	/* check if index is in range */
	if (a_index >= a_vector-> m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}

	a_vector-> m_item[a_index] = a_value;
	return VECTOR_SUCCESS;
}

size_t VectorSize(const Vector* a_vector)
{
	if (a_vector == NULL)
	{
		return 0;
	}
	return a_vector-> m_nItems;
}

size_t VectorCapacity(const Vector* a_vector)
{
	if (a_vector == NULL)
	{
		return 0;
	}
	return a_vector-> m_size;
}

void VectorPrint(const Vector *a_vector)
{
	int i;
	if (a_vector == NULL || a_vector-> m_item == NULL)
	{
		return;
	}
	for (i = 0; i < a_vector-> m_nItems; i++)
	{
		printf("the data in index[%d] is: %d\n", i, *((int*)(a_vector-> m_item[i])));
	}
}


/*-------------------------- privet function -------------------------------*/


static void ReAlloc(Vector *a_vector, size_t a_newSize)
{
	void **tempPtr;
	tempPtr = (void**)realloc(a_vector-> m_item, a_newSize * sizeof(void*) );

	if (tempPtr != NULL)
	{
		a_vector-> m_item = tempPtr;
		a_vector-> m_size =(a_newSize);
	}
}
