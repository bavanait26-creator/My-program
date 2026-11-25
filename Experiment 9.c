#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    float mark;
};

union Contact
{
    char phone[15];
};

int main()
{
    struct Student s;
    union Contact c;
    FILE *fp;

    printf("Enter roll number: ");
    scanf("%d", &s.rollno);

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter mark: ");
    scanf("%f", &s.mark);

    printf("Enter phone number: ");
    scanf("%s", c.phone);

    fp = fopen("student.txt", "w");

    if(fp == NULL)
        return 0;

    fprintf(fp, "%d\n%s\n%.2f\n%s\n",
            s.rollno, s.name, s.mark, c.phone);

    fclose(fp);

    fp = fopen("student.txt", "r");

    if(fp == NULL)
        return 0;

    fscanf(fp, "%d %s %f %s",
           &s.rollno, s.name, &s.mark, c.phone);

    printf("\nSTUDENT DETAILS\n");
    printf("Roll Number: %d\n", s.rollno);
    printf("Name: %s\n", s.name);
    printf("Mark: %.2f\n", s.mark);
    printf("Phone: %s\n", c.phone);

    fclose(fp);

    return 0;
}
