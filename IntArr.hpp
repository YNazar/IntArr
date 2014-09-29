#ifndef INTSTR_H_INCLUDED
#define INTSTR_H_INCLUDED
#include <iostream>
class Intarr
{
public:
    Intarr();
    explicit Intarr(size_t ins);
    Intarr ( const int *arr,size_t sz);
    ~Intarr(){delete [] arr;}
    Intarr(const Intarr &rhs);
    Intarr operator=(const Intarr& rhs);
    void printarr();
     void scanstr();
    size_t  get_size () const;
    const int* get_arr()const {return arr;};
    int&  operator [] (size_t idx);
    const int& operator[](size_t idx)const;
    void operator+=(const Intarr&a);
    void operator*=(const Intarr&a);
    void operator+=(int x);
    void operator*=(int x);
    void  dltelmt( int a);
    void  findelm(int a, size_t &number)const;
private:
    int *arr;
     size_t siz;
     size_t reserv;
    void resiz(size_t newsiz);
};
Intarr  operator+ (const Intarr& a,const Intarr& b);
Intarr operator+(const Intarr& a,int x);
Intarr operator* (const Intarr& a,const Intarr& b);
Intarr operator* (const Intarr& a,int x);
#endif // INTSTR_H_INCLUDED
