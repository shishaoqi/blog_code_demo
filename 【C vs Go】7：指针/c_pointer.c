#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int age;
    char *phone; // 11位手机号 + 1结束符
    char *name; // 10位 + 1结束符
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
    p->name = (char*)malloc(11);
    strcpy(p->name, "shishao\0");

    printf("p person info: \n");
    printf("p.age: %d\n", p->age);
    printf("p.phone: %s\n", p->phone);
    printf("p.name: %s\n", p->name);

    //一次分配所需内存
    void *pt;
    pt = (void*)malloc(sizeof(personType) + 8 + 12 + 11);

    personType *p2;
    char *phone;
    char *name;
    int age;

    *((int *)pt) = 99;
    age = *((int *)pt);
    printf("age = %d \n", age);

    *((char**)pt + 8) = "18259179840\0";
    // phone = (char*)((char*)pt + 8);
    // phone = "18259179840";
    // printf("phone = %s \n", phone);
    printf("(char*)((char*)pt + 8) = %s \n", (char*)((char*)pt + 8));

    name = (char*)((char*)pt + 8 + 12);
    name = "shishao-12\0";
    printf("name = %s \n", name);
    printf("(char*)((char*)pt + 8 + 12) = %s \n", ((char*)pt + 8 + 12));
 }