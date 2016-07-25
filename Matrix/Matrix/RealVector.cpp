//
//  RealVector.cpp
//  
//
//  Created by Manouchehr Sanei on 7/24/16.
//
//

#include "RealVector.h"


// default constructor
RealVector::RealVector() {
    
    //create a dynamic array
    n = 0;
    elements = new double[n];
    
}

// constructor with the size
RealVector::RealVector(int size){

    //create a dynamic array
    n = size;
    elements = new double[n];
    
}

// copy constructor
RealVector::RealVector(const RealVector &v){
    
    n = v.n;
    elements = new double[n];
    for (int i = 0; i < n; i++){
        elements[i]=v. elements[i];
    }
    
}

// destructor
RealVector::~RealVector(){
    
    delete [] elements;    
    
}

// overloaded operator =
RealVector& RealVector::operator = (const RealVector& v){
    
    n = v.n;
    elements = new double[n];
    for (int i = 0; i < n; i++){
        elements[i]=v. elements[i];
    }
    
    return * this;
}

// access methods get
void RealVector::GetElement(int i, double &element){
    
    if(i > n){
        std::cout<< "trying to access and element out of the range" << std::endl;
        return;
        
    }
    element = elements[i];
    
}

// access methods set
void RealVector::SetElement(int i, double element){
    
    if(i > n){
        std::cout<< "trying to access and element out of the range" << std::endl;
        return;
        
    }
    elements[i] = element;
}

// overloaded operator ==
bool RealVector::operator == (RealVector& vrhs){
    
    // check the size
    if(this->size() != vrhs.size()){
        return false;
    }
    
    double a,b;
    // check each element
    for(int i =0; i < n; i++){
        this->GetElement(i,a);
        vrhs.GetElement(i,b);
        
        // check the element
        if(a != b){
            return false;
        }
    }
    
    return true;
}

// overloaded operator * inner product of two RealVectors
double RealVector::operator * (RealVector& vrhs){
    
    bool IsEqualSizeQ = this->size() == vrhs.size();
    if(!IsEqualSizeQ){
        return -1.0;
    }
    
    double dot_val = 0.0;
    double a,b;
    // check each element
    for(int i =0; i < n; i++){
        this->GetElement(i,a);
        vrhs.GetElement(i,b);
        dot_val += a*b;
    }
    dot_val = sqrt(dot_val);
    return dot_val;
}

// overloaded operator * substraction of two RealVectors
RealVector RealVector::operator *= (double alpha){
    
    double a;
    // check each element
    for(int i =0; i < this->size(); i++){
        this->GetElement(i,a);
        a *= alpha;
        this->SetElement(i,a);
    }
    return *this;
    
}

// overloaded operator * sum of two RealVectors
RealVector RealVector::operator + (RealVector& vrhs){

    RealVector temp(0);
    
    bool IsEqualSizeQ = this->size() == vrhs.size();
    if(!IsEqualSizeQ){
        return temp;
    }
    
    temp.resize(this->size());
    
    double sum_val = 0.0;
    double a,b;
    // check each element
    for(int i =0; i < n; i++){
        this->GetElement(i,a);
        vrhs.GetElement(i,b);
        sum_val = a+b;
        temp.SetElement(i, sum_val);
    }
    return temp;
    
}

// overloaded operator * sum of two RealVectors
RealVector RealVector::operator - (RealVector& vrhs){
    
    RealVector temp(0);
    
    bool IsEqualSizeQ = this->size() == vrhs.size();
    if(!IsEqualSizeQ){
        return temp;
    }
    
    temp.resize(this->size());

    
    double su_val = 0.0;
    double a,b;
    // check each element
    for(int i =0; i < n; i++){
        this->GetElement(i,a);
        vrhs.GetElement(i,b);
        su_val = a-b;
        temp.SetElement(i, su_val);
    }
    return temp;
    
}

// norm of the RealVector
double RealVector::norm(){
    
    double norm_val = *this * *this;
    return norm_val;
}

// total sum of elements in the RealVector
double RealVector::total(){
    
    double total = 0.0;
    double a;
    // check each element
    for(int i =0; i < n; i++){
        this->GetElement(i,a);
        total += a;
    }
    return total;
}

// push a new element
void RealVector::push_back(double element){
    
    int current_size = this->size();
    this->resize(current_size+1);
    elements[current_size] = element;
}

// push a new element
void RealVector::pop_back(){
    
    int current_size = this->size();
    this->resize(current_size-1);
    
}

// returns the number of elements
int RealVector::size() const{
    
    return n;
}

// changes the size of array
void RealVector::resize(int new_size){
    
    if(new_size == n){
        return;
    }
    
    if(new_size > n){
        
        double *resizeElements = new double[new_size];
        for (int i = 0; i < n; i++)
        {
            resizeElements[i] = elements[i];
        }
        delete [] elements;
        elements = resizeElements;
        
        int last_of = new_size - n;
        for(int i = 0; i < last_of; i++ ){
            elements[i+n] = 0.0;
        }
        n = new_size;
        return;
    }
    
    if(new_size < n){
        
        double *resizeElements = new double[new_size];
        for (int i = 0; i < new_size; i++)
        {
            resizeElements[i] = elements[i];
        }
        delete [] elements;
        elements = resizeElements;
        n = new_size;
        return;
    }
    
}

// overload << operator
ostream& operator << (ostream& out, RealVector& v){
    
    double a;
    out << std::endl;
    out << "n = " << v.size() << std::endl;
    for(int i = 0; i < v.size(); i++){
        v.GetElement(i, a);
        out << a << std::endl;
    }
    return out;
}
