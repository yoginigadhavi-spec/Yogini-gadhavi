/* ====================================================================
   C PROGRAMMING: Complete Theory 
   ==================================================================== */

#include <stdio.h>
#include <stdlib.h>

/* ---------- 1. BASICS ---------- */
// --- 1.1 Hello World ---
void basics_hello_world() {
    printf("Hello, World!\n");
}
// --- 1.2 Data Types and Variables ---
void basics_data_types() {
    int age = 19;
    float height = 5.6;
    char initial = 'Y';
    char name[] = "Yogini";
    printf("Age: %d, Height: %.2f, Initial: %c, Name: %s\n",
           age, height, initial, name);
}

/* ---------- 2. INPUT/OUTPUT ---------- */
void io_example() {
    char name[30]; int age;
    printf("Name? "); scanf("%s", name);
    printf("Age? "); scanf("%d", &age);
    printf("Hello %s, %d years old.\n", name, age);
}

/* ---------- 3. CONTROL STATEMENTS ---------- */
void control_if_else() {
    int num; printf("Number? "); scanf("%d", &num);
    if(num % 2 == 0) printf("Even\n"); else printf("Odd\n");
}
void control_switch() {
    int day; printf("Day (1-7)? "); scanf("%d", &day);
    switch(day) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        default: printf("Other day\n");
    }
}

/* ---------- 4. LOOPS ---------- */
void loops_for() {
    for(int i=1;i<=5;i++) printf("%d ",i);
    printf("\n");
}
void loops_while() {
    int n=1; while(n<=5) { printf("%d ", n++); }
    printf("\n");
}

/* ---------- 5. ARRAYS ---------- */
void arrays_sample() {
    int arr[3] = {10, 20, 30};
    for(int i=0;i<3;i++) printf("%d ", arr[i]);
    printf("\n");
}

/* ---------- 6. STRINGS ---------- */
void strings_sample() {
    char s[20];
    printf("Enter name: ");
    scanf("%s", s);
    printf("Hello, %s\n", s);
}

/* ---------- 7. FUNCTIONS ---------- */
int add(int x, int y) { return x+y; }
void functions_sample() {
    printf("5+7=%d\n", add(5,7));
}

/* ---------- 8. RECURSION ---------- */
int factorial(int n) {
    if(n==0) return 1;
    return n*factorial(n-1);
}
void recursion_sample() {
    printf("Factorial 5 = %d\n", factorial(5));
}

/* ---------- 9. POINTERS ---------- */
void pointers_sample() {
    int x=5, *p;
    p=&x;
    printf("Value: %d, Address: %p, Value via pointer: %d\n", x, p, *p);
}

/* ---------- 10. DYNAMIC MEMORY ALLOCATION (malloc, calloc, realloc, free) ---------- */
void memory_sample() {
    int *arr, n = 5;
    arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) { printf("Memory error\n"); return; }
    for(int i=0;i<n;i++) arr[i]=i;
    printf("Malloc: "); for(int i=0;i<n;i++) printf("%d ", arr[i]);
    free(arr);

    arr = (int*)calloc(n, sizeof(int));
    printf("\nCalloc: "); for(int i=0;i<n;i++) printf("%d ", arr[i]);
    arr = (int*)realloc(arr, 2*n * sizeof(int));
    free(arr);
    printf("\nMemory freed.\n");
}

/* ---------- 11. STRUCTURES ---------- */
struct Student {
    int roll;
    char name[20];
    float marks;
};
void structs_sample() {
    struct Student s = {1, "Yogini", 95.0};
    printf("Struct: %d, %s, %.1f\n", s.roll, s.name, s.marks);
}

/* ---------- 12. FILES ---------- */
void file_sample() {
    FILE *f = fopen("sample.txt","w");
    if(f) { fprintf(f,"Hi File\n"); fclose(f); }
    f = fopen("sample.txt","r"); if(f) {
        char buf[30]; fgets(buf,30,f); printf("Read: %s", buf); fclose(f);
    }
}

int main() {
    basics_hello_world();
    basics_data_types();
    io_example();
    control_if_else();
    control_switch();
    loops_for();
    loops_while();
    arrays_sample();
    strings_sample();
    functions_sample();
    recursion_sample();
    pointers_sample();
    memory_sample();
    structs_sample();
    file_sample();
    return 0;
}

