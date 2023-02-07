//
// Created by QwQ on 2023/1/18.
// 顺序表
//

#include "SequenceList.h"


bool initList(ArrayList list) {  //这里就默认所有的顺序表初始大小都为10吧，随意
    list->array = static_cast<E *>(malloc(sizeof(E) * 10));   //使用malloc函数申请10个int大小的内存空间，作为底层数组使用
    if (list->array == NULL) {
        cout << "内存不足,初始化列表失败" << endl;
        return 0;
    }//查看是否申请成功
    list->capacity = 10;    //容量同样设定为10
    list->size = 0;
    return 1;
}

void list_run() {
    List list1;
    bool result = initList(&list1);
    if (result == 1) {
        cout << "列表初始化" << endl;
        print_list(&list1);

        cout << "插入测试" << endl;
        for (int i = 0; i < 30; ++i) {
            insert_list(&list1, i * 10, i + 1);
        }
        print_list(&list1);

        cout << "删除测试" << endl;
        delete_list(&list1, 2);
        print_list(&list1);

        cout << "查询大小测试" << endl;
        cout << sizeof_list(&list1) << endl;

        cout << "查找位置元素测试" << endl;
        cout << "第三个位置的元素 " << *getElement_list(&list1, 3) << endl;

        cout << "查找元素是否在列表中" << endl;
        cout << "100 在列表中的位置" << findElement_list(&list1, 100) << endl;


    } else {
        cout << "启动失败" << endl;
    }

}

bool insert_list(ArrayList list, E element, int index) {
    //判断插入位置index是否合法
    if (index < 1 || index > list->size + 1) {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    //判断容量是否溢出,进行扩容
    if (list->size == list->capacity) {
        //新的容量大小,是原来的一倍
        int new_capacity = list->capacity << 2;
        E *new_arry = static_cast<E *>(realloc(list->array, new_capacity * sizeof(E)));
        if (new_arry == NULL) {
            cout << "内存不足,无法插入" << endl;
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
    //检测删除位置是否合法
    if (index < 1 || index > list->size) {
        cout << "删除位置不合法" << endl;
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
        cout << "查询位置超范围" << endl;
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
