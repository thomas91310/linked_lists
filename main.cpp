//
//  main.cpp
//  linked_lists
//
//  Created by Thomas Theissier on 6/7/15.
//  Copyright (c) 2015 Thomas Theissier. All rights reserved.
//

#include <iostream>

struct node {
    int value;
    struct node *next;
};

void createLoop(node *head) {
    struct node *tmp = (struct node*) malloc(sizeof(node));
    tmp = head;
    struct node *loop = (struct node*) malloc(sizeof(node));
    for (int i = 0; i < 6; i++) {
        if (i == 1) {
            loop = tmp;
        }
        tmp = tmp->next;
        if (i == 5) {
            tmp->next = loop;
        }
    }
}

node* detectLoop(node *head) {
    node *tmp = (struct node*) malloc(sizeof(node));
    node *tmp2 = (struct node*) malloc(sizeof(node));
    tmp = head->next;
    tmp2 = head->next->next;
    int i = 0;
    while (tmp != tmp2 && tmp2 != NULL) {
        i = i + 1;
        std::cout << i << std::endl;
        tmp = tmp->next;
        tmp2 = tmp2->next->next;
    }
    return tmp;
}

int main(int argc, const char * argv[]) {
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->value = 5;
    
    struct node *firstNode = (struct node*) malloc(sizeof(struct node));
    firstNode->value = 9;
    
    head->next = firstNode;
    
    struct node *tmp = firstNode;
    
    for (int i = 0; i < 10; i++) {
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        newNode->value = i;
        tmp->next = newNode;
        tmp = newNode;
    }
    
    tmp = head;
    
    while (tmp != NULL) {
        std::cout << "tmp value: " << tmp->value;
        tmp = tmp->next;
    }
    
    createLoop(head);
    struct node *loop = (struct node*) malloc(sizeof(node));
    loop = detectLoop(head);
    
    return 0;
}
