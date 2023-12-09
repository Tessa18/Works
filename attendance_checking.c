#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    char name[50];
    bool isPresent;
};

void markAttendance(struct Student students[], int numStudents) {
    printf("Marking Attendance:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Is %s present? (1 for yes, 0 for no): ", students[i].name);
        int input;
        while (scanf("%d", &input) != 1 || (input != 0 && input != 1)) {
            printf("Invalid input. Please enter 1 for yes or 0 for no: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        students[i].isPresent = input;
    }
}

void displayAttendance(struct Student students[], int numStudents) {
    printf("Attendance Report:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %s\n", students[i].name, students[i].isPresent ? "Present" : "Absent");
    }
}

void searchStudent(struct Student students[], int numStudents) {
    char searchName[50];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("%s is %s\n", students[i].name, students[i].isPresent ? "Present" : "Absent");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void calculateAttendanceStats(struct Student students[], int numStudents) {
    int totalPresent = 0;
    int totalAbsent = 0;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].isPresent) {
            totalPresent++;
        } else {
            totalAbsent++;
        }
    }

    printf("Attendance Statistics:\n");
    printf("Total Present: %d\n", totalPresent);
    printf("Total Absent: %d\n", totalAbsent);
    printf("Attendance Percentage: %.2f%%\n", (float)totalPresent / numStudents * 100);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        students[i].isPresent = false;
    }

    markAttendance(students, numStudents);
    displayAttendance(students, numStudents);

    searchStudent(students, numStudents);

    calculateAttendanceStats(students, numStudents);

    return 0;
}
