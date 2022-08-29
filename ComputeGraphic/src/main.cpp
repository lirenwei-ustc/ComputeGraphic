#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "quater.h"
#include "hpb.h"
#include "matrix.h"
#include "algorithm.h"

using namespace std;

int main()
{
    Quater quater_a, quater_b;

    Quater quater_c = slerp(quater_a, quater_b, 0.45f);

    Matrix3f matrix;

    HPB hpb = changeToHPB<float>(matrix);

    return 0;
}