//
// Created by QwQ on 2023/2/3.
//

#include "QueueList.h"

bool initQueueList(Queue queue) {
    Node node = static_cast<Node>(malloc(sizeof(QueueList_Node)));
    if (node == NULL)return 0;
    node->next_node = NULL;
    //队首节点和队尾节点都是同一点
    queue->front = queue->rear = node;
    return 1;
}

void run_QueenList() {
    QueueList queue;
    initQueueList(&queue);
    for (int i = 0; i < 10; ++i) {
        offerQueue(&queue, i);
    }
    prin_QueueList(&queue);
    while (!isEmpty(&queue)) {

        cout << pollQueue(&queue) << " ";
    }


}

bool offerQueue(Queue queue, E element) {
    Node new_node = static_cast<Node>(malloc(sizeof(QueueList_Node)));
    if (new_node == NULL)return 0;
    new_node->element = element;
    new_node->next_node = NULL;
    //先让之前的尾节点连接上新入队的节点
    queue->rear->next_node = new_node;
    //再让队尾指针指向新的队尾
    queue->rear = new_node;
    return 1;

}

void prin_QueueList(Queue queue) {
    Node top = queue->front->next_node;
    while (top != NULL) {
        cout << top->element << " ";
        top = top->next_node;
    }
    cout << endl;


}

E pollQueue(Queue queue) {
    Node tmp = queue->front->next_node;
    E e_return = queue->front->next_node->element;
    // front->1->2(rear) 此时变成 front->2
    queue->front->next_node = queue->front->next_node->next_node;
    // 当front->1(rear)时, 若执行上面,会变成front-(rear)->NUll,出现front在near后
    //  应该此时让near=front,避免near指向的内容被释放
    if (queue->rear == tmp) {
        queue->rear = queue->front;
    }
    free(tmp);
    return e_return;

}

bool isEmpty(Queue queue) {

    return queue->rear == queue->front;
}
