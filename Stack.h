//  栈实现,使用的是顺序表实现
// Created by QwQ on 2023/2/1.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "Amain.h"

typedef int E;
struct Stack {
    E *array;//通过数组存储
    int capacity;//标记最大容量,即栈的能力
    int top;//标记的是此时栈顶的位置,默认为-1.从0开始
};
typedef Stack *ArrayStack;

/// 初始化栈
/// \param stack
/// \return
bool initStack(ArrayStack stack);

/// 打印栈中的元素
/// \param stack
void printStack(ArrayStack stack);

/// 入栈操作
/// \param stack
/// \param element 入栈的元素
/// \return
bool pushStack(ArrayStack stack, E element);

/// 判断栈是否为空
/// \param stack
/// \return 1表示为空,0表示为非空
bool isEmpty(ArrayStack stack);

E popStack(ArrayStack stack);

void run_Stack();

#endif //DATASTRUCTURE_STACK_H
