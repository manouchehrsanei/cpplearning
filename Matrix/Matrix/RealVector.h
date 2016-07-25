//
//  RealVector.h
//  
//
//  Created by Manouchehr Sanei on 7/24/16.
//
//

#ifndef ____RealVector__
#define ____RealVector__

#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class RealVector{
    
public:
    
    // default constructor
    RealVector();
    
    // constructor with the size
    RealVector(int size);
    
    // copy constructor
    RealVector(const RealVector &v);
    
    // destructor
    ~RealVector();
    
    // overloaded operator =
    RealVector& operator = (const RealVector& v);
    
    // overloaded operator ==
    bool operator == (RealVector& vrhs);
    
    // overloaded operator * sum of two RealVectors
    RealVector operator + (RealVector& vrhs);
    
    // overloaded operator * substraction of two RealVectors
    RealVector operator - (RealVector& vrhs);
    
    // overloaded operator * substraction of two RealVectors
    RealVector operator *= (double alpha);
    
    // overloaded operator * inner product of two RealVectors
    double operator * (RealVector& vrhs);
    
    // access methods get
    void GetElement(int i, double &element);
    
    // access methods set
    void SetElement(int i, double element);
    
    // push a new element
    void push_back(double element);
    
    // push a new element
    void pop_back();
    
    // returns the number of elements
    int size() const;
    
    // changes the size of array
    void resize(int new_size);
    
    // overload << operator
    friend ostream& operator << (ostream& out, RealVector& v);
    
    // norm of the RealVector
    double norm();
    
    // total sum of elements in the RealVector
    double total();
    
private:
    
    // pointer that points to double array
    double *elements;
    
    // number of elements
    int n;
    
};


#endif /* defined(____RealVector__) */
