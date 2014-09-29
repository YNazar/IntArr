#include "IntStr.h"
#include <iostream>
#include <limits>
using  namespace std;
Intarr::Intarr():arr(0),siz(0),reserv(0){}
Intarr::Intarr( const int *arr1,size_t sz):siz(sz),reserv(0)
{
    arr =new int[siz];
    for (size_t i=0; i<siz; i++)
        arr[i]=arr1[i];
}
Intarr::Intarr(size_t ins): siz (ins),reserv(0)
{
    arr=new int[siz];
    for (size_t i=0; i<ins; i++)
        arr[i]=0;
}
Intarr::Intarr(const Intarr &rhs):siz(rhs.siz),reserv(0)
{
    arr=new int[rhs.siz];
    for (size_t i=0; i<rhs.siz; i++)
        arr[i]=rhs.arr[i];
}
Intarr Intarr::operator=(const Intarr& rhs)
{
    if (this==&rhs)
        return *this;
    delete[] arr;
    siz=rhs.siz;
    arr=new int[siz];
    for (size_t i=0; i<siz; i++)
        arr[i]=rhs.arr[i];
    return *this;
}
size_t  Intarr::get_size () const
{
    return siz;
}
const int&  Intarr::operator[](size_t idx)const
{
    return arr[idx];
}
int&  Intarr::operator[] (size_t idx)
{
    return arr[idx];
}
void Intarr::printarr()
{
    for (size_t i=0; i<siz; i++)
        std::cout << arr[i]<<" ";
    std::cout << std::endl;
    std::cout <<"Elementiv :" <<siz<<std::endl;
}
void Intarr::scanstr()
{
    int x;
    delete[] arr;
    siz=0;
    size_t n=1;
    reserv=16;
    arr=new int[reserv];
    while(true)
    {
        std::cin>>x;
        if (x==0)
        break;
        arr[siz]=x;
        siz++;
        if (siz+1==reserv)
        {
            n++;
            reserv*=n;
            this->resiz(reserv);
        }
    }
}
void Intarr::resiz(size_t newsiz)
{
    int*tmp=new int [newsiz];
    for (size_t i=0; i<siz; i++)
        tmp[i]=arr[i];
    delete[] arr;
    siz=newsiz;
    arr=tmp;
}
Intarr operator+ (const Intarr&a,const Intarr&b)
{
    Intarr res=a;
    res+=b;
    return res;
}
Intarr operator* (const Intarr&a,const Intarr&b)
{
    Intarr res=a;
    res*=b;
    return res;
}
void Intarr::operator+=(const Intarr&a)
{
    if (siz==a.siz)
    {
        for (size_t i=0;i<siz;i++)
        arr[i]+=a.arr[i];
    }
    else
        std::cout<<"The size of arrays are different";
}
void Intarr::operator*=(const Intarr&a)
{
    if (siz==a.siz)
    {
        for (size_t i=0;i<siz;i++)
        arr[i]*=a.arr[i];
    }
    else
        cout<<"The sizes of arrays are different";
}
void Intarr::operator+=(int x)
{
    for (size_t i=0;i<siz;i++)
        arr[i]+=x;
}
void Intarr::operator*=(int x)
{
    for (size_t i=0;i<siz;i++)
        arr[i]+=x;
}
void Intarr:: dltelmt( int a)
{
    size_t lich=0,n=0;
    for(size_t i=0; i<siz; i++)
    {
        if (arr[i]==a)
            lich++;
    }
    siz-=lich;
    int *tmp=new int[siz];
    for (size_t i=0; i<(siz+lich); i++)
    {
        if (arr[i]!=a)
        {
            tmp[n]=arr[i];
            n++;
        }
    }
    arr=tmp;
}
void  Intarr::findelm(int a, size_t &number)const
{
    for (number=0; number<siz; number++)
    {
        if (arr[number]==a)
            break;
    }
    number=numeric_limits <size_t>::max();
}


