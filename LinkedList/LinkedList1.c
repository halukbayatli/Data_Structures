#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Lesson
{
    struct Lesson *nextLesson;
    char lessonName[50];
    int midtermGrade;
    int finalGrade;
} StuLesson;

typedef struct Student
{
    struct Student *nextStu;
    char name[50];
    char surname[50];
    int stuNumber;
    StuLesson *lessons;
} Stu;

Stu *Students = NULL;

Stu *fileRead(Stu *students)
{
    FILE *fileStudents;
    fileStudents = fopen("students.txt","r");
    if(fileStudents == NULL)
    {
        perror("Dosya okunamadi...\n");
        return NULL;
    }
}

void fileWrite(Stu *students)
{
    FILE *fileStudents;
    fileStudents = fopen("students.txt", "a");
    if (fileStudents == NULL)
    {
        perror("Dosya okunamadi...\n");
        return;
    }
    Stu *headStudents = students;
    while (headStudents != NULL)
    {
        fprintf(fileStudents, "%s %s %d\n", headStudents->name, headStudents->surname, headStudents->stuNumber);
        StuLesson *headLessons = headStudents->lessons;
        while (headLessons != NULL)
        {
            fprintf(fileStudents, "%s %d %d\n", headLessons->lessonName, headLessons->midtermGrade, headLessons->finalGrade);
            headLessons = headLessons->nextLesson;
        }
        fprintf(fileStudents, "\n");
        headStudents = headStudents->nextStu;
    }
    fclose(fileStudents);
}

Stu *sortStudent(Stu *students, Stu *newStudent)
{
    if (Students == NULL || students->stuNumber > newStudent->stuNumber)
    {
        newStudent->nextStu = students;
        return newStudent;
    }

    Stu *currentStudents = students;
    while(currentStudents->nextStu != NULL && currentStudents->nextStu->stuNumber < newStudent->stuNumber)
    {
        currentStudents = currentStudents->nextStu;
    }
    newStudent->nextStu = currentStudents->nextStu;
    currentStudents->nextStu = newStudent;
    return students;
}

Stu *stuAddition(Stu *students)
{
    Stu *newStudent = (Stu *)calloc(1, sizeof(Stu));
    printf("\n");
    printf("Ad: ");
    scanf(" %[^\n]", newStudent->name);
    printf("Soyad: ");
    scanf("%s", newStudent->surname);
    printf("Numara: ");
    scanf("%d",&newStudent->stuNumber);
    newStudent->lessons = NULL;
    Stu *temp = students;
    while (temp != NULL)
    {
        if (temp->stuNumber == newStudent->stuNumber)
        {
            printf("Bu numarali ogrenci mevcut lutfen tekrar deneyiniz...\n");
            free(newStudent);
            return students;
        }
        temp = temp->nextStu;
    }
    return sortStudent(students,newStudent);
}

StuLesson *lessonAddition(StuLesson *lessons)
{
    StuLesson *headLessons = lessons;
    if (lessons == NULL)
    {
        StuLesson *newlesson = (StuLesson *)calloc(1, sizeof(StuLesson));
        printf("Ders: ");
        scanf("%s", newlesson->lessonName);
        printf("Vize: ");
        scanf("%d", &newlesson->midtermGrade);
        printf("Final: ");
        scanf("%d", &newlesson->finalGrade);
        newlesson->nextLesson = NULL;
        return newlesson;
    }
    else
    {
        StuLesson *tempLessons = lessons;
        while (tempLessons->nextLesson != NULL)
        {
            tempLessons = tempLessons->nextLesson;
        }
        StuLesson *newlesson = (StuLesson *)calloc(1, sizeof(StuLesson));
        printf("Ders: ");
        scanf("%s", newlesson->lessonName);
        printf("Vize: ");
        scanf("%d", &newlesson->midtermGrade);
        printf("Final: ");
        scanf("%d", &newlesson->finalGrade);
        newlesson->nextLesson = NULL;
        tempLessons->nextLesson = newlesson;
    }
    return headLessons;
}

void listLesson(Stu *students)
{
    Stu *iterStudents = students;
    char lessonName[100];
    printf("Listelemek icin ders adi giriniz: ");
    scanf("%s", lessonName);
    while (iterStudents != NULL)
    {
        StuLesson *iterLesson = iterStudents->lessons;
        while (iterLesson != NULL)
        {
            if (strcmp(lessonName,iterLesson->lessonName) == 0)
            {
                printf("\n");
                printf("    %s\n",iterLesson->lessonName);
                printf("        Ad: %s\n", iterStudents->name);
                printf("        Soyad: %s\n", iterStudents->surname);
                printf("        Numara: %d\n", iterStudents->stuNumber);
                printf("        Ders: %s\n", iterLesson->lessonName);
                printf("        Vize: %d\t", iterLesson->midtermGrade);
                printf("        Final: %d\t", iterLesson->finalGrade);
                float averageGrade = ((iterLesson->midtermGrade) + (iterLesson->finalGrade)) * 0.5;
                printf("        Ortalama: %.2f\n", averageGrade);
            }
            iterLesson = iterLesson->nextLesson;
        }
        iterStudents = iterStudents->nextStu;
    }
    printf("\n");
    system("pause");
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
            float averageGrade = ((iterLesson->midtermGrade) + (iterLesson->finalGrade)) * 0.5;
            printf("        Ortalama: %.2f\n", averageGrade);
            iterLesson = iterLesson->nextLesson;
        }
        iterStudents = iterStudents->nextStu;
    }
    printf("\n");
    system("pause");
}

Stu *deletionStudent(Stu *students)
{
    Stu *iterStudents = students;
    Stu *prevStudent = NULL;
    char userSurname[100];
    printf("Soyadi giriniz: ");
    scanf("%s", userSurname);
    while (iterStudents != NULL) 
    {
        if (strcmp(userSurname, iterStudents->surname) == 0) 
        {
            Stu *tempStudent = iterStudents;
            if (prevStudent == NULL) 
            {
                students = iterStudents->nextStu;
                iterStudents = students;
            } 
            else 
            {
                prevStudent->nextStu = iterStudents->nextStu;
                iterStudents = prevStudent->nextStu;
            }
            free(tempStudent);    
        } 
        else 
        {
            prevStudent = iterStudents;
            iterStudents = iterStudents->nextStu;
        }
    }
    return students; 
}

void main()
{
    int choose;
    while (1)
    {
        printf("\n");
        printf("        Ogrenci Bilgi Sistemi\n");
        printf("    Ekleme Islemleri        ---> 1\n");
        printf("    Listeleme Islemleri     ---> 2\n");
        printf("    Silme Islemleri         ---> 3\n");
        printf("    Cikmak icin             ---> 4\n");
        printf("Islem secimi: ");
        scanf("%d", &choose);
        system("cls");
        if (choose == 1)
        {
            printf("\n");
            printf("    Ogrenci eklemek icin    ---> 1\n");
            printf("    Ders eklemek icin       ---> 2\n");
            printf("Islem secimi: ");
            scanf("%d", &choose);
            system("cls");
            if (choose == 1)
            {
                Students = stuAddition(Students);
                system("pause");
            }
            else if (choose == 2)
            {
                int number;
                int lessonNumber;
                printf("Ogrenci Numarasi: ");
                scanf("%d", &number);
                Stu *tempStudents = Students;
                while (tempStudents != NULL && number != tempStudents->stuNumber)
                {
                    tempStudents = tempStudents->nextStu;
                }
                if (tempStudents != NULL && tempStudents->stuNumber == number)
                {
                    StuLesson *tempLessons = tempStudents->lessons;
                    printf("Ders Sayisi: ");
                    scanf("%d", &lessonNumber);
                    for (int i = 0; i < lessonNumber; i++)
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
            printf("\n");
            printf("    Tum ogrencileri listelemek icin         ---> 1\n");
            printf("    Derse gore ogrenci listelemek icin      ---> 2\n");
            printf("Islem secimi: ");
            scanf("%d", &choose);
            system("cls");
            if (choose == 1)
            {
                listStudent(Students);
            }
            else
            {
                listLesson(Students);
            }
        }
        else if (choose == 3)
        {
            Students = deletionStudent(Students);
        }
        else if (choose == 4)
        {
            fileWrite(Students);
            StuLesson *tempLes;
            while (Students->lessons->nextLesson != NULL)
            {
                tempLes = Students->lessons;
                Students->lessons = Students->lessons->nextLesson;
                free(tempLes);
            }
            Stu *tempStu;
            while (Students->nextStu != NULL)
            {
                tempStu = Students;
                Students = Students->nextStu;
                free(tempStu);
            }
            break;
        }
        system("cls");
    }
}