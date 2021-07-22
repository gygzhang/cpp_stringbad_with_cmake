#include"stringbad.h"
#include<cstring>

int StringBad::num_str=0;

StringBad::StringBad(){

    std::cout<<"contruct a str! "<<std::endl;

    str ="";

    len=0;
}

StringBad::StringBad(char const *s){
    int len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_str++;
    std::cout<<"num_str="<<num_str<<", and "<<str<<" object was constructed! "<<std::endl;
}

StringBad::~StringBad(){
    num_str--;
    std::cout<<"deconstruct an object:"<<str<<"and num_str now is "<<num_str<<std::endl;
    delete []str;
}

std::ostream & operator<<(std::ostream &so, const StringBad &st){
    so<<st.str<<std::endl;
    return so;
}
