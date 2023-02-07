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
    //�ƶ���Ҫ����Ľڵ��ǰһ��λ��
    while (--index) {
        head = head->next_node;
        if (head == NULL) {
            return 0;
        }
    }
    //�����ڵ�
    Node node_inser = static_cast<Node>(malloc(sizeof(DoubleLink_Node)));
    //��ֹ�����ڴ�ʧ��
    if (node_inser == NULL) {
        return 0;
    }
    if (head->next_node) {
        //������ĩβ��������,��head.next=NULL,���ʱһ����ͷ����Ҫ���
        head->next_node->prev_node = node_inser;
    }
    //Ԫ��
    node_inser->element = element;
    //��ڵ�
    node_inser->next_node = head->next_node;//�����ʱhead.next�����ھ���null,��Ȼ������=
    //ǰ�ڵ�
    node_inser->prev_node = head;
    head->next_node = node_inser;
    return 1;

}

void prin_Doublelink(Node head) {
    cout << "�������" << endl;
    while (head->next_node != NULL) {
        head = head->next_node;
        cout << head->element << " ";
    }
    cout << endl;

    cout << "�������" << endl;
    //��ʱhead�����һ��
    //��ֹhead��һ��ʼ��ͷ�ڵ�,���Ԫ��0
    if (head->prev_node != NULL) {
        do {
            //��������ʼͷ�ڵ�,������
            cout << head->element << " ";
            head = head->prev_node;
        } while (head->prev_node != NULL);
    }
    cout << endl;


}

bool delete_Doublelink(Node head, int index) {

    if (index < 1)return 0;
    //��head�ƶ���Ҫɾ���Ľڵ�ǰһ���ڵ�
    while (--index) {
        head = head->next_node;
        if (head == NULL)return 0;
    }
    Node tmp = head->next_node;//�ȴ���Ҫɾ���Ľڵ�
    //�ж�Ҫɾ���Ľڵ��Ƿ�Ϊ�սڵ�
    if (head->next_node == NULL)return 0;
    //���Ƿ������һ���ڵ����ɾ��
    if (head->next_node->next_node != NULL) {
        head->next_node->next_node->prev_node = head;
    }
    head->next_node = head->next_node->next_node;

    //�ͷŽڵ�
    free(tmp);
    return 1;
}
