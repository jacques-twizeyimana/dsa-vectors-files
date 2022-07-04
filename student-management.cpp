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

    void printStudent() {
        cout <<"\t\t"<< id << "\t\t"<< name << "\t\t" << email << "\t\t" << age << "\t\t" << grade << endl;
    }
};

Student getStudentDataFromUser() {
    Student std = Student();

    cout << "\t\tEnter student name: ";
    cin >> std.name;
    cout << "\t\tEnter student email: ";
    cin >> std.email;
    cout << "\t\tEnter student age: ";
    cin >> std.age;    

    std.setGrade(0);
    std.id = generate_id();
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
        cout << "\t\tERROR: File not found" << endl;
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


bool updateStudent(int id) {

    vector <Student> students = readStudentsFromFile();

    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).id == id) {            
            // update student
            Student updatedStudent = getStudentDataFromUser();
            updatedStudent.id = id;
            students.at(i) = updatedStudent;

            //delete file and write updated students to file
            remove("students.csv");
            writeStudentsInFile(students);
            return true;
        }
    }
    return false;

}

bool deleteStudent(int id){
    fstream file;
    vector<Student> students = readStudentsFromFile();

    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).id == id) {
            //delete student at this index
            students.erase(students.begin() + i);

            // delete file and insert updated students
            remove("students.csv");
            writeStudentsInFile(students);
            return true;
        }
    }
    return false;
}

int main() {
    vector <Student> students;
    //student management system
    //user menu

    int choice,studentId;
    do {
        cout << "\n\t__________________________________________________________________________\n\n";
        cout << "\t\t1. ADD STUDENT"<<endl;
        cout << "\t\t2. UPDATE STUDENT"<<endl;
        cout << "\t\t3. DELETE STUDENT"<<endl;
        cout << "\t\t4. SHOW ALL STUDENTS"<<endl;
        cout << "\t\t5. EXIT"<<endl;
        cout << "\n\t\tEnter your choice: ";
        cin >> choice;
        cout <<endl<<endl;

        switch (choice) {
            case 1:
                students.clear();
                students.push_back(getStudentDataFromUser());
                writeStudentsInFile(students);
                break;
            case 2:
                cout << "\t\tEnter student id: ";
                cin >> studentId;
                if (updateStudent(studentId)) {
                    cout << "\n\t\tSTUDENT UPDATED SUCCESSFULLY" << endl;
                } else {
                    cout << "\n\t\tSTUDENT NOT FOUND" << endl;
                }
                break;
            case 3:
                cout << "\t\tEnter student id: ";
                cin >> studentId;
                if (deleteStudent(studentId)) {
                    cout << "\n\t\tSTUDENT DELETED SUCCESSFULLY" << endl;
                } else {
                    cout << "\n\t\tSTUDENT NOT FOUND" << endl;
                }
                break;
            case 4:
                students = readStudentsFromFile();

                if(students.size() == 0){
                    cout << "\n\t\tNO STUDENTS FOUND" << endl;
                } else {
                    cout << "\n\t\tID\t\tNAME\t\tEMAIL\t\t\t\tAGE\t\tGRADE" << endl << endl;
                    for (int i = 0; i < students.size(); i++) {
                        students.at(i).printStudent();
                    }
                }
                break;
            case 5:
                break;
            default:
                cout << "\n\t\tINVALID CHOICE" << endl;
        }
    } while (choice != 5);

    return 0;
}