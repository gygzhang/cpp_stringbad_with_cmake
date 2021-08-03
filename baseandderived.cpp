#include"baseandderived.h"

Base::Base(){

}

Base::~Base(){

}

Base::Base(string n){
    this->name = n;
    LOG(this->name);
}

void Base::ShowName(){
    if (name.empty())
    {
        LOG("Base::ShowName()");
        return;
    }
    LOG("Base::ShowName(): "<<name);
    
    
}

void BaseDerived::ShowName(){
    
    if (name.empty())
    {
        LOG("BaseDerived::ShowName()");
        return;
    }
    LOG("BaseDerived::ShowName(): "<<name);
}

BaseDerived::BaseDerived()
{
}

BaseDerived::BaseDerived(int i) : Base(), vb1(i)
{
    
}

BaseDerived::BaseDerived(string n) : Base(), vb1()
{
    this->name = n;
    LOG(this->name);
}

BaseDerived::~BaseDerived()
{
}