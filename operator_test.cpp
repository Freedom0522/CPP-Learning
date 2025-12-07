#include<iostream>

int add(int x,int y)
{
    return x + y;
}
int main()
{
    int x {5};
    int value{add(x,++x)};//求值顺序不定，导致未定义行为
    std::cout << value <<'\n';
    int y{5};

    std::cout << x << ' '<< y<<'\n';
    std::cout << ++x << ' '<< --y << '\n';//返回改变后的x的值
    std::cout << x << ' '<< y<<'\n';
    std::cout << x++ << ' '<< y-- << '\n';//返回x的副本

    return 0;
    
}