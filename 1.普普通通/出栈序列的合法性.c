/*
出栈序列的合法性
给定一个最大容量为 M 的堆栈，将 N 个数字按 1, 2, 3, ..., N 的顺序入栈，允许任意时刻出栈，则哪些数字序列是不可能得到的？例如给定 M=5、N=7，则我们有可能得
    到{ 1, 2, 3, 4, 5, 6, 7 }，但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。

    就是模拟堆栈，遇到比自然增长大的数，把该数之前的数存入堆栈，堆栈存不下就不合法，遇到比自然增长小的数就弹出栈顶元素，栈顶元素和读取的数不相等就不合法
*/
#include <stdio.h>
#include<string.h>

const int MAXSIZE = 1005;

int main() {
    int num[MAXSIZE];       //模拟堆栈，值为1表示在栈中，值为0表示未入栈，值为-1表示已出栈
    int currentMax = 0;     //从1到n增长，表示当前读取到的最大值
    int currentSize = 0;    //当前栈中元素
    int M, N, K, tem;
    int isFail = 0;         //是否不是合法序列
    scanf("%d%d%d", &M, &N, &K);

    while (K--) {
        currentMax = 0;
        currentSize = 0;
        isFail = 0;
        memset(num, 0, sizeof(num));

        for (int i = 0; i < N; ++i) {
            scanf("%d", &tem);
            if (isFail) continue;                                   //该序列不合法，但是数据还是得读取完的
            //读到一个数>currentMax,就把比该数小的数都存入栈，在把该数输出，当比该数小的数都存入栈后再加1(读取到的数)而栈满了就是false
            if (tem > currentMax) {
                currentSize = currentSize + tem - currentMax - 1;
                if (currentSize + 1 > M) isFail = 1;                //栈中装不下这么多元素
                for (int j = currentMax + 1; j < tem; ++j) {        //入栈操作
                    num[j] = 1;
                }
                num[tem] = -1;                                      //读取到的数出栈
                currentMax = tem;
            }
            //读到一个数>currentMax,就把比该数小的数都存入栈，在把该数输出,当 比该数小的数都存入栈后再加1(读取到的数)而栈满了就是false
            else {
                for (int j = currentMax - 1; j > 0; --j) {
                    if (num[j] == 1) {                              //弹出栈顶元素
                        if (j != tem)
                            isFail = 1;
                        else {
                            num[j] = -1;
                            currentSize--;                          //TODO 序列合法，这里栈中元素数量要减1，卡在了这里
                        }
                        break;
                    }
                }
            }
        }
        if (isFail) printf("NO\n");
        else printf("YES\n");
    }
}