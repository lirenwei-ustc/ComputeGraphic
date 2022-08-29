#ifndef __HPB_H
#define __HPB_H

#include <iostream>

#include "Global.h"

//ŷ���� HPB���ӹ�������ת����������
//ŷ���ǵĳ��ñ��� RPY������������ת�ɹ�������
/*
Roll����ת�ǣ�= -Bank
Pitch (������) = -Pitch
Yaw��ƫ���ǣ� = -Heading
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