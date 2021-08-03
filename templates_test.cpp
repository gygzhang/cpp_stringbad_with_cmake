#include"templates_test.hpp"
#include<iostream>

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