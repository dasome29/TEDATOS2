//
// Created by david on 1/3/20.
//

#ifndef SERVERSOCKET_MATRIX_H
#define SERVERSOCKET_MATRIX_H


#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

template<typename T>
class Matrix {
    std::vector<std::vector<T>> content;
    size_t width;
    size_t height;

public:
    Matrix(size_t width_, size_t height_) : width{width_}, height{height_}
    {
        content.resize(height);

        for (size_t i = 0; i < height; ++i)
        {
            content[i].resize(width);
        }
    }

    const std::vector<T>& operator[](size_t row_index) const {
        return content[row_index];
    }

    std::vector<T>& operator[](size_t row_index) {
        return content[row_index];
    }

    size_t get_width()  const { return width; }
    size_t get_height() const { return height; }
};

template<typename T1, typename T2>
auto operator*(const Matrix<T1>& a, const Matrix<T2>& b) -> Matrix<decltype(T1{} * T2{})>
{
    if (a.get_height() != b.get_width())
    {
        std::stringstream ss;
        ss << "Matrix dimenstion mismatch: ";
        ss << a.get_height();
        ss << " x ";
        ss << a.get_width();
        ss << " times ";
        ss << b.get_height();
        ss << " x ";
        ss << b.get_width();
        ss << ".";
        throw std::runtime_error(ss.str());
    }

    using value_type = decltype(T1{} + T2{});
    Matrix<decltype(T1{} * T2{})> result(a.get_height(), b.get_width());

    for (size_t rowa = 0; rowa != a.get_height(); ++rowa)
    {
        for (size_t colb = 0; colb != b.get_width(); ++colb)
        {
            value_type sum = 0;

            for (size_t i = 0; i != a.get_width(); ++i)
            {
                sum += a[rowa][i] * b[i][colb];
            }

            result[rowa][colb] = sum;
        }
    }

    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T> m)
{
    size_t maximum_entry_length = 0;

    for (size_t row = 0; row < m.get_height(); ++row)
    {
        for (size_t col = 0; col < m.get_width(); ++col)
        {
            std::stringstream ss;
            ss << m[row][col];
            std::string entry_text;
            ss >> entry_text;
            maximum_entry_length = std::max(maximum_entry_length,
                                            entry_text.length());
        }
    }

    for (size_t row = 0; row < m.get_height(); ++row)
    {
        for (size_t col = 0; col < m.get_width(); ++col)
        {
            os << std::setw((int) maximum_entry_length) << m[row][col];

            if (col < m.get_width() - 1)
            {
                os << ' ';
            }
        }

        if (row < m.get_height() - 1)
        {
            os << '\n';
        }
    }

    return os;
}


#endif //SERVERSOCKET_MATRIX_H
