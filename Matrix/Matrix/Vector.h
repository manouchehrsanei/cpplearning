//
//  Vector.h
//  
//
//  Created by Manouchehr Sanei on 7/24/16.
//
//

#ifndef ____Vector__
#define ____Vector__

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>


template< class T >
class Vector {
public:
    

    // default constructor
    Vector();

    // constructor based on size
    Vector(const long size);

    // constructor based on size and constant object
    Vector(const long size, const T& copy);
    
    // constructor based on copy
    Vector(const Vector<T> &copy);
    
    // default destructor
    ~Vector();
    
    // overladed assignement operator
    Vector<T> & operator=(const Vector<T> &v);

    // overladed access [] operator
    T& operator[]( const long i ) const;
    
    
    template <class T2>
    friend std::ostream& operator<<( std::ostream& Out, const Vector< T2 >& v );
    
    // push a new element
    void push_back(const T& v);
    
    // push a new element
    void pop_back();
    
    void fill(const T& v, const long from=0, const long numelem=-1);
    
    long size() const { return n; }

    void resize(const long newsize);
    
    void resize(const long newsize,const T& object);
    
    void Print(std::ostream &out = std::cout);

    void clear();
    
protected:

    T* elements;
    long n;
    
};

template< class T >
inline Vector<T>::Vector() : elements( 0 ), n( 0 )
{

}

template< class T >
Vector<T>::Vector( const long size ) : elements( 0 )
{

    if( size < 0 )
    {
        elements = new T[ 0 ];
    }
    
    
    if( size > 0 )
    {
        elements = new T[ size ];
    }
    
    n = size;
}

template< class T >
Vector<T>::Vector( const long size, const T& a ) : elements( 0 )
{

    if( size < 0 )
    {
        elements = new T[ 0 ];
    }
    
    if( size )
    {
        elements = new T[size];
    }
    
    n = size;
    
    for( long i = 0; i < size; i++ )
    {
        elements[i] = a;
    }
}

template< class T >
Vector<T>::Vector(const Vector<T> &copy){

    elements = 0;
    
    if( copy.n > 0 )
    {
        elements = new T[copy.n];
    }
    else{
        elements = 0;
    }

    for(long i=0; i<copy.n; i++){
        elements[i]=copy.elements[i];
    }
    
    n = copy.n;
}


template<class T>
inline Vector<T>::~Vector() {
    if( elements )
    {
        delete [] elements;
    }
}

template< class T >
Vector<T> &Vector<T>::operator=(const Vector<T> &v){
    if(this == &v) return *this;
    
    resize(v.size());
    
    for(long i=0; i<v.n; i++){
        elements[i]=v.elements[i];
    }
    n = v.size();
    
    return *this;
}

template< class T >
T& Vector<T>::operator[]( const long i ) const
{
    if( i < 0 || i >= n )
    {
        std::cout << " trying to acess element out of range.";
        std::cout << " n = " << size() << std::endl;
        std::cout << " i = " << i << std::endl;
    }
    return elements[ i ];
}

template< class T >
void Vector<T>::push_back(const T &v){
    
    int current_size = this->size();
    this->resize(current_size+1);
    elements[current_size] = v;
}

template< class T >
void Vector<T>::pop_back(){
    
    int current_size = this->size();
    this->resize(current_size-1);
    
}

template< class T >
void Vector<T>::resize(const long newsize,const T& object) {

    if(newsize<0) {
        std::cout << "AHFEM" << std::endl;
        return;
    }

    if(newsize == n) {
        return;
    }
    
    T* newstore;
    if(newsize) newstore = new T[newsize];
    else newstore = 0;
    long large = (n < newsize) ? n : newsize;
    long i;
    for(i=0L; i<large; i++) {
        newstore[i] = elements[i];
    }
    for(;i<newsize;i++) {
        newstore[i] = object;
    }
    if(elements) {
        delete[] elements;
        elements = 0;
    }
    elements = newstore;
    n = newsize;
}

#include <limits>

template< class T >
void Vector<T>::resize(const long newsize) {

    if(newsize<0) {
        std::cout << "AHFEM" << std::endl;
        return;
    }
    
    if(newsize == n) return;
    if (newsize == 0) {
        n = 0;
        delete[] elements;
        elements = 0;
        return;
    }
    T *newstore = new T[newsize];
    long large = (n < newsize) ? n : newsize;
    long i;
    for(i=0L; i<large; i++) {
        newstore[i] = elements[i];
    }
    if(elements) delete[] elements;
    elements = newstore;
    n = newsize;
}

template<class T>
void Vector<T>::clear()
{
    this->resize(0);
}


template< class T >
void Vector<T>::fill(const T& copy, const long from, const long numelem){
#ifndef NODEBUG
    if(numelem<0 && numelem != -1) {
        std::cout << "Vector::Fill" << std::endl
        << "It's negative parameter numelem, then numelem = "
        << n << std::endl;
        
        std::cout.flush();
    }
#endif
    
    long first = (from < 0) ? 0 : from;
    long nel = numelem;
    first = (first > n) ? n : first;
    if (nel < 0) nel = n;
    long last = (from+nel > n) ? n : from+nel;
    
    for(long i=first; i<last; i++)
        elements[i] = copy;
}

template< class T >
inline void Vector<T>::Print(std::ostream &out)
{
    out << std::endl << "Number of elements = " << n;
}

template <class T>
std::ostream& operator<<( std::ostream& Out, const Vector< T >& v )
{
    std::streamsize width = Out.width();
    
    const char* sep = ( width == 0 ? ", " : "" );
    
    long size = v.size();
    
    if(size) Out << std::setw(width) << v.elements[0];
    
    for( long ii = 1; ii < size; ii++ )
    {
        Out << std::setw( width ) << sep << v.elements[ ii ];
    }
    Out << std::endl;
    return Out;
}

inline std::ostream& operator<<( std::ostream& Out, const Vector< std::pair<double,double> >& v )
{
    
    Out << "{";
    
    long size = v.size();
    
    if(size > 0)
    {
        for( long ii = 0; ii < size; ii++ )
        {
            Out << "{" << v[ii].first << ',' << v[ii].second << "}";
            if( ii < size-1) Out << ",";
        }
    }
    
    Out << "}";
    return Out;
}


inline std::ostream &operator<<(std::ostream &out, const std::pair<int,int> &element)
{
    out << element.first << "|" << element.second;
    return out;
}


#endif /* defined(____Vector__) */
