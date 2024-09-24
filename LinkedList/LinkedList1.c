#include <stdio.h>
#include <stdlib.h>

typedef struct Lesson
{
    char lessonName[50];
    int midtermGrade;
    int finalGrade;
    struct Lesson *nextLesson;
}StuLesson;

typedef struct Student
{
    char name[50];
    char surname[50];
    int stuNumber;
    StuLesson *lessons;
    struct Student *nextStu;
}Stu;

Stu *Students = NULL;

StuLesson *lessonAdd(StuLesson *lessons)
{
    if(lessons == NULL)
    {
        lessons = (StuLesson*)malloc(sizeof(StuLesson));
        puts("Ders Adi: ");
        scanf("%s",lessons->lessonName);
        puts("")
    }
    else
    {

    }
}

Stu *studentAdd(Stu *students)
{
    int lessonNumber;
    if(students == NULL)
    {
        students = (Stu*)malloc(sizeof(Stu));
        puts("Ad: ");
        scanf("%s",students->name);
        puts("Soyad: ");
        scanf("%s",students->surname);
        students->stuNumber = 24001;
        students->lessons = NULL;
        students->nextStu = students;
    }
    else
    {
        while(students->nextStu)
        {
            students = students->nextStu;
        }
        students = (Stu*)malloc(sizeof(Stu));
        puts("Ad: ");
        scanf("%s",students->name);
        puts("Soyad: ");
        scanf("%s",students->surname);
        students->stuNumber++;
        students->lessons = NULL;
        students->nextStu = students;  
    }
    return students;
}

void main()
{
    int choose;
    while(1)
    {
        printf("        Ogrenci Ders Sistemi\n");
        printf("    Ders Ekleme Islemleri       ---> 1\n");
        printf("    Listeleme Islemleri         ---> 2\n");
        printf("    Silme Islemleri             ---> 3\n");
        printf("    Siralama Islemleri          ---> 4\n");
        puts("Islem secimi: ");
        scanf("%d",&choose);
        system("cls");
        if (choose == 1)
        {
            Students = Addition(Students);

        }
        else if (choose == 2)
        {
            /* code */
        }
        else if(choose == 3)
        {
            /* code */
        }
        else if (choose == 4)
        {
            /* code */
        }
        else if(choose == 5)
        {
            break;
        }
    }
}