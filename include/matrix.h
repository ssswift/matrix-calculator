#pragma once

typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;

//  
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix m);
Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_multiply(Matrix a, Matrix b);
Matrix matrix_transpose(Matrix m);

//  
void print_matrix(Matrix m);
Matrix matrix_from_array(double* data, int rows, int cols);

//  :   
double matrix_sum(Matrix m);
