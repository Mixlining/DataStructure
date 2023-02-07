//
// Created by QwQ on 2023/2/3.
//

#include "Queue.h"

bool initQueue(ArrayQueue queue) {
    queue->array = static_cast<E *>(malloc(sizeof(E) * 10));
    if (queue->array == NULL)return 0;
    //����10���ռ�,��һ����Ԥ����,����ֻ��9���Ǵ��Ԫ�ص�
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return 1;

}

void run_Queue() {
    Queue queue;
    initQueue(&queue);
    //����Ϊ10,��һ��,ֻ��ת��9������,��0-8
    for (int i = 0; i < 8; ++i) {
        offerQueue(&queue, i);
    }
    prin_Queue(&queue);
    
    cout << "����" << endl;
    while (!isEmpty(&queue)) {

        cout << pollQueue(&queue) << " ";
    }

}

bool offerQueue(ArrayQueue queue, E element) {
    //�ж϶����Ƿ�����
    //ʹ�������ж�
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        return 0;
    }
    //��βǰ��һλ
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 1;
}

void prin_Queue(ArrayQueue queue) {
    cout << "��ʼ��ӡ����" << endl;
    //�Ӷ��׿�ʼ��ӡ,�����е��ȴ�ӡ
    int i = queue->front;
    //�Զ�βΪ�жϱ�׼
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
