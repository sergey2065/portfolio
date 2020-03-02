#include <stdlib.h>

void Swap(int* nums, size_t firstIndex , size_t secondIndex)
{
    int temp = nums[firstIndex];
    nums[firstIndex] = nums[secondIndex];
    nums[secondIndex] = temp;
}

void moveZeroes(int* nums, size_t numsSize)
{
    size_t currIndex = 0;
    size_t i;
    
    for(i = 0; i < numsSize; ++i)
    {
        if (nums[i] != 0 && currIndex == i)
        {
            ++currIndex;
            continue;
        }
        else if(nums[i] == 0)
        {
            continue;
        }
        else
        {
            Swap(nums, i , currIndex);
            ++currIndex;
        }
    }
}
