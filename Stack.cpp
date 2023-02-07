//
// Created by QwQ on 2023/2/1.
//

#include "Stack.h"

bool initStack(ArrayStack stack) {
    stack->array = static_cast<E *>(malloc(sizeof(E) * 10));//初始化申请10个位置
    if (stack->array == NULL)return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;

}

void run_Stack() {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < 10; ++i) {
        pushStack(&stack, i);
    }
    printStack(&stack);

    while (!isEmpty(&stack)) {
        cout << popStack(&stack) << " ";
    }
    cout << endl << "清空结束" << endl;
    printStack(&stack);

}

bool pushStack(ArrayStack stack, E element) {
    if (stack->top + 1 == stack->capacity) {
        //让新容量是旧容量的1.5倍
        int new_capacity = stack->capacity + (stack->capacity >> 1);
        E *new_array = static_cast<E *>(realloc(stack->array, new_capacity * sizeof(E)));
        if (new_array == NULL)return 0;
        stack->capacity = new_capacity;
        stack->array = new_array;
    }
    stack->array[stack->top + 1] = element;
    stack->top++;
    return 1;

}

void printStack(ArrayStack stack) {
    for (int i = 0; i < stack->top + 1; ++i) {
        cout << stack->array[i] << " ";
    }
    cout << endl;
}

E popStack(ArrayStack stack) {
    //top--表示先使用top的值,再对top本身-1
    //--top表示先对top本身-1,再使用top的值
    return stack->array[stack->top--];
}

bool isEmpty(ArrayStack stack) {
    return stack->top == -1;

}
