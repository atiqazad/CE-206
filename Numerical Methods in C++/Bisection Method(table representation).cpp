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
	return x*x*x*x - 3*x*x + 2*x - 10;
}
void bisect(double xl, double xr, double error) {
	if(f(xl)*f(xr)>0) {
		cout << "There is no solution in the given range!";
	}
	else if(f(xl)*f(xr)==0) {
		cout << (f(xl)==0 ? xl:xr);
	}
	else {
		cout << "    xl\t\t\t    xr\t\t\t    xm\t\t\t  f(xm)\t\t\t error" << endl;
		double e = fabs(xr-xl);
		double xm;
		while(e>error) {
			xm = (xl+xr)/2;
			cout << fixed << setprecision(6) << xl << "\t\t" << xr << "\t\t" << xm << "\t\t" << f(xm) <<"\t\t" << e << endl;
			if(f(xl)*f(xm)>0) {
				xl = xm;
			}
			else xr = xm;
			
			e = fabs(xr-xl);
		}
		cout << fixed << setprecision(6) << xl << "\t\t" << xr << "\t\t" << xm << "\t\t" << f(xm) <<"\t\t" << e <<  endl;
		cout << "\n\nHence the solution is:\t" << xm;
	}
}

int main() {
	bisect(-3, -2, .0001);
}
