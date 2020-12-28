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
  for (const auto& [key, value] : data_tasks[person]){
    count_task_current = static_cast<int>(key);
    if (count_task_current > task_count){
      int value_for_untouched = count_task_current - task_count;
      untouched.insert({TaskStatus::NEW, value_for_untouched});
      update.insert({TaskStatus::IN_PROGRESS, task_count});
    }
  }

  return tuple<TaskInfo, TaskInfo>(update, untouched);
}
