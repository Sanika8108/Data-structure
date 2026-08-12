#include <iostream>
using namespace std;

struct Student {
    int roll;
    char name[30];
    float marks;
};

void display(Student *s, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks << endl;
    }
}

int main() {
    Student s[3];  

    for (int i = 0; i < 3; i++) {
        cout << "Enter Roll No, Name and Marks: ";
        cin >> s[i].roll >> s[i].name >> s[i].marks;
    }

    display(s, 3);  
    return 0;
}
