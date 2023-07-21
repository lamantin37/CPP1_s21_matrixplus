using namespace std;

#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(): _rows(DEFAULT_X), _cols(DEFAULT_Y) {}
S21Matrix::S21Matrix(int x, int y) : _rows(x), _cols(y) {(x < 0 || y < 0) ? throw out_of_range("Error: out of range"): this->ALLOCATE_MEMORY();}
S21Matrix::~S21Matrix() {this->DESTROY_MATRIX();}

S21Matrix::S21Matrix(const S21Matrix& other) {
    *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other): _rows(other._rows), _cols(other._cols), _matrix(other._matrix) {
    other.DESTROY_MATRIX();
}

double& S21Matrix::operator()(int row, int col) {
    OUT_OF_RANGE_MATRIX();
    return _matrix[row][col];
}

void S21Matrix::setRows(int rows) {
    if (rows < _rows) {
        _matrix.resize(rows);
    } else if (rows > _rows) {
        _matrix.resize(rows, vector<double>(_cols, 0.0));
    }
    _rows = rows;
}

void S21Matrix::setCols(int cols) {
    if (cols < _cols) {
        for (int i = 0; i < _rows; ++i) {
            _matrix[i].resize(cols);
        }
    } else if (cols > _cols) {
        for (int i = 0; i < _rows; ++i) {
            _matrix[i].resize(cols, 0.0);
        }
    }
    _cols = cols;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {*this = *this + other;}
void S21Matrix::sub_matrix(const S21Matrix& other) {*this = *this - other;}
void S21Matrix::mul_matrix(const S21Matrix& other) {*this = *this * other;}
void S21Matrix::mul_number(const double num) {*this = *this * num;}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {DIFFERENT_SIZES(); MATRIX_OPERATION(+, BASIC_ARITHMETIC);}
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {DIFFERENT_SIZES(); MATRIX_OPERATION(-, BASIC_ARITHMETIC);}
S21Matrix S21Matrix::operator*(double scalar) const {MATRIX_OPERATION(*, SCALAR);}

S21Matrix operator*(double scalar, const S21Matrix& other) {
    S21Matrix result;
    result = other;
    result *= scalar;
    return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {ASSIGNMENT_OPERATORS(sum);}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {ASSIGNMENT_OPERATORS(sub);}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {ASSIGNMENT_OPERATORS(mul);}
S21Matrix& S21Matrix::operator*=(const double num) {
    mul_number(num);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {return this->eq_matrix(other);}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    this->DESTROY_MATRIX();
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->ALLOCATE_MEMORY();
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
    WRONG_DIMENSIONS();
    S21Matrix result(_rows, other._cols);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < other._cols; ++j) {
            for (int k = 0; k < _cols; ++k) {
                result._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    return result;
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        return false;
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if (_matrix[i][j] != other._matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix result(this->_cols, this->_rows);
    for (int x = 0; x < _rows; ++x) {
		for (int y = 0; y < _cols; ++y) {
			result._matrix[y][x] = _matrix[x][y];
		}
	}
	return result;
}

double S21Matrix::determinant() {
    NOT_SQUARED_MATRIX();
    if (_rows == 1) {
        return _matrix[0][0];
    }
    double det = 0.0;
    int sign = 1;
    for (int col = 0; col < _cols; ++col) {
        S21Matrix minor(_rows - 1, _cols - 1);
        getMinor(0, col, minor);
        double minor_det = minor.determinant();
        det += sign * _matrix[0][col] * minor_det;
        sign = -sign;
    }
    return det;
}

void S21Matrix::getMinor(int row, int col, S21Matrix& result) const {
    int i_result = 0;
    int j_result;
    for (int i = 0; i < _rows; ++i) {
        if (i == row) {
            continue;
        }
        j_result = 0;
        for (int j = 0; j < _cols; ++j) {
            if (j == col) {
                continue;
            }
            result(i_result, j_result) = _matrix[i][j];
            ++j_result;
        }
        ++i_result;
    }
}

S21Matrix S21Matrix::calc_complements() {
    NOT_SQUARED_MATRIX();

    S21Matrix complements(_rows, _cols);
    int sign;

    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            S21Matrix minor(_rows - 1, _cols - 1);
            getMinor(i, j, minor);
            double cofactor_value = sign * minor.determinant();

            complements(i, j) = cofactor_value;
        }
    }

    return complements;
}

S21Matrix S21Matrix::inverse_matrix() {
    NOT_SQUARED_MATRIX(); // Ensure the matrix is square
    double det = determinant();
    ZERO_DET();
    S21Matrix complements = calc_complements();
    complements = complements.transpose();
    complements *= (1.0 / det);
    return complements;
}
