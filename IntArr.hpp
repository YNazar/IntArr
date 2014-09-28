#ifndef INTSTR_H_INCLUDED
#define INTSTR_H_INCLUDED
#include <iostream>
class Intstr
{
public:
    Intstr();
    explicit Intstr(size_t ins);
    Intstr ( const int *arr,size_t sz);
    ~Intstr(){delete [] arr;}
    Intstr(const Intstr &rhs);
    Intstr operator=(const Intstr& rhs);
    void printarr();
     void scanstr();
    size_t  get_size () const;
    int&  operator [] (size_t idx);
    const int& operator[](size_t idx)const;
    Intstr  operator+ (const Intstr& rhs);
    void operator+=(const Intstr&rhs);
    const int* get_arr()const {return arr;};
    void  dltelmt( int a);
    void  findelm(int a, size_t &number)const;
private:
    size_t siz;
    int *arr;
    void resiz(size_t newsiz);
};

#endif // INTSTR_H_INCLUDED
