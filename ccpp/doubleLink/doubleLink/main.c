//
//  main.c
//  doubleLink
//
//  Created by Ferris on 16/6/13.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct doubleLink {
    char data[80];
    struct doubleLink *pre;
    struct doubleLink *next;
}dnode;

dnode* createDLink();
void printDLink(dnode *head);
void deletedNode(dnode *head, char del[80]);
void insertdNode(dnode *head, char i[80], char pre[80]);

int main() {
    dnode *head;
    head = createDLink();
    printDLink(head);
    
    insertdNode(head, "Thank you!", "I am fine!");
    printDLink(head);
    
    deletedNode(head, "I am fine!");
    printDLink(head);
    getchar();
    return 0;
}

//建立链表
dnode* createDLink() {
    dnode *head, *p, *s;
    int i = 0;
    head = (dnode*)malloc(sizeof(dnode));
    p = head;
    char input[5][80] = { "how are you?", "I am fine!", "and you?", "me too.", "thank you!" };
    for (i = 0; i < 5; i++) {
        s = (dnode*)malloc(sizeof(dnode));
        strcpy(s->data, input[i]);
        s->pre = p;
        p->next = s;
        p = s;
    }
    p->next = NULL;
    head = head->next;
    head->pre = NULL;
    return head;
}

//顺序打印链表
void printDLink(dnode *head) {
    dnode *p, *s;
    p = head;
    while (p) {
        printf("%s  ", p->data);
        s = p;
        p = p->next;
    }
    printf("\n \n");
}

//删除一个结点
void deletedNode(dnode *head, char del[80]) {
    dnode *p;
    p = head;
    while (p) {
        if (strcmp(p->data, del) == 0) {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            free(p);
            return ;
        }
        p = p->next;
    }
    
    printf("data not found \n");
}

//插入一个结点
void insertdNode(dnode *head, char i[80], char pre[80]) {
    dnode *p, *temp;
    p = head;
    
    temp = (dnode*)malloc(sizeof(dnode));
    strcpy(temp->data, i);
    
    while (p && strcmp(p->data, pre) != 0){
        p = p->next;
    }
    temp->next = p->next;
    p->next->pre = temp;
    p->next = temp;
    temp->pre = p;
}



