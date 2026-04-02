#include <stdio.h>

int main()
{
    int Nums[10] = { 0 };

    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    int MultiplyNum = A * B * C;

    while (MultiplyNum != 0)
    {
        int TargetIndex = (MultiplyNum % 10);
        ++Nums[TargetIndex];

        MultiplyNum /= 10;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", Nums[i]);
    }

    return 0;
}