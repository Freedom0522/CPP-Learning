#include<string_view>
#include<iostream>
#include<string>
#include<vector>
#include<functional>

//class Base
//{
//public:
//	virtual ~Base() = default;
//	virtual std::string_view getName() const { return "Base"; }
//
//};
//
//class Derived :public Base {
//public:
//	virtual std::string_view getName() const { return "Derived"; }
//};
//
//int main() {
//	Derived derived{};
//	const Base& base{ derived };
//	//引用本质是一个指针，指向derived，而const Base& 限制base只能访问继承Base或者Base的函数且对函数内容不能修改，const Base& base 限制的是通过这个引用 不能修改对象状态，包括：
//	//调用非 const 成员函数，对引用对象进行赋值，直接修改成员变量，且derived独有的函数不能访问，并且引用不会发生切割，本质还是derived对象
//	std::cout << base.Base::getName() << '\n';//由于有作用域的限制，所以会直接限定为Base对象的getName，而不会发生动态绑定
//	return 0;
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//
//int substract(int x, int y) {
//	return x - y;
//}
//
//int multiply(int x, int y)
//{
//	return x * y;
//}
//
//
//int main() {
//	int x{};
//	std::cout << "Enter a number: ";
//	std::cin >> x;
//
//	int y{};
//	std::cout << "Enter another number";
//	std::cin >> y;
//
//	int op{};
//	do
//	{
//		std::cout << "Enter an operation(0=add,1=subtract,2=multiply):";
//		std::cin >> op;
//	} while (op < 0 && op>2);
//
//	/*int result{};*/
//	/*switch (op)
//	{
//	case 0:result = add(x, y); break;
//	case 1:result = substract(x, y); break;
//	case 2:result = multiply(x, y); break;
//	}
//
//	std::cout << "The answer is: " << result << '\n';*/
//
//	int (*pFcn)(int, int) { nullptr }; //函数指针声明
//	switch (op)
//	{
//	case 0:pFcn = add; break;
//	case 1:pFcn = substract; break;
//	case 2:pFcn = multiply; break;
//	}
//
//	std::cout << "The answer is: " << pFcn(x, y) << '\n';
//	return 0;
//}

//class Animal
//{
//protected:
//	std::string m_name;
//
//	Animal(const std::string_view& name)
//		:m_name{ name }
//	{
//
//	}
//public:
//	const std::string& getName() const { return m_name; }
//	/*virtual std::string_view speak() const { return "???"; }*/
//	virtual std::string_view speak() const = 0; //Animal不能被实例化，只有派生类提供具体实现才能通过实例化派生类对象来使用这个接口
//
//
//
//	virtual ~Animal() = default;
//};
//
//std::string_view Animal::speak() const
//{
//	return"buzz";//基类默认实现
//}
//
//
//class Cat :public Animal
//{
//public:
//	Cat( std::string_view name)
//		:Animal{ name }
//	{
//
//	}
//	/*std::string_view speak() const override { return "Meow"; }*/
//	std::string_view speak() const override
//	{
//		return Animal::speak();
//	}//重写基类的纯虚函数但调用了基类的默认实现
//	
//};
//
//class Dog :public Animal
//{
//public:
//	Dog(std::string_view name)
//		:Animal{ name }
//	{
//
//	}
//	std::string_view speak() const override { return "Woof"; }
//};
//

//class PoweredDevice
//{
//public:
//	PoweredDevice(int power)
//	{
//		std::cout << "PowerDevice: " << power << '\n'; //有参构造函数
//	}
//};
//class Scanner :public PoweredDevice
//{
//public:
//	Scanner(int scanner, int power)
//		:PoweredDevice{ power } //显式调用有参的父类构造函数，不然会报错
//	{
//		std::cout << "Scanner" << scanner << '\n';
//	}
//};
//
//class Printer :public PoweredDevice
//{
//public:
//	Printer(int printer, int power)
//		:PoweredDevice{ power }
//	{
//		std::cout << "Printer:" << printer << '\n';
//	}
//};
//
//class Copier :public Scanner, public Printer
//{
//public:
//	Copier(int scanner, int printer, int power)
//		:Scanner{ scanner,power }, Printer{ printer,power }
//	{
//
//	}
//};
class Base
{
protected:
	int my_value{};
public:
	Base(int value)
		:my_value{ value }
	{
	}

	virtual ~Base() = default;

	virtual std::string_view getName() const { return "Base"; }
	int getValue()const { return my_value; }
};

class Derived :public Base
{
public:
	Derived(int value)
		:Base{ value }
	{
	}

	std::string_view getName() const override { return "Derived"; }
};

void printName(const Base base)
{
	std::cout << "I am a " << base.getName() << '\n';
}


int main()
{
	/*Cat cat{ "Betsy" };
	std::cout << cat.getName() << "says" << cat.speak() << '\n';*/
	//Copier copier{ 1,2,3 };//Scanner 1，3-》P 3->S 1->P->3->P-》2
	/*Derived derived{ 5 };*/
	/*std::cout << "derived is a " << derived.getName() << " and has value "<<derived.getValue() << '\n';*/

	//Base& ref{ derived };
	//std::cout << "ref is a " << ref.getName() << "  and has value " << ref.getValue() << '\n'; //引用Derived。ref是derived对象的别名

	//Base* ptr{ &derived };
	//std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';//基类指针指向派生类的地址，其实还是指向派生类对象
	//Base base{ derived };
	//std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';
	/*printName(derived);*/

	//std::vector<Base> v{}; //创建一个Base对象的动态数组
	//v.push_back(Base{ 5 });//vector按值存储对象，每个对象都是Base类型，因此创建了一个Base对象，存的值为5
	//v.push_back(Derived{ 6 });//vector是Base类型，因此发生切片，只保留Dreived对象的Base部分

	//for (const auto& element : v)
	//	std::cout << "I am a " << element.getName() << "with value  " << element.getValue() << '\n';
	/*std::vector<std::reference_wrapper<Base>> v{};
	Base b{ 5 };
	Derived d{ 6 };

	v.push_back(b);
	v.push_back(d);

	for (const auto& element : v)
		std::cout << "I am a " << element.get().getName() << " with value" << element.get().getValue() << '\n';
	return 0;*/

	//std::vector<Base*>v{};//指针数组，存储对象的地址

	//Base b{ 5 };//创建值为5的Base对象
	//Derived d{ 6 };//创建值为6的Derived对象

	//v.push_back(&b);//将对象b的地址传入数组
	//v.push_back(&d);//再把对象d的地址传入数组对象d的地址其实就是一种Derived*的指针，然后Derived*指针可以转向Base*指针

	//for (const auto* element : v)
	//	std::cout << "I am a " << element->getName() << " with value" << element->getValue() << '\n';
	Derived d1{ 5 };//创建d1对象
	Derived d2{ 6 };//创建d2对象
	Base& b{ d2 };//b指向d2

	b = d1;//d2 = d1
}

