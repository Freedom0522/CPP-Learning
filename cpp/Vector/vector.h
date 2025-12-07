
#pragma once
#include <cstddef>
#include<iostream>
#include<algorithm>
#include<cstring>

namespace clz{
    template<class T>
    class vector{
        public:
        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin(){
            return _start;
        }

        iterator end(){
            return _finish;
        }

        const_iterator begin() const{
            return _start;
        }

        const_iterator end() const{
            return _finish;
        } //const iterator

        T& operator[](size_t pos){
            assert(pos < size());
            return _start[pos]; //*(_start+pos)
        }

        const T& operator[](size_t pos) const{
            assert(pos <size());
            return _start[pos];
        }

        void push_back(const T& n){
            // if(_finish == _endofstorage){
            //     int newcapacity = capacity() ==0?2:2*capacity();
            //     reserve(newcapacity);
            // }
            // *_finish = n;
            // ++_finish;
            insert(_finish,n);
        }

        void pop_back(){
            // assert(_start<_finish);
            // // --_finish;
            erase(_finish-1);
        }

        void insert(iterator pos,const T& x){
            // assert(_start<_finish);
            assert(pos>=_start);
            assert(pos<=_finish);
            //size_t sz = size()
            if(_finish == _endofstorage){
                size_t n = pos - _start;
                int newcapacity = capacity() ==0?2:2*capacity();
                reserve(newcapacity);
                pos = _start+n;
            }
            iterator end = _finish - 1;
            while(end >= pos){
                *(end+1)=*end;//Data shift back
                --end;
            }
            *pos= x;
            ++_finish;
        }

        iterator erase(iterator pos){
            assert(pos < _finish);
            iterator it = pos;
            while(it < _finish){
                *it = *(it+1);
                ++it;
            }
            --_finish;
            return pos; //return new element followed the last element

        }

        void reserve(size_t n){
            if(n>capacity()){
                T*tmp=new T[n];
                size_t sz = size();
                if(_start){
                    //memcpy(tmp,_start,sizeof(T) * sz);//shen qiankaobei
                    for(size_t i = 0;i < sz;++i){
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = tmp+sz;//_finish = tmp+size();
                _endofstorage = tmp + n;//_endofstorage = tmp+cpacity();
            }
        }

        void resize(size_t n,T val = T()){//T() Default value
            if(n>capacity()){
                // int newcapacity = capacity() ==0?2:2*capacity();
                // reserve(newcapacity);
                // _finish = _start+n;
                reserve(n);
            }
            // else{
            //     if(n>size()){
            //     _finish=_start+n;
            //    }
            // }
            if(n>size()){
                while(_finish<_start+n){
                    *_finish = val;
                    ++_finish;
                }
            }
            else{
                _finish = _start+n;
            }
            // else{
            //     if(n>size()){
            //         _finish = _start+n;
            //     }
            // }

            // if(n > size()){
            //     T* tmp = new T[n];
            //     size_t sz = size();
            //     if(_start){
            //         memcpy(tmp,_start,sizeof(T)*sz);
            //         delete _start;
            //     }
            //     _start = tmp;
            //     _finish = tmp+n;
            //     //_endofstorage =tmp +n;
            //     if(_finish==_endofstorage){
            //         int newcapacity = capacity() == 0?2:2*capacity();
            //         reserve(newcapacity);
            //     }
            // }
            

        }

        size_t capacity()const{
            return _endofstorage - _start;
        }

        size_t size() const{
            return _finish-_start;
        }

        vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endofstorage(nullptr){}

       

        
        // vector(int n,const T& val= T())
        // :_start(nullptr)
        // ,_finish(nullptr)
        // ,_endofstorage(nullptr){
        //     reserve(n);
        //     for(int i = 0;i < n;++i){
        //         push_back(val);
        //     }
        // }

        //v2(v1) 
        // vector(const vector<int>& v){
        //     _start = new T[v.capacity()];
        //     _finish = _start;
        //     _endofstorage = _start + v.capacity();

        //     for(size_t i = 0;i < v.size();i++){
        //         *_finish = v[i];
        //         ++_finish;
        //     }
        // }

        vector(const vector<int>& v)
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endofstorage(nullptr)
            {
                reserve(v.capacity());
                for(auto& e:v){
                    push_back(e);
                }
            }
        
        //v = v3
        // vector<T>& operator=(const vector<T>& v){
        //     if(this != &v){
        //         delete[] _start;
        //         _start = new T[v.capacity()];
        //         memcpy(_start,v._start,sizeof(T)*v.size());
        //         _finish = _start+v.size();
        //         _endofstorage = _start +v.capacity(); //new capacity change _start,_finish,_endofstorage

        //     }
        //     return *this;
        // }

        vector<T>& operator=(vector<T>& v){
            swap(v);
            return *this;
        } //swap(v,v2) and v1.swap(v2)

        void swap(vector<T>& v){
            ::swap(_start,v._start);
            ::swap(_finish,v._finish);
            ::swap(_endofstorage,v._endofstorage);

        }

        // vector(size_t n,const T& val= T())
        // :_start(nullptr)
        // ,_finish(nullptr)
        // ,_endofstorage(nullptr)
        // {
        //     reserve(n);
        //     for(size_t i = 0;i<n;++i){
        //         push_back(val);
        //     }
        // }
    private:
    iterator _start;
    iterator _finish;
    iterator _endofstorage;

    };

    void print_vector(const vector<int>& v){
        for(auto e:v){
            cout << e << " ";
        }
        cout << endl;
    }
    void test(){
            vector<int>v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            // v.insert(_finish,1);

            for(auto e:v){
                std::cout << e << " ";
            }
            std::cout << std::endl;
            std::cout << v.size() <<v.capacity()<< std::endl;
            v.resize(10);
            std::cout << v.capacity() << std::endl;
            std::cout<< v.size() <<endl;
        }
        void test2(){
            vector<int>v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            v.push_back(5);

            v.insert(v.begin(),0);
            print_vector(v);

            vector<int>::iterator it = v.begin();
            while(it != v.end()){
                if(*it % 2 == 0){
                    it = v.erase(it);
                }
                else{
                    ++it;
                }
            }
            print_vector(v);

        }

        void test3(){
            vector<int>v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            v.push_back(5);

            vector<int>v2(v);
            for(size_t i = 0;i <v.size();++i){
                cout <<v[i]<<" ";
            }
            cout << endl;
            cout << v.size() << endl;
            // for(size_t i = 0;i <v2.size();++i){
            //     cout <<v2[i]<<" ";
            // }
            // cout << endl;
            vector<int> v3;
            v3.push_back(10);
            v3.push_back(20);
            v3.push_back(30);

            v = v3;
           // cout << v.size() << endl;
            for(auto e:v){
                cout << e << " ";
            }
            cout << endl;

        }
        
        void test_vector5(){
            vector<string> v;
            v.push_back("111111111111111111111111");
            v.push_back("222222222222222222222222");
            v.push_back("333333333333333333333333");
            // v.push_back("44444444444444444444444444444");

            for(auto e:v){
                cout << e << " ";
            }
            cout << endl;


        }


}
