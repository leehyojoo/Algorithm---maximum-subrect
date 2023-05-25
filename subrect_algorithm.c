#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * O(n^6) algorithm
**/
int max_subrect_alg1(int** matrix, int row, int col) {
    int max_sum = matrix[0][0];
    for(int start_r = 0; start_r < row; start_r++) {
        for(int start_c = 0; start_c < col; start_c++) {
            for(int end_r = start_r; end_r < row; end_r++) {
                for(int end_c = start_c; end_c < col; end_c++) {
                    int this_sum = 0;

                    for(int r = start_r; r <= end_r; r++) {
                        for(int c = start_c; c <= end_c; c++) {
                            this_sum += matrix[r][c];
                        }
                    }

                    if(max_sum < this_sum) max_sum = this_sum;
                }
            }
        }
    }

    return max_sum;
}



/**
 * O(n^4) algorithm
**/
int max_subrect_alg2(int** matrix, int row, int col) {
    int max_sum = matrix[0][0];
    int** cum_matrix = (int**)malloc(sizeof(int*) * row);

    for(int r = 0; r < row; r++) {
        cum_matrix[r] = (int*)malloc(sizeof(int) * col);

        for(int c = 0; c < col; c++) {
            if(r == 0 && c == 0) {
                cum_matrix[r][c] = matrix[r][c];
            } else if(r == 0 && c != 0) {
                cum_matrix[r][c] = matrix[r][c] + cum_matrix[r][c-1];
            } else if(r != 0 && c == 0) {
                cum_matrix[r][c] = matrix[r][c] + cum_matrix[r-1][c];
            } else {
                cum_matrix[r][c] = matrix[r][c] + cum_matrix[r][c-1] + cum_matrix[r-1][c] - cum_matrix[r-1][c-1]; 
            }
        }
    }

    for(int start_r = 0; start_r < row; start_r++) {
        for(int start_c = 0; start_c < col; start_c++) {
            for (int r = start_r; r < row; r++) {
                for(int c = start_c; c < col; c++) {
                    int this_sum = 0;

                    if(start_r == 0 && start_c == 0) {
                        this_sum = cum_matrix[r][c];
                    } else if (start_r == 0 && start_c != 0) {
                        this_sum = cum_matrix[r][c] - cum_matrix[r][start_c - 1];
                    } else if(start_r != 0 && start_c == 0) {
                        this_sum = cum_matrix[r][c] - cum_matrix[start_r - 1][c];
                    } else {
                        this_sum = cum_matrix[r][c] - cum_matrix[start_r - 1][c] - cum_matrix[r][start_c - 1] + cum_matrix[start_r - 1][start_c - 1];
                    }

                    if(max_sum < this_sum) max_sum = this_sum;
                }
            }
        }
    }
    return max_sum;
}


/**
 * O(n^3) algorithm
**/
int max_subrect_alg3(int** matrix, int row, int col) {
    int max_sum = matrix[0][0];

    int* temp = (int*)malloc(sizeof(int) * row);

    int this_sum, start, finish;

    for(int left = 0; left < col; left++) {
        memset(temp, 0, sizeof(int) * row);
        for(int right = left; right < col; right++) {
            for(int i = 0; i < row; i++) {
                temp[i] += matrix[i][right];
            }

            int this_sum = 0, _max_sum = matrix[0][0];
            int _start = 0;
            finish = -1;

            for(int i = 0; i < row; i++) {
                this_sum += temp[i];
                if(this_sum < 0) {
                    this_sum = 0;
                    _start = i + 1;
                } else if(this_sum > _max_sum) {
                    _max_sum = this_sum;
                    start = _start;
                    finish = i;
                }
            }

            if(finish != -1) {
                if( max_sum < _max_sum ) max_sum = _max_sum;
            } else {
                _max_sum = temp[0];
                start = 0;
                finish = 0;

                for(int i = 1; i < row; i++) {
                    if(temp[i] > _max_sum) {
                        _max_sum = temp[i];
                        start = i;
                        finish = i;
                    }
                }
                if(max_sum < _max_sum) max_sum = _max_sum;
            }
        }
    }
    free(temp);

    return max_sum;

}

/**
 * To save output file
 * **/
void wirte_file(char* input_file, int algorithm_index, int row, int col, int max_sum, double running_time) {
    char output_file_name[100] = "result_";
    strcat(output_file_name, input_file);
    FILE* output_file = fopen(output_file_name, "w");

    fprintf(output_file, "%s\n", input_file);
    fprintf(output_file, "%d\n", algorithm_index);
    fprintf(output_file, "%d\n", row);
    fprintf(output_file, "%d\n", col);
    fprintf(output_file, "%d\n", max_sum);
    fprintf(output_file, "%lf\n", running_time);

    printf("%s is created. check the max subrect sum and running time!\n", output_file_name);
}