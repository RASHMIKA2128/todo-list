#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "To-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << endl;
    } while (choice != 5);
    
    return 0;
}
