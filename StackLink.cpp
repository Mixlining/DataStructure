//
// Created by QwQ on 2023/2/2.
//

#include "StackLink.h"

void initStackLink(Node head) {
    head->next_node = NULL;
    head->element = 0;
}

void run_StackLink() {
    StackLink_Node head;
    initStackLink(&head);
    for (int i = 0; i < 10; ++i) {
        push_StackLink(&head, i);
    }
    prin_StackLink(&head);
    while (!isEmpty(&head)) {
        cout << pop_StackLink(&head) << " ";
    }

}

bool push_StackLink(Node head, E element) {
    Node new_node = static_cast<Node>(malloc(sizeof(StackLink_Node)));
    if (new_node == NULL)return 0;
    new_node->next_node = head->next_node;
    head->next_node = new_node;
    new_node->element = element;
    return 1;
}

void prin_StackLink(Node head) {
    head = head->next_node;
    while (head != NULL) {
        cout << head->element << " ";
        head = head->next_node;
    }
    cout << endl;
}

E pop_StackLink(Node head) {
    Node tmp = head->next_node;
    E top = head->next_node->element;

    head->next_node = head->next_node->next_node;
    free(tmp);
    return top;
}

bool isEmpty(Node head) {
    return head->next_node == NULL;

}
