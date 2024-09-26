#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lesson
{
    struct Lesson *nextLesson;
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
    StuLesson *lessons;
}Stu;

Stu *Students = NULL;

Stu *stuAddition(Stu *students)
{
    Stu *headStudents = students;
    if(students == NULL)
    {
        students = (Stu*)calloc(1,sizeof(Stu));
        printf("Ad: ");
        scanf(" %[^\n]",students->name);
        printf("Soyad: ");
        scanf("%s",students->surname);
        students->stuNumber = 240001;
        printf("Numara: %d\n",students->stuNumber);
        students->lessons = NULL;
        students->nextStu = NULL; 
        return students;
    }
    else
    {
        Stu *tempStudents = students;
        while(tempStudents->nextStu != NULL)
        {
            tempStudents = tempStudents->nextStu;
        }
        int number = tempStudents->stuNumber;
        Stu *newStudent = (Stu*)calloc(1,sizeof(Stu));
        printf("Ad: ");
        scanf(" %[^\n]",newStudent->name);
        printf("Soyad: ");
        scanf("%s",newStudent->surname);
        newStudent->stuNumber = number+1;
        printf("Numara: %d\n",newStudent->stuNumber);
        newStudent->lessons = NULL;
        newStudent->nextStu = NULL;
        tempStudents->nextStu = newStudent;
    }
    return headStudents;
}

StuLesson *lessonAddition(StuLesson *lessons)
{
    StuLesson *headLessons = lessons;
    if (lessons == NULL)
    {
        StuLesson *newlesson = (StuLesson*)calloc(1,sizeof(StuLesson));
        printf("Ders: ");
        scanf("%s",newlesson->lessonName);
        printf("Vize: ");
        scanf("%d",&newlesson->midtermGrade);
        printf("Final: ");
        scanf("%d",&newlesson->finalGrade);
        newlesson->nextLesson = NULL;
        return newlesson;
    }
    else
    {
        StuLesson *tempLessons = lessons;
        while(tempLessons->nextLesson != NULL)
        {
            tempLessons = tempLessons->nextLesson;
        }
        StuLesson *newlesson = (StuLesson*)calloc(1,sizeof(StuLesson));
        printf("Ders: ");
        scanf("%s",newlesson->lessonName);
        printf("Vize: ");
        scanf("%d",&newlesson->midtermGrade);
        printf("Final: ");
        scanf("%d",&newlesson->finalGrade);
        newlesson->nextLesson = NULL;
        tempLessons->nextLesson = newlesson;
    }
    return headLessons;
}

void listStudent(Stu *students)
{
    Stu *iterStudents = students;
    while (iterStudents != NULL)
    {
        printf("\n");
        printf("    Ad: %s\n", iterStudents->name);
        printf("    Soyad: %s\n", iterStudents->surname);
        printf("    Numara: %d\n", iterStudents->stuNumber);
        printf("    Dersler:\n");
        StuLesson *iterLesson = iterStudents->lessons;
        while (iterLesson != NULL)
        {
            printf("        Ders: %s\n", iterLesson->lessonName);
            printf("        Vize: %d\t", iterLesson->midtermGrade);
            printf("        Final: %d\t", iterLesson->finalGrade);
            float averageGrade = (iterLesson->midtermGrade) + (iterLesson->finalGrade)*0.5;
            printf("        Ortalama: %.2f\n", averageGrade);
            iterLesson = iterLesson->nextLesson;
        }
        iterStudents = iterStudents->nextStu;
    }
}

void main()
{
    int choose;
    while(1)
    {
        printf("\n");
        printf("        Ogrenci Bilgi Sistemi\n");
        printf("    Ekleme Islemleri        ---> 1\n");
        printf("    Listeleme Islemleri     ---> 2\n");
        printf("    Silme Islemleri         ---> 3\n");
        printf("    Siralama Islemleri      ---> 4\n");
        printf("Islem secimi: ");
        scanf("%d",&choose);
        system("cls");
        if (choose == 1)
        {
            printf("\n");
            printf("    Ogrenci eklemek icin    ---> 1\n");
            printf("    Ders eklemek icin       ---> 2\n");
            printf("Islem secimi: ");
            scanf("%d",&choose);
            system("cls");
            if(choose == 1)
            {
                Students = stuAddition(Students);
                system("pause");
            }
            else if(choose == 2)
            {
                int number;
                int lessonNumber;
                printf("Ogrenci Numarasi: ");
                scanf("%d",&number);
                Stu *tempStudents = Students;
                while(tempStudents != NULL && number != tempStudents->stuNumber)
                {
                    tempStudents = tempStudents->nextStu;
                }
                if(tempStudents != NULL && tempStudents->stuNumber == number)
                {
                    StuLesson *tempLessons = tempStudents->lessons;
                    printf("Ders Sayisi: ");
                    scanf("%d",&lessonNumber);
                    if(lessonNumber < 3)
                    {
                        lessonNumber = 3;
                    }
                    for(int i = 0; i < lessonNumber; i++)
                    {
                        tempLessons = lessonAddition(tempLessons);
                    }
                    tempStudents->lessons = tempLessons;
                }
                else
                {
                    printf("Ogrenci numarasi bulunamadi... Lutfer tekrar deneyiniz...\n");
                }
                system("pause");
            }
        }
        else if (choose == 2)
        {
            listStudent(Students);
            system("pause");
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
        system("cls");
    }
}