#include"templates_test.hpp"
#include<iostream>




template<typename T1>
class ES1
{
private:
    /* data */
public:
    ES1(){LOG("T1");};
    ~ES1();
};

template<> 
class ES1<const char*>
{
private:
    /* data */
public:
    ES1() {LOG("const char*");};
    ~ES1();
};






namespace Impl {

template <typename T>
class B { T value; };

template <>
class B<int> { bool value; };

}












