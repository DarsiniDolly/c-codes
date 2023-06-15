#include <stdio.h>

struct Student {
    char fname[50];
    int roll;
    int mark1;
    int mark2;
    int mark3;
    char gender;
    int total;
    char result;
} s[100];

int main() {
    int i, k, rn;
    char g;
    int pass = 0, fail = 0; 

    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < 3; i++) {
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
        printf("Enter gender (M/F): ");
        scanf(" %c", &s[i].gender); 
        s[i].total = s[i].mark1 + s[i].mark2 + s[i].mark3;

        // Determine pass/fail
        if (s[i].total > 150) {
            s[i].result = 'P';
            pass++;
        } else {
            s[i].result = 'F';
            fail++;
        }
    }

    printf("\nDisplaying Information:\n\n");

    // displaying information
    for (i = 0; i < 3; i++) {
        printf("\nRoll number: %d\n", i + 1);
        printf("Name: %s\n", s[i].fname);
        printf("Mark1: %d\n", s[i].mark1);
        printf("Mark2: %d\n", s[i].mark2);
        printf("Mark3: %d\n", s[i].mark3);
        printf("Gender: %c\n", s[i].gender);
        printf("Total: %d\n", s[i].total);
        printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
    }

    printf("\nNumber of students passed: %d\n", pass);
    printf("Number of students failed: %d\n", fail);

    printf("\nEnter the roll number to find the student details: \n");
    scanf("%d", &rn);

    for (i = 0; i < 3; i++) {
        if (s[i].roll == rn) {
            k = i; // for finding the position of the student
            printf("\nRecord found at position no %d \n", k + 1);
            printf("Name: %s\n", s[k].fname);
            printf("Roll number: %d\n", s[k].roll);
            printf("Marks: %d\n", s[k].total);
            printf("Result: %s\n", s[k].result == 'P' ? "Passed" : "Failed");

            printf("\nUpdate marks for the student (roll number %d):\n", s[k].roll);
            printf("Enter new mark1: ");
            scanf("%d", &s[k].mark1);
            printf("Enter new mark2: ");
            scanf("%d", &s[k].mark2);
            printf("Enter new mark3: ");
            scanf("%d", &s[k].mark3);
            s[k].total = s[k].mark1 + s[k].mark2 + s[k].mark3;

            // Update pass/fail status
            if (s[k].total > 150) {
                s[k].result = 'P';
            } else {
                s[k].result = 'F';
            }

            printf("\nMarks updated successfully!\n");
            printf("Updated total: %d\n", s[k].total);
            printf("Updated result: %s\n", s[k].result == 'P' ? "Passed" : "Failed");
            break;
        }
    }

    printf("\nEnter the gender (M/F) to find the student details: \n");
    scanf(" %c", &g);

    for (i = 0; i < 3; i++) {
        if (s[i].gender == g) {
            printf("\nName: %s\n", s[i].fname);
            printf("Roll number: %d\n", s[i].roll);
            printf("Marks: %d\n", s[i].total);
            printf("Result: %s\n", s[i].result == 'P' ? "Passed" : "Failed");
        }
    }

    return 0;
}
