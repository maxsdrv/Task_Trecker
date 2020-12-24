#include "TaskTrecker.h"

const TaskInfo& TaskTrecker::GetPersonTaskInfo(const string& person) const
{
    TaskInfo temp;
    return temp;
}

void TaskTrecker::AddNewTask(const string& person)
{
    data_tasks.push_back(person);
}

tuple<TaskInfo, TaskInfo> TaskTrecker::PerforPersonTasks(const string& person, int task_count)
{
    return tuple<TaskInfo, TaskInfo>();
}
