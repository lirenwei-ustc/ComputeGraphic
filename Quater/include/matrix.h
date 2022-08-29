#ifndef __MATRIX_H
#define __MATRIX_H

#include <vector>
#include <iostream>

#include "Global.h"

//æÿ’Û¿‡

template <typename tp, unsigned int n, unsigned int m>
class Matrix
{
private:
	int row, column;
	std::vector<std::vector<tp>> _vect;

public:
	Matrix();
	~Matrix();

	void Indentity();

	inline std::vector<tp>& operator[](unsigned int index)
	{
		return _vect[index];
	}
	inline const std::vector<tp>& operator[](unsigned int index) const
	{
		return _vect[index];
	}
};

template <typename T, unsigned int n, unsigned int m>
Matrix<T, n, m>::Matrix() : row(n), column(m)
{
	_vect.resize(row, std::vector<T>(column, 0));

	Indentity();
}

template <typename T, unsigned int n, unsigned int m>
Matrix<T, n, m>::~Matrix()
{

}

template <typename T, unsigned int n, unsigned int m>
void Matrix<T, n, m>::Indentity()
{
	if (n != m) return;

	memset(&_vect, 0, sizeof(_vect));

	for (int a = 0; a < n; ++a)
	{
		_vect[a][a] = 1;
	}
}

//2-4Œ¨∑Ω’Û
typedef Matrix<float, 2, 2> Matrix2f;
typedef Matrix<double, 2, 2> Matrix2d;
typedef Matrix<float, 3, 3> Matrix3f;
typedef Matrix<double, 3, 3> Matrix3d;
typedef Matrix<float, 4, 4> Matrix4f;
typedef Matrix<double, 4, 4> Matrix4d;

#endif