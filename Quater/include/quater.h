#ifndef __QUATER_H
#define __QUATER_H

#include "Global.h"

class DLL_EXPORT Quater
{
private:
	float x, y, z, w;

public:
	Quater();
	Quater(float, float, float, float);
	~Quater();

public:
	const Quater& operator=(const Quater& quater);

public:
	void pow(float exponent);

	friend DLL_EXPORT Quater slerp(const Quater& a, const Quater& b, float t);
};

#endif