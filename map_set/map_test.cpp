#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<set>
#include <windows.h>
using namespace std;

void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);
    //排序加去重
    set<int>::iterator it = s.begin();
    while(it!=s.end())
    {
        cout << *it <<" ";
        ++it;
    }//不能赋值，常量对象
    cout << endl;

    for(auto e:s)
    {
        cout <<e ;
    }
    cout<<'\n';
    set<int>copy(s);
     for(auto e:copy)
    {
        cout <<e ;
    }
    cout<<'\n';

    // set<int>::iterator pos = s.find(3);//如果找不到，返回end位置（非法位置）O(log(N)),函数模板
    // auto pos = s.find(3);
    set<int>::iterator pos = find(s.begin(),s.end(),3);//上下两种find的区别O(N)，效率较低
    
    if(pos != s.end())
    {
        s.erase(pos);
    }
    //返回迭代器，不合法的位置不可以删
    for(auto e:s)
    {
        cout <<e ;
    }
    cout<<'\n';
}
void test_map()
{
    map<int,int> m;
    //面向文档编程
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(3,3));
    m.insert(pair<int,int>(2,2));//pair构造函数，构造一个匿名对象
    m.insert(make_pair(4,4));//函数模板构造一个对象


    map<int,int>::iterator it = m.begin();
    while(it != m.end())
    {
        //cout << (*it).first << " :"<<(*it).second<<'\n';//由于C++不允许返回两个值，因此返回pair结构，pair不支持输出
        cout << it->first << " :"<<it->second<<'\n';//operator* 返回值是结点中值的引用，operator->返回值是节点中值的指针
        ++it;
    }//中序遍历
    cout << '\n';

    for(auto e:m)
    {
        cout << e.first<<":"<<e.second<<'\n';
    }//为啥这里是e.first而不是（*e).first

}

void test_map2()
{
    std::map<std::string,std::string>dict;
    dict.insert(pair<std::string,std::string>("sort","排序"));
    dict.insert(make_pair("string","字符串"));
    dict.insert(make_pair("left","左边"));//string默认支持比较大小

    std::map<std::string,std::string>::iterator it = dict.begin();
    while(it != dict.end())
    {
        cout<<it->first<<":"<<it->second<<'\n';
        ++it;
    }
}

void test_map3()
{
    string strs[] = {"西瓜","樱桃","西瓜","西瓜","香蕉","香蕉","西瓜","苹果"};
    map<string,int>countMap;
    // for(auto& str:strs)
    // {
    //     //1.如果水果没在map中，则插入成功
    //     //2.如果水果已经在map中，插入失败，通过返回值拿到水果所在的节点迭代器，++次数
    //     pair<map<string,int>::iterator,bool> ret = countMap.insert(make_pair(str,1));
    //     if(ret.second == false)
    //     {
    //         ret.first->second++;
    //     }
    // }
    // for(auto& str:strs)
    // {
    //     map<string,int>::iterator ret = countMap.find(str);
    //     if(ret != countMap.end())
    //     {
    //         ret->second++;
    //     }
    //     else
    //     {
    //         countMap.insert(make_pair(str,1));
    //     }
    // }//还差一种统计方式
    // mappped_type& operator[](const key_type& k)
    // {
    //     return(*((this->insert(make_pair(k,mapped_type()))).first)).second;
    // }
    for(auto& str :strs)
    {
        //1.如果水果不在map中，则[]会插入pair<str,0>,返回映射对象（次数）的引用进行了++
        //2.如果水果在map中，则operator[]返回水果对应的映射对象（次数）的引用，对它++
        countMap[str]++;
    }
    countMap["波罗蜜"];
    countMap["波罗蜜"]=1;
    cout<<countMap["波罗蜜"]<<'\n';
    countMap["哈密瓜"]=5;

    std::map<std::string,std::string>dict;
    dict.insert(make_pair("sort","排序"));
    dict["string"];
    dict["string"]="字符串";
    dict["left"]="左边";

    for(auto& e:countMap)
    {
        cout<<e.first<<":"<<e.second<<'\n';
    }


}

void test_muti()
{
    //允许键值冗余
    multiset<int>ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1);
    ms.insert(4);
    ms.insert(5);
    
    for(auto e:ms)
    {
        cout << e<<" ";
    }
    cout << endl;

    auto pos = ms.find(3);
    cout<<*pos<<endl;
    ++pos;
    cout<<*pos<<endl;
    ++pos;
    cout<<*pos<<endl;
    ++pos;

    //排序加去重
    // set<int>s;
    // s.insert(3);
    // s.insert(2);
    // s.insert(3);
    // s.insert(1);
    // s.insert(4);
    // s.insert(5);
    
    // for(auto e:s)
    // {
    //     cout << e<<" ";
    // }
    // cout << endl;

    //muti_map和map区别上上面一样的
    //附加的是muti_map没有opertaor[],因为当有多个相同的value，不知道返回哪个key对应的value

    multimap<string,int>mm;
    mm.insert(make_pair("苹果",1));
    mm.insert(make_pair("苹果",1));
    mm.insert(make_pair("苹果",1));
    mm.insert(make_pair("西瓜",2));
    mm.insert(make_pair("苹果",1));
    mm.insert(make_pair("西瓜",1));

   





}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // test_set1();
    // test_map();
    // test_map2();
    // test_map3();
    test_muti();
    return 0;
}
