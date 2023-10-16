#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE (128)
#define MAX_LINE (1024)
#define MAX_POINTS (15)

/*. Napisati program koji prvo pročita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamički alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i učitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100*/

int readNoRowsInFile()
{
	int counter = 0;
	FILE* filePointer = NULL;
	char buffer[MAX_SIZE] = { 0 };

	filePointer = fopen("students.txt", );
	if (!filePointer)
	{
		return FILE_NOT_OPEN;
	}
	while (!feof(filePointer))
	{
		fgets(buffer, MAX_SIZE, filePointer)
	}

	fclose(filePointer);
}

Student* allocateMemoryAndReadStudents(int noStudents)
{
	int counter = 0;
	FILE* filePointer = NULL;
	Student* students = NULL;

	students = (Student*)malloc(noStudents * sizeof(Student));
	if (!students)
	{

	}
}

int main()
{
	
	int noRows = 0;
	Student* students = NULL;

	typedef struct _student
	{
		char namem;
	};

	

	return 0;
}