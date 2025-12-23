#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//allocate matrix dynamically
int** allocate_matrix(int rows, int cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        // Handle error if allocation fails
        perror("malloc failed for row pointers");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            perror("malloc failed for row data");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

//free allocated matrix
void free_matrix_ptr(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

//initialize matrix with values
void initialize_matrix(int** matrix, int rows, int cols) {
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j + value;
        }
        value += rows;
    }
}

//print matrix using pointer arithmetic
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

//transpose matrix
int** transposed_matrix(int** matrix, int rows, int cols) {
    int** transposed = allocate_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main()
{
    int rows = 3, cols = 4;

    int** matrix = allocate_matrix(rows, cols);
    initialize_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);

    printf("Transposed Matrix:\n");
    int** transposed = transposed_matrix(matrix, rows, cols);
    print_matrix(transposed, cols, rows);

    free_matrix_ptr(transposed, cols);
    free_matrix_ptr(matrix, rows);
    return 0;
}