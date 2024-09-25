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
        scanf("%s",students->name);
        printf("Soyad: ");
        scanf("%s",students->surname);
        students->stuNumber = 240001;
        students->lessons = NULL;
        students->nextStu = NULL; 
        return students;
    }
    else
    {
        Stu *tempStudents = students;
        while(tempStudents)
        {
            tempStudents = tempStudents->nextStu;
        }
        int number = tempStudents->stuNumber;
        Stu *newStudents = (Stu*)calloc(1,sizeof(Stu));
        printf("Ad: ");
        scanf("%s",newStudents->name);
        printf("Soyad: ");
        scanf("%s",newStudents->surname);
        newStudents->stuNumber = number+1;
        newStudents->lessons = NULL;
        newStudents->nextStu = NULL;
        tempStudents->nextStu = newStudents;
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
        return lessons;
    }
    else
    {
        StuLesson *tempLessons = lessons;
        while(tempLessons)
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
    while(students)
    {
        printf("\n");
        printf("    Ad: %s\n",students->name);
        printf("    Soyad: %s\n",students->surname);
        printf("    Numara: %d\n",students->stuNumber);
        printf("    Dersler:\n");
        while(students->lessons)
        {
            printf("        %s\n",students->lessons->lessonName);
            printf("        %d\n",students->lessons->midtermGrade);
            printf("        %d\n",students->lessons->finalGrade);
            float averageGrade = (float)(students->lessons->midtermGrade)+(students->lessons->finalGrade);
            printf("        %.2f\n",averageGrade);
            students->lessons = students->lessons->nextLesson;
        }
        students = students->nextStu; 
    }
}

void main()
{
    int choose;
    while(1)
    {
        printf("        Ogrenci Bilgi Sistemi\n");
        printf("    Ekleme Islemleri        ---> 1\n");
        printf("    Listeleme Islemleri     ---> 2\n");
        printf("    Silme Islemleri         ---> 3\n");
        printf("    Siralama Islemleri      ---> 4\n");
        puts("Islem secimi: ");
        scanf("%d",&choose);
        system("cls");
        if (choose == 1)
        {
            int lessonNumber;
            Students = stuAddition(Students);
            printf("Ders Sayisi: ");
            scanf("%d",&lessonNumber);
            if(lessonNumber < 3)
            {
                lessonNumber = 3;
            }
            for(int i = 0; i < lessonNumber; i++)
            {
                Students->lessons = lessonAddition(Students->lessons);
            }   
        }
        else if (choose == 2)
        {
            listStudent(Students);
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