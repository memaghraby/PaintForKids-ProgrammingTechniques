#include "Function.h"

double Area(int X1, int X2, int X3, int Y1, int Y2, int Y3)
{
	return abs(X1*(Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2)) / 2.0;
}
