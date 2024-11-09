#include <stdio.h>

struct student {
    char name[40];
    int roll;
    float CPI;
    int backlog;
};

int main() {
    struct student student1;

    printf("Enter Student Name: ");
    scanf("%s", student1.name);

    printf("Enter Student Roll Number: ");
    scanf("%d", &student1.roll);

    printf("Enter Student CPI: ");
    scanf("%f", &student1.CPI);

    printf("Enter Student Backlog: ");
    scanf("%d", &student1.backlog);

    printf("\nStudent using simple structure variable.\n");
    printf("Student name: %s\n", student1.name);
    printf("Student Enrollment: %d\n", student1.roll);
    printf("Student CPI: %f\n", student1.CPI);
    printf("Student Backlog: %i\n", student1.backlog);

    return 0;
}