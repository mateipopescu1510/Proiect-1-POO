#include <iostream>
#include "triangle.h"
using namespace std;

int main() {
	cout << "\n----------------POINT CLASS-----------------\n\n";
	point A;
	cout << "Operator \"<<\" prints (x, y)\n\nDefault point constructor: " << A;
	point B(134, 1);
	cout << "Parameterized constructor: " << B;
	point C(B);
	cout << "Copy constructor:\n" << C;
	point D = C;
	cout << D;
	D.setPoint(10, -8);
	cout << "\nsetPoint(10, -8): " << D;
	cout << "\nget x coordinate: " << D.getx() << "\nget y coordinate: " << D.gety() << "\n";
	point E;
	cout << "\nOperator \">>\" takes two real x and y coordinates\nInput: ";
	cin >> E;
	cout << "Output: " << E;
	cout << "\nAll operators:\nInput A: ";
	cin >> A;
	cout << "Input B: ";
	cin >> B;
	cout << "\nA + B = " << A + B;
	cout << "A - B = " << A - B;
	A += B;
	cout << "A += B => A = " << A;
	A -= B;
	cout << "A -= B => A = " << A;
	cout << "\nInput constant: ";
	double c;
	cin >> c;
	cout << "\nA * c = " << A * c;
	cout << "A / c = " << A / c;
	A *= c;
	cout << "A *= c => A = " << A;
	A /= c;
	cout << "A /= c => A = " << A;
	C.setPoint(5, -1);
	cout << "\nA: " << A << "B: " << B << "C: " << C;
	cout << "\nMiddle point of A and B: " << middle(A, B);
	cout << "Distance from A to B = " << A.distance(B);
	cout << "\n\nAre A, B and C collinear?: " << A.collinear(B, C);
	cout << "\nAB line equation: ";
	A.line(B);

	cout << "\n---------------TRIANGLE CLASS---------------\n\n";

	cout << "Operator \"<<\" prints each point and distances between them calculated with X.distance(Y)\n";
	cout << "Operator \">>\" takes x and y for 3 points of the new triangle: ";
	triangle R;
	cin >> R;
	cout << R;

	triangle T;
	cout << "\nDefault triangle constructor sets the points to (0, 0):\n" << T;

	point X(-2, 3), Y(2, 2), Z(-1, -2);
	triangle S(1, 2, -3, 4, 5, -6), U(X, Y, Z);
	cout << "\nTwo parameterized constructors:\n";
	cout << "S(1, 2, -3, 4, 5, -6):\n" << S << "\nU(X, Y, Z):\n" << U;

	triangle V(U);
	cout << "\nCopy constructor (triangle V(U)):\n" << V;

	T.setTriangle(-2, 1, 5, 4, 4, -3);
	cout << "\nsetTriangle works like the two constructors:\n";
	cout << "\nT.setTriangle(-2, 1, 5, 4, 4, -3):\n" << T;

	T.setTriangle(X, Y, Z);
	cout << "\nT.setTriangle(X, Y, Z):\n" << T;

	X.setPoint(10, 10);
	T.setC(X);
	cout << "\nTriangle's point setters must also update the distances:\n";
	cout << "X.setPoint(10, 10); T.setC(X) =>\n" << T;

	cout << "\nPoint getters return one of the triangle's points, T.getB(): " << T.getB();
	cout << "\nDistance getters return one of the triangle's line's distance, T.getAC(): " << T.getAC();
	cout << "\n\nTrigonometric getters cos and sin for an angle of the triangle:\n";
	cout << "T.cosA(): " << T.cosA() << "\nT.sinA(): " << T.sinA();
	cout << "\npow(T.cosA(), 2) + pow(T.sinA(), 2) = " << pow(T.cosA(), 2) + pow(T.sinA(), 2);

	cout << "\n\nPerimeter: " << T.perimeter();
	cout << "\nArea: " << T.area();
	cout << "\nTriangle's center point: " << T.center();

	V.setTriangle(-2, 2, 6, -2, 4, 4);
	triangle W(-3, 1, -2, -2, 1, -1);

	cout << "\nTriangle V:\n" << V;
	cout << "\nTriangle W:\n" << W;
	cout << "\nAre V and W similar?: " << V.isSimilar(W) << endl;

	X.setPoint(1, 0);
	W.setC(X);
	cout << "\nTriangle V:\n" << V;
	cout << "\nTriangle W (with an altered point value):\n" << W;
	cout << "\nAre V and W similar?: " << V.isSimilar(W) << endl;
	while (1) {

	}
	return 0;
}
