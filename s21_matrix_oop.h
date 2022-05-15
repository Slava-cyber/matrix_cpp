
#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define SUCCESS 1
#define FAILURE 0

class S21Matrix {
    private:
        int _rows, _cols;
        double **_matrix;

    public:
        // constructors and destructors
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();
        // functions
        bool eq_matrix(const S21Matrix& other);
        void sum_matrix(const S21Matrix& other);
        void sub_matrix(const S21Matrix& other);
        void mul_number(const double num);
        void mul_matrix(const S21Matrix& other);
        S21Matrix transpose();
        S21Matrix calc_complements();
        double determinant();
        S21Matrix inverse_matrix();
        // operators
        S21Matrix& operator=(const S21Matrix& other);
        S21Matrix operator+(const S21Matrix& other);
        S21Matrix operator-(const S21Matrix& other);
        S21Matrix operator*(const S21Matrix& other);
        S21Matrix operator*(const double value);
        bool operator==(const S21Matrix& other);
        S21Matrix& operator+=(const S21Matrix& other);
        S21Matrix& operator-=(const S21Matrix& other);
        S21Matrix& operator*=(const S21Matrix& other);
        S21Matrix& operator*=(const double value);
        double operator()(int rows, int cols);
        // accessor and mutator
        int getRows() const;
        int getCols() const;
        void setRows(int number);
        void setCols(int number);
        // for tests
        void set_value(int rows, int cols, double value);
        void form_matrix();
    
    friend S21Matrix operator*(const double value, const S21Matrix& other);

    protected:
        void matrix_create();
        double get_minor(int n, int m, S21Matrix& other);
        S21Matrix mini_matrix(int n, int m, S21Matrix& other);
};

#endif  // SRC_S21_MATRIX_OOP_H_ 