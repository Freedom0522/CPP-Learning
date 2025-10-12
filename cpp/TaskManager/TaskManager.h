#pragma
#define  TASK_MANAGER_H

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

struct Task{
    string title;
    int priority;
    bool completed = false;

    Task(string t, int p);
};
class  TaskManager{
    private:
    vector<Task> allTasks;
    priority_queue<int,vector<int>,less<int>>highPriority;
    list<Task> completed;
    stack<Task> undoStack;
    queue<Task> waitng;

    public:
    void addTask(const string& name,int p);
    void completeTask();
    void undoLast();

    void showAll()const;
    void showCompleted()const;
    void findTask(const string& name)const;

    void sortByPriority();
    void reverseAll();
};

