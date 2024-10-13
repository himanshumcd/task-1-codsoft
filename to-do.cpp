#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    // Add a new task to the list
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added successfully!" << endl;
    }

    // View all tasks with their status
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "Task List: " << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description
                 << (tasks[i].completed ? " [Completed]" : " [Pending]") << endl;
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
        } else {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        }
    }

    // Remove a task from the list
    void remove(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
        } else {
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task removed " << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDesc;
    int taskNum;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the leftover newline character after entering the choice

        switch (choice) {
            case 1:
                // Add task
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;

            case 2:
                // View tasks
                todoList.viewTasks();
                break;

            case 3:
                // Mark task as completed
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNum;
                todoList.markTaskAsCompleted(taskNum);
                break;

            case 4:
                // Remove task
                cout << "Enter the task number to remove: ";
                cin >> taskNum;
                todoList.remove(taskNum);
                break;

            case 5:
                // Exit
                cout << "Exiting" << endl;
                return 0;

            default:
                cout << "Invalid ." << endl;
        }
    }

    return 0;
}
