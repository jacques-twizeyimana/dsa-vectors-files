#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Student {
    public:
        string name;
    string email;
    int age;
    double grade;

    Student() {}
    Student(string givenName, string givenEmail, int ageN) {
        name = givenName;
        email = givenEmail;
        age = ageN;
        grade = 0;
    }

    void setGrade(int g) {
        grade = g;
    }

    string toString() {
        return name + "," + email + "," + to_string(age) + "," + to_string(grade);
    }
};

Student getStudentDataFromUser() {
    Student std = Student();

    cout << "Enter student name: ";
    cin >> std.name;
    cout << "Enter student email: ";
    cin >> std.email;
    cout << "Enter student age: ";
    cin >> std.age;

    std.setGrade(0);
    return std;
}

void writeStudentsInFile(vector<Student> students) {
    fstream file;
    //write students to file
    file.open("students.csv", ios:: in );

    if (!file) {
        file.close();
        file.open("students.csv", ios::app);
        file << "name,email,age,grade" << endl;
    } else {
        file.close();
        file.open("students.csv", ios::app);
    }

    //loop students and insert in file
    for (int i = 0; i < students.size(); i++) {
        Student std = students.at(i);
        file << std.toString() << endl;
    }

    file.close();
}

void readStudentsFromFile(){
    fstream file;
    file.open("students.csv", ios::in);

    if (!file) {
        cout << "File not found" << endl;
    } 
    else{
        string line;
        
        while(getline(file,line)){          
            cout << line << endl;
        }
    }

    file.close();
}

int main() {
    vector < Student > students;

    // int n;
    // cout << "How many students do you want to enter? ";
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     cout << "\n_________________________________________________________\n";
    //     cout << endl << "\t\t\t STUDENT No " << i + 1 << endl << endl;
    //     students.push_back(getStudentDataFromUser());
    //     cout << "_________________________________________________________" << endl << endl;
    // }

    // writeStudentsInFile(students);

    readStudentsFromFile();

    return 0;
}