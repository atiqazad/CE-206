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

double f(double x) {
	return x*x*x + 2*x*x + 10*x - 20;
}
double f_prime(double x) {
	return 3*x*x + 4*x + 10; //derivative of f
}

double newton_raphson(double xn, double error) {
	
	if(f(xn)==0) return xn;
	else {
		cout << "   x_n\t\t\t x_n+1\t\t\t f(x_n+1)\t\t  error\n";
		double xn_1 = xn - (f(xn)/f_prime(xn));
		double e = fabs(xn_1-xn);
		cout << fixed << setprecision(6) << xn << "\t\t" << xn_1 << "\t\t" << f(xn_1) << "\t\t" << e << endl;
		while(e>error) {
			cout << fixed << setprecision(6) << xn << "\t\t" << xn_1 << "\t\t" << f(xn_1) << "\t\t" << e << endl;
			xn = xn_1;
			xn_1 = xn_1 - (f(xn_1)/f_prime(xn_1));
			e = fabs(xn_1-xn);
		}
		cout << fixed << setprecision(6) << xn << "\t\t" << xn_1 << "\t\t" << f(xn_1) << "\t\t" << e << endl;
		return xn_1;
	}	
}

int main() {
	cout <<"\n\nHence the solution is:\t"<< newton_raphson(-1, .001);
}
