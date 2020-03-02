#include <stdlib.h>


 struct TreeNode 
 {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 


size_t maxDepth(struct TreeNode* a_root)
{
    size_t leftDepth = 0;
    size_t rightDepth = 0;
    
    if (a_root == NULL)
    return 0;
    
    leftDepth = maxDepth(a_root-> left);
    rightDepth = maxDepth(a_root-> right);
    
    if (leftDepth >= rightDepth)
    {
        return leftDepth + 1;
    }
    else 
    {
        return rightDepth + 1;
    }
}