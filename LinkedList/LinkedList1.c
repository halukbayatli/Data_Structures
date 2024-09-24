#include <stdio.h>
#include <stdlib.h>

typedef struct Lesson
{
    struct Lesson *nextLesson;
    lessonName[50];
    int midtermGrade;
    int finalGrade;
}StuLesson;

typedef struct Student
{
    struct Student *nextStu;
    name[50];
    surname[50];
    int stuNumber;
    StuLesson lessons;
}Stu;


void lessonAdd(Stu *students)
{
    while(students != NULL)
    {
        students = students->nextStu;
    }
    puts("Ad: ");
    scanf("%s",students->name);
    puts("Soyad: ");
    scanf("%s",students->surname);
    students->stuNumber = 0;
    int lessonNumber;
    puts("Ders Sayisi: ");
    scanf("%d",&lessonNumber);
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
            /* code */
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