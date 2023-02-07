//  队列 使用顺序表(数组)实现
//  包含了循环 取余的思想
// Created by QwQ on 2023/2/3.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "Amain.h"

typedef int E;
struct Queue {
    E *array;//数组
    int capacity;//数组容量
    int rear, front;//队尾,队首指针
};
typedef Queue *ArrayQueue;

bool initQueue(ArrayQueue queue);

/// 打印队列:从队首(front)开始打印
/// \param queue
void prin_Queue(ArrayQueue queue);

void run_Queue();

/// 入队操作
/// \param queue
/// \param element
/// \return
bool offerQueue(ArrayQueue queue, E element);

/// 出队操作
/// \param queue
/// \return
E pollQueue(ArrayQueue queue);

/// 判断是否为空
/// \param queue
/// \return 为空返回1,不为空返回0
bool isEmpty(ArrayQueue queue);

#endif //DATASTRUCTURE_QUEUE_H
