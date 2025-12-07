#include<iostream>

int value{5};
// void foo()
// {
//     std::cout << "global variable value"<<value<<'\n';
// }
//内部链接，确保自己文件内容不被其他文件访问
// static int g_x{};
// static int g_x{10};
// const int g_y{1};
// constexpr int g_z{2};
// static int foo{};

extern int g_y;
extern  const int g_y;
//extern constexpr int g_y;//不允许向前生命
int g_x;
int g_x{1};
extern const int g_x{2};
extern constexpr int g_x{3};
int main()
{
    // int apples{5};
    // {
    //     std::cout << apples << '\n';
    //     int apples{0};
    //     apples = 10;//遮蔽嵌套块内的变量
    //     std::cout << apples <<'\n';
    // }
    // std::cout << apples << '\n';
    
    // int value{7};//局部变量遮蔽全局变量
    // ++value;
    // std::cout << "local variable value"<<value<<'\n';
    // foo();

    std::cout << g_x << ' '<<g_y<<'\n';

    return 0;
}