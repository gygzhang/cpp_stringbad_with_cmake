#include <iostream>
#include <vector>

#include"stringbad.h"
#include"queuebad.h"
using namespace std;


#define MK_VAR(v1,v2) (v1##v2)

class cls1
{
private:
    int var1=0;

public:
    cls1(int i)
    {
        var1 = i;
    }

     operator int(){
        return var1;
    }


};


// ostream & operator<<(ostream &os, )
void call1(StringBad sb){
    //LOG(sb);
}

void test01(){
    using namespace std;
    StringBad *st1 = new StringBad("abc");
    //StringBad st3(); will not call the constructor, 
    //otherwise it will be treated as a function declaration.
    StringBad st2{};
    //string s(typeid(st2).name());
    //cout<<s<<endl;

    StringBad st3("abd");
    const StringBad st4("abc");

    LOG(int((*st1)==st3));
    LOG(int((*st1)==st4));
    LOG(int(st4>st3));
    LOG(int(st4<st3));
    
    LOG(st4[1]);
    const char* st5="E4M";
    st3=st5;
    LOG(st3);
    int cnt = StringBad::HowMany();
    LOG("CNT: "<<cnt);

    //cin>>st3;
    //LOG(st3);

    A a;
    LOG(sizeof(a));
    
    
    //StringBad st2("Hello World!");
    //std::cout<<__LINE__<<"st2: "<<st2<<std::endl;
    //LOG(st3);
    //call1(st3);
    //std::cout<<st2<<std::endl;
    //st3=st2;
    //StringBad st4=StringBad(st2);
    //LOG(st3);
    //cout<<st3<<endl;
    //LOG("test01 end!");
    //delete st1;
    delete st1;
    //cout<<"test01 end!"<<endl;
    
}

void test02(){
    char* buf = new char[900];
    
    StringBad *sb1,*sb2; 
    sb1 = new (buf) StringBad("sb1");
    sb2 = new StringBad("sb2");
    
    //LOG(sb1<<", "<<sb2<<", "<<reinterpret_cast<uintptr_t>(buf));
    // buf is 
    LOG("buf address: "<<static_cast <const void*>(buf));
    LOG(sb1<<" + "<<sizeof(sb1)<<" = "<<sb1+sizeof(sb1));
    uintptr_t a = reinterpret_cast<uintptr_t>(&sb1);
    cout<<reinterpret_cast<uintptr_t>(sb1)<<endl;
    //LOG((int)*&sb1)
    //sb1 is a pointer point to a class object(8 of size), sb1+8 means (int)sb1 + 8*16
    LOG(reinterpret_cast<uintptr_t>(sb1)<<" + "<<(long unsigned)sizeof(*sb1)<<" = "<<reinterpret_cast<uintptr_t>(sb1+sizeof(sb1)));
    // reinterpret_cast<uintptr_t>(sb1) convert the pointer to unsigned long
    LOG(reinterpret_cast<uintptr_t>(sb1)<<" + "<<(long unsigned)sizeof(*sb1)<<" = "<<reinterpret_cast<uintptr_t>(sb1)+(sizeof(*sb1)));


}

void test03(){
    //use StringBad(double), is a implicit conversion,
    //if explicit is used, it is not valid!
    //StringBad sb = 5.5;
    //must use this form
    StringBad sb(5.5);
}

void test04(){
    Item it1,it2,it3,it4,it5;
    QueueBad qb;
    it1.i = 1; it2.i =2; it3.i = 3; it4.i =4; it5.i =5;
    qb.enqueue(MK_VAR(it,1));
    qb.enqueue(MK_VAR(it,2));
    qb.enqueue(MK_VAR(it,3));
    qb.enqueue(MK_VAR(it,4));
    qb.enqueue(MK_VAR(it,5));
    for (int i = 1; i < 5; i++)
    {
        
        
    }
    
    
}
int main()
{
    //test01();
    //test02();
    //test03();
    test04();
    //vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    //msg.assign()
    //cls1 c1(25);

    // int temp = (int)c1;

    // c1=55;

    // cout<<temp<<endl;

    

    //c1 = 11;
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    //cout << endl;
}
