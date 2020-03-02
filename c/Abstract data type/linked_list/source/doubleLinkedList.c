#include <stdio.h>
#include <stdlib.h> /* malloc */
#include "../include/doubleLinkedList.h"

/*------------- structs ------------*/

typedef struct Node
{
     void* m_data;
     struct Node* m_next;
     struct Node* m_prev;
}Node;

struct List
{
     Node m_head;
     Node m_tail;
};
/*---------------- privet functions declarations ----------------*/
static void Push(Node *_headOrTail ,Node *_ptrNode);
static void* Pop(Node *_headOrTail);
static Node* CreateNode(void *_item);
static void DestroyElements(List *a_pList, void (*a_elementDestroy)(void* a_item));
static void DestroyAllNodes(List *a_pList);

/*------------------------- public functions ---------------------------*/
List* ListCreate(void)
{
     List *tempPtr;
     
     if ((tempPtr = (List*)calloc(1, sizeof(List))) == NULL)
     {
          return NULL;
     }    
     
     tempPtr->m_head.m_next = &(tempPtr-> m_tail); 
     tempPtr->m_head.m_prev = &tempPtr->m_head;
     tempPtr->m_tail.m_next = &tempPtr->m_tail;
     tempPtr->m_tail.m_prev = &(tempPtr-> m_head); 
         
     return tempPtr;
}

void ListDestroy(List** a_pList, void (*a_elementDestroy)(void* a_item))
{         
     if (NULL == a_pList || *a_pList == NULL) 
     {
          return;
     }
     
     if (a_elementDestroy != NULL)
     {
          DestroyElements(*a_pList, a_elementDestroy);
	}
   
     DestroyAllNodes(*a_pList);
     
     free(*a_pList);
     (*a_pList) = NULL;
     return;
}

ListResult ListPushHead(List* a_list, void* a_item)
{
     Node *nodeP;

     if (NULL == a_list)
     {
          return LIST_UNINITIALIZED_ERROR;
     }

     if (a_item == NULL)
     {
          return LIST_NULL_ELEMENT_ERROR;
     }

     if ((nodeP = CreateNode(a_item)) == NULL)
     {
          return LIST_ALLOCATION_ERROR;
     }

     Push(a_list->m_head.m_next ,nodeP); 
     
     return LIST_SUCCESS;
}

ListResult ListPushTail(List* a_list, void* a_item)
{
     Node *nodeP;

     if (NULL == a_list)
     {
          return LIST_UNINITIALIZED_ERROR;
     }

     if (a_item == NULL)
     {
          return LIST_NULL_ELEMENT_ERROR;
     }

     if ((nodeP = CreateNode(a_item)) == NULL)
     {
          return LIST_ALLOCATION_ERROR;
     }

     nodeP-> m_data = a_item;
     Push(&(a_list-> m_tail), nodeP); 
     
     return LIST_SUCCESS;
     
}

ListResult ListPopHead(List* a_list, void** a_pItem)
{
     if (NULL == a_list || NULL == a_pItem)
     {
          return LIST_UNINITIALIZED_ERROR;
     }
     
     if (a_list->m_head.m_next == &(a_list->m_tail))
     {
          return LIST_UNDER_FLOW_ERROR;
     }

     *a_pItem = a_list->m_head.m_next-> m_data;
     Pop(a_list->m_head.m_next);
     
     return LIST_SUCCESS;
}

ListResult ListPopTail(List* a_list, void** a_pItem)
{
     if ( NULL == a_list || NULL == a_pItem )
     {
          return LIST_UNINITIALIZED_ERROR;
     }
     
     if ( a_list->m_head.m_next == &a_list->m_tail)
     {
          return LIST_UNDER_FLOW_ERROR;
     }

     *a_pItem = a_list->m_head.m_next-> m_data;
     
     Pop(a_list->m_tail.m_prev);
     
     return LIST_SUCCESS;
}

size_t ListSize(const List* a_list)
{
     size_t size = 0;
     Node *cur = NULL;
     
     if (a_list != NULL)
     {
          cur = a_list->m_head.m_next;
          while(cur != &(a_list-> m_tail) )
          {
               ++size;
               cur = cur-> m_next;
          }
     }    
     return size;
}

static void DestroyAllNodes(List *a_pList)
{
     Node *curr = NULL;
     Node *prev = NULL;
     
     curr = a_pList-> m_head.m_next;
     while(curr != &(a_pList->m_tail))
     {
          prev = curr;
          curr = curr->m_next;

          free(prev);
     }
}

static void DestroyElements(List *a_pList, void (*a_elementDestroy)(void* a_item))
{
     Node* curr = NULL;

     curr = a_pList-> m_head.m_next;
     while (curr != &(a_pList->m_tail))
     {
          a_elementDestroy(curr-> m_data);
          curr = curr-> m_next;
     }
}

static void Push(Node *_rightNode ,Node *_ptrNode)
{
     _ptrNode->m_prev =  _rightNode-> m_prev;
     _ptrNode->m_next =  _rightNode ;
     _rightNode -> m_prev ->m_next = _ptrNode;
     _rightNode -> m_prev= _ptrNode ;
         
     return;     
}

static void* Pop(Node *_node)
{
     void* _item = _node ->m_data;
     _node->m_next->m_prev = _node->m_prev;
     _node->m_prev->m_next = _node->m_next;    
     free(_node);
     return _item;
}

static Node* CreateNode(void *a_item)
{
     Node* newNode = NULL;
     if((newNode = (Node*)malloc(sizeof(Node))) == NULL)
     {
          return NULL;
     }

     newNode-> m_data = a_item;
     return newNode;
}
