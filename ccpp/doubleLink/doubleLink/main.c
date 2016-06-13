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

typedef struct doubleLink
{
    char data[80];
    struct doubleLink *pre;
    struct doubleLink *next;
}dnode;

//建立链表
dnode* createDLink()
{
    dnode *head,*p,*s;
    char x[80];
    head = (dnode*)malloc(sizeof(dnode));
    p = head;
    char end[4] = "end";
    while(1)
    {
        printf("please input the data: ");
        scanf("%s",x);
        if(strcmp(x,end) != 0)
        {
            s = (dnode*)malloc(sizeof(dnode));
            strcpy(s -> data, x);
            s-> pre = p;
            p->next = s;
            p=s;
        }
        else
            break;
    }
    p->next = NULL;
    head = head ->next;
    head->pre = NULL;
    return head;
}

//顺序、反序打印链表
void printDLink(dnode *head)
{
    dnode *p,*s;
    p = head;
    printf(" left to right: \n");
    while(p)
    {
        printf("%s  ",p->data);
        s = p;
        p = p->next;
    }
    printf("\n right to left: \n");
    while(s)
    {
        printf("%s  ",s->data);
        s = s->pre;
    }
    printf("\n \n");
}

//删除一个结点
dnode* deletedNode(dnode *head,int i)
{
    dnode *p;
    p = head;
    if(p->data == i)
    {
        head = p->next;
        head->pre = NULL;
        free(p);
        return head;
    }
    
    while(p)
    {
        if(p->data == i)
        {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            free(p);
            return head;
        }
        p = p->next;
    }
    
    printf("data not found \n");
    return head;
}

//插入一个结点
dnode* insertdNode(dnode *head,char i[80])
{
    dnode *p,*temp;
    p = head;
    
    temp = (dnode*)malloc(sizeof(dnode));
    strcpy(temp ->data, i);
    
    if(i < p->data)
    {
        head = temp;
        head->next = p;
        head->pre = NULL;
        p->pre = head;
        return head;
    }
    
    while(p != NULL && i > p->data)
    {
        p = p->next;
    }
    if(i < p->data)
    {
        temp ->next = p;
        temp ->pre = p->pre;
        p ->pre->next = temp;
        p ->pre = temp;
        return head;
    }else
    {
        p->next = temp;
        temp ->pre = p;
        temp ->next = NULL;
        return head;
    }
}


void main()
{
    dnode *head;
    head = createDLink();
    printDLink(head);
    
    head = insertdNode(head,"Thank you!");
//    head = deletedNode(head,3);  
    printDLink(head);
}  
