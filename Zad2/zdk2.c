/*2. Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
A. dinamièki dodaje novi element na poèetak liste,
B. ispisuje listu,
C. dinamièki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable. */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

struct _Person;
typedef struct _Person* Position;
typedef struct _Person {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    int birthYear;
    Position next;
}Person;

int menu(Position head);
int addPersonAtFrontOfTheList(Position P);
int addPersonAtTheEnd(Position P);
int printList(Position P);
Position findPerson(Position P);
Position FindBySurname(Position first, char* surname);
Position FindBefore(Position wantedPerson, Position head);
int DeleteAfter(char* surname, Position head);

int main(){

    Person head = { .next = NULL, .name = {0}, .surname = {0}, .birthYear = 0 };

    menu(&head);

    return 0;
}

int menu(Position head){

    char choice = '\0';
    Position resPerson = NULL;
    char surname[MAX_SIZE] = { 0 };

    while (1)
    {
        printf("\nZa dodati novi element na pocetak liste upisite: 1\nZa dodavanje novog elementa na kraj liste: 2\nZa ispis liste: 3\nZa pronalazenje elementa u listi po prezimenu: 4\nZa brisanje elementa iz liste: 5\nZa izlazak iz programa: 0\n");
        scanf("\n%c", &choice);
        switch (choice)
        {
        case '1':
            addPersonAtFrontOfTheList(head);
            break;
        case '2':
            addPersonAtTheEnd(head);
            break;
        case '3':
            printList(head->next);
            break;
        case '4':
            resPerson = findPerson(head->next);
            if (resPerson == NULL)
                printf("\nOsoba nije nadena u listi\n");
            else
                printf("\nOsoba po prezimenu %s je nadena na lokaciji %d\n", resPerson, resPerson->surname);
            break;
        case '5':
            printf("-------- Brisanje studenta po prezimenu. -------- \nUnesite prezime studenta kojeg zelite izbrisati iz liste: ");
            scanf(" %s", surname);
            DeleteAfter(surname, head);
            break;
        case '0':
            printf("\nKraj programa!\n");
            return 0;

        default:
            printf("Unijeli ste nedozvoljeni broj! ");
            break;
        }
    }
    return 1;
}

int printList(Position P){

    printf("\n------------\n");

    Position temp = P;

    if (P == NULL)// ili (!P)
    {
        printf("Empty list!\n");
    }
    else {

        while (P != NULL) {
            printf("%s %s %d\n", P->name, P->surname, P->birthYear);
            P = P->next;
        }
    }

    printf("------------");

    return EXIT_SUCCESS;
}

int addPersonAtFrontOfTheList(Position P){

    Position newPerson = NULL;

    newPerson = (Person*)malloc(sizeof(Person));
    newPerson->next = NULL;

    printf("\nUnesite ime, prezime i godinu rodenja nove osobe:\n");
    scanf("\n%s %s %d", newPerson->name, newPerson->surname, &newPerson->birthYear);

    newPerson->next = P->next;
    P->next = newPerson;

    return EXIT_SUCCESS;
}

int addPersonAtTheEnd(Position P){

    Position newPerson = NULL;

    newPerson = (Person*)malloc(sizeof(Person));

    printf("\nUnesite ime, prezime i godinu rodenja nove osobe: \n");
    scanf("\n%s %s %d", newPerson->name, newPerson->surname, &newPerson->birthYear);

    while (P->next != NULL) {
        P = P->next;
    }

    newPerson->next = P->next;
    P->next = newPerson;

    return EXIT_SUCCESS;
}

Position findPerson(Position P){

    char wantedPerson[MAX_SIZE];

    printf("Unesite prezime trazene osobe: ");
    scanf("%s", wantedPerson);

    while ( strcmp(P->surname, wantedPerson) != 0)
    {
        P = P->next;
    }

    return P;
}

Position FindBySurname(Position first, char* surname){
    //iako je first poslan necemo s njim radit nego inicijaliziramo temp=first
    Position temp = first;

    // " If two strings are same then strcmp() returns 0 , otherwise, it returns a non-zero value. 
    // ...This function compares strings character by character using ASCII value of the characters"

    while (temp) {
        if (strcmp(temp->surname, surname) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    // zelimo nac bas ovaj poslani argument char* surname, pa prolazimo po cijeloj listi i usporedujemo prezimena na listi sa tim poslanim...
    // ...prezimenom , ako ga nademo, returnamo adresu strukture(odnosno temp koji je tipa Position koji je tipa Person *) na kojoj je prezime nadeno
    // ...ako se prezime ne nade vracamo NULL

    return NULL;
}

Position FindBefore(Position wantedPerson, Position head) {
    //trazimo prethodnika kako bi izbrisali neki element

    Position temp = head;

    while (temp->next != NULL && temp->next != wantedPerson)
    {
        temp = temp->next;
    }

    // ako je sljedeci nakon temp-a(temp->next) onaj kojeg zelimo obrisat, onda bas taj temp trebamo i njega returnamo

    if (temp->next == NULL)
        return NULL;
    else
        return temp;
}

int DeleteAfter(char* surname, Position head) {

    Position before = NULL;
    Position toDelete = NULL;

    toDelete = FindBySurname(head->next, surname);
    before = FindBefore(toDelete, head);
    if (!before) {

        printf("Greska u brisanju!\n");
        return -1;
    }

    toDelete = before->next;
    before->next = toDelete->next;
    free(toDelete);

    return EXIT_SUCCESS;    
}