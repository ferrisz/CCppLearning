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
void menu(dnode *head);
void insert(dnode *head);
void del(dnode *head);

int main() {
    dnode *head;
    head = createDLink();
    printf("当前链表为：\n");
    printDLink(head);
    menu(head);
    system("pause");
    return 0;
}

//建立菜单
void menu(dnode *head){
    char n;
    printf("1、插入\n");
    printf("2、删除\n");
    printf("0、退出\n");
    n=getchar();
    switch (n) {
        case '1':
            insert(head);
            break;
            
        case '2':
            del(head);
            break;
            
        case '0':
            system("exit");
            break;
            
        default:
            menu(head);
            break;
    }
}

//插入函数
void insert(dnode *head){
    char prestring[80];
    char istring[80];
    dnode *p;
    p = head;
    printf("当前链表为：\n");
    printDLink(head);
    printf("您要插入在哪个字符串之后？\n");
    scanf("%s",&prestring);
    printf("\n");
    while (p) {
        if (strcmp(p->data, prestring) == 0) {
            printf("您要插入的字符串为？\n");
            scanf("%s",&istring);
            insertdNode(head, istring, prestring);
            printf("插入完成");
            printf("当前链表为：\n");
            printDLink(head);
        }
        p = p->next;
    }
    printf("data not found \n");
    menu(head);
}

//删除函数
void del(dnode *head){
    char istring[80];
    dnode *p;
    p = head;
    printf("当前链表为：\n");
    printDLink(head);
    printf("您要删除哪个字符串？\n");
    gets(istring);
    deletedNode(head, istring);
    menu(head);
}


//建立链表
dnode* createDLink() {
    dnode *head, *p, *s;
    int i = 0;
    head = (dnode*)malloc(sizeof(dnode));
    p = head;
    char input[5][80] = { "How are you?", "I am fine!", "And you?", "Me too.", "Thank you!" };
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
            printf("删除完成");
            printf("当前链表为：\n");
            printDLink(head);
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
