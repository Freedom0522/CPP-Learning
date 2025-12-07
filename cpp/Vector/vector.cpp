
#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#include"vector.h"

void test_vector1(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);


    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
        ++it;
    }

    cout << endl; 
  
    vector<int>::reverse_iterator rit = v.rbegin();
    while(rit != v.rend()){
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void print_vector(const vector<int>& vt){
    vector<int>::const_iterator it = vt.begin();
    while(it != vt.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

}


void test_vector2(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
     v.push_back(4);
    v.push_back(5);  
    print_vector(v);
    cout << v.capacity() <<  endl;

    v.reserve(4);
    cout << v.capacity() << endl;

    v.resize(8);
    cout << v.capacity() << endl;
    v.resize(15,1);
    cout << v.capacity() << endl;
    v.resize(3);
    
} 

void test_vector3(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);  

   for(auto e:v){
    cout << e << " ";
   }
   cout << endl;

   v.assign(10,1);
   for(auto e:v){
    cout << e <<" ";
   }
   cout << endl;

   vector<int>v1;
   v1.push_back(10);
   v1.push_back(20);
   v1.push_back(30);

   v.assign(v1.begin(),v1.end());

   for(auto e:v){
    cout << e <<" ";
   }
   cout << endl;

   string str("hello world");
   v.assign(str.begin(),str.end());
   for(auto e:v){
    cout << e <<" ";
   }
   cout << endl;

   v.assign(++str.begin(),--str.end());
   for(auto e:v){
    cout << e <<" ";
   }
   cout << endl;

}


void test_vector4(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(v.begin(),4);
    v.insert(v.begin()+2,4);

    vector<int>::iterator it = find(v.begin(),v.end(),3);
    if(it != v.end()){
        v.insert(it,30);
    }

    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v1.swap(v);
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;

    swap(v1,v);

    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
}

void test_vector5(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.reserve(100);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.shrink_to_fit();
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.clear();
    cout << v.size() << endl;
    cout << v.capacity() << endl;


}


void test_vector6(){
     vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);  

    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        if(*it % 2 == 0){
            it = v.erase(it); 
        }
        else{
            ++it;
        }
    }
}

int main(){
    // test_vector1();
    // test_vector2();
    // test_vector3();
    // test_vector4();
    //test_vector5();
    //clz::test();
    //clz::test2();
    // clz::test3();
    clz::test_vector5();
}