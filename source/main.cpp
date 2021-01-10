#include <iostream>

#include "tasktrecker.h"

using namespace std;

void PrintTaskInfo(TaskInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
    ", " << tasks_info[TaskStatus::IN_PROGRESS] <<
    " tasks in progress" << ", " << tasks_info[TaskStatus::TESTING] <<
    " tasks are being tested" << ", " << tasks_info[TaskStatus::DONE] <<
    " tasks are done" << endl;
}

int main() {
    TaskTrecker tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTaskInfo(tasks.GetPersonTaskInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTaskInfo(tasks.GetPersonTaskInfo("Ivan"));

    TaskInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTaskInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTaskInfo(untouched_tasks);
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTaskInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTaskInfo(untouched_tasks);
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTaskInfo(updated_tasks);

    return 0;
}
