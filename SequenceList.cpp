//
// Created by QwQ on 2023/1/18.
// ˳���
//

#include "SequenceList.h"


bool initList(ArrayList list) {  //�����Ĭ�����е�˳����ʼ��С��Ϊ10�ɣ�����
    list->array = static_cast<E *>(malloc(sizeof(E) * 10));   //ʹ��malloc��������10��int��С���ڴ�ռ䣬��Ϊ�ײ�����ʹ��
    if (list->array == NULL) {
        cout << "�ڴ治��,��ʼ���б�ʧ��" << endl;
        return 0;
    }//�鿴�Ƿ�����ɹ�
    list->capacity = 10;    //����ͬ���趨Ϊ10
    list->size = 0;
    return 1;
}

void list_run() {
    List list1;
    bool result = initList(&list1);
    if (result == 1) {
        cout << "�б��ʼ��" << endl;
        print_list(&list1);

        cout << "�������" << endl;
        for (int i = 0; i < 30; ++i) {
            insert_list(&list1, i * 10, i + 1);
        }
        print_list(&list1);

        cout << "ɾ������" << endl;
        delete_list(&list1, 2);
        print_list(&list1);

        cout << "��ѯ��С����" << endl;
        cout << sizeof_list(&list1) << endl;

        cout << "����λ��Ԫ�ز���" << endl;
        cout << "������λ�õ�Ԫ�� " << *getElement_list(&list1, 3) << endl;

        cout << "����Ԫ���Ƿ����б���" << endl;
        cout << "100 ���б��е�λ��" << findElement_list(&list1, 100) << endl;


    } else {
        cout << "����ʧ��" << endl;
    }

}

bool insert_list(ArrayList list, E element, int index) {
    //�жϲ���λ��index�Ƿ�Ϸ�
    if (index < 1 || index > list->size + 1) {
        cout << "����λ�ò��Ϸ�" << endl;
        return 0;
    }
    //�ж������Ƿ����,��������
    if (list->size == list->capacity) {
        //�µ�������С,��ԭ����һ��
        int new_capacity = list->capacity << 2;
        E *new_arry = static_cast<E *>(realloc(list->array, new_capacity * sizeof(E)));
        if (new_arry == NULL) {
            cout << "�ڴ治��,�޷�����" << endl;
            return 0;
        }
        list->capacity = new_capacity;
        list->array = new_arry;
    }
    for (int i = list->size; i > index - 1; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return 1;
}


void print_list(ArrayList list) {
    for (int i = 0; i < list->size; ++i) {
        cout << list->array[i] << " ";
    }
    cout << endl;

}

bool delete_list(ArrayList list, int index) {
    //���ɾ��λ���Ƿ�Ϸ�
    if (index < 1 || index > list->size) {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
        return 0;
    }
    for (int i = index - 1; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}

int sizeof_list(ArrayList list) {
    return list->size;
}

E *getElement_list(ArrayList list, int index) {
    if (index < 1 || index > list->size) {
        cout << "��ѯλ�ó���Χ" << endl;
        return NULL;
    }
    return &list->array[index - 1];
}

int findElement_list(ArrayList list, const E element) {
    for (int i = 0; i < list->size; ++i) {
        if (element == list->array[i]) {
            return i + 1;
        }
    }
    return -1;
}
