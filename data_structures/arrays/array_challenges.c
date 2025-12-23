#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    int stringListCount = 3;
    int queriesCount = 3;
    char** stringList = (char**) malloc(stringListCount * sizeof(char*));\
    stringList[0] = "def";
    stringList[1] = "de";
    stringList[2] = "fgh";
    char** queries = (char**) malloc(queriesCount * sizeof(char*));
    queries[0] = "de";
    queries[1] = "lmn";
    queries[2] = "fgh";
    int res_count;
    int* results = matchingStrings(stringList, stringListCount, queries, queriesCount, &res_count);

    for (int i = 0; i < res_count; i++)
    {
        printf("%d ", results[i]);
    }
    printf("\n");
    free(results);
    free(stringList);
    free(queries);
    return 0;
}