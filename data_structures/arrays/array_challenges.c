#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//invert the arraya
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

//rotate the array "d" times to the left
int* leftRotate(int* arr, int d, int n)
{
    printf("Array Size: %d\n", n);

    d = d % n; // In case d is greater than n
    int* rotatedArr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        rotatedArr[i] = arr[(i - d) % n];
    }
    return rotatedArr;
}

//counting the number of times each query string occurs in the string list
int* matchingStrings(char** stringList, int stringListCount, char** queries, int queriesCount, int* result_count)
{
    int* results = (int*)malloc(queriesCount * sizeof(int));
    for (int i = 0; i < queriesCount; i++)
    {
        int count = 0;
        for (int j = 0; j < stringListCount; j++)
        {
            if (strcmp(queries[i], stringList[j]) == 0)
            {
                count++;
            }
        }
        results[i] = count;
    }
    *result_count = queriesCount;
    return results;
}


//remove duplicates from a sorted array
void removeDuplicateSortedArray(int* arr, int* n)
{
    if (*n == 0 || *n == 1)
        return;
    
    int j = 0;
    for (int i = 0; i < *n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[*n - 1];
    *n = j;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    removeDuplicateSortedArray(arr, &n);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}