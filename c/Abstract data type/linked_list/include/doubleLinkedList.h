#ifndef __LIST_H__
#define __LIST_H__
#include <stddef.h>  /* size_t */

/** 
 *  @file doubleLinkedList.h
 *  @brief Create a Generic Double Linked List data type
 * 
 *  @details Implemented as double linked list using head and tail sentinels.
 *  Nodes are allocated from heap an store pointer to user proveded element.
 * 
 *  @bug No known bugs.
 */ 


typedef struct List List;
typedef struct ListItr* ListItr;

typedef enum ListResult 
{
	LIST_SUCCESS = 0,
	LIST_UNINITIALIZED_ERROR,			/**< Uninitialized list 					 	*/
	LIST_ALLOCATION_ERROR,				/**< Node allocation failed due to heap error */
	LIST_NULL_ELEMENT_ERROR,
	LIST_UNDER_FLOW_ERROR

} ListResult;

/** 
 * @brief Create an empty linked list.
 * 
 * @returns a pointer to the created list.
 * @retval NULL on failure due to allocation failure
 */
List* ListCreate(void);

/** 
 * @brief Destroy list
 * @details Destroys the list completely 
 *          optionally destroys elements using user provided function
 *
 * @param[in] a_pList : A pointer to previously created List returned via ListCreate
 *					   on completion *a_pList will be null
 * @param[in] a_elementDestroy : A function pointer to be used to destroy elements inserted into the list
 *             or a null if no such destroy is required
 */
void ListDestroy(List** a_pList, void (*a_elementDestroy)(void* a_item));

/** 
 * @brief Add element to head of list
 * @details time complexity: O(1).
 *
 * @param[in] a_list A previously created List ADT returned via ListCreate
 * @param[in] a_item An item to add to the list
 * 
 * @returns error code
 * @retval LIST_SUCCESS on success
 * @retval LIST_UNINITIALIZED_ERROR if the list is not initialized
 * @retval LIST_NULL_ELEMENT_ERROR  if a_item is NULL
 * @retval LIST_ALLOCATION_ERROR on memory allocation failure
 */
ListResult ListPushHead(List* a_list, void* a_item);

/** 
 * @brief Add element to the list's tail
 * @details time complexity O(1).
 *
 * @param[in] a_list - pointer to the list. 
 * @param[in] a_data - the item you want to push.
 * @returns error code.
 * @retval LIST_UNINITIALIZED_ERROR - if list pointer is null.
 * @retval LIST_NULL_ELEMENT_ERROR - if element to insert is NULL.
 * @retval LIST_ALLOCATION_ERROR - if no memory to allocate.
 * @retval LIST_SUCCESS - if item was inserted successfuly.
 */
ListResult ListPushTail(List* a_list, void* a_item);

/** @brief Remove element from list's head
 *  @details if successfull, stores a pointer to the removed item in a_pItem
 *  time complexity O(1).
 *
 * @param[in] a_list : A previously created List ADT returned via ListCreate
 * @param[in] a_pItem: To store a pointer to the removed item in.
 * @returns error code.
 * @retval LIST_UNINITIALIZED_ERROR - if list pointer is null or pointer to return value is null.
 * @retval LIST_UNDER_FLOW_ERROR - if the list is empty.
 * @retval LIST_SUCCESS - if item was poped successfuly.
 */
ListResult ListPopHead(List* a_list, void** a_pItem);

/** @brief Remove element from list's tail
 *  @details if successfull, stores a pointer to the removed item in a_pItem
 *  time complexity O(1).
 *
 * @param[in] a_list : A previously created List ADT returned via ListCreate
 * @param[in] a_pItem: To store a pointer to the removed item in.
 * @returns error code.
 * @retval LIST_UNINITIALIZED_ERROR - if list pointer is null or pointer to return value is null.
 * @retval LIST_UNDER_FLOW_ERROR - if the list is empty.
 * @retval LIST_SUCCESS - if item was poped successfuly.
 */
ListResult ListPopTail(List* a_list, void** a_pItem);

/** @brief Get number of elements in the list
 * Average time complexity O(n).
 *
 * @params a_list : A previously created List ADT returned via ListCreate
 * @return - size of list, 0 if error.
 */ 
size_t ListSize(const List* a_list);

#endif /* __LIST_H__ */






