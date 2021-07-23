//stringbad.h -- flaw string defination
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#endif
#include<iostream>
#include<string>



#define LOG(str) std::cout<<"["<<__FUNCTION__ <<" at line "<<__LINE__<<"]: "<<str<<std::endl;


class StringBad
{
private:
    char * str;   //pointer to string 
    int len;        // length of the string 
    static int num_str;  //number of the string
public:

    StringBad();
    StringBad(const char *s);
    StringBad(const StringBad &sb);
    StringBad & operator=(const StringBad &sb);
    ~StringBad();
    //friend function
    friend std::ostream & operator<<(std::ostream &so, const StringBad &st);
};

