#include<iostream>

void incrementAndPrint()
{
    static int s_value{1};//静态局部变量只在初次调用时进行初始化
    ++s_value;
    std::cout << s_value<<'\n';
}

int generateID()
{
    static int s_itemID{0};
    return s_itemID++;
}
//静态局部变量最好用于避免每次调用函数时昂贵的局部对象初始化。

int getInteger()
{
    static bool s_isFirstCall{true};

    if(s_isFirstCall)
    {
        std::cout << "Enter an integer";
        s_isFirstCall = false;
    }
    else
    {
        std::cout << "Enter another integer";
    }

    int i{};
    std::cin >> i;
    return i;
}

// constexpr bool g_firstCall{true};

// int getInteger(bool bFirstCall)
// {
//     if(bFirstCall)
//     {
//         std::cout<<"Enter an integer";
//     }
//     else
//     {
//         std::cout<<"Enter another integer";

//     }

//     int i{};
//     std::cin>>i;
//     return i;
// }

int getInteger(std::string_view promt)
{
    
    std::cout << promt;
    int x{};
    std::cin>>x;
    return x;
}
int main()
{
    // incrementAndPrint();
    // incrementAndPrint();
    // incrementAndPrint();

    // int id = generateID();
    // int id1 = generateID();
    // int id2 = generateID();
    // int i = 0;

    // while(i<=5)
    // {
    //     printf("id:%d",generateID());
    //     i++;
    // }

    // int a{getInteger()};
    // int b{getInteger()};

    // std::cout << a <<"+"<<b<<"="<<(a+b)<<'\n';

    // int c{getInteger()};
    // int d{getInteger()};
    // std::cout << c <<"-"<<d<<"="<<(c-d)<<'\n';

    // int a{getInteger(g_firstCall)};
    // int b{getInteger(!g_firstCall)};

    // std::cout << a <<"+"<<b<<"="<<(a+b)<<'\n';


    // int c{getInteger(g_firstCall)};
    // int d{getInteger(!g_firstCall)};

    // std::cout << c <<"-"<<d<<"="<<(c-d)<<'\n';


    int a{getInteger("Enter an ineger: ")};//字符串变量科一隐式转换为bool->false
    int b{getInteger("Enter another ineger: ")};

    std::cout << a <<"+"<<b<<"="<<(a+b)<<'\n';

    int c{getInteger("Enter an ineger: ")};
    int d{getInteger("Enter another ineger: ")};

    std::cout << c <<"-"<<d<<"="<<(c-d)<<'\n';

    return 0;
    
}