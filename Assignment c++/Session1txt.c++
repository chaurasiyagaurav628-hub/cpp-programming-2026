// Question :1
// Write a simple C program tasklist_c.c that allows you to add up to 5 tasks (as strings) to a global array and print all tasks using a for loop.

// Answer::
 
#include <stdio.h>

char tasks[5][100];

int main() {
    int n, i;

    printf("Enter number of tasks (max 5): ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 5) {
        printf("Invalid number of tasks!");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(tasks[i], 100, stdin);
    }

    printf("\nTask List:\n");

    for (i = 0; i < n; i++) {
        printf("%d. %s", i + 1, tasks[i]);
    }

    return 0;
}

// Question :2
// Modify your tasklist_c.c to add a function markTaskDone(int index) that sets the selected task to 'DONE' in the array, then print the updated list.<br><br><em><strong>Hint:</strong> Use a separate status array or append ' - DONE' to the task string.</em>

// Answer::
#include <stdio.h>
#include <string.h>

char tasks[5][100];
int status[5] = {0};

void markTaskDone(int index) {
    status[index] = 1;
}

int main() {
    int n, i, choice;

    printf("Enter number of tasks (max 5): ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > 5) {
        printf("Invalid number of tasks!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter task %d: ", i + 1);
        fgets(tasks[i], 100, stdin);

        tasks[i][strcspn(tasks[i], "\n")] = '\0';
    }

    printf("\nEnter task number to mark as DONE (1-%d): ", n);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= n) {
        markTaskDone(choice - 1);
    } else {
        printf("Invalid task number!\n");
    }

    printf("\nUpdated Task List:\n");

    for (i = 0; i < n; i++) {
        if (status[i] == 1) {
            printf("%d. %s - DONE\n", i + 1, tasks[i]);
        } else {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }

    return 0;
}
// Question :3
// Create a Task class in your favorite OOP language (Java, Python, or C++) with properties: title and isDone. Add a method markDone() that sets isDone to true, and a method display() that prints the task with its status.

// Answer::

#include <iostream>
#include <string>
using namespace std;

class Task {
public:
    string title;
    bool isDone;

    Task(string t) {
        title = t;
        isDone = false;
    }

    void markDone() {
        isDone = true;
    }

    void display() {
        cout << "Task: " << title << endl;
        cout << "Status: ";

        if (isDone) {
            cout << "DONE" << endl;
        } else {
            cout << "PENDING" << endl;
        }
    }
};

int main() {
    Task t1("Learn C++");

    t1.display();

    t1.markDone();

    t1.display();

    return 0;
}

// Question:4
// Build a simple TaskList class/object that stores multiple Task objects and provides addTask(title), markTaskDone(index), and showTasks() methods. Demonstrate adding 3 tasks, marking one as done, and displaying all tasks with their statuses.

// Answer::



```cpp
#include <iostream>
#include <string>
using namespace std;

class Task {
public:
    string title;
    bool isDone;

    Task() {
        title = "";
        isDone = false;
    }

    Task(string t) {
        title = t;
        isDone = false;
    }

    void markDone() {
        isDone = true;
    }

    void display() {
        cout << "Task: " << title << " | Status: ";

        if (isDone) {
            cout << "DONE";
        } else {
            cout << "PENDING";
        }

        cout << endl;
    }
};

class TaskList {
private:
    Task tasks[5];
    int count;

public:
    TaskList() {
        count = 0;
    }

    void addTask(string title) {
        if (count < 5) {
            tasks[count] = Task(title);
            count++;
        }
    }

    void markTaskDone(int index) {
        if (index >= 0 && index < count) {
            tasks[index].markDone();
        }
    }

    void showTasks() {
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            tasks[i].display();
        }
    }
};

int main() {
    TaskList myTasks;

    myTasks.addTask("Learn C");
    myTasks.addTask("Learn C++");
    myTasks.addTask("Complete Assignment");

    myTasks.markTaskDone(1);

    cout << "Task List:" << endl;
    myTasks.showTasks();

    return 0;
}
```

// Question:5
// Compare your procedural C version and OOP TaskList version: List 3 problems you faced in the C version that were solved by using classes and methods in the OOP version.

// Answer:
// . Data Management:
// In C, data and functions are separate. In OOP, data and methods are combined inside a class.

// . Code Reusability:
// In C, managing similar tasks may require writing extra code. In OOP, classes and objects make code reuse easier.

// . Data Protection:
// In C, data can be accessed directly if it is in a global variable. In OOP, private members can protect data from direct access.


