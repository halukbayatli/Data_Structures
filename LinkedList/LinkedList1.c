#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lesson
{
    char lessonName[50];
    int midtermGrade;
    int finalGrade;
}StuLesson;

typedef struct Student
{
    struct Student *nextStu;
    char name[50];
    char surname[50];
    int stuNumber;
    int lessonNumber;
    StuLesson *lessons;
}Stu;

Stu *Students = NULL;

Stu *Addition(Stu *students)
{
    Stu *headStudent = students;
    int lessonNumber;
    if(students == NULL)
    {
        students = (Stu*)malloc(sizeof(Stu));
        printf("Ad: ");
        scanf(" %[^\n]",students->name);
        printf("Soyad: ");
        scanf("%s",students->surname);
        students->stuNumber = 240001;
        printf("Ders Sayisi: ");
        scanf("%d",&students->lessonNumber);
        if(students->lessonNumber < 3)
        {
            students->lessonNumber = 3;
        }
        lessonNumber = students->lessonNumber;
        students->lessons = (StuLesson*)malloc(lessonNumber*sizeof(StuLesson));
        for(int i = 0; i < lessonNumber; i++)
        {
            printf("Ders: ");
            scanf(" %[^\n]",((students->lessons)+i)->lessonName);
            printf("Vize Notu: ");
            scanf("%d",&((students->lessons)+i)->midtermGrade);
            printf("Final Notu: ");
            scanf("%d",&((students->lessons)+i)->finalGrade);
        }
        students->nextStu = NULL;
        return students;
    }
    else
    {
        Stu *temp = students;
        int number;
        while(temp->nextStu)
        {
            temp = temp->nextStu;
        }
        number = temp->stuNumber;
        Stu *newStudents = (Stu*)malloc(sizeof(Stu));
        printf("Ad: ");
        scanf(" %[^\n]",newStudents->name);
        printf("Soyad: ");
        scanf("%s",newStudents->surname);
        newStudents->stuNumber = number+1;
        printf("Ders Sayisi: ");
        scanf("%d",&newStudents->lessonNumber);
        if(newStudents->lessonNumber < 3)
        {
            newStudents->lessonNumber = 3;
        }
        lessonNumber = newStudents->lessonNumber;
        newStudents->lessons = (StuLesson*)malloc(lessonNumber*sizeof(StuLesson));
        for(int i = 0; i < lessonNumber; i++)
        {
            printf("Ders: ");
            scanf(" %[^\n]",((newStudents->lessons)+i)->lessonName);
            printf("Vize Notu: ");
            scanf("%d",&((newStudents->lessons)+i)->midtermGrade);
            printf("Final Notu: ");
            scanf("%d",&((newStudents->lessons)+i)->finalGrade);
        }
        newStudents->nextStu = NULL;
        temp->nextStu = newStudents;
    }
    return headStudent;
}

void Listing(Stu *students)
{
    // while(students)
    // {

    //     students = students->nextStu;
    // }
    while(students)
    {
        printf("    Ad: %s\n",students->name);
        printf("    Soyad: %s\n",students->surname);
        printf("    Numara: %d\n",students->stuNumber);
        printf("    Dersler:\n");
        for(int i = 0; i < students->lessonNumber; i++)
        {
            printf("        %s\n",((students->lessons)+i)->lessonName);
            printf("            Vize: %d\n",((students->lessons)+i)->midtermGrade);
            printf("            Final: %d\n",((students->lessons)+i)->finalGrade);
        }
        students = students->nextStu;
    }
}

Stu *deletion(Stu *students)
{
    char userSurname[100];
    printf("Soyadinizi giriniz: ");
    scanf("%s",userSurname);
    
    Stu *temp;
    Stu *iterStudents = students;
    if(strcmp(userSurname,iterStudents->surname) == 0)
    {
        temp = students;
        students = students->nextStu;
        free(temp);
        return students;
    }
    else
    {
        while(iterStudents->nextStu != NULL && strcmp(userSurname,iterStudents->surname) != 0)
        {
            iterStudents = iterStudents->nextStu;
        }
        if(iterStudents->nextStu == NULL)
        {
            printf("Silme işlemi başarısız oldu...");
            return students;
        }
        temp = iterStudents->nextStu;
        iterStudents->nextStu = iterStudents->nextStu->nextStu;
        free(temp);
        return students;
    }
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
        printf("Islem secimi: ");
        scanf("%d",&choose);
        system("cls");
        if (choose == 1)
        {
            Students = Addition(Students);
        }
        else if (choose == 2)
        {
            Listing(Students);
            system("pause");
        }
        else if(choose == 3)
        {
            Students = deletion(Students);
        }
        else if (choose == 4)
        { 
            /* code */
        }
        else if(choose == 5)
        {
            break;
        }
        system("cls");
    }
}