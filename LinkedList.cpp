//
// Created by QwQ on 2023/1/21.
//

#include "LinkedList.h"

void initList(Node head) {
    head->nextNode = NULL;//头节点默认下一个为NULL
    head->element = 0;//为头节点初始化,以防出现问题

}

bool insert_List(Node head, E element, int index) {
    if (index < 1) {
        return false;
    }
    while (--index) {
        head = head->nextNode;//让节点前移,移到要插入的节点之前
        if (head == NULL)//若发现前移时节点是null,说明无法插入,index非法
        {
            return false;
        }
    }
    //若index通过上述边界约束条件,说明可以插入
    //先创建节点
    Node node_inser = static_cast<Node>(malloc(sizeof(Linked_node)));
    node_inser->element = element;
    node_inser->nextNode = head->nextNode;
    head->nextNode = node_inser;
    return true;
}


void print_list(Node head) {
    while (head->nextNode != NULL) {
        head = head->nextNode;//不打印头节点,打印的都是下一个节点
        cout << head->element << " ";
    }
    cout << endl;
}


bool delete_List(Node head, int index) {
    if (index < 1) {
        return false;
    }
    //此处将head移动到要删除的index前一位
    while (--index) {
        head = head->nextNode;
        if (head == NULL) {
            return false;
        }
    }
    //此时head->nextNode就是要删除的节点,先判断该节点是否为NULL
    if (head->nextNode == NULL) {
        return false;
    }
    //不能先释放head->nextNode,否则head->nextNode->nextNode找不到
    //先存起来地址
    Node tmp = head->nextNode;
    head->nextNode = head->nextNode->nextNode;
    free(tmp);
    return true;
}

void runList() {
    Linked_node head;//创建一个头节点
    initList(&head);//初始化头节点
    for (int i = 1; i <= 3; i++) {
        insert_List(&head, i * 100, 1);
    }

    print_list(&head);
    cout << find_List(&head, 100);

}

E *get_List(Node head, int index) {
    if (index < 1) {
        return NULL;
    }
    while (--index) {
        head = head->nextNode;
        if (head == NULL) {
            return NULL;
        }
    }
    if (head->nextNode == NULL) {
        return NULL;
    }
//   下面的方式可以直接让head到index位置,而不是index-1
//    do {
//        head = head->nextNode;
//        if (head == NULL) {
//            return NUll;
//        }
//    } while (--index);
    return &head->nextNode->element;
}

int find_List(Node head, E element) {
    head = head->nextNode;//初始比较位置为1
    int index = 1;//表示元素的位置,初始比较位置为1
    while (head) {
        if (head->element == element) {
            return index;
        }
        head = head->nextNode;
        index++;
    }
    return -1;
}

int size_List(Node head) {
    int size = 0;
    while (head->nextNode != NULL) {
        size++;
        head = head->nextNode;
    }
    return size;
}
