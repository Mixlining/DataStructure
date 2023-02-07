//
// Created by QwQ on 2023/1/18.
// 顺序表
//

#ifndef DATASTRUCTURE_SEQUENCELIST_H
#define DATASTRUCTURE_SEQUENCELIST_H

#include "Amain.h"

typedef int E;  //这里我们的元素类型就用int为例吧，先起个别名

struct List {
    E *array;   //实现顺序表的底层数组
    int capacity;   //表示底层数组的容量
    int size;//表示表中的元素数量
};
typedef struct List *ArrayList; //因为是数组实现，所以就叫ArrayList，初始化需要对结构体内部的值进行修改,所以需要传入指针

bool initList(ArrayList list);

/// 插入函数
/// \param list 列表
/// \param element 要插入的元素
/// \param index 插入的位置,此处位置为1开始,非0开始
bool insert_list(ArrayList list, E element, int index);

/// 删除函数
/// \param list 列表
/// \param index 位置
/// \return 返回是否删除成功
bool delete_list(ArrayList list, int index);

/// 查询列表大小
/// \param list
/// \return 返回列表大小
int sizeof_list(ArrayList list);

/// 输入位置返回列表该位置元素的值(指针)
/// \param list
/// \param index
/// \return
E *getElement_list(ArrayList list, int index);

/// 查询元素是否在列表内
/// \param list 列表
/// \param element 要查询的元素
/// \return 返回查询的元素在列表中的位置(从1开始),若查无返回-1
int findElement_list(ArrayList list, const E element);

/// 打印列表
/// \param list 要打印的列表
void print_list(ArrayList list);

void list_run();

#endif //DATASTRUCTURE_SEQUENCELIST_H
