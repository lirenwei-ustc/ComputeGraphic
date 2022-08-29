#ifndef __HPB_H
#define __HPB_H

#include <iostream>

#include "Global.h"

//欧拉角 HPB，从惯性坐标转成物体坐标
//欧拉角的常用别名 RPY，从物体坐标转成惯性坐标
/*
Roll（滚转角）= -Bank
Pitch (俯仰角) = -Pitch
Yaw（偏航角） = -Heading
*/

class DLL_EXPORT HPB
{
private:
	float heading, pitch, bank;

public:
	HPB();
	HPB(float h, float p, float bank);
	~HPB();
};

#endif