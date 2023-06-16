#include <stdio.h>
#include <string.h>

struct Student {
    char fname[50];
    int roll;
    int mark1;
    int mark2;
    int mark3;
    char gender[10];
    int total;
    char result;
} s[100];

void manageStudents() {
    int i, k, rn;
    int pass = 0, fail = 0; 
    int count = 3; 

    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < count; i++) {
        s[i].roll = i + 1;
        printf("\nFor roll number %d,\n", s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].fname);
        printf("Enter mark1: ");
        scanf("%d", &s[i].mark1);
        printf("Enter mark2: ");
        scanf("%d", &s[i].mark2);
        printf("Enter mark3: ");
        scanf("%d", &s[i].mark3);
        printf("Enter gender: ");
        scanf("%s", s[i].gender); 
        s[i].total = s[i].mark1 + s[i].mark2 + s[i].mark3;

        // Determine pass/fail
        if (s[i].total > 170) {
            s[i].result = 'P';
            pass++;
        } else {
            s[i].result = 'F';
            fail++;
        }
    }

    printf("\nDisplaying Information:\n\n");

    // displaying information
    for (i = 0; i < count; i++) {
        printf("\nRoll number: %d\n", i + 1);
        printf("Name: %s\n", s[i].fname);
        printf("Mark1: %d\n", s[i].mark1);
        printf("Mark2: %d\n", s[i].mark2);
        printf("Mark3: %d\n", s[i].mark3);
        printf("Gender: %s\n", s[i].gender);
        printf("Total: %d\n", s[i].total);
        printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
    }

    printf("\nNumber of students passed: %d\n", pass);
    printf("Number of students failed: %d\n", fail);


    printf("\nEnter the gender to find the student details: \n");
    char gendertochoose[10];
    scanf("%s", gendertochoose);

    for (i = 0; i < count; i++) {
        if (strcmp(s[i].gender, gendertochoose) == 0) {
            printf("\nName: %s\n", s[i].fname);
            printf("Roll number: %d\n", s[i].roll);
            printf("Marks: %d\n", s[i].total);
            printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
        }
    }

    printf("\nEnter the name of the student to delete: \n");
    char nameToDelete[50];
    scanf("%s", nameToDelete);

    // Find and delete the student by name
    for (i = 0; i < count; i++) {
        if (strcmp(s[i].fname, nameToDelete) == 0) {
            k = i; // Position of the student to delete
            printf("\nName: %s\n", s[i].fname);
            printf("Roll number: %d\n", s[i].roll);
            printf("Marks: %d\n", s[i].total);
            printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
            break;
        }
    }

    if (k != count) {
        // Shift remaining elements to fill the gap
        for (i = k; i < count - 1; i++) {
            strcpy(s[i].fname, s[i + 1].fname);
            s[i].roll = s[i + 1].roll;
            s[i].mark1 = s[i + 1].mark1;
            s[i].mark2 = s[i + 1].mark2;
            s[i].mark3 = s[i + 1].mark3;
            strcpy(s[i].gender, s[i + 1].gender);
            s[i].total = s[i + 1].total;
            s[i].result = s[i + 1].result;
        }

        count--; // Decrease the count of students
        printf("\nDeleted the student successfully!\n");
    } else {
        printf("\nStudent not found!\n");
    }

    printf("\nUpdated Information:\n\n");

    // Display updated information
    for (i = 0; i < count; i++) {
        printf("\nRoll number: %d\n", i + 1);
        printf("Name: %s\n", s[i].fname);
        printf("Mark1: %d\n", s[i].mark1);
        printf("Mark2: %d\n", s[i].mark2);
        printf("Mark3: %d\n", s[i].mark3);
        printf("Gender: %s\n", s[i].gender);
        printf("Total: %d\n", s[i].total);
        printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
    }

    printf("\nEnter the roll number of the student to update marks: \n");
    scanf("%d", &rn);

    // Find and update student details by roll number
    for (i = 0; i < count; i++) {
        if (s[i].roll == rn) {
            printf("\nCurrent Details:\n");
            printf("Name: %s\n", s[i].fname);
            printf("Roll number: %d\n", s[i].roll);
            printf("Marks: %d\n", s[i].total);
            printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");

            printf("\nEnter new mark1: ");
            scanf("%d", &s[i].mark1);
            printf("Enter new mark2: ");
            scanf("%d", &s[i].mark2);
            printf("Enter new mark3: ");
            scanf("%d", &s[i].mark3);
            s[i].total = s[i].mark1 + s[i].mark2 + s[i].mark3;

            // Update pass/fail status
            if (s[i].total > 170) {
                s[i].result = 'P';
            } else {
                s[i].result = 'F';
            }

            printf("\nUpdated Details:\n");
            printf("Name: %s\n", s[i].fname);
            printf("Roll number: %d\n", s[i].roll);
            printf("Marks: %d\n", s[i].total);
            printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");

            break;
        }
    }

    printf("\nFinal Information:\n\n");

    // Display final information
    for (i = 0; i < count; i++) {
        printf("\nRoll number: %d\n", i + 1);
        printf("Name: %s\n", s[i].fname);
        printf("Gender: %s\n", s[i].gender);
        printf("Total: %d\n", s[i].total);
        printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
    }
}

int main() {
    manageStudents();
    return 0;
}
