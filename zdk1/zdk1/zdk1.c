
/*Napisati program koji prvo pročita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamički alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i učitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ZNAKOVA (128)
#define MAX_LINE (1024)
#define FILE_NOT_OPENED (-1)

typedef struct studenti
{
    char name[MAX_ZNAKOVA];
    char surname[MAX_ZNAKOVA];
    double points;

}student;

int readNoRowsInFile(char* datoteka);
student* allocateMemoryAndReadStudents(int noRows, char* datoteka);
double calculateRelativePoints(int noRows, student* students);
int showStudents(int noRows, student* students);


int main()
{
    int noRows = 0;
    student* students = NULL;
    noRows = readNoRowsInFile("datoteka.txt");
    students = allocateMemoryAndReadStudents(noRows, "datoteka.txt");
    showStudents(noRows, students);
    free(students);

    return 0;
}

//Funkcija prebrojava redove u datoteci
int readNoRowsInFile(char* datoteka)
{
    int noRows = 0;
    FILE* filePointer = NULL;
    char buffer[MAX_LINE] = { 0 };

    filePointer = fopen("datoteka.txt", "r");
    if (!filePointer)
    {
        printf("Neuspjesno otvaranje datoteke.\n");
        return FILE_NOT_OPENED;
    }
    while (!feof(filePointer))
    {
        fgets(buffer, MAX_LINE, filePointer);
        noRows++;
    }

    fclose(filePointer);
    return noRows;
}

//Funkcija ucitava podatke iz datoteke i sprema ih u niz struktura
student* allocateMemoryAndReadStudents(int noRows, char* datoteka)
{
    int i;
    FILE* filePointer = NULL;
    student* students = NULL;

    students = (student*)malloc(noRows * sizeof(student));
    filePointer = fopen("datoteka.txt", "r");

    if (!filePointer)
    {
        printf("Neuspjesna alokacija memorije.\n");
        return FILE_NOT_OPENED;
    }
    for (i = 0; i < noRows; i++)
    {
        fscanf(filePointer, " %s %s %lf", students[i].name, students[i].surname, &students[i].points);
    }

    fclose(filePointer);

    return students;
}

//Funkcija racuna maksimalan broj bodova
double calculateRelativePoints(int noRows, student* students)
{
    int i = 0;
    double maxPoints = 0;

    for (i = 0; i < noRows; i++)
    {
        if (students[i].points > maxPoints)
        {
            maxPoints = students[i].points;
        }
    }
    return maxPoints;
}

//Funkcija za ispis studenata
int showStudents(int noRows, student* students)
{
    int i;
    double maxPoints = 0;
    maxPoints = calculateRelativePoints(noRows, students);

    printf("NAME\tSURNAME\tPOINTS\tRELATIVE POINTS\n");
    for (i = 0; i < noRows; i++)
    {
        printf("%s\t%s\t%.3lf\t%.3lf%\n", students[i].name, students[i].surname, students[i].points, students[i].points / maxPoints * 100);
    }
}
