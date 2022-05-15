#include "s21_matrix_oop.h"

// public functions
    // Constructors and destructors
S21Matrix::S21Matrix() : _rows(2), _cols(2) {
    matrix_create();
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    if (_rows <= 0 || _cols <= 0) {
       throw std::out_of_range("Incorrect input, size of matrix can not be negative number");
    }
    matrix_create();
}

S21Matrix::~S21Matrix() {
    if (_matrix) {
        for (int i = 0; i <_rows; i++) {
            delete[] _matrix[i];
        }
    delete _matrix;
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : _rows(other._rows), _cols(other._cols) {
    matrix_create();
    *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other) : _rows(0), _cols(0), _matrix(nullptr) {
    std::swap(_rows, other._rows);
    std::swap(_cols, other._cols);
    std::swap(_matrix, other._matrix);
}
    
    // functions
bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool result = true;
    if (_rows != other._rows || _cols != other._cols) {
        result = false;
    }
    if (result) {
        for(int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                if (_matrix[i][j] != other._matrix[i][j])
                    result = false;
            }
        }
    }
    return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range("Error");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
        }
    }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range("Error");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
        }
    }
}
    
void S21Matrix::mul_number(const double num) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] * num;
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    S21Matrix result(_rows, other._cols);
    if (_cols != other._rows) {
        throw std::out_of_range("Error");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < other._cols; j++) {
            for (int k = 0; k < _cols; k++) {
                result._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    this->~S21Matrix();
    _cols = other._cols;
    matrix_create();
    *this = result;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix result(_rows, _cols);
    for (int i = 0; i < _cols; i++) {
        for (int j = 0; j < _rows; j++) {
            result._matrix[i][j] = _matrix[j][i];
        }
    }
    return result;
}

S21Matrix S21Matrix::calc_complements() {
    S21Matrix result(_rows, _cols);
    if (_rows != _cols || _rows < 2 || _cols < 2) {
        throw std::out_of_range("Error");
    }
    if (_rows == 2) {
            result._matrix[0][0] = _matrix[1][1];
            result._matrix[1][1] = _matrix[0][0];
            result._matrix[0][1] = _matrix[1][0] * (-1);
            result._matrix[1][0] = _matrix[0][1] * (-1);
    } else {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _rows; j++) {
                result._matrix[i][j] = get_minor(i, j, *this) * pow(-1, i + j);
            }
        }       
    }
    return result;
}

double S21Matrix::determinant() {
    double result = 0;
    if (_rows != _cols || _rows < 1 || _cols < 1) {
        throw std::out_of_range("Error");
    }
    if (_rows == 1) {
        result = _matrix[0][0];
    } else if (_rows == 2) {
        result = _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
    } else {
        for (int i = 0; i < _rows; i++) {
            S21Matrix buffer(_rows - 1, _cols - 1);
            buffer = mini_matrix(i, 0, *this);
            result += pow(-1, i + 2) * _matrix[i][0] * buffer.determinant();
        }
    }
    return result;
}

S21Matrix S21Matrix::inverse_matrix() {
    S21Matrix result(_rows, _cols);
    result = *this;
    double determinant = result.determinant();
    if (determinant == 0 && determinant == NAN) {
        throw std::out_of_range("Error");
    }
    result = result.calc_complements();
    result = result.transpose();
    result.mul_number(1.0 / determinant);
    return result;
}

    // operators
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        this->~S21Matrix();
        _rows = other._rows;
        _cols = other._cols;
        matrix_create();
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
    return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix result(_rows, _cols);
    result = *this;
    result.sum_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix result(_rows, _cols);
    result = *this;
    result.sub_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix result(_rows, other._cols);
    result = *this;
    result.mul_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const double value) {
    S21Matrix result(_rows, _cols);
    result = *this;
    result.mul_number(value);
    return result;
}

S21Matrix operator*(const double value, const S21Matrix& other) {
    S21Matrix result(other._rows, other._cols);
    result = other;
    result.mul_number(value);
    return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
    return eq_matrix(other);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    sum_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    sub_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double value) {
    mul_number(value);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    mul_matrix(other);
    return *this;
}

double S21Matrix::operator()(int rows, int cols) {
    if (rows >= _rows || rows < 0 || cols < 0 || cols >= _cols) {
        throw std::out_of_range("Error");
    }
    return _matrix[rows][cols];
}

    // accessor and mutator
int S21Matrix::getRows() const {
    return _rows;
}

int S21Matrix::getCols() const {
    return _cols;
}

void S21Matrix::setRows(int number) {
    _rows = number;
}

void S21Matrix::setCols(int number) {
    _cols = number;
}

    // for tests
void S21Matrix::set_value(int rows, int cols, double value) {
    if (rows >= _rows || rows < 0 || cols < 0 || cols >= _cols) {
        throw std::out_of_range("Error");
    }
    _matrix[rows][cols] = value;
}  

void S21Matrix::form_matrix() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = i + j;
        }
    }
}
    // support functions
void S21Matrix::matrix_create() {
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols]();
    }
}

double S21Matrix::get_minor(int n, int m, S21Matrix& other) {
    double determinant;
    S21Matrix buffer(other._rows - 1, other._cols - 1);
    buffer = mini_matrix(n, m, other);
    determinant = buffer.determinant();
    return determinant;
}

S21Matrix S21Matrix::mini_matrix(int n, int m, S21Matrix& other) {
    S21Matrix result(other._rows - 1, other._cols - 1);
    int l = 0, k = 0;
    for (int i = 0; i < other._rows; i++) {
        if (i != n) {
            for (int j = 0; j < other._rows; j++) {
                if (j != m) {
                    result._matrix[k][l] = other._matrix[i][j];
                    l += 1;
                }
            }
            k += 1;
            l = 0;
        }
    }
    return result;
}
