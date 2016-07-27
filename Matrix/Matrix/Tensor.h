//
//  Tensor.h
//  
//
//  Created by Manouchehr Sanei on 7/26/16.
//
//

#ifndef ____Tensor__
#define ____Tensor__

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>


template< class S >
class Tensor {
public:
    
    
    // default constructor
    Tensor();
    
    // constructor based on size
    Tensor(const long size, const long rank);
    
    // constructor based on size and constant object
    Tensor(const long size, const long rank, const S& copy);
    
    // constructor based on copy
    Tensor(const Tensor<S> &copy);
    
    // default destructor
    ~Tensor();
    
    // overladed assignement operator
    Tensor<S> & operator=(const Tensor<S> &t);
    
    // Rules for sum
    Tensor<S>  & operator+(const Tensor<S> &t);
    
    // Rules for sum
    Tensor<S>  & operator+=(const Tensor<S> &t);
    
    // Rules for sub
    Tensor<S>  & operator-(const Tensor<S> &t);
    
    // Rules for sub
    Tensor<S>  & operator-=(const Tensor<S> &t);
    
    // Rules for inner product
    double & operator*(const Tensor<S> &t);
    
    // overladed access [] operator
    S& operator[]( const long j ) const;
    
    
    template <class S2>
    friend std::ostream& operator<<( std::ostream& Out, const Tensor< S2 >& t );
    
    // push a new element
    void push_back(const S& t);
    
    // pop a new element
    void pop_back();
    
    void fill(const S& t, const long from=0, const long numelem=-1);
    
    long size() const { return m; }
    
    long rank() const { return k; }
    
    void resize(const long newsize);
    
    void resize(const long newsize,const S& object);
    
    void Print(std::ostream &out = std::cout);
    
    void zero();
    
    void clear();
    
protected:
    
    S* elements;
    long m;
    long k;
    
};

template< class S >
inline Tensor<S>::Tensor() : elements( 0 ), m( 0 ), k(-1)
{
    
}

template< class S >
Tensor<S>::Tensor( const long size , const long rank) : elements( 0 )
{
    
    if(rank == 0 ){
        m = 1;
        k = rank;
        elements = new S[ 0 ];        
        return;
    }
    
    if( size < 0 )
    {
        elements = new S[ 0 ];
    }
    
    
    if( size > 0 )
    {
        elements = new S[ size ];
    }
    
    m = size;
    k = rank;
}

template< class S >
Tensor<S>::Tensor( const long size, const long rank, const S & b ) : elements( 0 )
{
    
    if(rank == 0 ){
        m = 1;
        k = rank;
        elements = new S[ 1 ];
        elements[0] = b;
        return;
    }
    
    if( size < 0 )
    {
        elements = new S[ 0 ];
    }
    
    if( size > 0)
    {
        elements = new S[size];
    }
    
    m = size;
    k = rank;
    
    for( long j = 0; j < size; j++ )
    {
        elements[j] = b;
    }
}

template< class S >
Tensor<S>::Tensor(const Tensor<S> &copy){
    
    elements = 0;
    
    if( copy.m > 0 )
    {
        elements = new S[copy.m];
    }
    else{
        elements = 0;
    }
    
    for(long j=0; j<copy.m; j++){
        elements[j]=copy.elements[j];
    }
    
    m = copy.m;
    k = copy.k;
}


template<class S>
inline Tensor<S>::~Tensor() {
    if( elements )
    {
        delete [] elements;
    }
}

template<class S>
Tensor<S> & Tensor<S>::operator+(const Tensor<S> &t){
    
    Tensor<S> tensor;
    // first case when rank are equal
    if (this->rank() == t.rank()) {
        
        
        Tensor<S> Q = *this;
        switch (Q.rank()) {
            case 0:
            {
                tensor = Q[0]+t[0];
            }
                break;
            case 1:
            {
                 Tensor<S> tensor_temporal(t);
                for (long i = 0; i < Q.size(); i++) {
                    tensor_temporal[i] = Q[i]+t[i];
                }
                tensor = tensor_temporal;
                
            }
                break;
            case 2:
            {
                std::cout<< "not implemented" << std::endl;
            }
                break;
            default:
                break;
        }
        
        
    }
    return tensor;
    
}

template<class S>
Tensor<S> & Tensor<S>::operator+=(const Tensor<S> &t){
    
    Tensor<S> Q = *this;
    // first case when rank are equal
    if (this->rank() == t.rank()) {

        switch (Q.rank()) {
            case 0:
            {
                Q[0] = Q[0]+t[0];
            }
                break;
            case 1:
            {
                for (long i = 0; i < Q.size(); i++) {
                    Q[i] = Q[i]+t[i];
                }
                
            }
                break;
            case 2:
            {
                std::cout<< "not implemented" << std::endl;
            }
                break;
            default:
                break;
        }
        
        
    }
    *this = Q;
    return *this;
    
}

template<class S>
Tensor<S> & Tensor<S>::operator-(const Tensor<S> &t){
    
    Tensor<S> tensor;
    // first case when rank are equal
    if (this->rank() == t.rank()) {
        
        
        Tensor<S> Q = *this;
        switch (Q.rank()) {
            case 0:
            {
                tensor = Q[0]-t[0];
            }
                break;
            case 1:
            {
                Tensor<S> tensor_temporal(t);
                for (long i = 0; i < Q.size(); i++) {
                    tensor_temporal[i] = Q[i]-t[i];
                }
                tensor = tensor_temporal;
                
            }
                break;
            case 2:
            {
                std::cout<< "not implemented" << std::endl;
            }
                break;
            default:
                break;
        }
        
        
    }
    return tensor;
    
}

template<class S>
Tensor<S> & Tensor<S>::operator-=(const Tensor<S> &t){
    
    Tensor<S> Q = *this;
    // first case when rank are equal
    if (this->rank() == t.rank()) {
        
        switch (Q.rank()) {
            case 0:
            {
                Q[0] = Q[0]-t[0];
            }
                break;
            case 1:
            {
                for (long i = 0; i < Q.size(); i++) {
                    Q[i] = Q[i]-t[i];
                }
                
            }
                break;
            case 2:
            {
                std::cout<< "not implemented" << std::endl;
            }
                break;
            default:
                break;
        }
        
        
    }
    *this = Q;
    return *this;
    
}

template<class S>
double & Tensor<S>::operator*(const Tensor<S> &t){
    
    double inner_product = 0.0;
    // first case when rank are equal
    if (this->rank() == t.rank()) {
        

        Tensor<S> Q = *this;
        switch (Q.rank()) {
            case 0:
            {
                inner_product += Q[0]*t[0];
            }
            break;
            case 1:
            {
                for (long i = 0; i < Q.size(); i++) {
                    inner_product += Q[i]*t[i];
                }
            }
                break;
            case 2:
            {
                std::cout<< "not implemented" << std::endl;
            }
                break;
            default:
                break;
        }
     

    }
    
    return inner_product;
}

template< class S >
Tensor<S> &Tensor<S>::operator=(const Tensor<S> &t){

    if(this == &t) return *this;
    
    resize(t.size());
    
    for(long j=0; j<t.m; j++){
        elements[j]=t.elements[j];
    }
    m = t.size();
    k = t.rank();
    
    return *this;
}

template< class S >
S& Tensor<S>::operator[]( const long j ) const
{
    if( j < 0 || j >= m )
    {
        std::cout << " trying to acess element out of range.";
        std::cout << " m = " << size() << std::endl;
        std::cout << " j = " << j << std::endl;
    }
    return elements[ j ];
}

template< class S >
void Tensor<S>::push_back(const S &t){
    
    int current_size = this->size();
    this->resize(current_size+1);
    elements[current_size] = t;
}

template< class S >
void Tensor<S>::pop_back(){
    
    int current_size = this->size();
    this->resize(current_size-1);
    
}

template< class S >
void Tensor<S>::resize(const long newsize,const S& object) {
    
    if(newsize<0) {
        std::cout << "trying to define the suitable range" << std::endl;
        return;
    }
    
    if(newsize == m) {
        return;
    }
    
    S* newstore;
    if(newsize) newstore = new S[newsize];
    else newstore = 0;
    long large = (m < newsize) ? m : newsize;
    long j;
    for(j=0L; j<large; j++) {
        newstore[j] = elements[j];
    }
    for(;j<newsize;j++) {
        newstore[j] = object;
    }
    if(elements) {
        delete[] elements;
        elements = 0;
    }
    elements = newstore;
    m = newsize;
}

#include <limits>

template< class S >
void Tensor<S>::resize(const long newsize) {
    
    if(newsize<0) {
        std::cout << "trying to define the suitable range" << std::endl;
        return;
    }
    
    if(newsize == m) return;
    if (newsize == 0) {
        m = 0;
        delete[] elements;
        elements = 0;
        return;
    }
    S *newstore = new S[newsize];
    long large = (m < newsize) ? m : newsize;
    long j;
    for(j=0L; j<large; j++) {
        newstore[j] = elements[j];
    }
    if(elements) delete[] elements;
    elements = newstore;
    m = newsize;
}

template<class S>
void Tensor<S>::clear()
{
    this->resize(0);
}

template<class S>
void Tensor<S>::zero()
{
    for (long i = 0; i < this->size(); i++) {
        elements[i].clear();
    }
}


template< class S >
void Tensor<S>::fill(const S& copy, const long from, const long numelem){
#ifndef NODEBUG
    if(numelem<0 && numelem != -1) {
        std::cout << "Tensor::Fill" << std::endl
        << "It's negative parameter numelem, then numelem = "
        << m << std::endl;
        
        std::cout.flush();
    }
#endif
    
    long first = (from < 0) ? 0 : from;
    long nel = numelem;
    first = (first > m) ? m : first;
    if (nel < 0) nel = m;
    long last = (from+nel > m) ? m : from+nel;
    
    for(long j=first; j<last; j++)
        elements[j] = copy;
}

template< class S >
inline void Tensor<S>::Print(std::ostream &out)
{
    out << std::endl << "Number of elements = " << m;
}

template <class S>
std::ostream& operator<<( std::ostream& Out, const Tensor< S >& t )
{
    int space = int(Out.width());
    const char* sep = ( space == 0 ? ", " : "" );
    
    long size = t.size();
    
    if(size) {
        Out << std::setw(space) << t.elements[0];
    }
    
    for( long j = 0; j < size; j++ )
    {
        Out << std::setw( space ) << sep << t.elements[ j ];
    }
    
    Out << std::endl;
    return Out;
}


#endif /* defined(____Tensor__) */
