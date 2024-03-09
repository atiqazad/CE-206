#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
/*
	It’s merely a comment, please don’t get daunted by this. Remove it if you want
	
	These will help in forming transcendental function in C++:
	
	i) exp(2) == e^2; 
	ii) log(2) == ln(2) [e-based log]
	iii) log10(2) [10-based log]
	iv) log2(10) [2-based log]
	v) log(a)/log(b) == logb(a) [b-based log of a]
	vi) acos(-1) == cos^-1(-1) == 3.14159radian == 180degrees
	vii) sqrt(49) == 7 [square root]
	viii) cbrt(8) == 2 [cubic root]
	ix) pow(4, 0.5) == 4^(0.5) == 2 [pow(base, power)]
	
	go to these links to learn more: 1.https://www.w3schools.com/cpp/cpp_math.asp
								     2.https://cplusplus.com/reference/cmath/
*/
void swap(double &a, double &b) {
	//a = 5, b = 3[say]
	a = a + b;//a = a + b = 5 + 3 = 8
	b = a - b;//b = a - b = 8 - 3 = 5
	a = a - b;//a = a - b = 8 - 5 = 3
}
double f(double x) {
	return x*x*x*x - 3*x*x + 2*x - 10;
}

//same as bisection only the formula is different
void regula_falsi(double xl, double xr, double error) {
	if(f(xl)*f(xr)>0) {
		cout << "There is no solution in the given range!";
	}
	else if(f(xl)*f(xr)==0) {
		cout << (f(xl)==0 ? xl:xr);
	}
	else {
		if(f(xl)>0) {
			swap(xl, xr);
		}
		cout << "   xl\t\t\t   xr\t\t\t   f(xl)\t\t  error\n";
		double e = fabs(xl-xr);
		double xc;
		while(e>error) {
			cout << fixed << setprecision(6) << xl << "\t\t" << xr << "\t\t" << f(xl) << "\t\t" << e << endl;
			xc = (xl*f(xr) - xr*f(xl)) / (f(xr) - f(xl));
			e = fabs(xl-xc);
			xl = xc;
		}
		cout << fixed << setprecision(6) << xl << "\t\t" << xr << "\t\t" << f(xl) << "\t\t" << e << endl;
		cout <<"\n\nHence the solution is: "<< xc;
	}
}

int main() {
	regula_falsi(-1, -3, .00001);
}
