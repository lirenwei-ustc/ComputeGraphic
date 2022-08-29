#include "quater.h"
#include <cmath>
#include <iostream>

using namespace std;

Quater::Quater() : w(1), x(0), y(0), z(0)
{

}
Quater::Quater(float w, float x, float y, float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}
Quater::~Quater()
{

}
const Quater& Quater::operator=(const Quater& quater)
{
    this->w = quater.w;
    this->x = quater.x;
    this->y = quater.y;
    this->z = quater.z;

    return *this;
}
void Quater::pow(float exponent)
{
    //这里检查了单位四元数，如果w = 1, (x y z)是零向量的话
    //表示没有旋转
    //而且单位四元数会导致除零，并且其任意次幂都是本身
    if (fabs(w) < .9999f)
    {
        //提取出半角 (alpha = theta / 2)
        float alpha = acos(w);
        float new_alpha = alpha * exponent;

        //通过欧拉公式再次计算出新的w值
        w = cos(new_alpha);

        float mult = sin(new_alpha) / sin(alpha);

        x *= mult;
        y *= mult;
        z *= mult;
    }
}
Quater slerp(const Quater& quater_a, const Quater& quater_b, float t)
{
    Quater quater = quater_a;
    float cos_omega = quater_a.w * quater_b.w + quater_a.x * quater_b.x +
        quater_a.y * quater_b.y + quater_a.z * quater_b.z;
    float k0, k1;

    if (cos_omega < 0)
    {
        quater.w = -quater.w;
        quater.x = -quater.x;
        quater.y = -quater.y;
        quater.z = -quater.z;

        cos_omega = -cos_omega;
    }
    if (fabs(cos_omega) > 0.9999f)
    {
        k0 = 1 - t;
        k1 = t;
    }
    else
    {
        //计算sin_omega
        float sin_omega = sqrt(1 - cos_omega * cos_omega);
        //计算omega
        float omega = asin(sin_omega);
        float sin_omega_verse = 1.0f / sin_omega;

        k0 = sin((1 - t) * omega) * sin_omega_verse;
        k1 = sin(t * omega) * sin_omega_verse;
    }

    quater.w = k0 * quater.w + k1 * quater_b.w;
    quater.x = k0 * quater.x + k1 * quater_b.x;
    quater.y = k0 * quater.y + k1 * quater_b.y;
    quater.z = k0 * quater.z + k1 * quater_b.z;

    return move(quater);
}