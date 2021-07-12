#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int age;
    char *phone; // 11位手机号 + 1结束符
    char *name; // 50位 + 1结束符
}personType;

int main() {
    char *string;
    int n = 0;

    string = malloc(20);

    string[n++] = 'a';
    string[n++] = 'b';
    string[n++] = 'c';
    string[n++] = '\0';

    printf("string = %s\n", string);

    string++;
    printf("string++ = %s\n", string);

    // 单独分配内存与赋值
    personType *p;
    p = (personType*)malloc(sizeof(personType));
    p->age = 20;
    p->phone = (char*)malloc(12);
    strcpy(p->phone, "18259179840\0");
    p->name = (char*)malloc(51);
    strcpy(p->name, "shishao\0");

    printf("p person info: \n");
    printf("p.age: %d\n", p->age);
    printf("p.phone: %s\n", p->phone);
    printf("p.name: %s\n", p->name);


    //一次分配所需内存
    void *pt;
    personType *p2;
    pt = (void*)malloc(sizeof(personType) + 12 + 51);

    char *phone;
    char *name;
    int *age;
    personType *temp;
    temp = (personType*)(pt+sizeof(personType));
    age = ((int*)temp)-16;
    *age = 100;
    printf("p2 age info: %d\n", (*temp).age);

    // strcpy(p2->phone, "18259179840\0");
    // strcpy(p2->name, "shishao\0");
    // printf("p2 person info: ");
    // printf("p2.age: %d\n", p2->age);
    // printf("p2.phone: %s\n", p2->phone);
    // printf("p2.name: %s\n", p2->name);
 }