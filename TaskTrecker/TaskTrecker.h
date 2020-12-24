#ifndef TASKTRECKER_H_
#define TASKTRECKER_H_

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
	tuple<TaskInfo, TaskInfo> PerforPersonTasks(
		const string& person, int task_count);
private:
	vector<string> data_tasks;
};

#endif // !TASKTRECKER_H_
