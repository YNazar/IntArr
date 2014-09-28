#include "IntStr.h"
#include <iostream>
#include <limits>
using  namespace std;
Intstr::Intstr():siz(0),arr(0) {}
Intstr::Intstr( const int *arr1,size_t sz)
{
    siz=sz;
    arr =new int[siz];
    for (size_t i=0; i<siz; i++)
    arr[i]=arr1[i];
}
Intstr::Intstr(size_t ins): siz (ins)
{
    arr=new int[siz];
    for (size_t i=0; i<ins; i++)
        arr[i]=0;
}
Intstr::Intstr(const Intstr &rhs):siz(rhs.siz)
{
    arr=new int(rhs.siz);
    for (size_t i=0; i<rhs.siz; i++)
        arr[i]=rhs.arr[i];
}
Intstr Intstr::operator=(const Intstr& rhs)
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
size_t  Intstr::get_size () const
{
    return siz;
}
const int&  Intstr::operator[](size_t idx)const
{
    return arr[idx];
}
int&  Intstr::operator [] (size_t idx)
{

    return arr[idx];
}

void Intstr::printarr()
{
    for (size_t i=0; i<siz; i++)
        std::cout << arr[i]<<" ";
    std::cout << std::endl;
    std::cout <<"Elementiv :" <<siz<<std::endl;

}
void Intstr::scanstr()
{
    cout << "Enter string and | 0 | to break "<< endl;
    delete[] arr;
    siz=0;
    arr=new int[siz+1];
    while(true)
    {
        cin>>arr[siz];
        if (arr[siz]==0)
        {
            arr[siz]='\0';
            break;
        }
        siz++;
        this->resiz(siz);
    }
}
void Intstr::resiz(size_t newsiz)
{
    int*tmp=new int [newsiz];
    for (size_t i=0; i<siz; i++)
        tmp[i]=arr[i];
    delete[] arr;
    siz=newsiz;
    arr = tmp;
}
Intstr Intstr::combine (const Intstr  &a,const Intstr& b)
{
    Intstr res=a;
    a+=b;
    return res;
}
void Intstr::combineit(const Intstr&rhs)
{
    int *tmp=new int[siz+rhs.siz];
    for(size_t i=0; i<siz; i++)
        tmp[i]=arr[i];
    for(size_t i=0; i<rhs.siz; i++)
        tmp[siz+i]=rhs.arr[i];
    siz=siz+rhs.siz;
    tmp=arr;
}
void Intstr:: dltelmt( int a)
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
void  Intstr::findelm(int a, size_t &number)const
{


    for (number=0; number<siz; number++)
    {
        if (arr[number]==a)
            break;
    }
    number=numeric_limits <size_t>::max();

}


