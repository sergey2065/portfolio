#include <stdio.h>
#include <assert.h>
#include  "../include/doubleLinkedList.h"

#define TESTING_LENGTH 1000

void MakeIntZero(void* a_item)
{
     *(int*)a_item = 0;
}

void PushTailPopHeadTest(void)
{
     List* myList = NULL;
     int arr[TESTING_LENGTH];
     size_t i = 0;
     void *returnValue = NULL;

     myList = ListCreate();

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          arr[i] = i;
          ListPushTail(myList, &arr[i]);
     }

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          ListPopHead(myList, &returnValue);
          assert(*(int*)returnValue == i);
     }
     
     ListDestroy(&myList, NULL);
     printf("push tail pop head test: PASS\n");
}

void PushHeadPopTailTest(void)
{
     List* myList = NULL;
     int arr[TESTING_LENGTH];
     size_t i = 0;
     void *returnValue = NULL;

     myList = ListCreate();

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          arr[i] = i;
          ListPushTail(myList, &arr[i]);
     }

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          ListPopHead(myList, &returnValue);
          assert(*(int*)returnValue == i);
     }
     
     ListDestroy(&myList, NULL);
     printf("push head pop tail test: PASS\n");
}

void DestroyWithNoElementDestroyFunc()
{
     List* myList = NULL;
     int arr[TESTING_LENGTH];
     size_t i = 0;

     myList = ListCreate();

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          arr[i] = i;
          ListPushTail(myList, &arr[i]);
     }
     ListDestroy(&myList, NULL);
     printf("destroy without element destroy func: PASS\n");
}

void DestroyWithElementDestroyFunc()
{
     List* myList = NULL;
     int arr[TESTING_LENGTH];
     size_t i = 0;

     myList = ListCreate();

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          arr[i] = i;
          ListPushTail(myList, &arr[i]);
     }

     ListDestroy(&myList, MakeIntZero);

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          assert(arr[i] == 0);
     }

     printf("destroy with element destroy func: PASS\n");
}

void DestroyWithNullListPointer()
{
     List *NullPuinter = NULL;
     ListDestroy(&NullPuinter, NULL);

     printf("destroy with null pointer test: PASS\n");
}
void DestroyWithNullPointerToListpointer()
{
     ListDestroy(NULL, NULL);

     printf("destroy with null pointer to list pointer test: PASS\n");  
}

void PushTailWhenListPointerIsNull()
{
     assert(ListPushTail(NULL, NULL) == LIST_UNINITIALIZED_ERROR);

     printf("push tail with null list status: PASS\n");
}

void PushHeadWhenListPointerIsNull()
{
     assert(ListPushHead(NULL, NULL) == LIST_UNINITIALIZED_ERROR);

     printf("push head with null list status: PASS\n");
}

void PushHeadWithNullItem()
{
     List *ListP = NULL;

     ListP = ListCreate();

     assert(ListPushHead(ListP, NULL) == LIST_NULL_ELEMENT_ERROR);

     printf("push head with null item status: PASS\n");

}

void PushTailWithNullItem()
{
     List *ListP = NULL;

     ListP = ListCreate();

     ListPushTail(ListP, NULL);

     assert(ListPushTail(ListP, NULL) == LIST_NULL_ELEMENT_ERROR);

     printf("push tail with null item status: PASS\n");
}

void PopHeadWithNullList()
{
     void *retVal = NULL;

     assert(ListPopHead(NULL, &retVal) == LIST_UNINITIALIZED_ERROR);

     printf("pop head with null list status: PASS\n");
}
void PopTailWithNullList()
{
     void *retVal = NULL;

     assert(ListPopTail(NULL, &retVal) == LIST_UNINITIALIZED_ERROR);

     printf("pop tail with null list status: PASS\n");
}

void PopHeadWithNullReturValue()
{
     List *ListP = NULL;

     assert(ListPopHead(ListP, NULL) == LIST_UNINITIALIZED_ERROR);

     printf("pop head with null return value pointer status: PASS\n");
}
void PopTailWithNullReturValue()
{
     List *ListP = NULL;

     assert(ListPopTail(ListP, NULL) == LIST_UNINITIALIZED_ERROR);

     printf("pop tail with null return value pointer: PASS\n");
}

void PopHeadEmptyList()
{
     List *ListP = NULL;
     void *retVal = NULL;

     ListP = ListCreate();
     assert(ListPopHead(ListP, &retVal) == LIST_UNDER_FLOW_ERROR);

     printf("pop head with empty list: PASS\n");
}

void PopTailEmptyList()
{
      List *ListP = NULL;
     void *retVal = NULL;

     ListP = ListCreate();
     assert(ListPopTail(ListP, &retVal) == LIST_UNDER_FLOW_ERROR);

     printf("pop Tail with empty list: PASS\n");
}

void SizeWithNullList()
{
     assert (ListSize(NULL) == 0);

     printf("size with null pointer: PASS\n");
}

void TestSize()
{
     List *listP = NULL;
     size_t i = 0;

     listP = ListCreate();

     for(i = 0; i < TESTING_LENGTH; ++i)
     {
          assert(ListSize(listP) == i);
          ListPushHead(listP, &i);
     }
     printf("size regular test is: PASS\n");
}

int main()
{
     PushTailPopHeadTest();
     PushHeadPopTailTest();
     DestroyWithNoElementDestroyFunc();
     DestroyWithElementDestroyFunc();
     DestroyWithNullListPointer();
     DestroyWithNullPointerToListpointer();
     PushTailWhenListPointerIsNull();
     PushHeadWhenListPointerIsNull();
     PushHeadWithNullItem();
     PushTailWithNullItem();
     PopHeadWithNullList();
     PopTailWithNullList();
     PopHeadWithNullReturValue();
     PopTailWithNullReturValue();
     PopHeadEmptyList();
     PopTailEmptyList();
     SizeWithNullList();
     TestSize();

     return 0;
}