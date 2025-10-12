#include<iostream>
#include<queue>
#include<functional>

using namespace std;

 #include "stack.h"
#include "queue.h"
#include "priority_queue.h"



 void test_deque(){
        deque<int> d;
        d.push_back(-1);
        d.push_back(1);
        
        d.push_back(2);
        d.push_back(5);
        d.push_back(0);
        d.push_back(10);
        d.push_back(15);

        for(size_t i = 0;i <d.size();++i){
                   cout<<d[i]<<" ";
        }
        cout << endl;
              
    }


    //容器适配器都不支持迭代器遍历，因为它们通常都包含一些特殊的性质
    //如果支持迭代器随便遍历，他们无法很好的保持她的性质
void test_priority_queue()
{
    // priority_queue<int>pq; //默认大的优先级高
    priority_queue<int,vector<int>,greater<int>>pq;//想变得小的优先级高采用仿函数
    pq.push(3);
    pq.push(1);
    pq.push(9);
    pq.push(4);
    pq.push(2);
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

}
//一般情况下，成员变部分私有，部分共有就用class，
//所有成员开放成共有struct
namespace clz{
template<class T>
struct less{
    bool operator()(const T& x1,const T& x2){
        return x1<x2;//仿函数(函数对象)
    }

};
template<class T>
struct greater{
    bool operator()(const T& x1,const T& x2){
        return x1>x2;//仿函数(函数对象)
    }

};
}
int main(){
    clz::test_stack();
    clz::test_queue();
    // cout << "hello" ;
    test_deque();
    clz::test_priority_queue();
    clz::less<int> lessFunc;
    cout << lessFunc(1,2) <<endl;//lessFunc.operator()(1,2)
    return 0;
}
