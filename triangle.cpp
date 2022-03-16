#include <iostream>
#include <cmath>
#include "triangle.h"
using namespace std;

point point::operator +(point& B) {
	point C;
	C.x = x + B.x;
	C.y = y + B.y;
	return C;
}
point point::operator -(point& B) {
	point C;
	C.x = x - B.x;
	C.y = y - B.y;
	return C;
}
point point::operator *(double c) {
	point C;
	C.x = x * c;
	C.y = y * c;
	return C;
}
point point::operator /(double c) {
	point C;
	C.x = x / c;
	C.y = y / c;
	return C;
}
void point::operator +=(point& B) {
	x += B.x;
	y += B.y;
}
void point::operator -=(point& B) {
	x -= B.x;
	y -= B.y;
}
void point::operator *=(double c) {
	x *= c;
	y *= c;
}
void point::operator /=(double c) {
	x /= c;
	y /= c;
}
bool point::operator ==(point& B) {
	if (x == B.x && y == B.y) {
		return true;
	}
	else return false;
}
bool point::operator !=(point& B) {
	if (x == B.x && y == B.y) {
		return false;
	}
	else return true;
}
istream& operator >>(istream& i, point& A) {
	i >> A.x >> A.y;
	return i;
}
ostream& operator <<(ostream& o, const point& A) {
	o << "(" << A.x << ", " << A.y << ")\n";
	return o;
}
void point::line(const point& B) {
	double m, c;
	if (x - B.x == 0) {
		cout << "d: x = " << x;
	}
	else {
		m = (y - B.y) / (x - B.x);
		c = -m * x + y;
		if (!c) {
			cout << "y = " << m << "*x\n";
		}
		if (c > 0) {
			cout << "y = " << m << "*x+" << c << endl;
		}
		if (c < 0) {
			cout << "y = " << m << "*x" << c << endl;
		}
	}
}
point middle(point& A, point& B) {
	point C((A.x + B.x) / 2, (A.y + B.y) / 2);
	return C;
}

istream& operator >>(istream& i, triangle& T) {
	i >> T.A >> T.B >> T.C;
	T.AB = T.A.distance(T.B);
	T.AC = T.A.distance(T.C);
	T.BC = T.B.distance(T.C);
	return i;
}
ostream& operator <<(ostream& o, const triangle& T) {
	o << "A: " << T.A << "B: " << T.B << "C: " << T.C;
	o << "AB = " << T.AB << " AC = " << T.AC << " BC = " << T.BC << endl;
	return o;
}
bool triangle::isSimilar(triangle& T) {
	//using angle-angle theorem
	if (cosA() == T.cosA() && sinA() == T.sinA() && cosB() == T.cosB() && sinB() == T.sinB()) {
		return true;
	}
	if (cosA() == T.cosA() && sinA() == T.sinA() && cosB() == T.cosC() && sinB() == T.sinC()) {
		return true;
	}
	if (cosA() == T.cosB() && sinA() == T.sinB() && cosB() == T.cosA() && sinB() == T.sinA()) {
		return true;
	}
	if (cosA() == T.cosB() && sinA() == T.sinB() && cosB() == T.cosC() && sinB() == T.sinC()) {
		return true;
	}
	if (cosA() == T.cosC() && sinA() == T.sinC() && cosB() == T.cosA() && sinB() == T.sinA()) {
		return true;
	}
	if (cosA() == T.cosC() && sinA() == T.sinC() && cosB() == T.cosB() && sinB() == T.sinB()) {
		return true;
	}
	return false;
}
