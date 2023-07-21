#include <iostream>
#include <stdexcept>
#include <vector>

#ifndef S21_MATRIX_H_INCLUDED
#define S21_MATRIX_H_INCLUDED

#define DEFAULT_X 3
#define DEFAULT_Y 3

#define OUT_OF_RANGE_MATRIX() do {(row < 0 || row >= _rows || col < 0 || col >= _cols) ? throw out_of_range("Error: index out of range"): 0;} while(0)
#define DIFFERENT_SIZES() do {(_rows != other._rows || _cols != other._cols) ? throw invalid_argument("Error: matrices have different sizes"): 0;} while(0)
#define WRONG_DIMENSIONS() do {(_cols != other._rows) ? throw invalid_argument("Error: matrix dimensions do not match for multiplication"): 0;} while(0)
#define NOT_SQUARED_MATRIX() do {(_rows != _cols) ? throw invalid_argument("Matrix must be square to calculate determinant."): 0;} while(0)
#define ZERO_DET() do {(det == 0.0) ? throw invalid_argument("Matrix is not invertible (determinant is zero)."): 0;} while(0)

#define OPERATION_TYPE_BASIC_ARITHMETIC other._matrix[i / _cols][i % _cols];
#define OPERATION_TYPE_SCALAR scalar
#define MATRIX_OPERATION(op, m)                                                                                          \
    do {                                                                                                                 \
        S21Matrix result(_rows, _cols);                                                                                  \
        for (int i = 0; i < _rows * _cols; ++i)                                                                          \
            result._matrix[i / _cols][i % _cols] = _matrix[i / _cols][i % _cols] op OPERATION_TYPE_##m;                  \
        return result;                                                                                                   \
    } while (0)

#define ASSIGNMENT_OPERATORS(m) do {m##_matrix(other); return *this;} while(0)

class S21Matrix {
private:
    int _rows, _cols;                 // Rows and columns
    vector<vector<double>> _matrix;

public:
    S21Matrix();
    S21Matrix(int x, int y);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    int getRows() const {return _rows;}
    int getCols() const {return _cols;}

    void setRows(int rows);
    void setCols(int cols);

    double& operator()(int row, int col);
    S21Matrix operator+(const S21Matrix& other) const;
    S21Matrix operator-(const S21Matrix& other) const;
    S21Matrix operator*(double scalar) const;
    S21Matrix operator*(const S21Matrix& other) const;
    friend S21Matrix operator*(double scalar, const S21Matrix& other);

    bool eq_matrix(const S21Matrix& other);
    bool operator==(const S21Matrix& other);

    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);

    double determinant();
    void getMinor(int row, int col, S21Matrix& result) const;
    S21Matrix transpose();
    S21Matrix calc_complements();
    S21Matrix inverse_matrix();

    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double num);
    S21Matrix& operator=(const S21Matrix& other);

    inline void ALLOCATE_MEMORY() { this->_matrix.resize(this->_rows, vector<double>(this->_cols)); }
    inline void DESTROY_MATRIX() { this->_matrix.clear(); this->_cols = 0; this->_rows = 0; }

};

double cofactor(int row, int col, const S21Matrix& matrix);

#endif // S21_MATRIX+_H_INCLUDED

