#ifndef __VECTOR_H__
#define __VECTOR_H__

/** 
 * @brief Create a Generic Vector data type
 * that stores pointer to user provided elements of generic type
 * The Vector is heap allocated and can grow and shrink on demand.
 */ 

#include <stdlib.h>  /* size_t */

typedef struct Vector Vector;
typedef int	(*VectorElementAction)(void* a_element, size_t a_index, void* a_context);

typedef enum Vector_Result {
	VECTOR_SUCCESS,
	VECTOR_UNITIALIZED_ERROR,				/**< Uninitialized vector error 	*/
	VECTOR_ALLOCATION_ERROR,				/**< realloc error on grow/shrink   */
	VECTOR_INDEX_OUT_OF_BOUNDS_ERROR		/**< deleting with o items or add when _blocksize is 0 and no free space  */ 

} Vector_Result;


/**  
 * @brief Dynamically create a new vector object of given capacity.
 * @param[in] a_initialCapacity - initial capacity, number of elements that can be stored initially.
 * @param[in] a_blockSize - the vector will grow or shrink on demand by this size 
 * @return Vector * - on success / NULL on fail 
 *
 * @warning if _blockSize is 0 the vector will be of fixed size. 
 * @warning if both a_initialCapacity and a_blockSize are zero function will return NULL.
 */
Vector* VectorCreate(size_t a_initialCapacity, size_t a_blockSize);


/**  
 * @brief Dynamically deallocate a previously allocated vector  
 * @param[in] a_vector - Vector to be deallocated.
 * @param[in] a_elementDestroy : A function pointer to be used to destroy all elements in the vector
 *             or a null if no such destroy is required
 * @return void
 */
void VectorDestroy(Vector** a_vector, void (*a_elementDestroy)(void* a_item));


/**  
 * @brief Add an Item to the back of the Vector.  
 * @param[in] a_vector - Vector to append integer to.
 * @param[in] a_item - Item to add.
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNITIALIZED_ERROR if a_vector or a_item is null
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR if vector is full and block_size is 0.
 * @retval VECTOR_ALLOCATION_ERROR if vector is full and realock fails.
 */
Vector_Result VectorAppend(Vector* a_vector, void* a_item);

/**  
 * @brief Delete an Element from the back of the Vector.  
 * @param[in] a_vector - Vector to delete integer from.
 * @param[out] a_pValue - pointer to variable that will receive deleted item value.
 * @return success or error code.
 * @retval VECTOR_SUCCESS on success.
 * @retval VECTOR_UNITIALIZED_ERROR if a_vector or a_pValue is null.
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR if vector is empty.
 * 
 * @warning _item can't be null. this will be assertion violation.
 */
Vector_Result VectorRemove(Vector* a_vector, void** a_pValue);

/**  
 * @brief Get value of item at specific index from the the Vector.
 * @param[in] a_vector - Vector to use.
 * @param[in] a_index - index of item to get value from. the index of first elemnt is 1.
 * @param[out] a_pValue - pointer to variable that will recieve the item's value.
 * @return success or error code.
 * @retval VECTOR_SUCCESS on success.
 * @retval VECTOR_UNITIALIZED_ERROR if a_vector or a_pValue is null.
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR if index is out of range.
 *
 * @warning Index starts from 0.
 */
Vector_Result VectorGet(const Vector* a_vector, size_t a_index, void** a_pValue);

/**  
 * @brief Set an item at specific index to a new value.
 * @param[in] a_vector - Vector to use.
 * @param[in] a_index - index of an existing item.
 * @param[in] a_value - new value to set.
 * @return success or error code 
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNITIALIZED_ERROR if a_vector or a_value is null.
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR if index is out of range.
 *
 * @warning Index starts from 0.
 */
Vector_Result VectorSet(const Vector* a_vector, size_t a_index, void* a_value);

/**  
 * @brief Get the number of actual items currently in the vector.
 * @param[in] a_vector - Vector to use.
 * @return  number of items on success 0 if vector is empty or invalid			
 */
size_t VectorSize(const Vector* _vector);

/**  
 * @brief Get the current capacity of the vector.
 * @param[in] a_vector - Vector to use.
 * @return  capacity of vector			
 */
size_t VectorCapacity(const Vector* _vector);




#endif /* __VECTOR_H__ */
