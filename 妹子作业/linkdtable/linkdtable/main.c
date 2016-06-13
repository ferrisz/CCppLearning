//
//  main.c
//  linkdtable
//
//  Created by Ferris on 16/5/29.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct List
{
    int num;
    struct List *next;
};

struct List *head;

void deleteFushu()
{
    struct List *p = NULL, *q = NULL;
    p = head;
    if (p -> num < 0) {
        head = p -> next;
    }
    p = head;
    q = p -> next;
    while (q != NULL) {
        if (q -> num < 0) {
            q = q -> next;
            p -> next = q;
        }
        else
        {
            p = q;
            q = q -> next;
        }
    }
    return ;
}

void deleteNode(struct List *head)
{
    printf("输入删除的位置：");
    int num;
    scanf("%d",&num);
    if (num > 12) {
        printf("没有此位置！\n");
        return;
    }
    struct List *p = NULL, *q = NULL;
    p = head;
    if (num == 1) {
        head = p -> next;
        free(p);
        return;
    }
    q = p -> next;
    int tot = 1;
    while (q != NULL) {
        tot++;
        if (tot == num) {
            p -> next = q -> next;
            free(p);
            return;
        }
        p = q;
        q = q->next;
    }
    return;
}

struct List *Create()
{
    int data[11] = {-1,18,-9,4,-2,0,2,40,16,-8,10};
    struct List *p = NULL;
    struct List *q = NULL;
    head = NULL;
    for (int i = 0; i < 11; i++) {
        p = malloc(sizeof(struct List));
        p -> num = data[i];
        if (head == NULL) {
            head = p;
        }
        else
        {
            q ->next = p;
        }
        q = p;
    }
    
    if (head != NULL) {
        q -> next = NULL;
    }
    return head;
}

void Insert(struct List *head)
{
    struct List *node = NULL;
    node = malloc(sizeof(struct List));
    node -> num = 100;
    node -> next = NULL;
    struct List *q, *p;
    p = head;
    q = head -> next;
    while (q != NULL) {
        if (q -> num != 0) {
            p = q;
            q = q -> next;
        }
        else
        {
            p = q;
            q = q -> next;
            break;
        }
    }
    p -> next = node;
    node -> next = q;
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
