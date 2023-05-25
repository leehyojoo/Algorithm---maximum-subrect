#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "subrect_algorithm.h"

int main(int argc, char* argv[]) {
    clock_t start = clock();
    if(argc != 3) {
        printf("arguments count mismatch!\n");
        return 0;
    }

    FILE* input_file = fopen(argv[1], "r");
    int algorithm_index = atoi(argv[2]);

    if(algorithm_index < 1 || algorithm_index > 3) {
        printf("The algorithm index is not appropriate. Please enter 1 or 2 or 3\n");
        return 0;
    }
    int row = 0, col = 0;

    int** matrix;

    if(input_file == NULL) {
        printf("The input file is not exist\n");
        return 0;
    } else {
        fscanf(input_file, "%d %d\n", &row, &col);

        matrix = (int**)malloc(sizeof(int*) * row);

        //matrix dynamic allocate
        for(int i = 0; i < row; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * col);
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                fscanf(input_file, "%d", &matrix[i][j]);
            }
        }

        fclose(input_file);
    }


    //check matrix
    /*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(matrix[i][j] >= 0 ) {
                printf(" ");
            }
            printf("%.2d ", matrix[i][j]);
        }
        printf("\n");
    }
    */

    int max_sum = 0;
    switch(algorithm_index) {
        case 1:
        max_sum = max_subrect_alg1(matrix, row, col);
        break;
        case 2:
        max_sum = max_subrect_alg2(matrix, row, col);
        case 3:
        max_sum = max_subrect_alg3(matrix, row, col);
        default:
        break;
    }

    //free memory
    for(int i = 0; i < row; i++) {
        free(matrix[i]);
    }

    free(matrix);

    clock_t end = clock();

    double running_time = (double)(end - start);
    printf("MAX SUBRECT SUM : %d\n", max_sum);


    wirte_file(argv[1], algorithm_index, row, col, max_sum, running_time);

    return 0;
}