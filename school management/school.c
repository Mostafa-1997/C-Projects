#include "school.h"
#include <stdio.h>
#include <stdlib.h>

void School_selectionSortByname(struct student *p,int size)
{
    int i,j,last=size-1,index_m;
    struct student temp;
    for(i=0; i<size; i++)
    {
        index_m=0;
        for(j=0; j<=last; j++)
        {
            if(string_compareSort_NotCaseSensetive(p[j].name,p[index_m].name)==1)
            {
                index_m=j;
            }
        }
        temp=p[index_m];
        p[index_m]=p[last];
        p[last]=temp;
        last--;
    }
}

void School_selectionSortByage(struct student *p,int size)
{
    int i,j,last=size-1,index_m;
    struct student temp;
    for(i=0; i<size; i++)
    {
        index_m=0;
        for(j=0; j<=last; j++)
        {
            if(p[j].age>p[index_m].age)
            {
                index_m=j;
            }
        }
        temp=p[index_m];
        p[index_m]=p[last];
        p[last]=temp;
        last--;

    }
}

void student_scanByAddress(struct student *ps)
{
    printf("Enter name: ");
    string_scan(ps->name,20);
    printf("Enter age: ");
    scanf("%d",&ps->age);
    fflush(stdin);
    printf("Enter grade: ");
    scanf(" %c",&ps->grade);
    if (ps->grade>='a' && ps->grade<'z')
    {
        ps->grade=ps->grade-32;
    }
    printf("enter mobile: ");
    string_scan(ps->mobile,12);
    for (int i=0; i<8; i++)
    {
        ps->score[i]=0;
    }
}

void SchoolPrint(struct student *ps,int size)
{
    system("cls");
    for (int i=0; i<size; i++)
    {
        printf("ID: %d\tName: %s \tAge: %d\tGrade: %c\tMobile: %s\n\n",i+1,ps[i].name,ps[i].age,ps[i].grade,ps[i].mobile);
    }
}

int SchoolSearch(struct student *ps,int size)
{
    int i,index;
    int c=Choices(1,2);
    if (c==1)
    {
        system("cls");
        char search[20];
        printf("Enter Name: ");
        string_scan(search,20);
        for (i=0; i<size; i++)
        {
            if (string_compareNotcaseSenstive(search,ps[i].name))
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        system("cls");
        printf("Enter ID: ");
        scanf("%d",&index);
        fflush(stdin);
        if (index>size || index<0)
        {
            return -1;
        }
        index--;
        return index;
    }
}

void School_EditStudent (struct student *p)
{
    system("cls");
    printf("1-Edit Age\n2-Edit Grade\n3-Edit Mobile\n");
    int c=Choices(1,3);
    if (c==1)
    {
        system("cls");
        printf("New age= ");
        scanf("%d",&p->age);
        fflush(stdin);
        if (p->grade>='a' && p->grade<'z')
        {
            p->grade=p->grade-32;
        }
    }
    else if (c==2)
    {
        system("cls");
        printf("New grade= ");
        scanf(" %c",&p->grade);
    }
    else
    {
        system("cls");
        printf("New mobile= ");
        string_scan(&p->mobile,12);
    }
}

void SaveSchool (struct student *school,int num_students)
{
    FILE *fp;
    fp = fopen("school.dat", "wb");
    fwrite(school, sizeof(struct student), num_students, fp);
    fclose(fp);
}

void PrintStudent (struct student *p)
{
    char* subjects[]= {"Arabic","English","French","Math","Chemistry","Physics","Biology","Total"};
    int i;
    printf("Name: %s \tAge: %d\tGrade: %c\tMobile: %s\n",p[0].name,p[0].age,p[0].grade,p[0].mobile);
    for (i=0; i<7; i++)
    {
        printf("%10s = %d/50\t%.2f%%\n",subjects[i],p[0].score[i],((float)p[0].score[i]/50)*100);
    }
    printf("%10s = %d/350\t%.2f%%\n",subjects[i],p[0].score[i],((float)p[0].score[i]/350)*100);
    printf("\n");
}

void CallStudent (struct student *p)
{
    system("cls");
    printf("Calling %s",p->name);
    for (int i=0; i<3; i++)
    {
        printf(".");
        usleep(500000);
        printf(".");
        usleep(500000);
        printf(".");
        usleep(500000);
        if (i<2)
        {
            printf("\b\b\b");
            printf("   ");
            printf("\b\b\b");
            usleep(500000);
        }
        else
        {
            system("cls");
        }
    }
    printf("No Answer!\n\n");
}

void AddScores (struct student *p)
{
    char* subjects[]= {"Arabic","English","French","Math","Chemistry","Physics","Biology"};
    int score,total=0;
    for (int i=0; i<7; i++)
    {
        printf("%s = ",subjects[i]);
        scanf("%d",&score);
        fflush(stdin);
        if (score<0 || score>50)
        {
            printf("Inavlid score");
        }
        while (score<0 || score>50)
        {
            scanf("%d",&score);
            fflush(stdin);
            if (score<0 || score>50)
            {
                printf("Inavlid score");
            }
        }
        p->score[i]=score;
        total=total+score;
    }
    p->score[7]=total;
}
