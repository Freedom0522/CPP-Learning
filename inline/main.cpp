#include"constants.h"
#include<iostream>

int main()
{
    std::cout << "Enter a radis";
    double radius{};
    std::cin>>radius;

    std::cout<<"The circumference is: "<<2*radius*constants::pi<<'\n';
    return 0;
}