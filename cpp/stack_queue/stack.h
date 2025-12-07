#pragma once
#include<vector>
#include<list>


namespace clz
{
    template<class T,class Container>

    class stack{
        public:
        void push(const T& x){
            _con.push_back(x);
        }
        void pop(){
            _con.pop_back();
        }
        size_t Size(){
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        T& top(){
            return _con.back();
        }
        private:
               Container _con;

    };
    /**
     * 适配器:
     * Container 将Container转换为我们所需要的容器 

     */

    void test_stack(){
        // stack<int,std::vector<int>> st;
        stack<int,list<int>>st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}