#include"pool.h"

void pool::setPrice(double fencePrice2, double concretePrice2)
{
	fencePrice = fencePrice2;
	concretePrice = concretePrice2;
}

void pool::setR(double R)
{
	swimPool.setR(R);
	fence.setR(R + 3);
}
