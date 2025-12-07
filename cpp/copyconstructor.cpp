#include<iostream>
#include<cstring>

// struct Vector2{
//      float x,y;

// };

// int main(){
//     // int a = 2;
//     // int b = a;
//     // Vector2 a = {2,3};
//     // Vector2 b = a;
//     // std::cout<<a.x<<b.x<<std::endl;
//     // b.x = 5;
//     // std::cout<<a.x<<b.x<<std::endl;
//     // std::cin.get();
//     Vector2* a = new Vector2();
//     Vector2* b = a;
//     std::cout<<b->x<<a->x<<std::endl;
//     //b++;影响指针
//     b->x = 2;//影响指针所指的内存
//     std::cout<<b->x<<a->x<<std::endl;

// }

class String{
    private:
    char* m_Buffer;
    unsigned int m_Size;
    public:
    String(const char* string){
        m_Size=strlen(string);
        m_Buffer=new char[m_Size+1];// m_Buffer=new char[m_Size];//strcpy
        memcpy(m_Buffer,string,m_Size+1);//Why +1 就添加kong做终止符
        m_Buffer[m_Size]=0;
    }

    // String(const String& other)
    //     : m_Buffer(other.m_Buffer),m_Size(other.m_Size){}
    // String(const String& other){memcpy(this,&other,sizeof(String));}
    // String(const String& other)=delete;禁止拷贝构造 unique_pointer

    String(const String& other)
    :m_Size(other.m_Size){
        std::cout<<"Copy String";
        m_Buffer=new char[m_Size+1];
        memcpy(m_Buffer,other.m_Buffer,m_Size+1);
    }

    ~String(){
        delete[] m_Buffer;
    }
    char& operator[](unsigned index){
        return m_Buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream,const String& string);
};

std::ostream& operator<<(std::ostream& stream,const String& string){
    stream <<string.m_Buffer;// stream << string.GetBuffer();
    return stream; //?
}

void PrintString(String& string){
    // String copy = string;如果想要复制
    string[2]='a';
    std::cout<<string<<std::endl;
}

int main(){
    String string = "Clz";
    String second = string;

    second[2] =='a';
    // std::cout<<string<<std::endl;
    // std::cout<<second<<std::endl;
    PrintString(string);
    PrintString(second);
}