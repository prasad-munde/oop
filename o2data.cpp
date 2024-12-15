#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;
    string other;

public:
    static int studentCount;

    // Constructor
    Student(string name, int rollNumber, string className, char division, string dateOfBirth,
            string bloodGroup, string contactAddress, string telephoneNumber,
            string drivingLicenseNo, string other)
        : name(name), rollNumber(rollNumber), className(className), division(division),
          dateOfBirth(dateOfBirth), bloodGroup(bloodGroup), contactAddress(contactAddress),
          telephoneNumber(telephoneNumber), drivingLicenseNo(drivingLicenseNo), other(other) {
        studentCount++;
   }

    // Default Constructor
    Student() : rollNumber(0), division('A') {
        studentCount++;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        className = s.className;
        division = s.division;
        dateOfBirth = s.dateOfBirth;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
        other = s.other;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static Member Function
    static int getStudentCount() {
        return studentCount;
    }

    // Friend Class
    friend class StudentDatabase;

    // Inline Member Function
    inline void displayStudent() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className
             << "\nDivision: " << division << "\nDate of Birth: " << dateOfBirth
             << "\nBlood Group: " << bloodGroup << "\nContact Address: " << contactAddress
             << "\nTelephone Number: " << telephoneNumber
             << "\nDriving License No.: " << drivingLicenseNo << "\nOther: " << other << endl;
    }

    // This Pointer
    void setStudentDetails(const string &name, int rollNumber, const string &className,
                           char division, const string &dateOfBirth, const string &bloodGroup,
                           const string &contactAddress, const string &telephoneNumber,
                           const string &drivingLicenseNo, const string &other) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->className = className;
        this->division = division;
        this->dateOfBirth = dateOfBirth;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNo = drivingLicenseNo;
        this->other = other;
    }
};


int Student::studentCount = 0;

class StudentDatabase {
private:
    vector<Student *> students;

public:
    void addStudent(Student *s) {
        students.push_back(s);
    }
    void displayAllStudents() const {
        for (const auto &student : students) {
            student->displayStudent();
            cout << "---------------------------------" << endl;
        }
    }

    ~StudentDatabase() {
        for (auto &student : students) {
            delete student;
        }
    }
};

int main() {
    try {
        StudentDatabase db;

        // Dynamic Memory Allocation
        Student *s1 = new Student("John Doe", 1, "BSc", 'A', "01/01/2000", "O+", "123 Main St",
                                  "1234567890", "DL12345", "None");
        db.addStudent(s1);

        Student *s2 = new Student("Jane Smith", 2, "BSc", 'B', "02/02/2000", "A+", "456 Elm St",
                                  "0987654321", "DL67890", "None");
        db.addStudent(s2);
        cout << "Total Students: " << Student::getStudentCount() << endl;

        db.displayAllStudents();
    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
