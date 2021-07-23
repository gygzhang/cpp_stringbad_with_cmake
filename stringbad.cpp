#include"stringbad.h"
#include<cstring>
#include<string>
int StringBad::num_str=0;

StringBad::StringBad(){
    LOG("contruct a str without parameters ! ");
    //is necessary, because the `delete []str statement`
    str = new char[1];
    str[0] = '\0';
    //std::strcpy(str,"C++");
    len=0;
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

char& StringBad::operator[](int i){
    return this->str[i];
}
const char & StringBad::operator[](const int i) const{
    return this->str[i];
}

int StringBad::HowMany(){
    return num_str;
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

StringBad & StringBad::operator=(const char* st){
    delete []str;
    len = std::strlen(st);
    str = new char[len+1];
    std::strcpy(str,st);
    return *this;
}



std::ostream & operator<<(std::ostream &so, const StringBad &st){
    so<<st.str<<std::endl;
    return so;
}


//friend function
//bool operator==(StringBad &sb1);
void operator>>(std::istream &is,StringBad &sb){
    char temp[StringBad::CINLIM];
    is.get(temp,StringBad::CINLIM);
    if(is) {
        sb = temp;
    }
    while(is&&is.get()!='\n') {
        continue;
    }

    return;
}

/*
strcmp
<0	the first character that does not match has a lower value in ptr1 than in ptr2
0	the contents of both strings are equal
>0	the first character that does not match has a greater value in ptr1 than in ptr2
*/
bool operator<(const StringBad &sb1, const StringBad &sb2){
    return std::strcmp(sb1.str,sb2.str)<0?true:false;
}
bool operator>(const StringBad &sb1, const StringBad &sb2){
    return std::strcmp(sb1.str,sb2.str)<0?false:true;
}
bool operator==(const StringBad &sb1, const StringBad &sb2){
    return std::strcmp(sb1.str,sb2.str)==0?true:false;
}




