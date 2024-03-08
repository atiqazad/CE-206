#include<iostream>
#include<cmath>
using namespace std;

double f(double x) {
	return x*x*x*x - 3*x*x + 2*x - 10;
}
void secant(double x0, double x1, double error) {
	if(f(x0)*f(x1)>0) {
		cout << "There is no solution in the given range!";
	}
	else if(f(x0)*f(x1)==0) {
		cout<< (f(x0)==0 ? x0:x1);
	}
	else {
		double e = fabs(x1-x0);
		double xn;
		while(e>error) {
			xn = (x0*f(x1) - x1*f(x0)) / (f(x1) - f(x0));
			x0 = x1;
			x1 = xn;
			e = fabs(x1-x0);
		}
		cout << xn;
	}
}

int main() {
	secant(3, 2, .000001);
}
