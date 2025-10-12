#include "TaskManager.h"

// ===============================
// Task 构造函数
// ===============================
Task::Task(string t, int p)
    : title(std::move(t)), priority(p) {}

// ===============================
// 添加任务
// ===============================
void TaskManager::addTask(const string& name, int p) {
    allTasks.emplace_back(name, p);
    highPriority.push(p);
    waiting.push(Task(name, p));
    cout << "✅ 添加任务: " << name << " (优先级 " << p << ")\n";
}

// ===============================
// 完成优先级最高的任务
// ===============================
void TaskManager::completeTask() {
    if (highPriority.empty()) {
        cout << "⚠️ 没有任务可完成。\n";
        return;
    }

    int topPriority = highPriority.top();
    highPriority.pop();

    auto it = find_if(allTasks.begin(), allTasks.end(),
                      [&](const Task& t){ return !t.completed && t.priority == topPriority; });

    if (it != allTasks.end()) {
        it->completed = true;
        completed.push_back(*it);
        undoStack.push(*it);
        cout << "🎯 完成任务：" << it->title << " (优先级 " << it->priority << ")\n";
    }
}

// ===============================
// 撤销最近完成的任务
// ===============================
void TaskManager::undoLast() {
    if (undoStack.empty()) {
        cout << "⚠️ 没有可撤销的任务。\n";
        return;
    }

    Task last = undoStack.top();
    undoStack.pop();
    last.completed = false;

    completed.remove_if([&](const Task& t){ return t.title == last.title; });
    highPriority.push(last.priority);

    cout << "↩️ 撤销完成任务：" << last.title << endl;
}

// ===============================
// 展示所有任务
// ===============================
void TaskManager::showAll() const {
    cout << "\n📋 所有任务：\n";
    for (const auto& t : allTasks)
        cout << " - " << t.title << " [" << (t.completed ? "完成" : "待办")
             << "] 优先级:" << t.priority << endl;
}

// ===============================
// 展示已完成任务（使用 reverse_iterator）
// ===============================
void TaskManager::showCompleted() const {
    cout << "\n✅ 已完成任务（反向输出）：\n";
    for (auto it = completed.rbegin(); it != completed.rend(); ++it)
        cout << " - " << it->title << " (优先级:" << it->priority << ")\n";
}

// ===============================
// 查找任务（find_if）
// ===============================
void TaskManager::findTask(const string& name) const {
    auto it = find_if(allTasks.begin(), allTasks.end(),
                      [&](const Task& t){ return t.title == name; });
    if (it != allTasks.end())
        cout << "🔍 找到任务：" << it->title << "（优先级 " << it->priority << "）\n";
    else
        cout << "❌ 未找到任务：" << name << endl;
}

// ===============================
// 按优先级排序（sort + 仿函数）
// ===============================
void TaskManager::sortByPriority() {
    sort(allTasks.begin(), allTasks.end(),
         [](const Task& a, const Task& b){ return a.priority > b.priority; });
    cout << "\n📈 按优先级排序完成。\n";
}

// ===============================
// 反转任务顺序（reverse）
// ===============================
void TaskManager::reverseAll() {
    reverse(allTasks.begin(), allTasks.end());
    cout << "\n🔁 已反转任务顺序。\n";
}
