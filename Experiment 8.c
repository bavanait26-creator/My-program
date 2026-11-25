#include <stdio.h>
#include <stdlib.h>

/* Call by Value */
int add(int a, int b)
{
    return a + b;
}

/* Call by Reference */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b, res, n, i, sum = 0;
    int *ptr, *arr;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    ptr = &a;
    printf("\nPointer Value = %d", *ptr);

    res = add(a, b);
    printf("\nCall by Value Sum = %d", res);

    swap(&a, &b);
    printf("\nAfter swapping: %d %d", a, b);

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
        return 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("Sum = %d", sum);

    free(arr);
    return 0;
}
