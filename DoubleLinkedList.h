//  双向链表
// Created by QwQ on 2023/1/31.
//

#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include "Amain.h"

typedef int E;

/*双向链表节点 结构体
 * element 该节点存放的数据
 * next_node 存放的下一节点的指针
 * prev_node 存放的上一节点的指针
 * */
struct DoubleLink_Node {
    E element;
    struct DoubleLink_Node *next_node;
    struct DoubleLink_Node *prev_node;
};

typedef DoubleLink_Node *Node;

/// 初始化节点
/// \param node
void initNode(Node node);

/// 插入节点,允许在末尾插入
/// \param head 双向链表的头节点
/// \param element 插入的元素值
/// \param index 插入的位置(默认从1开始),此处支持在最末尾插入
/// \return 返回是否插入成功,1表示成功,0表示插入失败
bool insert_Doublelink(Node head, E element, int index);

/// 打印双向链表
/// \param head
void prin_Doublelink(Node head);

/// 删除节点,允许在删除末尾
/// \param head 头节点
/// \param index 要删除的节点的位置
/// \return 返回是否删除成功
bool delete_Doublelink(Node head, int index);

void runDoubleLinkList();

#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
