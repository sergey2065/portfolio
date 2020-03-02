#include <stdio.h>
#include <stdlib.h>


/*void PrintArr(int* a_arr, size_t a_size)
{
    size_t i = 0;

    printf("{");
    for(i = 0; i < a_size; ++i)
    {
        printf("%d, ", a_arr[i]);
    }
    printf("}\n");
}- for debbuging*/

int* MaxFromLeft(const int* a_height, size_t a_heightSize)
{
    int* maxFromLeftArr = NULL;
    size_t i = 0;
    
    if (( maxFromLeftArr = (int*)malloc(a_heightSize * sizeof(int)) ) == NULL)
    {
        return NULL;
    }
    
    maxFromLeftArr[0] = a_height[0];
    
    for (i = 1; i < a_heightSize; ++i)
    {
        if (a_height[i] >= maxFromLeftArr[i - 1])
        {
            maxFromLeftArr[i] = a_height[i];
        }
        else
        {
            maxFromLeftArr[i] = maxFromLeftArr[i - 1];
        }
    }
    return maxFromLeftArr;
}

int* MaxFromRight(const int* a_height, size_t a_heightSize)
{
    int* maxFromRightArr = NULL;
    int i = 0;
    
    if (( maxFromRightArr = (int*)malloc(a_heightSize * sizeof(int)) ) == NULL)
    {
        return NULL;
    }
    
    maxFromRightArr[a_heightSize - 1] = a_height[a_heightSize - 1];

    for (i = a_heightSize - 2; i >= 0; --i)
    {
        if (a_height[i] >= maxFromRightArr[i + 1])
        {
            maxFromRightArr[i] = a_height[i];
        }
        else
        {
            maxFromRightArr[i] = maxFromRightArr[i + 1];
        }
    }
    return maxFromRightArr;
}

int FindLowestMax(size_t i, int* a_maxFromRightArr, int *a_maxFromLeftArr)
{
    if(a_maxFromLeftArr[i - 1] >= a_maxFromRightArr[i + 1])
    {
        return a_maxFromRightArr[i + 1];
    }
    else
    {
        return a_maxFromLeftArr[i - 1];
    }
    
}

size_t CalculateTrapedWater(int* a_maxFromLeftArr, int* a_maxFromRightArr, int* a_height, size_t a_heightSize)
{
    size_t trappedWater = 0;
    size_t i = 0;
    int lowestMax = 0;

    if (a_maxFromLeftArr == NULL || a_maxFromRightArr == NULL || a_height == NULL)
    {
        return 0;
    }

    for (i = 1; i < a_heightSize - 1; ++i)
    {
        lowestMax = FindLowestMax(i, a_maxFromRightArr, a_maxFromLeftArr);
        if (a_height[i] < lowestMax)
        {
            trappedWater += (lowestMax - a_height[i]);
        }
    }
    return trappedWater;
}


size_t Trap(int* a_height, int a_heightSize)
{
    size_t trapedWater = 0;

    int *maxFromLeftArr = NULL;
    int *maxFromRightArr = NULL;
    
    if (a_height == NULL || a_heightSize <= 2)
    {
        return 0;
    }    
    
    maxFromLeftArr = MaxFromLeft(a_height, a_heightSize);
    maxFromRightArr = MaxFromRight(a_height, a_heightSize);
    
    trapedWater = CalculateTrapedWater(maxFromLeftArr, maxFromRightArr, a_height, a_heightSize);

    free (maxFromLeftArr);
    free (maxFromRightArr);

    return trapedWater;
}


int main()
{
    int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("trapping water calculated is %ld\n", Trap(height, 12) );
    return 0;
}