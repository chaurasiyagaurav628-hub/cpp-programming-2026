
// Question::1
// Create a Content class with properties: title, platform, views, and status. Write a method to display all details of a Content object.

// Answer::
#include <iostream>
#include <string>
using namespace std;

class Content {
public:
    string title;
    string platform;
    int views;
    string status;

    void display() {
        cout << "Title: " << title << endl;
        cout << "Platform: " << platform << endl;
        cout << "Views: " << views << endl;
        cout << "Status: " << status << endl;
    }
};

int main() {
    Content c;

    c.title = "My First Video";
    c.platform = "YouTube";
    c.views = 1000;
    c.status = "Uploaded";

    c.display();

    return 0;
}


// Question::2
// Build a console menu that lets users add new content ideas (title, platform, views, status) and save each entry to a text file named content_list.txt.<br><br><em><strong>Hint:</strong> Use file handling to append each new content item to the file.</em>

// Answer::
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string title, platform, status;
    int views, choice;

    do {
        cout << "\n1. Add Content\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter platform: ";
            getline(cin, platform);

            cout << "Enter views: ";
            cin >> views;
            cin.ignore();

            cout << "Enter status: ";
            getline(cin, status);

            ofstream file("content_list.txt", ios::app);

            file << title << endl;
            file << platform << endl;
            file << views << endl;
            file << status << endl;

            file.close();

            cout << "Content saved successfully!\n";
        }

    } while (choice != 2);

    return 0;
}

// Question::3
// Implement a function to read all content items from content_list.txt and display them in a numbered list, showing title and platform for each.

// Answer::

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayContent() {
    ifstream file("content_list.txt");

    string title, platform, status;
    int views, number = 1;

    while (getline(file, title)) {
        getline(file, platform);
        file >> views;
        file.ignore();
        getline(file, status);

        cout << number << ". "
             << title << " - " << platform << endl;

        number++;
    }

    file.close();
}

int main() {
    displayContent();
    return 0;
}



// Question::4
// Add an option in your console app to let users update the status of any content idea by selecting its number from the displayed list and saving the change back to the file.<br><br><em><strong>Hint:</strong> You will need to read all items, modify the selected one, and overwrite the file.</em>

// Answer::

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    ifstream file("content_list.txt");
    ofstream temp("temp.txt");

    string title, platform, status, newStatus;
    int views, number = 1, target;
    bool found = false;

    cout << "Enter content number to update: ";
    cin >> target;
    cin.ignore();

    while (getline(file, title)) {
        getline(file, platform);
        file >> views;
        file.ignore();
        getline(file, status);

        if (number == target) {
            cout << "Enter new status: ";
            getline(cin, newStatus);
            status = newStatus;
            found = true;
        }

        temp << title << endl;
        temp << platform << endl;
        temp << views << endl;
        temp << status << endl;

        number++;
    }

    file.close();
    temp.close();

    if (found) {
        remove("content_list.txt");
        rename("temp.txt", "content_list.txt");
        cout << "Status updated successfully!" << endl;
    } else {
        remove("temp.txt");
        cout << "Invalid content number!" << endl;
    }

    return 0;
}



// Question::5
// Add a feature to delete a content item by its number from the list, update the file accordingly, and display the updated list to confirm deletion.


// Answer::

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    ifstream file("content_list.txt");
    ofstream temp("temp.txt");

    string title, platform, status;
    int views, number = 1, target;
    bool found = false;

    cout << "Enter content number to delete: ";
    cin >> target;

    while (getline(file, title)) {
        getline(file, platform);
        file >> views;
        file.ignore();
        getline(file, status);

        if (number == target) {
            found = true;
        } else {
            temp << title << endl;
            temp << platform << endl;
            temp << views << endl;
            temp << status << endl;
        }

        number++;
    }

    file.close();
    temp.close();

    if (found) {
        remove("content_list.txt");
        rename("temp.txt", "content_list.txt");
        cout << "Content deleted successfully!" << endl;
    } else {
        remove("temp.txt");
        cout << "Invalid content number!" << endl;
    }

    ifstream updatedFile("content_list.txt");

    cout << "\nUpdated Content List:\n";

    number = 1;

    while (getline(updatedFile, title)) {
        getline(updatedFile, platform);
        updatedFile >> views;
        updatedFile.ignore();
        getline(updatedFile, status);

        cout << number << ". "
             << title << " - " << platform << endl;

        number++;
    }

    if (number == 1) {
        cout << "No content found." << endl;
    }

    updatedFile.close();

    return 0;
}


