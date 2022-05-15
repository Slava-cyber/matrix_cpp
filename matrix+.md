#A reminder of the matrix basics
Matrix is a rectangular table of numbers arranged in m rows and n columns
```
    1 2 3
A = 4 5 6
    7 8 9
```
```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```
You can get the desired element using indices as follows A[1,1] = 1, where the first index is the row number, the second is the column number.

The order of a matrix is the number of its rows or columns.
The main diagonal of a square matrix is the diagonal from the upper left to the lower right corner. \

A rectangular matrix (B) is a matrix with the number of rows not equal to the number of columns.
A square matrix (A) is a matrix with the number of rows equal to the number of columns.

#Matrix operations
There is a brief description of the matrix operations below that need to be implemented in the developing library. They are similar to the operations you performed earlier in «structured programming», so you can see a more detailed description of them there. Note that some operations have exceptional situations that require special handling using the exception mechanism.
```
Operation	Description	Exceptional situations
bool eq_matrix(const S21Matrix& other)	Checks matrices for equality with each other	
void sum_matrix(const S21Matrix& other)	Adds the second matrix to the current one	different matrix dimensions
void sub_matrix(const S21Matrix& other)	Subtracts another matrix from the current one	different matrix dimensions
void mul_number(const double num)	Multiplies the current matrix by a number	
void mul_matrix(const S21Matrix& other)	Multiplies the current matrix by the second matrix	the number of columns of the first matrix is not equal to the number of rows of the second matrix
S21Matrix transpose()	Creates a new transposed matrix from the current one and returns it	
S21Matrix calc_complements()	Calculates the algebraic addition matrix of the current one and returns it	the matrix is not square
double determinant()	Calculates and returns the determinant of the current matrix	the matrix is not square
S21Matrix inverse_matrix()	Calculates and returns the inverse matrix	matrix determinant is 0
Apart from those operations, you also need to implement constructors and destructors:
```
Method	Description
S21Matrix()	A basic constructor that initialises a matrix of some predefined dimension
S21Matrix(int rows, int cols)	Parametrized constructor with number of rows and columns
S21Matrix(const S21Matrix& other)	Copy constructor
S21Matrix(S21Matrix&& other)	Move constructor
~S21Matrix()	Destructor
```
And you also need to overload the following operators, partly corresponding to the operations above:
```
Operator	Description	Exceptional situations
+	Addition of two matrices	different matrix dimensions
-	Subtraction of one matrix from another	different matrix dimensions
*	Matrix multiplication and matrix multiplication by a number	the number of columns of the first matrix does not equal the number of rows of the second matrix
==	Checks for matrices equality (eq_matrix)	
=	Assignment of values from one matrix to another one	
+=	Addition assignment (sum_matrix)	different matrix dimensions
-=	Difference assignment (sub_matrix)	different matrix dimensions
*=	Multiplication assignment (mul_matrix/mul_number)	the number of columns of the first matrix does not equal the number of rows of the second matrix
(int i, int j)	Indexation by matrix elements (row, column)	index is outside the matrix
```

#Implementation of the s21_matrix_oop.h library functions
The program must be developed in C++ language of C++17 standard using gcc compiler
The program code must be located in the src folder
Implement the matrix as an S21Matrix class
Use only the matrix, rows and columns fields as private
Implement the access to private fields rows and columns via accessor and mutator
Make it as a static library (with s21_matrix_oop.h header file)
Implement the operations described above
Overload the operators according to the table in the chapter above
Prepare full coverage of library functions code with unit-tests using the GTest library
Provide a Makefile for building the library and tests (with targets all, clean, test, s21_matrix_oop.a)