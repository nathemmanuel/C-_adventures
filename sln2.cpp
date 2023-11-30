#include <iostream>
using namespace std;

void solveEqn(double varArr[3][3], double curArray[3]);
/**
 * main - calls the solveEqn function
 *
 * Return: 0(successful)
 */
int main(void)
{
	cout << "This program uses nodal analysis "
		<< "to solve the second question "
		<< "in assignment 1.\n\n" << endl;
	cout << "The parameters given were:\n"
		<< "R1 = " << 2 << " Ohms\n"
		<< "R2 = " << 4 << " Ohms\n"
		<< "R3 = " << 8 << " Ohms\n"
		<< "R4 = " << 4 << " Ohms\n\n"
		<< "The independent current source: "
		<< 3 << " Amps\n"
		<< "The dependent current source: "
		<< "2Ix" << " where Ix is the current through "
		<< "the 2-ohm resistor" << endl;

	double myArray[3][3] = {{3, 4, 6}, {-2, -7, -9}, {-1, 1, 3}};
	double currentArr[3] = {12, 0, 0};
	solveEqn(myArray, currentArr);
			
	return (0);

}

/**
 * solveEqn - solves the matrix equation
 * @varArr: This is the array that accepts
 * the coefficient values for the resistance
 * @curArray: This is the array that accepts
 * the coefficient values for the current
 *
 * Return: Void
 */
void solveEqn(double varArr[3][3], double curArray[3])
{
	double a, b, c, d,
	      e, f, g, h, i;
	a = varArr[0][0];
	b = varArr[0][1];
	c = varArr[0][2];
	d = varArr[1][0], e = varArr[1][1],
	f = varArr[1][2], g = varArr[2][0],
	h = varArr[2][1], i = varArr[2][2];

	double det, v1_det, v2_det, v3_det;

	 /*
         * a    d       g	curArray[0]
         * b    e       h	curArray[1]
         * c    f       i	curArray[2]
         */

	/* To calculate the normal determinant */
	det = (a * ((e * i) - (f * h)))
		- (d * ((b * i) - (c * h)))
		+ (g * ((b * f) - (c * e)));
	/* To calculate V1 */
	v1_det = (curArray[0] * ((e * i) - (f * h)))
		- (d * ((curArray[1] * i) - (curArray[2] * h)))
		+ (g * ((curArray[1] * f) - (curArray[2] * e)));
	v1_det /= det;
	/* To calculate V2 */
	v2_det = (a * ((curArray[1] * i) - (curArray[2] * h)))
		- (curArray[0] * ((b * i) - (c * h)))
		+ (g * ((b * curArray[2]) - (c * curArray[1])));
	v2_det /= det;
	/* To calculate  v3 */
	v3_det = (a * ((e * curArray[2]) - (f * curArray[1])))
		- (d * ((b * curArray[2]) - (c * curArray[1])))
		+ (curArray[0] * ((b * f) - (c * e)));
	v3_det /= det;

	cout << "The voltage V1 is: " << v1_det << "V" << endl;
	cout << "The voltage V2 is: " << v2_det << "V" << endl;
	cout << "The voltage V3 is: " << v3_det << "V" << endl;
}
