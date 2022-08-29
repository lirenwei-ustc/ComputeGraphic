#include <cmath>
#include <vector>

#include "algorithm.h"

template <typename T>
HPB changeToHPB(const Matrix<T, 3, 3>& matrix)
{
	const T PI = 3.1415926;

	T h, p, b;
	T sp = -matrix[1][2];

	p = asin(sp);
	
	if (sp <= -1.0)
	{
		p = -PI / 2;
	}
	else if (sp >= 1.0)
	{
		p = PI / 2;
	}
	else
	{
		p = asin(sp);
	}

	if (abs(sp) > 0.9999)
	{
		b = 0;
		h = atan2(-matrix[2][0], matrix[0][0]);
	}
	else
	{
		h = atan2(matrix[0][2], matrix[2][2]);
		b = atan2(matrix[1][0], matrix[1][1]);
	}

	return std::move(HPB(h, p, b));
}

template
DLL_EXPORT HPB changeToHPB<float>(const Matrix<float, 3, 3>& matrix);

template
DLL_EXPORT HPB changeToHPB<double>(const Matrix<double, 3, 3>& matrix);