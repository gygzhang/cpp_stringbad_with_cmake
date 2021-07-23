#include"stringbad.h"
#include<cstring>
#include<string>
int StringBad::num_str=0;

StringBad::StringBad(){
    LOG("contruct a str without parameters ! ");
    str = new char[4];
    std::strcpy(str,"C++");
    len=4;
    num_str++;
}

StringBad::StringBad(char const *s){
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_str++;
    LOG("num_str="<<num_str<<", and "<<str<<" object was constructed! ");
    //std::cout<<"num_str="<<num_str<<", and "<<str<<" object was constructed! "<<std::endl;
}

StringBad::StringBad(const StringBad &sb){
    this->len = std::strlen(sb.str);
    this->str = new char[this->len + 1];
    std::strcpy(this->str, sb.str);
    this->num_str ++;
    LOG("num_str="<<num_str<<", and "<<str<<" object was constructed! ")

}

StringBad & StringBad::operator=(const StringBad &sb){
    if(this==&sb) return *this;

    //must be done, or after `this->str = new char[len+1];`, there is no pointer point to this->str
    delete [] this->str;

    len = std::strlen(sb.str);
    this->str = new char[len+1];
    std::strcpy(this->str, sb.str);
    this->num_str = sb.num_str;
    return *this;

}

StringBad::~StringBad(){
    num_str--;
    char *temp = new char[len+1];
    std::strcpy(temp,str);
    
    //std::cout<<"deconstruct an object:"<<str<<"and num_str now is "<<num_str<<std::endl;
    delete []str;
    //str = nullptr;
    LOG("deconstruct an object:"<<temp<<" and num_str now is "<<num_str);
    delete []temp;
    //std::cout<<"left! "<<std::endl;
}

std::ostream & operator<<(std::ostream &so, const StringBad &st){
    so<<st.str<<std::endl;
    return so;
}
