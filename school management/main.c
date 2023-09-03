#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "school.h"



int main()
{
    FILE *fp;
    struct student *school;
    int num_students;
begin:
    if (access("school.dat", F_OK) != -1)
    {
        fp = fopen("school.dat", "rb+");
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        num_students = file_size / sizeof(struct student);
        rewind(fp);
        school = (struct student *) malloc(num_students * sizeof(struct student));
        fread(school, sizeof(struct student), num_students, fp);
        fclose(fp);
    }
    else
    {
        fp = fopen("school.dat", "wb+");
        goto begin;
    }
    while (1)
    {
        printf("Please enter the number of your choice\n1-Add student\n2-Edit student info\n3-Record student's Scores\n4-Print student\n5-Delete student\n6-Print School\n7-Call student\n8-Quit\n\n");
        int c=Choices(1,8),index;
        if(c==1)
        {
            system("cls");
            struct student new_student;
            student_scanByAddress(&new_student);
            school = (struct student *) realloc(school, (num_students + 1) * sizeof(struct student));
            school[num_students] = new_student;
            num_students++;
            SaveSchool(school,num_students);
            system("cls");
            continue;
        }
        else if (c==2)
        {
            system("cls");
            printf("1-Edit student by name\n2-Edit student by ID\n");
            index=SchoolSearch(school,num_students);
            if (index<0)
            {
                system("cls");
                printf("Student not found!\n\n");
                continue;
            }
            printf("Name: %s \tAge: %d\tGrade: %c\tMobile: %s\n\n",school[index].name,school[index].age,school[index].grade,school[index].mobile);
            School_EditStudent(school+index);
            SaveSchool(school,num_students);
            system("cls");
        }
        else if (c==3)
        {
            system("cls");
            printf("1-Record student by name\n2-Record student by ID\n");
            index=SchoolSearch(school,num_students);
            if (index<0)
            {
                system("cls");
                printf("Student not found!\n\n");
                continue;
            }
            AddScores(school+index);
            SaveSchool(school,num_students);
            system("cls");
        }
        else if (c==4)
        {
            system("cls");
            printf("1-Print student by name\n2-Print student by ID\n");
            index=SchoolSearch(school,num_students);
            if (index<0)
            {
                system("cls");
                printf("Student not found!\n\n");
                continue;
            }
            system("cls");
            PrintStudent(school+index);
        }
        else if (c==5)
        {
            system("cls");
            printf("1-Delete student by name\n2-Delete student by ID\n");
            index=SchoolSearch(school,num_students);
            if (index<0)
            {
                system("cls");
                printf("Student not found!\n\n");
                continue;
            }
            for (int i=index; i<num_students-1; i++)
            {
                school[i]=school[i+1];
            }
            num_students--;
            SaveSchool(school,num_students);
            system("cls");
        }
        else if(c==6)
        {
            SchoolPrint(school,num_students);
        }
        else if (c==7)
        {
            system("cls");
            printf("1-Call by name\n2-Call by ID\n");
            index=SchoolSearch(school,num_students);
            if (index<0)
            {
                system("cls");
                printf("Student not found!\n\n");
                continue;
            }
            CallStudent(school+index);
        }
        else
        {
            return 0;
        }

    }
    return 0;
}
