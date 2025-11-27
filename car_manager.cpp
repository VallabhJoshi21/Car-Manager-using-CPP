#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// -----------------------
// Car Part Class
// -----------------------
class CarPart {
public:
    string name;
    string type;
    float length, width, height;

    CarPart() {}

    CarPart(string n, string t, float l, float w, float h) {
        name = n;
        type = t;
        length = l;
        width = w;
        height = h;
    }

    void display() {
        cout << "Part Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Dimensions: " << length << " x " << width << " x " << height << endl;
        cout << "-----------------------------" << endl;
    }
};

// -----------------------
// Manager Class
// -----------------------
class CarDesignManager {
private:
    CarPart parts[50]; // Array storage
    int count;

    stack<string> undoStack;   // Undo recording
    queue<string> taskQueue;   // Upcoming tasks

public:
    CarDesignManager() {
        count = 0;
    }

    // Add Car Part
    void addPart() {
        if (count >= 50) {
            cout << "Storage Full! Cannot add more parts.\n";
            return;
        }

        string name, type;
        float l, w, h;

        cout << "Enter Part Name: ";
        cin >> name;
        cout << "Enter Type (Engine/Body/Interior/etc): ";
        cin >> type;
        cout << "Enter Length Width Height: ";
        cin >> l >> w >> h;

        parts[count] = CarPart(name, type, l, w, h);
        count++;

        undoStack.push("Added " + name);
        cout << "Part Added Successfully!\n";
    }

    // Remove Car Part
    void removePart() {
        if (count == 0) {
            cout << "No parts available to remove.\n";
            return;
        }

        string removedName = parts[count - 1].name;
        count--;

        undoStack.push("Removed " + removedName);
        cout << "Part Removed Successfully!\n";
    }

    // Search Part
    void searchPart() {
        string name;
        cout << "Enter part name to search: ";
        cin >> name;

        for (int i = 0; i < count; i++) {
            if (parts[i].name == name) {
                cout << "Part Found!\n";
                parts[i].display();
                return;
            }
        }
        cout << "Part not found.\n";
    }

    // Display All Parts
    void showParts() {
        if (count == 0) {
            cout << "No parts available.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            parts[i].display();
        }
    }

    // Undo last operation
    void undoLast() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }
        cout << "Undo Action: " << undoStack.top() << endl;
        undoStack.pop();
    }

    // Add a design task
    void addTask() {
        string t;
        cout << "Enter task name: ";
        cin >> t;
        taskQueue.push(t);
        cout << "Task Added!\n";
    }

    // Process a task
    void processTask() {
        if (taskQueue.empty()) {
            cout << "No tasks in queue.\n";
            return;
        }
        cout << "Processing Task: " << taskQueue.front() << endl;
        taskQueue.pop();
    }
};

// -----------------------
// Main Menu
// -----------------------
int main() {
    CarDesignManager manager;
    int choice;

    while (true) {
        cout << "\n======== Car 3D Part Manager ========\n";
        cout << "1. Add Car Part\n";
        cout << "2. Remove Car Part\n";
        cout << "3. Search Car Part\n";
        cout << "4. Show All Parts\n";
        cout << "5. Undo Last Action\n";
        cout << "6. Add Design Task\n";
        cout << "7. Process Next Task\n";
        cout << "8. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addPart(); break;
            case 2: manager.removePart(); break;
            case 3: manager.searchPart(); break;
            case 4: manager.showParts(); break;
            case 5: manager.undoLast(); break;
            case 6: manager.addTask(); break;
            case 7: manager.processTask(); break;
            case 8: return 0;
            default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}
