#include <iostream>
#include <stdlib.h>
#include <string>

using std::string;

int main()
{
    char** subjects;
    int* grades;
    int subjectCount, maxSubjectSize = 0;
    std::cout << "Enter amount of subjects: ";
    std::cin >> subjectCount;

    subjects = (char**)malloc(subjectCount * sizeof(char*));
    grades = (int*)malloc(subjectCount * sizeof(int));

    for (int subject = 0; subject < subjectCount; subject++) {
        string name;
        float grade;
        std::cout << "Enter subject No." << subject + 1 << " name: ";
        std::cin >> name;
        std::cout << "Enter " << name << " grade: ";
        std::cin >> grade;
        *(grades + subject) = (int)(grade + 0.5);
        name.append("^");
        *(subjects + subject) = (char*)malloc(name.length() * sizeof(char));
        for (int c_name = 0; c_name < name.length(); c_name++) {
            *(*(subjects + subject) + c_name) = (char)name[c_name];
        }
    }

    for (int subject = 0; subject < subjectCount; subject++) {
        std::cout << std::endl;
        int c_name = 0;
        while (*(*(subjects + subject) + c_name) != '^') {
            std::cout << *(*(subjects + subject) + c_name);
            c_name++;
        }
        std::cout << ": " << *(grades + subject);
    }
}