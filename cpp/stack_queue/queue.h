#pragma once
#include<vector>
#include<list>
#include<deque>

namespace clz
{
    template<class T,class Container>

    class queue{
        public:
        void push(const T& x){
            _con.push_back(x);
        }
        void pop(){
            _con.pop_front();
        }
        size_t Size(){
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        T& front(){
            return _con.front();
        }

        T& back(){
            return _con.back();
        }
        private:
               Container _con;

    };
    /**
     * Container 将Container转换为我们所需要的容器 容器进行适配转换
     * deque
     */

    void test_queue(){
        // queue<int,std::vector<int>> q; 
        /**
         * vector不支持pop_front，因为vector头插头删效率太低，需要移动整个数组
         */
        queue<int,list<int>>q;
       
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);

        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
/**
 *  deque双端队列:任意位置插入删除
 * 支持随机访问，既有vector的优点，也有list的优点
 */
}



/**
 * stl中的stack和queue是通过容器适配转换出来的，不是原生实现的->复用
 */