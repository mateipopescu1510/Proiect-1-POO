#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class point {
public:
	point() {
		x = y = 0;
	}
	point(double a, double b) {
		x = a;
		y = b;
	}
	point(const point& B) {
		x = B.x;
		y = B.y;
	}
	~point() {}
	void setPoint(double a, double b) {
		x = a;
		y = b;
	}
	double getx() {
		return x;
	}
	double gety() {
		return y;
	}
	point operator +(point&);
	point operator -(point&);
	point operator *(double);
	point operator /(double);
	void operator +=(point&);
	void operator -=(point&);
	void operator *=(double);
	void operator /=(double);
	bool operator ==(point&);
	bool operator !=(point&);
	friend istream& operator >>(istream&, point&);
	friend ostream& operator <<(ostream&, const point&);
	double distance(const point& B) {
		return sqrt(pow((x - B.x), 2) + pow((y - B.y), 2));
	}
	bool collinear(const point& B, const point& C) {
		return abs(x * (B.y - C.y) + B.x * (C.y - y) + C.x * (y - B.y)) == 0;
	}
	void line(const point&);
	friend point middle(point&, point&);
private:
	double x, y;
};

class triangle {
public:
	triangle() {
		AB = AC = BC = 0;
	}
	triangle(double a, double b, double c, double d, double e, double f) {
		A.setPoint(a, b);
		B.setPoint(c, d);
		C.setPoint(e, f);
		AB = A.distance(B);
		AC = A.distance(C);
		BC = B.distance(C);
	}
	triangle(point& M, point& N, point& P) {
		A = M;
		B = N;
		C = P;
		AB = A.distance(B);
		AC = A.distance(C);
		BC = B.distance(C);
	}
	triangle(const triangle& T) {
		A = T.A;
		B = T.B;
		C = T.C;
		AB = T.AB;
		AC = T.AC;
		BC = T.BC;
	}
	~triangle() {}
	void setTriangle(double a, double b, double c, double d, double e, double f) {
		A.setPoint(a, b);
		B.setPoint(c, d);
		C.setPoint(e, f);
		AB = A.distance(B);
		AC = A.distance(C);
		BC = B.distance(C);
	}
	void setTriangle(point& M, point& N, point& P) {
		A = M;
		B = N;
		C = P;
		AB = A.distance(B);
		AC = A.distance(C);
		BC = B.distance(C);
	}
	void setA(point& P) {
		A = P;
		AB = A.distance(B);
		AC = A.distance(B);
	}
	void setB(point& P) {
		B = P;
		AB = A.distance(B);
		BC = B.distance(C);
	}
	void setC(point& P) {
		C = P;
		AC = A.distance(C);
		BC = B.distance(C);
	}
	point& getA() {
		return A;
	}
	point& getB() {
		return B;
	}
	point& getC() {
		return C;
	}
	double getAB() {
		return AB;
	}
	double getAC() {
		return AC;
	}
	double getBC() {
		return BC;
	}
	double cosA() {
		return (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
	}
	double sinA() {
		return sqrt(1 - pow(cosA(), 2));
	}
	double cosB() {
		return (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
	}
	double sinB() {
		return sqrt(1 - pow(cosB(), 2));
	}
	double cosC() {
		return (AC * AC + BC * BC - AB * AB) / (2 * AC * BC);
	}
	double sinC() {
		return sqrt(1 - pow(cosC(), 2));
	}
	friend istream& operator >>(istream&, triangle&);
	friend ostream& operator <<(ostream&, const triangle&);
	double perimeter() {
		return AB + AC + BC;
	}
	double area() {
		return abs(A.getx() * (B.gety() - C.gety()) + B.getx() * (C.gety() - A.gety()) + C.getx() * (A.gety() - B.gety())) / 2;
	}
	point center() {
		point center((A.getx() + B.getx() + C.getx()) / 3, (A.gety() + B.gety() + C.gety()) / 3);
		return center;
	}
	bool isSimilar(triangle&);
private:
	point A, B, C;
	double AB, AC, BC;
};
