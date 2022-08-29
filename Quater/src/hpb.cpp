#include "hpb.h"

HPB::HPB()
{
	heading = pitch = bank = 0.f;
}
HPB::HPB(float h, float p, float b) : heading(h), pitch(p), bank(b)
{
	
}
HPB::~HPB()
{

}