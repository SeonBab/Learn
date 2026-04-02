#include <stdio.h>
#include <malloc.h>

int main()
{
    int NumberCount;

    scanf("%d", &NumberCount);

    int* NumArr = (int*)malloc(NumberCount * sizeof(int));

    for (int i = 0; i < NumberCount; ++i)
    {
        scanf("%d", &NumArr[i]);
    }

    int TargetNumber;

    scanf("%d", &TargetNumber);

    int FoundCount = 0;

    for (int i = 0; i < NumberCount; ++i)
    {
        if (TargetNumber == NumArr[i])
        {
            ++FoundCount;
        }
    }

    printf("%d", FoundCount);
    
    free(NumArr);
    NumArr = NULL;

    return 0;
}