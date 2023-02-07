//
// Created by QwQ on 2023/2/3.
//

#include "Queue.h"

bool initQueue(ArrayQueue queue) {
    queue->array = static_cast<E *>(malloc(sizeof(E) * 10));
    if (queue->array == NULL)return 0;
    //申请10个空间,有一个是预留的,所以只有9个是存放元素的
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return 1;

}

void run_Queue() {
    Queue queue;
    initQueue(&queue);
    //容量为10,空一格,只能转入9个数据,即0-8
    for (int i = 0; i < 8; ++i) {
        offerQueue(&queue, i);
    }
    prin_Queue(&queue);
    
    cout << "出队" << endl;
    while (!isEmpty(&queue)) {

        cout << pollQueue(&queue) << " ";
    }

}

bool offerQueue(ArrayQueue queue, E element) {
    //判断队列是否已满
    //使用余数判断
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        return 0;
    }
    //队尾前进一位
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 1;
}

void prin_Queue(ArrayQueue queue) {
    cout << "开始打印队列" << endl;
    //从队首开始打印,先入列的先打印
    int i = queue->front;
    //以队尾为判断标准
    while (i != queue->rear) {
        i = (i + 1) % queue->capacity;
        cout << queue->array[i] << " ";
    }
    cout << endl;


}

E pollQueue(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];

}

bool isEmpty(ArrayQueue queue) {
    return queue->rear == queue->front;

}
