//
// Created by QwQ on 2023/1/31.
//

#include "DoubleLinkedList.h"

void initNode(Node node) {
    node->next_node = node->prev_node = NULL;
    node->element = 0;

}

void runDoubleLinkList() {
    DoubleLink_Node head;
    initNode(&head);
    insert_Doublelink(&head, 1000, 1);
    insert_Doublelink(&head, 500, 1);
    insert_Doublelink(&head, 300, 1);
    prin_Doublelink(&head);

    delete_Doublelink(&head, 2);
    prin_Doublelink(&head);

}

bool insert_Doublelink(Node head, E element, int index) {
    if (index < 1) {
        return 0;
    }
    //移动到要插入的节点的前一个位置
    while (--index) {
        head = head->next_node;
        if (head == NULL) {
            return 0;
        }
    }
    //创建节点
    Node node_inser = static_cast<Node>(malloc(sizeof(DoubleLink_Node)));
    //防止申请内存失败
    if (node_inser == NULL) {
        return 0;
    }
    if (head->next_node) {
        //处理在末尾插入问题,即head.next=NULL,则此时一个箭头不需要完成
        head->next_node->prev_node = node_inser;
    }
    //元素
    node_inser->element = element;
    //后节点
    node_inser->next_node = head->next_node;//如果此时head.next不存在就是null,依然可以用=
    //前节点
    node_inser->prev_node = head;
    head->next_node = node_inser;
    return 1;

}

void prin_Doublelink(Node head) {
    cout << "正向遍历" << endl;
    while (head->next_node != NULL) {
        head = head->next_node;
        cout << head->element << " ";
    }
    cout << endl;

    cout << "反向遍历" << endl;
    //此时head是最后一个
    //防止head是一开始的头节点,输出元素0
    if (head->prev_node != NULL) {
        do {
            //如果不是最开始头节点,就正常
            cout << head->element << " ";
            head = head->prev_node;
        } while (head->prev_node != NULL);
    }
    cout << endl;


}

bool delete_Doublelink(Node head, int index) {

    if (index < 1)return 0;
    //将head移动到要删除的节点前一个节点
    while (--index) {
        head = head->next_node;
        if (head == NULL)return 0;
    }
    Node tmp = head->next_node;//先储存要删除的节点
    //判断要删除的节点是否为空节点
    if (head->next_node == NULL)return 0;
    //分是否在最后一个节点进行删除
    if (head->next_node->next_node != NULL) {
        head->next_node->next_node->prev_node = head;
    }
    head->next_node = head->next_node->next_node;

    //释放节点
    free(tmp);
    return 1;
}
