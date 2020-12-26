#include "TaskTrecker.h"

const TaskInfo& TaskTrecker::GetPersonTaskInfo(const string& person) const
{
    return data_tasks.find(person)->second;
}

void TaskTrecker::AddNewTask(const string& person){
    if (data_tasks.count(person) == 0) {
        data_tasks.insert({ person, {{TaskStatus::NEW, 1},
            {TaskStatus::IN_PROGRESS, 0}, {TaskStatus::TESTING, 0},
            {TaskStatus::DONE, 0}} });
    }
    else {
        data_tasks.at(person).at(TaskStatus::NEW)++;
    }
}

tuple<TaskInfo, TaskInfo> TaskTrecker::PerformPersonTasks(const string& person, int task_count)
{
    TaskInfo update;
    TaskInfo untouched;
    //for (const auto& [key, value] : data_tasks[person]) {
    //    //Not completed
    //}
    
    return tuple<TaskInfo, TaskInfo>();
}
