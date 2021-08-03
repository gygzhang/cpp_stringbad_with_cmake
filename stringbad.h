//stringbad.h -- flaw string defination
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#endif
#include<iostream>
#include<string>


#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl
//#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl;


class StringBad
{
private:
    char * str;   //pointer to string 
    //https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class
    mutable int len;        // length of the string 
    static int num_str;  //number of the string
    static const int CINLIM = 80; //limit of cin
public:

    StringBad();
    StringBad(const char *s);
    StringBad(const StringBad &sb);
    //convert funtion
    explicit StringBad(double dl);
    

    ~StringBad();
    int length()const {return len;};

    StringBad & operator=(const StringBad &sb);
    StringBad & operator=(const char* st);

    //同时提供const和非const版本，const对象和非const对象将调用不同版本的函数
    char& operator[](int i);
    //use for const StringBad object
    //https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class
    const char & operator[](const int i) const;
    static int HowMany();

    //friend function
    friend std::ostream & operator<<(std::ostream &so, const StringBad &st);
    friend void operator>>(std::istream &is,StringBad &sb);
    friend bool operator<(const StringBad &sb1, const StringBad &sb2);
    friend bool operator>(const StringBad &sb1, const StringBad &sb2);
    //or bool operator==(StringBad &sb1);
    friend bool operator==(const StringBad &sb1, const StringBad &sb2);
};

class A{
    char str;
    int a;
    
    int length()const {return a;};
};

