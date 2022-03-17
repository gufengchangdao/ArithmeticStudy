#include<stdio.h>

typedef int elementType;

void swap(elementType *a, elementType *b) {
    elementType tem = *a;
    *a = *b;
    *b = tem;
}

/**
 * 将左边界数、右边界数、中间数排序并取中间数为基元，把基元放在倒数第二位上，
 * 所以左边界和最后两个数都不用参与比较了
 *
 * @param a 数组
 * @param left 数组左边界
 * @param right 数组右边界
 * @return 基元大小
 */
elementType median3(elementType a[], int left, int right) {
    int center = (left + right) >> 1;
    // 使得左边界数、右边界数、中间数有序
    if (a[left] > a[center]) swap(&a[left], &a[center]);
    if (a[left] > a[right]) swap(&a[left], &a[right]);
    if (a[center] > a[right]) swap(&a[center], &a[right]);
    // 将基元放在倒数第二位上
    swap(&a[center], &a[right - 1]);

    return a[right - 1];
}

// 简单的插入排序
void insertionSort(elementType *a, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int j, tmp = a[i]; //tem为待排序数
        for (j = i; j > left && a[j - 1] > tmp; --j) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

/**
 * 快速排序
 * @param a 待排数组
 * @param left 数组左边界
 * @param right 数组右边界，a[right]必须有效
 */
void quickSort(elementType *a, int left, int right) {
    int pivot; //基准值
    int cutoff = 2; //阈值，当待排序元素小于该值时使用简单排序
    int low, high;
    if (cutoff <= right - left) {
        pivot = median3(a, left, right); //寻找基元
        low = left;
        high = right - 1; //基元
        while (1) {
            while (a[++low] < pivot);
            while (a[--high] > pivot);
            if (low < high) swap(&a[low], &a[high]); //如果lwo和high没有错位就不断交换
            else break;
        }
        swap(&a[low], &a[right - 1]); //将基准放在low的位置
        quickSort(a, left, low - 1);
        quickSort(a, low + 1, right);
    } else {
        insertionSort(a, left, right); //元素太少，使用简单排序，不再递归
    }
}

int main() {
    int n;
    elementType a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    // insertionSort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }


}