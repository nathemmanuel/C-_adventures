#include <iostream>
using namespace std;

void solveMesh(double current[2][2], double voltage[2]);

/**
 * main - calls the solveMesh function
 * and prints the circuit parameters
 *
 * Return: 0(success)
 */
int main(void)
{
	double current[2][2] = {
		{18, -12},
		{-12, 24}
	}, voltage[2] = {12, -8};

	cout << "The circuit parameters are:\n" << endl;
	cout << "In Mesh 1:\n" << endl;
	cout << "R1 = 2-Ohms\nR2 = 4-Ohms\nV1 = 12-Volts\n" << endl;
	cout << "In Mesh 1-2:\nR4 = 12-Ohms\n\n" << endl;
	cout << "In Mesh 2:" << endl;
	cout << "R5 = 9-Ohms\nR6 = 3-Ohms\nV2 = 8-Volts\n" << endl;

	cout << "On analysing the circuit using mesh analysis"
		<< " the results are:" << endl;
	solveMesh(current, voltage);
	return (0);
}

/**
 * solveMesh - This solves the matrix form of
 * the mesh analysis simultaneous equations
 * @current: This is the array that accepts
 * the coefficients of i(1) and i(2)
 * @voltage: Takes the one-dimensional voltage
 * matrix
 *
 * Return: Void
 */

void solveMesh(double current[2][2], double voltage[2])
{
	double curOne, curTwo, det;

	det = ((current[0][0] * current[1][1])
			- (current[1][0] * current[0][1]));

	curOne = ((voltage[0] * current[1][1])
			- (voltage[1] * current[0][1]));
	curOne /= det;

	curTwo = ((current[0][0] * voltage[1])
				- (current[1][0] * voltage[0]));
	curTwo /= det;

	cout << "Current I1 = " << curOne << "A" << endl;
	cout << "Current I2 = " << curTwo << "A" << endl;
}
