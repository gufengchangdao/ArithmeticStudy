#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();

bool IsEmpty(Stack S);

bool Push(Stack S, SElementType X);

SElementType Pop(Stack S); /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S);/* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT);

void PreorderTraversal(BinTree BT);

void PostorderTraversal(BinTree BT);

int main() {
    BinTree BT = CreateBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */

// 中序遍历
void InorderTraversal(BinTree BT) {
    BinTree T = BT;
    Stack S = CreateStack(); // 创建并初始化堆栈S
    while (T || !IsEmpty(S)) {
        // 一直向左并将沿途结点压入堆栈
        while (T) {
            Push(S, T);
            T = T->Left;
        }

        T = Pop(S);   // 结点弹出堆栈
        printf(" %c", T->Data); // (访问) 打印结点
        T = T->Right; // 转向右子树
    }
}
// 先序遍历
void PreorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    Stack S = CreateStack();
    Push(S, BT); //根结点存入
    while (!IsEmpty(S)) {
        BinTree node = Pop(S);
        printf(" %c", node->Data);
        if (node->Right)
            Push(S, node->Right);
        if (node->Left)
            Push(S, node->Left);
    }
}

// 先序遍历
// void PreorderTraversal(BinTree BT) {
//     BinTree T = BT;
//     Stack S = CreateStack(); // 创建并初始化堆栈S
//     while (T || !IsEmpty(S)) {
//         // 一直向左并将沿途结点压入堆栈
//         while (T) {
//             Push(S, T);
//             printf(" %c", T->Data); // (访问) 打印结点
//             T = T->Left;
//         }
//
//         T = Pop(S);   // 结点弹出堆栈
//         T = T->Right; // 转向右子树
//     }
// }

// 后序遍历
void PostorderTraversal(BinTree BT) {
    BinTree flag = NULL;
    BinTree T = BT;
    Stack stack = CreateStack();
    while (T || !IsEmpty(stack)) {
        // 向左
        while (T) {
            Push(stack, T);
            T = T->Left;
        }
        BinTree node = Peek(stack);
        // 右子树如果为NULL或者已经访问过就不再遍历，直接输出
        if (node->Right == NULL || flag == node->Right) {
            printf(" %c", node->Data);
            flag = Pop(stack); //进行标记
        } else {
            T = node->Right;
        }
    }
}

/**
 * 遍历的规律
 */
void Traversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack();
    while (T || !IsEmpty(S)) {
        while (T) {
            // TODO 先序遍历
            Push(S, T);
            T = T->Left;
        }
        // TODO 后序遍历时结点不要弹出，只是返回，还需要判断右结点是否遍历过，遍历过就弹出，没遍历过就 T=T->Right 开始右结点遍历
        T = Pop(S);
        // TODO 中序遍历
        T = T->Right;
    }
}
