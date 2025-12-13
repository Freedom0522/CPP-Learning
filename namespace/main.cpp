#include<iostream>
#include"FooLib.h"
#include"FooDouble.h"
using Foo::print;
#include"FooInt.h"

// int cout()
// {
//     return 5;
// }

// void print()
// {
//     std::cout<<"Hello\n";
// }
// int get(long)
// {
//     return 1;
// }

int main()
{
    // using namespace std;
    // //两个cout函数无法确定导致"ambiguous symbol"错误
    // cout << "Hello,world!\n";
    // return 0;
    // using namespace Foo;
    // std::cout << a<<'\n';
    // // print();
    // std::cout << get(0)<<'\n';
    print(5);
    return 0;
}