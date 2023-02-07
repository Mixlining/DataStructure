//
// Created by QwQ on 2023/1/21.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include "Amain.h"

typedef int E;

struct Linked_node {
    E element;//该节点存放的数据
    struct Linked_node *nextNode;//该节点存放的指向下一节点的指针
};
typedef struct Linked_node *Node;

/// 初始化头节点,让其指向为null,头节点不含数据
/// \param head 要初始化的节点的地址(一般是头节点
void initList(Node head);

/// 链表的插入,插入只能在中间插入,不能插入末尾
/// \param head 头节点
/// \param element 插入的元素
/// \param index 插入的位置,此处认为头节点位置为0(不含元素),故index必须>0

bool insert_List(Node head, E element, int index);

/// 链表的删除
/// \param head 头节点
/// \param index 待删除的节点位序
/// \return 是否删除成功
bool delete_List(Node head, int index);

/// 获取对应位置上的元素
/// \param head
/// \param index
/// \return
E *get_List(Node head, int index);

/// 查找对应元素的位置
/// \param head 列表头
/// \param element 要查询的元素值
/// \return 返回-1标识没有找到,返回其他标识元素的位置
int find_List(Node head, E element);

/// 检测链表的长度,不包括链表头
/// \param head 链表的头
/// \return 返回链表的长度
int size_List(Node head);

void print_list(Node head);

void runList();

#endif //DATASTRUCTURE_LINKEDLIST_H
