#include <iostream>
using namespace std;

struct User {
    int id;
    string name;
    string reason;
    string date;
};

struct Stack {
    User arr[10];
    int top = -1;

    bool is_full() { return top == 9; }
    bool is_empty() { return top == -1; }

    void pushReturnRequest(User val) {
        if (is_full()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = val;
    }

    void peekLatestRequest() {
        if (is_empty()) {
            cout << "No requests available." << endl;
            return;
        }
        cout << "\nLatest Request:" << endl;
        cout << "ID: " << arr[top].id << "\n"
             << "Name: " << arr[top].name << "\n"
             << "Reason: " << arr[top].reason << "\n"
             << "Date: " << arr[top].date << endl;
    }

    void popReturnRequest() {
        if (is_empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "\nPopped Request ID: " << arr[top].id 
             << " (" << arr[top].name << ")" << endl;
        top--;
    }

    void displayAllRequests() {
        if (is_empty()) {
            cout << "No return requests in the stack." << endl;
            return;
        }

        cout << "\nAll Return Requests (Top to Bottom):\n";
       
        for (int i = top; i >= 0; i--) {
            cout << "ID: " << arr[i].id << "\n"
                 << "Name: " << arr[i].name << "\n"
                 << "Reason: " << arr[i].reason << "\n"
                 << "Date: " << arr[i].date << "\n";
        }   
        
    }
};

int main() {
    Stack s;
    s.pushReturnRequest({182, "Fizzah", "Defective item", "12 Oct 2025"});
    s.pushReturnRequest({122, "Waqar", "Incorrect item", "13 Oct 2025"});
    s.pushReturnRequest({145, "Hira", "Size issue", "14 Oct 2025"});

    s.displayAllRequests();
    s.peekLatestRequest();
    s.popReturnRequest();
    s.displayAllRequests();
    
    return 0;
}
