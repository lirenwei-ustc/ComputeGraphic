#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "quater.h"

using namespace std;

int main()
{
    Quater quater_a, quater_b;

    Quater quater_c = slerp(quater_a, quater_b, 0.45f);

    return 0;
}