#include <stdio.h>

struct student {
    char name[30];
    int rollno;
    float gpa;
};

int main() {
    int n;
    struct student *ptr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    ptr = (struct student *)malloc(n * sizeof(struct student));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", (ptr + i)->name);

        printf("Enter roll number: ");
        scanf("%d", &(ptr + i)->rollno);

        printf("Enter GPA: ");
        scanf("%f", &(ptr + i)->gpa);
    }

    printf("\nStudent Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", (ptr + i)->name);
        printf("Roll number: %d\n", (ptr + i)->rollno);
        printf("GPA: %.2f\n", (ptr + i)->gpa);
    }

    free(ptr);
    return 0;
}