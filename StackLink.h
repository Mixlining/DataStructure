// 栈实现 通过链表实现
// Created by QwQ on 2023/2/2.
// 将头节点指向栈顶,然后栈顶节点连接后续节点
// 入栈时,只需要在头节点和栈顶节点间插入新节点

#ifndef DATASTRUCTURE_STACKLINK_H
#define DATASTRUCTURE_STACKLINK_H

#include "Amain.h"

typedef int E;
struct StackLink_Node {
    E element;
    StackLink_Node *next_node;
};

typedef StackLink_Node *Node;

/// 初始化节点
/// \param head
void initStackLink(Node head);


void run_StackLink();

/// 打印栈,从栈顶开始打印
/// \param head
void prin_StackLink(Node head);

/// 入栈操作
/// \param head
/// \param element
/// \return
bool push_StackLink(Node head, E element);

/// 出栈操作
/// \param head
/// \return
E pop_StackLink(Node head);

/// 判断栈是否为空
/// \param head
/// \return 为空返回1,不为空返回0
bool isEmpty(Node head);

#endif //DATASTRUCTURE_STACKLINK_H
