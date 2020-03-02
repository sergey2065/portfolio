#include <stdio.h>
#include <stdlib.h>

void PrintArr(int* a_arr, size_t a_size)
{
    size_t i = 0;

    printf("{");
    for(i = 0; i < a_size; ++i)
    {
        printf("%d, ", a_arr[i]);
    }
    printf("}\n");
}

typedef struct TreeNode
{
    int m_val;
    struct TreeNode *m_left;
    struct TreeNode *m_right;
} TreeNode;


void CountTreeLength(const TreeNode* a_root, size_t *a_count)
{
    if (a_root ==  NULL)
    {
        return;
    }
    
    ++(*a_count);
    CountTreeLength(a_root-> m_left, a_count);
    CountTreeLength(a_root-> m_right, a_count);
}

void PushInoder(const TreeNode* a_root, int* a_serialized, size_t *currPos)
{
    if (a_root == NULL)
    {
        return;
    }

    PushInoder(a_root-> m_left, a_serialized, currPos);

    a_serialized[*currPos] = a_root-> m_val;
    ++(*currPos);

    PushInoder(a_root-> m_right, a_serialized, currPos);
}

void PushPreOrder(const TreeNode* a_root, int* a_serialized, size_t *currPos)
{
    if (a_root == NULL)
    {
        return;
    }

    a_serialized[(*currPos)++] = a_root-> m_val;

    PushPreOrder(a_root-> m_left, a_serialized, currPos);
    PushPreOrder(a_root-> m_right, a_serialized, currPos);
}

int* serialize(const TreeNode* a_root, size_t *a_size)
{
    size_t treeLen = 0;
    size_t currPos = 0;
    int* serialized = NULL;

    CountTreeLength(a_root, &treeLen);
    *a_size = treeLen * 2;
        
    serialized = (int*)malloc(*a_size * sizeof(int)); 
    
    PushInoder(a_root, serialized, &currPos);
    PushPreOrder(a_root, serialized, &currPos);
    
    return serialized;
}

TreeNode* deserialize(char* data) 
{
    
}


int main()
{
    TreeNode a = {5, NULL, NULL};
    TreeNode b = {4, NULL, NULL};
    TreeNode d = {2, NULL, NULL};
    TreeNode c;
    TreeNode e;
    size_t sizeOfSerialized = 0;
    int* serializedArr = NULL;

    c.m_val = 3;
    c.m_left = &b;
    c.m_right = &a;

    e.m_val = 1;
    e.m_left = &d;
    e.m_right = &c;

    serializedArr = serialize(&e, &sizeOfSerialized);
    printf("size of new arr is %ld", sizeOfSerialized);
    PrintArr(serializedArr, sizeOfSerialized);

}