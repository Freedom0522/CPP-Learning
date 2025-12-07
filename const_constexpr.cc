#include<iostream>
#include<string>
#include<string_view>
int getNumber()
{
	std::cout << "Enter anumber: \n";
	int y{};
	std::cin >> y;
	return y;
}

void printSV(std::string_view str)
{
	std::cout << str << '\n';
}

void printString(std::string str)
{
	std::cout << str << '\n';
}

int main()
{
	//bool b{};
	//std::cout << "Enter a boolean value:";
 //   std::cin >> std::boolalpha;//因此要加上std::boolalpha
	//std::cin >> b;//std::cin不接受true/false作为布尔参数值
	//
	//
	//std::cout << "You entered:" << b << '\n';



	//const int x{ 3 };//x是编译时常量
	//const int y{ 4 };

	//std::cout << x + y;//x+y是编译时常量
	//return 0;

	//const int x{ 3 };//x是编译时运行常量

	//std::cout << "Enter a number ";
	//const int y{ getNumber() };//y是运行时常量

	//std::cout << x + y;

	/*constexpr double gravity{ 9.8 };
	constexpr int sum{ 4 + 5 };
	constexpr int something{ sum };

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;*/


	//constexpr int myAge{ age };//age不是编译期常量，因此会出错
	//任何在编译器确定初始值且之后不会有任何变化的用constexpr
	//任何在运行时确定初始值的且初始化之后不会改变的变量用const
	// const变量必须在声明的时候初始化
	//按值传递，返回值不要用const

	//std::setprecision()输出操纵器，控制精度

	//std::cout << "Enter your full name";
	//std::string name{};
	////std::cin >> name;//std::cin只会提取第一个空格前的字符，剩余字符会被留到缓冲区内，读取一整行最好使用getline
	//std::getline(std::cin >> std::ws, name);

	//std::cout << "Enter your age";
	//std::string age{};
	///*std::cin >> age;*/
	//std::getline(std::cin >> std::ws, age);;

	//std::cout << "Your name is " << name << "Your age is " << age << '\n';
	//std::cout << "Pick 1 or 2: ";
	//int choice{};
	//std::cin >> choice;
	//用户输入2回车，operator>>只读取2，不会读取'\n'
	//因此'\n'被留在缓冲区内
	//std::cout << "Now enter your name";
	//std::string name{};
	///*std::getline(std::cin, name);*/
	//getline 看到缓冲区已有'\n'，会认为这是一个空行
	//因此他立即返回，name变成空字符串

	//std::getline(std::cin >> std::ws, name);//忽略任何前置空白字符串
	//当提取到变量时，提取运算符（>>）会忽略前导空格。它在遇到非前导空格时停止提取。
	//std::getline()不会忽略前导空格。如果您希望它忽略前导空格，请将 std::cin >> std::ws 作为第一个参数传递。它在遇到换行符时停止提取。

	//std::cout << "Hello," << name << ",your picked"<<choice<<'\n';

	//不要按值传递std::string

	//std::string_view s{ "Hello world" };
	//printSV(s);
	////当你只需要只读字符串时，尤其是在函数参数中，优先使用std::string_view而不是std::string
	//std::string s2{ "Hello world" };
	//printSV(s2);
	//std::string_view s3{ s2 };
	//printSV(s3);
	//std::string_view s3{s2} 不会重新开辟空间，不会复制字符串内容
	//而是指向 s2 的内部内存，行为上类似引用，只是指向这块原有的字符数据，但是他是指针＋长度，并不拥有和改变底层数据
	//std::string_view不会隐式转为std::string
	//如果需要这样做
	//std::string_view sv{ "Hello world" };
	//std::string s{ sv };//用std::string_view初始化std::string
	//printString(s);//打印std;:string字符串
	//printString(static_cast<std::string>(sv));//使用static_cast将std::string_view强制转化为std::string
	
	std::string name{ "Alex" };
	std::string_view sv{ name };//用name初始化sv
	std::cout << sv << '\n';

	sv = "John";//改变sv，sv不在指向name而是指向新的字符串"John"
	std::cout << sv << '\n';

	std::cout << name << '\n';//不改变name的值

	using namespace std::string_literals;
	using namespace std::string_view_literals;
	
	std::cout << "foo\n";
	std::cout << "goo\n"s;
	std::cout << "moo\n"sv;

	constexpr std:: string_view s{ "Hello World" };//字符串常量
	std::cout << s << '\n';
	return 0;
}

