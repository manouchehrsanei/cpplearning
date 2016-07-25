
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "RealVector.h"
#include "Vector.h"


double SinIntegral(double a, double b, int n){
    
    RealVector f;
    RealVector integral;
    double dx = (b-a)/double(n);
    double f_val,x_val;
    for(int i = 1; i <= n; i++){
        x_val = double(i)*dx;
        f_val = sin(x_val);
        f.push_back(f_val);
    }
    integral =f;
    integral *= dx;
    return integral.total();
}

template< class T >
Vector< Vector<T> >  Matrix(long m, long n, const T & asshole);


int main()
{
    
    
    double sin_int = SinIntegral(0.0,M_PI,1000);
    std::cout << "Integral value using riemman = " << sin_int << std::endl;
    
    std::complex<double> z = 1i* 1i;
    Vector< Vector< std::complex<double> > > A;
    
    A = Matrix(10, 40, z);
    std::cout << "A = " << A << std::endl;
    
    return 0;
}

template< class T >
Vector< Vector<T> >  Matrix(long m, long n, const T & asshole){
    
    Vector<T> col(m,asshole);
    Vector< Vector<T> > matrix(n,col);
    return matrix;
}