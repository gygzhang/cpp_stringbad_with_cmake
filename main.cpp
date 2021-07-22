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

void test01(){
    StringBad *st1 = new StringBad();
    StringBad st2("Hello World!");
    //std::cout<<st2<<std::endl;
    std::cout<<st2<<std::endl;

}

int main()
{
    //vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    //msg.assign()
    cls1 c1(25);

    int temp = (int)c1;

    c1=55;

    cout<<temp<<endl;

    test01();

    //c1 = 11;
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    //cout << endl;
}
