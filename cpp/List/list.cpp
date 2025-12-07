#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

void test_list1(){
    std::list<int> lt;
    //vector<int> v;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    std::list<int>::iterator it = lt.begin();
    while(it != lt.end())
    {
        std::cout<<*it<<" ";
        it++;
    }
    std::cout<<std::endl; //iterator

    std::list<int>::reverse_iterator rit = lt.rbegin();
    while(rit != lt.rend()){
        std::cout<<*rit<<" ";
        ++rit;
    }
    std::cout<<std::endl; 

    lt.push_front(10);
    lt.push_front(20);
    lt.push_front(30);
    lt.push_front(40);
   
    for(auto e:lt){
        std::cout << e << " ";
    }

    std::cout<<std::endl;

    lt.pop_back();
    lt.pop_back();
    lt.pop_back();
    lt.pop_back();

    for(auto e:lt){
        std::cout << e << " ";
    }

    std::cout<<std::endl;
}
void print_lt(std::list<int> lt){
    for(auto e: lt){
        std::cout << e  << " ";
    }
    std::cout<<std::endl;
}

void test_list2(){
    std::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    lt.sort();
    print_lt(lt);
    lt.reverse();
    print_lt(lt);

    auto pos = std::find(lt.begin(),lt.end(),3);
    if(pos != lt.end()){
        lt.insert(pos,30);
        pos = lt.erase(pos); //shixiao
    }

    std::cout << *pos << std::endl;
    *(pos)++;

    for(auto e: lt){
        std::cout << e  << " ";
    }
    std::cout<<std::endl;
    lt.erase(pos);
    for(auto e: lt){
        std::cout << e  << " ";
    }
    std::cout<<std::endl;

}
void test_list3(){
    std::list<int> lt;
    lt.push_back(10);
    lt.push_back(2);
    lt.push_back(5);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(4);
    lt.push_back(6);
    lt.push_back(4);
    lt.push_back(0);

    print_lt(lt);
    lt.remove(3);
    print_lt(lt);
    lt.remove(30);
    print_lt(lt);

    lt.sort();
    print_lt(lt);

    lt.unique();
    print_lt(lt);
}

void test_list5(){
    std::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);

    std::list<int>::iterator it = lt.begin();
    while(it != lt.end()){
        if(*it % 2 == 0){
            it = lt.erase(it);
        }
        else{
            ++it;
        }
    }
    print_lt(lt);
}

void test_op(){
    srand(time(0));
    const int N = 100000;
    std::vector<int> v;
    v.reserve(N);

    std::list<int> lt1;
    std::list<int> lt2;

    for(int i = 0;i < N;++i){
        auto e = rand();
        lt1.push_back(e);
        lt2.push_back(e);
    }

    int begin1 = clock();
    for(auto e: lt1){
        v.push_back(e);
    }
    sort(v.begin(),v.end());
    size_t i = 0;
    for(auto& e: lt1){
        e = v[i++];
    }
    int end1 = clock();

    int begin2 = clock();

    lt2.sort();
    int end2 = clock();

    printf("vector sort:%d\n",end1-begin1);
    printf("list sort:%d\n",end2-begin2);

}
// using namespace std;

#include"list.h"

int main(){
    //test_list1();
    //test_list2();
    // test_list5();
    // test_list3();
    //test_op();
    clz::test_list2();

}