#include<iostream>
// [[maybe_unused]]constexpr int g_x{2};//消除unused variable警告
[[maybe_unused]]
static int add(int x,int y)
{
    return x+y;
}

void sayHi()
{
    std::cout<< "Hi\n";
}

int g_x{2};
extern const int g_y{3};//内部变量
// extern constexpr int g_z{3};


