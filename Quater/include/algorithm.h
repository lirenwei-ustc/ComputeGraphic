#ifndef __MATRIX_ALGORITHM_H
#define __MATRIX_ALGORITHM_H

#include "hpb.h"
#include "matrix.h"

//矩阵和欧拉角的转换
template <typename T>
HPB changeToHPB(const Matrix<T, 3, 3>& matrix);

#endif