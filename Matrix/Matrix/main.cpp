
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include "RealVector.h"
#include "Vector.h"
#include "Tensor.h"


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


void IntegralMain(){
    
    double sin_int = SinIntegral(0.0,M_PI,1000);
    std::cout << "Integral value using riemman = " << sin_int << std::endl;
}

void VectorMain(){
    
    int n = 10;
    double z = 1.0;
    Vector< double > v(n,z);
    std::cout << v <<std::endl;

}

int main()
{
    
    Tensor< double > a(1,0,2.0);
    Tensor< double > b(1,0,2.0);
    
    Tensor< Tensor< double > > a_v(10,1,a);
    Tensor< Tensor< double > > b_v(10,1,b);

    std::cout<< "rank = " << a_v.rank() << std::endl;
    std::cout<< "inner = " << a*b << std::endl;
    std::cout<< "inner = " << a_v*b_v << std::endl;

    
    int shit = 0;
    return 0;
}
