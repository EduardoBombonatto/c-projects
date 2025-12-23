#include <stdio.h>
#include <stdlib.h>

int* reverseArray(int* arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return arr;
}

int* leftRotate(int* arr, int d, int n)
{
    printf("Array Size: %d\n", n);

    d = d % n; // In case d is greater than n
    int* rotatedArr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        rotatedArr[i] = arr[(i + d) % n];
    }
    return rotatedArr;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int* reversedArr = leftRotate(arr1, 2, n);
    printf("Rotate Left twice: ");
    for (int i = 0; i < n; i++)
    {   
        printf("%d ", reversedArr[i]);
    }
    printf("\n");
    return 0;
}