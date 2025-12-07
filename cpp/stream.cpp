#include<sstream>
#include<iostream>

int main(){
    std::ostringstream out;
    out << 123 << " " << "hello";

    std::string data = out.str();

    std::istringstream in(data);
    int num;
    std::string word;
    in >> num >> word;
    std::cout << num << "," << word;
}