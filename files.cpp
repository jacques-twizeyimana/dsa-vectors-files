#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<fstream>

using namespace std;

//generate random id
int generate_id()
{
    int id;
    srand(time(NULL));
    id = rand() % 1000000;
    return id;
}


class Student {
    public:
        int id;
        string name;
        string email;
        int age;
        double grade;

    Student() {}
    Student(string givenName, string givenEmail, int ageN) {
        name = givenName;
        email = givenEmail;
        age = ageN;
        id = generate_id();
        grade = 0;

    }

    Student(int userId,string givenName, string givenEmail, int ageN) {
        name = givenName;
        email = givenEmail;
        age = ageN;
        id = userId;
        grade = 0;
    }

    void setGrade(int g) {
        grade = g;
    }

    string toString() {
        return to_string(id) + "," + name + "," + email + "," + to_string(age) + "," + to_string(grade);
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
        file << "id,name,email,age,grade" << endl;
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

vector<Student> readStudentsFromFile(){
    vector<Student> students;

    fstream file;
    file.open("students.csv", ios::in);

    if (!file) {
        cout << "File not found" << endl;
    } else {
        string line;
        int i = 0;

        while (getline(file, line)) {
            //skip first line
            if (i == 0) {
                i++;
                continue;
            }
            //split line by comma
            stringstream ss(line);
            string id,name, email, age, grade;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, age, ',');
            getline(ss, grade, ',');

            Student std = Student(stoi(id), name, email, stoi(age));
            std.setGrade(stoi(grade));
            students.push_back(std);
            i++;
        }
    }

    file.close();
    return students;
}

int main() {
    vector < Student > students;

    int n;
    cout << "How many students do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n_________________________________________________________\n";
        cout << endl << "\t\t\t STUDENT No " << i + 1 << endl << endl;
        students.push_back(getStudentDataFromUser());
        cout << "_________________________________________________________" << endl << endl;
    }

    writeStudentsInFile(students);

    vector<Student> stds = readStudentsFromFile();
    //print stds
    for (int i = 0; i < stds.size(); i++) {
        Student std = stds.at(i);
        cout << std.toString() << endl;
    }

    return 0;
}