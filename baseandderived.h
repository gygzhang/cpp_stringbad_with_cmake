#ifndef BASEANDDERIVED_H_
#define BASEANDDERIVED_H_
#endif
#include<string>
#include<iostream>

#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl

using std::string;

class Base{
private:
    int va1;
    string name;
public:
    Base();
    Base(string n);
    //when declare to virtual, who call, who call
    virtual void ShowName();
    //why?
    //Deleting an object through pointer to base invokes undefined behavior 
    //unless the destructor in the base class is virtual:
    virtual ~Base();
};

class BaseDerived : public Base
{
private:
    int vb1;
    string name;
public:
    BaseDerived();
    BaseDerived(int i);
    BaseDerived(string n);
    virtual void ShowName();
    ~BaseDerived();
};





