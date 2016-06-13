//
//  main.c
//  lianbiao
//
//  Created by Ferris on 16/6/7.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//typedef struct Node Node;
typedef struct Node {
    int num;
    struct Node *next;
}Node;

typedef Node *ListH;
typedef Node *Position;

//struct Node {
//    int num;
//    Node *next;
//};


ListH creatList(ListH pHead);
Position search(ListH pHead, int data);
void displayList(ListH pHead);
void InsertLast(int x, ListH h);
void Delete(ListH h, Position del);



int main() {
    ListH pHead = NULL;
    Position s = NULL;
    pHead = creatList(pHead);
    printf("你输入的链表为\n");
    int m;
    displayList(pHead);
    printf("请输入一个整数:");
    scanf("%d", &m);
    
    s = search(pHead, m);
    if (s) {
        printf("找到该元素\n");
        printf("删除前\n");
        displayList(pHead);
        printf("删除后\n");
        Delete(pHead, s);
        displayList(pHead);
    }
    else {
        printf("未找到该元素\n");
        InsertLast(m, pHead);
        printf("插入后\n");
        displayList(pHead);
    }
    
    return 0;
}



ListH creatList(ListH pHead) {
    int input;
    int i = 1;
    pHead = (Node *)malloc(sizeof(Node));
    pHead->next = NULL;
    printf("创建链表：请输入数字，空格分开，输入0结束\n");
    scanf("%d", &pHead->num);
    scanf("%d", &input);
    while (input != 0) {
        InsertLast(input, pHead);
        scanf("%d", &input);
    }
    printf("链表创建成功\n");
    return pHead;
}



void displayList(ListH pHead) {
    if (NULL == pHead) {
        printf("链表为空\n");
    }
    else {
        while (NULL != pHead) {
            printf("%d ", pHead->num);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

Position search(ListH pHead, int data) {
    Position p = pHead;
    while (p) {
        if (p->num == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void InsertLast(int x, ListH h) {
    Position t;
    Position p = h;
    while (p->next)
        p = p->next;
    t = (Node *)malloc(sizeof(Node));
    t->num = x;
    t->next = p->next;
    p->next = t;
}

void Delete(ListH h, Position del) {
    Position p = h, t;
    while (p->next != del) {
        p = p->next;
    }
    t = p->next;
    p->next = t->next;
    free(t);
}