// Libary
    // -- Aid Harrison
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int top;
int bookID[100];

void Interface();

typedef struct book {
    char title[24];
    int pageCount;
    int id;
} book; 

struct book books[100];

// Test, replace with file read
const char *bookNames[3][24] = {
        {"The lord of the rings"},
        {"American Psycho"},
        {"1984"},
        {"Animal Farm"}
    };

void editBook(book * b) {
    char input[24];
    printf("%s", "Enter a new title: ");
    //scanf(input);
    memcpy(b->title, input, sizeof(char) * strlen(input)); // Check!
}

void auto_init_book(book * b) {
    int choice = 0;
    choice = rand() % 3;
    strcpy(b->title, bookNames[choice], sizeof(char) * strlen(bookNames[choice]);
    b->pageCount = rand() % 500;
    if(b->pageCount <= 100)
        b->pageCount = 100;
}

void GenerateBooks() {
    int AMOUNT = rand() % 100;
    for(int i = 0; i < AMOUNT; i++) {
        book newBook;
        auto_init_book(&newBook);
    }
}

void init_Book(struct book * b) {
    char input[24];
    int pCount;
    printf("Enter title: ");
    scanf("%s", input);
    strcpy(b->title, input);
    printf("Enter page count: ");
    scanf("%d", &pCount);
    b->pageCount = pCount;
    b->id = top;
    printf("You added: %s", input);
    printf("\n========================");
    Interface();
}

void Print() {
    for(int i = 0; i < 100; i++) {
        printf("%s\n", books[i].title);
    }
}

void AddBook() {
    printf("\n=Add book=\n");
    struct book newBook;
    init_Book(&newBook);
    newBook.id = top;
    bookID[top++] = top;
    books[top] = newBook;
}

// Paramters are for genre/section searching | Implement
int BinarySearch(int left, int right, const int target) {
    while(left < right) {
        int mid = left + (right-left) / 2 - 1;
        if(books[mid].id == target) { return mid; }
        else if(books[mid].id < target) { left = mid+1; }
        else {right = mid - 1; }
    }
    printf("Failed to find: ");
    return 0;
}

book SearchBook() {
    char input[24];
    int sInput;
    int isID = true;
    printf("Search via ID or Title?");
    printf("1) ID \n2) Title");
    scanf("%d", sInput);
    while(sInput != 1 || sInput != 2) {
        switch(sInput) {
            case 1:  {
                printf("Enter ID: ");
                break;
            }
            case 2: {
                printf("Enter title: ");
                isID = false;
                break;
            }
        }
    }
    scanf("%s", input);
    if(isID)
        return books[sInput];
    else
        return books[BinarySearch(0, 100, input)];
}

void RemoveBook() {
    SearchBook();
}

void Interface() {
    int input = 0;
    int running = true;
    printf("\n-LIBRARY-\n");
    while(running) {
        printf("Enter: ");
        scanf("%d", &input);
        switch(input) {
            case 0: running = false; break;
            case 1: AddBook(); break;
        }
    }
}

int main(int argc, char * argv[]) {
    //struct book testBook1;
    //init_Book(&testBook1);
    //struct book testBook2;
    //struct book testBook3;

    Interface();

    return 0;
}