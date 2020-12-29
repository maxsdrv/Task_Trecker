#include "tasktrecker.h"

const TaskInfo &TaskTrecker::GetPersonTaskInfo(const string &person) const {
  return data_tasks.find(person)->second;
}

void TaskTrecker::AddNewTask(const string &person) {
  if (data_tasks.count(person) == 0) {
    data_tasks.insert({person,
                       {{TaskStatus::NEW, 1},
                        {TaskStatus::IN_PROGRESS, 0},
                        {TaskStatus::TESTING, 0},
                        {TaskStatus::DONE, 0}}});
  } else {
    data_tasks.at(person).at(TaskStatus::NEW)++;
  }
}

tuple<TaskInfo, TaskInfo> TaskTrecker::PerformPersonTasks(const string &person,
                                                          int task_count) {

  TaskInfo update;
  TaskInfo untouched;
  int count_task_current = 0;
  auto current_status = static_cast<TaskStatus>(count_task_current);
  for (const auto& [key, value] : data_tasks[person]){
    if (value >= task_count){
      untouched.insert({current_status, ++count_task_current});
      current_status = static_cast<TaskStatus>(count_task_current);
      update.insert({current_status, task_count});
    }
  }
  /*for (const auto& [key, value] : data_tasks[person]){
    count_task_current = static_cast<int>(key);
    if (count_task_current > task_count){
      int value_for_untouched = count_task_current - task_count;
      untouched.insert({current_status, value_for_untouched});
    }
  }*/

  return tuple<TaskInfo, TaskInfo>(update, untouched);
}

void TaskTrecker::UpdateDataTasks(const string& person, const TaskInfo& task_info)
{
  for (const auto& [key, value] : task_info){
    data_tasks[person].erase(key);
    data_tasks[person].insert({key, value});
  }
}

