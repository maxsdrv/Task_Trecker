#include "tasktrecker.h"

const TaskInfo& TaskTrecker::GetPersonTaskInfo(const string& person) const {
	return data_tasks.find(person)->second;
}

void TaskTrecker::AddNewTask(const string& person) {
	if (data_tasks.count(person) == 0) {
		data_tasks.insert({ person,
		{{TaskStatus::NEW, 1},
		{TaskStatus::IN_PROGRESS, 0},
		{TaskStatus::TESTING, 0},
		{TaskStatus::DONE, 0}}
		});
	}
	else {
		data_tasks.at(person).at(TaskStatus::NEW)++;
	}
}

tuple<TaskInfo, TaskInfo> TaskTrecker::PerformPersonTasks(const string& person,
	int task_count) {

	TaskInfo update;
	TaskInfo untouched;
	for (auto status = static_cast<int>(TaskStatus::NEW); status < static_cast<int>(TaskStatus::DONE); ++status) {
		TaskStatus start = static_cast<TaskStatus>(status);
		TaskStatus next = static_cast<TaskStatus>(++status);
		int count_start = 0;

		if (!data_tasks.count(person)) continue;
		if (!update.count(start)) {
			update.insert({ start, 0 });
		}

		while (task_count && data_tasks[person].at(start)) {
			if (!update.count(next)) {
				update.insert({ next, 0 });
			}
			data_tasks[person].at(start)--;
			update.at(start)++;
			--task_count;
		}
	}

	return tuple<TaskInfo, TaskInfo>(update, untouched);
}

void TaskTrecker::UpdateDataTasks(const string& person, const TaskInfo& update, const TaskInfo& untouched)
{
	for (const auto& [key_update, value_update] : update) {
		for (const auto& [key_untouched, value_untouched] : untouched) {
			data_tasks[person].erase(key_untouched);
			data_tasks[person].insert({ key_untouched, value_untouched });
		}
		data_tasks[person].erase(key_update);
		data_tasks[person].insert({ key_update, value_update });
	}
}


