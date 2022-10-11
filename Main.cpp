#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

long double power(double, int);
long double quickPower(double, int);
long double recPower(double, int);
long double recQuickPower(double, int);


int powerCount = 0;
int quickPowerCount = 0;
int recPowerCount = 0;
int recQuickPowerCount = 0;


void main(void) {
	for (int i = 1; i <= 10; i++) {
		double randx = 0.01 + (rand() % 50) + ((rand() % 100) / 100);
		int randn = 1 + (rand() % 100);
		cout << "power: " << power(randx, randn) << "		Number of steps: " << powerCount << endl;
		cout << "quickPower: " << quickPower(randx, randn) << "		Number of steps: " << quickPowerCount << endl;
		cout << "recPower: " << recPower(randx, randn) << "		Number of steps: " << recPowerCount << endl;
		cout << "recQuickPower: " << recQuickPower(randx, randn) << "	Number of steps: " << recQuickPowerCount << endl;
		cout << "cmath power: " << pow(randx, randn) << endl;
		cout << "" << endl;
		powerCount = 0;
		quickPowerCount = 0;
		recPowerCount = 0;
		recQuickPowerCount = 0;
	}
}
//Висновок: ітераривні та рекусивні методи однакові за швидкістю

long double power(double x, int n) {
	long double res = 1;
	for (int i = 1; i <= n; ++i) {
		powerCount++;
		res *= x;
	}
	return res;
}


long double quickPower(double x, int n) {
	long double res = 1;
	while (n > 0)
	{
		quickPowerCount++;
		if (n % 2 == 1) {
			res *= x;
		}
		x *= x;
		n = n / 2;
	}
	return res;
}

long double recPower(double x, int n) {
	if (n == 0) {
		return 1;
	}
	recPowerCount++;
	return x * recPower(x, n - 1);
}

long double recQuickPower(double x, int n) {
	if (n != 0)
	{
		if (n % 2)
		{
			recQuickPowerCount++;
			return (x * recQuickPower(x * x, n / 2));
		}
		else
		{
			recQuickPowerCount++;
			return (recQuickPower(x * x, n / 2));
		}

	}
	else
	{
		return 1;
	}
}