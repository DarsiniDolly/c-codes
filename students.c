#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASS_MARK 50

struct Student {
    char name[50];
    char gender;
    int marks[3];
    unsigned int isPass : 1;
};

void updateResult(struct Student *student) {
    for (int i = 0; i < 3; i++) {
        if (student->marks[i] < PASS_MARK) {
            student->isPass = 0;
            return;
        }
    }
    student->isPass = 1;
}

void printStudentDetails(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Gender: %c\n", student.gender);
    printf("Marks: %d, %d, %d\n", student.marks[0], student.marks[1], student.marks[2]);
    printf("Result: %s\n", student.isPass ? "Pass" : "Fail");
}

void printPassedStudents(struct Student *students, int number_of_students) {
    printf("\n--- Passed Students ---\n");
    int passCount = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].isPass) {
            printf("%s\n", students[i].name);
            passCount++;
        }
    }
    if (passCount == 0)
        printf("No students passed.\n");
}

void printFailedStudents(struct Student *students, int number_of_students) {
    printf("\n--- Failed Students ---\n");
    int failCount = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (!students[i].isPass) {
            printf("%s\n", students[i].name);
            failCount++;
        }
    }
    if (failCount == 0)
        printf("No students failed.\n");
}

void deleteStudent(struct Student *students, int *number_of_students, const char *name) {
    for (int i = 0; i < *number_of_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            for (int j = i; j < *number_of_students - 1; j++) {
                students[j] = students[j + 1];
            }
            (*number_of_students)--;
            printf("Student '%s' deleted.\n", name);
            return;
        }
    }
    printf("Student '%s' not found.\n", name);
}

void printGenderStudents(struct Student *students, int number_of_students, char gender) {
    printf("\n--- Students of Gender '%c' ---\n", gender);
    int genderCount = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].gender == gender) {
            printStudentDetails(students[i]);
            genderCount++;
        }
    }
    if (genderCount == 0)
        printf("No students of gender '%c' found.\n", gender);
}

int checkGenderPass(struct Student *students, int number_of_students, char gender) {
    int passCount = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].gender == gender && students[i].isPass)
            passCount++;
    }
    return passCount;
}

void editMarks(struct Student *students, int number_of_students, const char *name) {
    for (int i = 0; i < number_of_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Enter new marks for student '%s':\n", name);
            for (int j = 0; j < 3; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%d", &students[i].marks[j]);
            }
            updateResult(&students[i]);
            printf("Marks for student '%s' modified.\n", name);
            return;
        }
    }
    printf("Student '%s' not found.\n", name);
}

int main() {
    int number_of_students;
    printf("Enter the number of students: ");
    scanf("%d", &number_of_students);

    struct Student *students = (struct Student *)malloc(number_of_students * sizeof(struct Student));

    for (int student = 0; student < number_of_students; student++) {
        printf("\nEnter details for student %d:\n", student + 1);
        printf("Name: ");
        scanf("%s", students[student].name);
        printf("Gender: ");
        scanf(" %c", &students[student].gender);
        printf("Enter marks for student '%s':\n", students[student].name);
        for (int i = 0; i < 3; i++) {
            printf("Subject %d: ", i + 1);
            scanf("%d", &students[student].marks[i]);
        }
        updateResult(&students[student]);
    }

    char gender;
    printf("\nEnter the gender to display students: ");
    scanf(" %c", &gender);
    printGenderStudents(students, number_of_students, gender);

    printf("\nEnter the gender to check pass count: ");
    scanf(" %c", &gender);
    int passCount = checkGenderPass(students, number_of_students, gender);
    printf("Number of %c students who passed: %d\n", gender, passCount);


    int choice;
    char name[50];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Update marks\n");
        printf("2. Delete student\n");
        printf("3. Print passed students\n");
        printf("4. Print failed students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the student to update marks: ");
                scanf("%s", name);
                editMarks(students, number_of_students, name);
                break;
            case 2:
                printf("\nEnter the name of the student to delete: ");
                scanf("%s", name);
                deleteStudent(students, &number_of_students, name);
                break;
            case 3:
                printPassedStudents(students, number_of_students);
                break;
            case 4:
                printFailedStudents(students, number_of_students);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    free(students);

    return 0;
}

