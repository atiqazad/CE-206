#include<iostream>
#include<cmath>
using namespace std;

double f(double x) {
	return x*x*x*x - 3*x*x + 2*x - 10;
}
double g1(double x) {
	return (3*x*x + 10 - x*x*x*x);
}
double g1_prime(double x) {
	return (3*x - 2*x*x);//derivative of g1
}
double g2(double x) {
	return sqrt((x*x*x*x + 2*x - 10)/3.00);
}
double g2_prime(double x) {
	return (4*x*x*x + 2)/(6*g2(x));//derivative of g2
}
double g3(double x) {
	return pow((3*x*x-2*x+10), 1.00/4.00);
}
double g3_prime(double x) {
	return ((3*x-1)/(2*g3(x)*g3(x)*g3(x)));//derivative of g3
}
void successive_iteration(double a, double b, double error) {
	if(f(a)*f(b)>0) {
		cout << "There is no solution in the given range!";
	}
	else if(f(a)*f(b)==0) {
		cout<< (f(a)==0 ? a:b);
	}
	else {
		int choice;
		double x0 = (a+b)/2;
		
		if(fabs(g1_prime(x0))<1) {
			choice = 1;	
		}
		else if(fabs(g2_prime(x0))<1) {
			choice = 2;
		}
		else {
			choice = 3;
		}
		double e = fabs(a-b);
		double xn;

		while(e>error) {
			if(choice==1) xn = g1(x0);
			else if(choice==2) xn = g2(x0);
			else xn = g3(x0);
			e = fabs(xn-x0);
			x0 = xn;
		}
		cout << xn;
	}
}

int main() {
	successive_iteration(3, 1, .001);
}
