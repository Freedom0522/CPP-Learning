#pragma once
#include<iostream>
namespace clz
{
    template<class T>
    struct list_node{
        list_node<T>* _next;
        list_node<T>* _prev;
        T _data;

        list_node(const T& x)
        :_next(nullptr)
        ,_prev(nullptr)
        ,_data(x)
        {}
    };


    // template<class T,class Ref,class Ptr>
    // struct _list_iterator{
    //     typedef list_node<T> node;
    //     typedef _list_iterator<T,Ref,Ptr>Self;
    //     node* _pnode;
    //     _list_iterator(node* p)
    //     :_pnode(p)
    //     {}

    //     Ptr operator->(){
    //         return &_pnode->_data;
    //     }

    //     Ref operator*(){
    //         return _pnode->_data;
    //     }

    //     Self& operator++(){
    //         _pnode = _pnode->_next;
    //         return *this;
    //     }

    //     Self operator++(int){
    //         Self tmp(*this);
    //         _pnode = _pnode->_next;
    //         return tmp;
    //     }

    //     Self operator--(){
    //         _pnode = _pnode ->_prev;
    //         return *this;
    //     }

    //     Self operator--(int){
    //         Self tmp(*this);
    //         _pnode = _pnode->_prev;
    //         return tmp;
    //     }

    //     bool operator!=(const Self& it)const{
    //         return _pnode != it._pnode;
    //     }

    //     bool operator==(const Self& it)const{
    //         return _pnode == it._pnode;
    //     }
    // };

    template<class T>
    struct _list_iterator{
        typedef list_node<T> node;
        node* _pnode;

        _list_iterator(node* p)
        :_pnode(p)
        {}

        T& operator*(){
            return _pnode->_data;
        }
        T* operator->(){
            return &_pnode->_data;
        }

        _list_iterator<T>& operator++(){
            _pnode = _pnode->_next;
            return *this;
        }

        _list_iterator<T>& operator++(int){
            _list_iterator<T> tmp(*this);
            ++(*this);

            return tmp;
        }

        _list_iterator<T>& operator--(){
            _pnode = _pnode->_prev;
            return *this;
        }

        _list_iterator<T>& operator--(int){
            _list_iterator<T> tmp(*this);
            --(*this);

            return  tmp;

        }

        bool operator!=(const _list_iterator<T>& it){
            return _pnode!=it._pnode;
        }
    };

    template<class T>
    class list{
        typedef list_node<T> node;
        public:
        typedef _list_iterator<T> iterator;
        // typedef _list_iterator<T,const T&>const_iterator;

        iterator begin(){
            return iterator(_head->_next);
        }

        // const_iterator begin() const{
        //     return const_iterator(_head->_next);
        // }

        iterator end(){
            return iterator(_head);
        }

        // const_iterator end()const{
        //     return const_iterator(_head);
        // }

        // void empty_initialize(){
        //     _head = new node(T());
        //     _head->_next = _head;
        //     _head->_prev = _head;

        //     _size = 0;
        // }

    //     list(){
    //         empty_initialize();
    //     }

        //lt2(lt1)
        // list(const list<T>& lt){
        //     empty_initialize();

        //     for(const auto& e : lt){
        //         push_back(e);
        //     }
        // }

        // //lt1 = lt3
        // list<T>& operator=(const list<T>& lt){
        //     if(this != &lt){
        //         clear();
        //         for(const auto& e : lt){
        //             push_back(e);
        //         }
        //     }
        //     return *this;
        // }

        // template <class InputIterator>
        // list(InputIterator first,InputIterator last)
        // {
        //     empty_initialize();
        //     while(first != last){
        //         push_back(*first);
        //         ++first;
        //     }
        // }

        // void swap(list<T>& lt){
        //     std::swap(_head,lt._head);
        //     std::swap(_size,lt._size);
        // }

        // list(const list<T>& lt){
        //     empty_initialize();

        //     list<T> tmp(lt.begin(),lt.end());
        //     swap(tmp);
        // }

        // list<T>& operator=(list<T> lt){
        //     swap(lt);
        //     return *this;
        // }
        // T* operator->(){
        //     return &_pnode->_data;
        // }

        // size_t size() const{
        //     return _size;
        // }

        // bool empty() const{
        //     return _size == 0;
        // }



        list(){
            _head = new node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }
        // list(const list<T>& lt);
        // list<T>& operator(const list<T>& lt);

        // ~list(){
        //     clear();
        //     delete _head;
        //     _head = nullptr;

        // }

        // void clear(){
        //     iterator it = begin();
        //     while(it != end()){
        //         // erase(it++);
        //         it = erase(it);
        //     }
        // }

        void push_back(const T& x){
            node* newnode = new node(x);
            node* tail = _head->_prev;

            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next= _head;
            _head->_prev = newnode;
            // _size++;
        }

        void pop_back(){
            // erase(--end());
        }
        // void push_front(const T& x){
        //     insert(begin(),x);
        // }
        void pop_front(){
            // erase(begin());
        }
        // iterator insert(iterator pos,const T& x){
        //     node* newnode = new node(x);
        //     node* cur = pos._pnode;
        //     node* prev = cur->_prev;

        //     prev->_next = newnode;
        //     newnode->_prev = prev;
        //     newnode->_next = cur;
        //     cur->_prev = newnode;

        //     ++_size;
        //     return iterator(newnode);
        // }
        // iterator erase(iterator pos){
        //     assert(pos!= end());

        //     node* prev = pos._pnode->_prev;
        //     node* next = pos._pnode->_next;

        //     prev->_next = next;
        //     next->_prev = prev;

        //     delete pos._pnode;
        //     --_size;

        //     return iterator(next);
        // }

        private:
        node* _head;
        // size_t _size;
    };


// void test_list2(){
//     // std::cout<<"list 2"<<std::endl;
//     list<Date> lt;
//     lt.push_back(Date());
//     lt.push_back(Date());

//     list<Date>::iterator it = lt.begin();
//     while(it != lt.end()){
//         // std::cout << *it << " ";
//         std::cout << it->_year<<"-"<<it->_month<<"-"<<it->_day<<" ";
//     }
//     std::cout << std::endl;
// }
void test_list1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    list<int>::iterator it = lt.begin();
    while(it != lt.end()){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;



    for(auto e:lt){
        std::cout << e << " ";
    }
   std::cout << std::endl;
}

struct Date{
    int _year = 0;
    int _month =1;
    int _day = 1;

};
// void test_list2(){}
void test_list2(){
    list<Date> lt;
    lt.push_back(Date());
    lt.push_back(Date());

    list<Date>::iterator it = lt.begin();
    while(it != lt.end()){
        // std::cout << *it << " ";
        std::cout << it->_year<<"-"<<it->_month<<"-"<<it->_day<<" ";
        ++it;
    }
    std::cout << std::endl;
}
// void print_list(const list<int>& lt){
//     list<int>::const_iterator it = lt.begin();
//     while(it != lt.end()){
//         std::cout << *it << std::endl;
//         ++it;
//     }
// }
void test_list3(){
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);


}


} // namespace clz还有什么问题码 