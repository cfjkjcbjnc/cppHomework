#pragma once
#define pi 3.14159
class circle {
public:
	circle() { r = 0; };
	circle(double R) { r = R; };
	double setR(double R) { r = R; return r; };
	double getR() const { return r; } ;
	double getArea() const { return pi * r * r; };
	double get_length()const { return pi * 2 * r; };
private:
	double r;
};

class pool {
public:
	pool(double R, double fencePrice2, double concretePrice2) : swimPool(R), fence(R + 3), fencePrice(fencePrice2), concretePrice(concretePrice2) {};
	void setPrice(double fencePrice2, double concretePrice2);
	void setR(double R);
	double fenceCost() const { return fence.get_length() * fencePrice; };
	double concreteCost() const { return (fence.getArea() - swimPool.getArea()) * concretePrice; };
	double totalCost() const { return fenceCost() + concreteCost(); };
private:
	circle swimPool;
	circle fence;
	double fencePrice;
	double concretePrice;
};