//  队列:通过链表实现
//  感觉可以通过:给出 尾节点指针的循环单链表 实现
// Created by QwQ on 2023/2/3.
//

#ifndef DATASTRUCTURE_QUEUELIST_H
#define DATASTRUCTURE_QUEUELIST_H

#include "Amain.h"

typedef int E;

//节点
struct QueueList_Node {
    E element;
    QueueList_Node *next_node;
};
typedef QueueList_Node *Node;

//整个链表代表的队列
struct QueueList {
    Node front;//队首节点,队首不存放元素
    Node rear;//队尾节点
};
typedef QueueList *Queue;

bool initQueueList(Queue queue);

void run_QueenList();

/// 入队
/// \param queue
/// \param element
/// \return
bool offerQueue(Queue queue, E element);

/// 打印
/// \param queue
void prin_QueueList(Queue queue);

/// 出队
/// \param queue
/// \return
E pollQueue(Queue queue);

/// 判断是否为空
/// \param queue
/// \return
bool isEmpty(Queue queue);

#endif //DATASTRUCTURE_QUEUELIST_H
