#ifndef TEMPLATES_TEST_H_
#define TEMPLATES_TEST_H_
#include<iostream>
#endif
#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl
template <typename T>
class Aarry
{
private:
    T t;
};

template<typename Tp>
class Stack
{
    Aarry<Tp> ar;
};

//Aarry<Stack<int>> asi;

template<typename Tp>
class Stack1
{
    Tp ar;
    //enum or static const int?
    //It's partly because older compilers did not support the declaration of a true class constant
    //The other reason is that enums can be used as a convenient syntactic device to organise class
    // constants into those that are related, and those that are not
    enum{RATE=100};
    static const int sci=100;
    const int ci=10;
};

//double is not allowed, because the following is not the same:
//template class foo<10./3.>
//template class foo<1./3 * 10.>
template<typename T,int n>
class NonType
{
    T ar[n];
};

//DEAULT_T2<double,double> √
//DEAULT_T2<double> is equivalent to DEAULT_T2<double,int> √
template<typename T1, typename T2=int>
class DEAULT_T2
{
    T1 t1;
    T2 t2;
};

//√
template<typename T1, typename T2=int, int n=0>
class DEAULT_T3
{
    T1 t1;
    T2 t2;
};

template<typename T1, typename T2=int>
T1 func1(T1 t1, T2 t2)
{
    LOG(t1<<" "<<t2);
    return 0;
}

template<typename T1, typename T2=int,int n=5>
T1 func2(T1 t1, T2 t2)
{
    LOG(t1<<" "<<t2<<" "<<n+5);
    return 0;
}

//explicit specialization
//two class, 
/*
    template<> 
    class ES1<const char*>{}

    and

    template<typename T1>
    class ES1{};

*/
namespace ES
{
template<typename T1>
class ES1
{
private:
    /* data */
public:
    ES1();
    ~ES1();
};

template<> 
class ES1<const char*>
{
private:
    /* data */
public:
    ES1();
    ~ES1();
};



template<typename T> 
ES1<T>::ES1()
{
    LOG("T1");
}

ES1<const char*>::ES1()
{
    LOG("const char*");
}

template<typename T> 
ES1<T>::~ES1()
{
    LOG("ES1<T>::~ES1()");
}

ES1<const char*>::~ES1()
{
    LOG("ES1<const char*>::~ES1()");
}

} //end of namespace ES 


namespace PartialSpecialization 
{

template<typename T1, typename T2>
class PS1
{
private:
    T1 t1;
public:
    PS1();
    ~PS1();
};

template<typename T1, typename T2>
PS1<T1,T2>::PS1()
{
    LOG("PS1<T1,T2>::PS1()");
}

template<typename T1, typename T2>
PS1<T1,T2>::~PS1()
{

}


//only T2 was specialized, if T1 specialized too, get an explicit specialization
template<typename T1>
class PS1<T1,int>
{
private:
    T1 t1;
public:
    PS1();
    ~PS1();
};

template<typename T1>
PS1<T1,int>::PS1()
{
    LOG("PS1<T1,int>::PS1()");
}

template<typename T1>
PS1<T1,int>::~PS1()
{

}

//explicit specialization
template<>
class PS1<double,int>
{
private:
    double t1;
public:
    PS1();
    ~PS1();
};


PS1<double,int>::PS1()
{
    LOG("PS1<double, int>::PS1()");
}

PS1<double,int>::~PS1()
{

}


}//end of namespace PartialSpecialization


namespace MemberTemplate
{

template<typename T>
class MainClass{

private:
    T t;
    template<typename U>
    class SubClass;
    SubClass<T> st;
    SubClass<int> subci;

public:
    template<typename V>
    V fun1(T,V);

}; //end of class MainClass

template<typename T>
template<typename U>
class MainClass<T>::SubClass
{

private:
    T t1;
    U u1;

public:
    void show(T t,U u) {LOG(t<<" "<<u);};

};

template<typename T>
template<typename V>
V MainClass<T>::fun1(T t, V v){
    //show(T t,U u), T now is int, so const char* is invaild!
    this->st.show(3.666,5.45);
    this->subci.show(2,5);
    LOG("V MainClass<T>::fun1(T t, V v): "<<t<<" "<<v);
    return 0;
}


}//end of namespace MemberTemplate

namespace TemplateAsParamter
{

template<typename T>
class C1
{

};

template<template<typename T> class C>
class C2
{
public:
    C2();
};

template<template<typename T> class C>
C2<C>::C2()
{
    LOG("template as parameter: "<<"C2<C>::C2()");
}

template<template<typename T> class C, typename T1, typename T2>
class C3
{
private:
    C<T2> c;
    T1 t1;
    T2 t2;
public:
    C3();
};

template<template<typename T> class C, typename T1, typename T2>
C3<C,T1,T2>::C3()
{
    LOG("mix template parameter: "<<"C3<C,T1,T2>::C3()");
}

}//end of namespace TemplateAsParamter


namespace FriendAndTemplate
{

// template<typename T>
// class FriAndTe
// {

// public:
//     friend void counts();
    
//     friend void report(FriAndTe<T> &);

// private:
//     T t;


// };//end of class FriAndTe

// void counts()
// {
//     LOG("void counts()");
// }

//error! report() is not a template function, must explicit specialization
// template<typename T>
// void report(FriAndTe<T> &fat)
// {
//     LOG(typeid(fat));
// }

//explicit specialization

// void report(FriAndTe<int> &fat)
// {
//     LOG(typeid(fat).name());
// }

// void report(FriAndTe<double> &fat)
// {
//     LOG((typeid(fat)).name());
// }

template<typename TT> void counts();
template<typename TT> void report(TT &t);

template<typename TT>
class FriAndTeT
{

private:
    TT tt;
    

public:
    static int cnt;
    FriAndTeT(const TT &i):tt(i) {cnt++;};
    ~FriAndTeT(){cnt--;};
    friend void counts<TT>();
    //<> can be empty, could be deducted
    friend void report<>(FriAndTeT<TT> &);
    //OR:
    //friend void report< template<typename TT> >(FriAndTeT<TT> &tt);




};//end of class FriAndTeT

template<typename TT> 
int FriAndTeT<TT>::cnt = 0;

template<typename TT> 
void count()
{
    LOG("sizeof(FriAndTeT<TT>): "<<sizeof(FriAndTeT<TT>)<<"");
    LOG("FriAndTeT<TT>::cnt   : "<<FriAndTeT<TT>::cnt<<"");

}


template<typename TT> 
void report(FriAndTeT<TT> &t)
{
    LOG((FriAndTeT<TT>::cnt));
}


}//end of namespace FriendAndTemplate


namespace FriendAndTemplate2
{

template<typename T> void counts();
template<typename T> void report(T &t);

template<typename T>
class FriAndTe
{

public:
    friend void counts<T>();
    //<> can be empty, could be deducted
    friend void report<>(FriAndTe<T> &);

private:
    T t;


};//end of class FriAndTe

void counts()
{
    LOG("void counts()");
}

//error! report() is not a template function, must explicit specialization
// template<typename T>
// void report(FriAndTe<T> &fat)
// {
//     LOG(typeid(fat));
// }

//explicit specialization

void report(FriAndTe<int> &fat)
{
    LOG(typeid(fat).name());
}

void report(FriAndTe<double> &fat)
{
    LOG((typeid(fat)).name());
}


}//end of namespace FriendAndTemplate2


#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    
};











