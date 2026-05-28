/*
==============================================================================
  C PROJECT: LIBRARY MANAGEMENT SYSTEM (Console-Based)
==============================================================================
Description:
- Menu-driven application to manage book records in a small library (add, view, search, delete, update).
- Uses file handling for persistent data storage.
- Suitable for diploma students, beginners, and self-study.
- Open-source: Anyone can use, modify, and learn from this code!
- Author: Yogini Gadhavi
- Year: 2026
- For any course, project, or assignment use.
==============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"

struct Book {
    int id;
    char title[100];
    char author[50];
    int year;
};

void addBook();
void listBooks();
void searchBook();
void deleteBook();
void updateBook();

int main() {
    int choice;
    do {
        printf("\n----- Library Management System -----\n");
        printf("1. Add Book\n");
        printf("2. List all Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Update Book by ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 0);
    return 0;
}

void addBook() {
    struct Book b;
    printf("Enter Book ID: "); scanf("%d", &b.id);
    getchar();
    printf("Enter Title: "); fgets(b.title, 100, stdin); b.title[strcspn(b.title,"\n")]=0;
    printf("Enter Author: "); fgets(b.author, 50, stdin); b.author[strcspn(b.author,"\n")]=0;
    printf("Enter Year: "); scanf("%d", &b.year);
    FILE *fp = fopen(FILE_NAME,"ab");
    if(fp) {
        fwrite(&b, sizeof(b), 1, fp);
        fclose(fp);
        printf("Book added successfully.\n");
    } else { printf("Unable to open file!\n"); }
}

void listBooks() {
    struct Book b;
    FILE *fp = fopen(FILE_NAME,"rb");
    if(!fp) { printf("No books found!\n"); return; }
    printf("\n-- Book List --\n");
    while(fread(&b, sizeof(b), 1, fp)) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n---\n", b.id, b.title, b.author, b.year);
    }
    fclose(fp);
}

void searchBook() {
    int id, found=0;
    struct Book b;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    FILE *fp = fopen(FILE_NAME,"rb");
    if(!fp) { printf("No books found!\n"); return; }
    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            printf("Book Found!\nID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n", b.id, b.title, b.author, b.year);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(!found) printf("Book not found.\n");
}

void deleteBook() {
    int id, found=0;
    struct Book b;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if(!fp || !temp) { printf("Unable to open files!\n"); return; }
    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            found = 1; continue;
        } else {
            fwrite(&b, sizeof(b), 1, temp);
        }
    }
    fclose(fp); fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    if(found) printf("Book deleted.\n"); else printf("Book not found.\n");
}

void updateBook() {
    int id, found=0;
    struct Book b;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);
    FILE *fp = fopen(FILE_NAME, "rb+");
    if(!fp) { printf("No books found!\n"); return; }
    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            printf("Enter new Title: "); getchar();
            fgets(b.title, 100, stdin); b.title[strcspn(b.title,"\n")]=0;
            printf("Enter new Author: "); fgets(b.author,50,stdin); b.author[strcspn(b.author,"\n")]=0;
            printf("Enter new Year: "); scanf("%d", &b.year);
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("Book updated.\n");
            found = 1; break;
        }
    }
    fclose(fp);
    if(!found) printf("Book not found.\n");
}

/*
Sample Menu Usage:
1. Add Book: Stores info to file.
2. List all Books: Reads & prints all records.
3. Search Book by ID: Finds and prints.
4. Delete: Removes book from file (via temp).
5. Update: Changes info for given ID.

Make sure to run this as a console program. File "library.dat" stores the book records.
*/
