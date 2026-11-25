#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    char attendance;
};

int main()
{
    struct Student s[50];
    FILE *fp;
    int n, i, present = 0, absent = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter roll number: ");
        scanf("%d", &s[i].rollno);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Attendance (P/A): ");
        scanf(" %c", &s[i].attendance);

        if(s[i].attendance == 'P' ||
           s[i].attendance == 'p')
            present++;
        else
            absent++;
    }

    fp = fopen("attendance.txt", "w");

    if(fp == NULL)
        return 0;

    fprintf(fp, "Attendance Report\n");

    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%d %s %c\n",
        s[i].rollno, s[i].name,
        s[i].attendance);
    }

    fclose(fp);

    printf("\nATTENDANCE REPORT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %s %c\n",
        s[i].rollno, s[i].name,
        s[i].attendance);
    }

    printf("\nTotal Present = %d", present);
    printf("\nTotal Absent = %d", absent);

    return 0;
}
