#include <iostream>
#include <vector>

#include"stringbad.h"
using namespace std;

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
    StringBad st3{};
    string s(typeid(st3).name());
    cout<<st3<<endl;
    
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
    //delete st1;
    //cout<<"test01 end!"<<endl;
    
}

int main()
{
    test01();
    
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
