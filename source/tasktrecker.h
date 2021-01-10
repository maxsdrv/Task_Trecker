#ifndef TASKTRECKER_H_
#define TASKTRECKER_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TaskInfo = map<TaskStatus, int>;

class TaskTrecker {
public:
    const TaskInfo& GetPersonTaskInfo(const string& person)const;
    void AddNewTask(const string& person);
    tuple<TaskInfo, TaskInfo> PerformPersonTasks(
        const string& person, int task_count);
    void UpdateDataTasks(const string& person, const TaskInfo& task_info);
private:
    map<string, TaskInfo> data_tasks;
};

#endif // !TASKTRECKER_H_
