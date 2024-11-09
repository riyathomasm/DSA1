#include<stdio.h>

struct address{
    int pincode;
    char place[20];
};

struct student{
    int rollno;
    struct address add;
};

int main() {
    struct student s;
    printf("enter rollno: ");
    scanf("%d",&s.rollno);

    printf("enter pincode: ");
    scanf("%d",&s.add.pincode);

    printf("pincode is %d",s.add.pincode);

    return 0;

}