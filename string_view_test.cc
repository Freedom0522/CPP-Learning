#include<iostream>
#include<string>
#include<string_view>



std::string getName()
	{
		std::string s{ "Alex" };
		return s;
	}

//std:: string_view getBoolName(bool b)
//{
//	std::string t{ "true" };
//	std::string f{ "false" };
//
//	if (b)
//		return t;
//	return f;
//}
std::string_view getBoolName(bool b)
{
	if (b)
		return "true";//字符串常量
	return "false";
}

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
	if (s1 < s2)
		return s1;
	return s2;
}

std::string_view secondAlphabetical(const std::string_view s1, const std::string_view s2)
{
	if (s1 < s2)
		return s1;
	return s2;
}

std::string_view A(int a1, int  a2)
{
	if (a1 > a2)
		return "true";
	return "false";
}

std::string_view getName(int num)
{
	std::cout << "Enter the name of person# " << num << ":";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	return name;
}

int getAge(std::string_view sv)
{

	std::cout << "Enter the age of " << sv << ":";
	int age{};
	std::cin >> age;
	return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
	if(age1>age2)
		std::cout << name1 << "(age" << age1 << ")" << "is older than " << name2 << "(age" << age2 << ")" << '\n';
	else
		std::cout << name2 << "(age" << age2 << ")" << "is older than " << name1 << "(age" << age1 << ")" << '\n';
}

int main()

{
	
	//std::string_view  sv{};
	//{
	//	std::string s{ "Hello world" };
	//	sv = s;
	//}//s在嵌套块的末尾被销毁

	//std::cout << sv << '\n';

	//std::string_view name{ getName() };//name被getName()返回值初始化
	//std::cout << name << '\n';//临时值被销毁，std::string_view悬空

	//using namespace std::string_literals;
	//std::string_view name{ "Alex"s };
	//std::cout << name << '\n';//name悬空，未定义行为
	//不要用std::string初始化std::string_view
	//std::string s{ "Hello World" };
	//std::string_view sv{ s };

	//s = "Hello,universe";//s被修改
	//std::cout << sv << '\n';//sv失效,导致未定义行为
	////修改std::string 很可能会使所有指向std::string的视图失效
	//sv = s;//使sv重新生效
	//std::cout << sv << '\n';

	/*std::string_view name{ getName() };
	std::cout << name  << '\n';*/
	//getname 返回一个 string_view 的引用，然后函数销毁，再进行打印操作时，需要打印函数的返回值，发现是悬空引用


	//using namespace std;
	//std::string_view name{ "Alex"s };//表达式结束后，临时的std::string销毁->悬空指针
	//std::cout << name << '\n';

	/*std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n';*/
	//t在返回以后已经被销毁，返回的std::string_view正在查看一个已经被销毁的对象

	/*std::string a{ "Hello" };
	std::string b{ "World" };*/
	//std::string sv = secondAlphabetical(a, b);//在函数运行后对象被销毁sv指针被悬空，sv下一条语句使用出现未定义错误
	//std::cout << secondAlphabetical(a, b) << '\n';//临时对象的生命期延长至完整表达式结束
	//std::cout << firstAlphabetical(a, b) << '\n';//s1,s2分别是a,b的视图，因此即使函数被销毁，a，b依然存在，std::string_view访问a，b是可以的
	//如果参数是一个包含在函数调用的完整表达式结束时销毁的临时变量，返回的std::string_view必须立即使用，因为他在临时变量销毁后立即悬空

	//std::string_view str("Peach");
	//std::cout << str << '\n';

	//str.remove_prefix(1);//左侧
	//std::cout << str << '\n';

	//str.remove_suffix(2);//右侧
	//std::cout << str << '\n';

	//str = "Peach";
	//std::cout << str << '\n';

	//std::string_view可能已空字符串结尾，也可能不，std:;string始终以空字符串结尾
	/*int a1{};
	int a2{};
	std::string n1{};
	std::string n2{};
	std::getline(std::cin >> std::ws, n1);
    std::cin >> a1;
	std::getline(std::cin >> std::ws, n2);
    std::cin >> a2;
	std::cout << "Enter the name of person#1: "<<n1<<'\n';
    std::cout << "Enter the age of " << n1 << ":" << a1 <<'\n';
	
	
	
	std::cout << "Enter the name of person#2:"<<n2<< '\n';
	std::cout << "Enter the age of " << n2 << ":" << a2 << '\n';
	std::string_view s = A(a1, a2);
	if (s == "true")
	{
		std::cout << n1 << "(age" << a1 << ")" << "is older than " << n2 << "(age" << a2 << ")" << '\n';
	}
	else
		std::cout << n2 << "(age" << a2 << ")" << "is older than " << n1 << "(age" << a1 << ")" << '\n';



	return 0;*/

	const std::string name1{ getName(1) };
	const int age1{ getAge(name1) };
	const std::string name2{ getName(2) };
	const int age2{ getAge(name2) };
	printOlder(name1, age1,name2, age2);


  
}