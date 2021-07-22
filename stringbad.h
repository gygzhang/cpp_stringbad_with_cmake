//stringbad.h -- flaw string defination
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#endif
#include<iostream>
class StringBad
{
private:
    char * str;   //pointer to string 
    int len;        // length of the string 
    static int num_str;  //number of the string
public:
    StringBad();
    StringBad(const char *s);
    ~StringBad();
    //friend function
    friend std::ostream & operator<<(std::ostream &so, const StringBad &st);
};

