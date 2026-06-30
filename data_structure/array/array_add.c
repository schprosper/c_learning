#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;

#define MAXSIZE 100 //假设非零元个数的最大值为100

typedef struct {
    int i,j;		//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;		//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];// 非零元三元组表
    int    m, n, len;	// 矩阵的行数、列数和非零元个数
}TSMatrix;



// 将稀疏矩阵 pM 和 pN 相加，结果存入 pQ
/*
两个有序表：
pa 扫 M
pb 扫 N
k 写 Q

谁的位置小，谁先进入 Q；
位置相同，就相加；
相加结果为 0，不写入 Q。
*/

/*这里传输进来的时候也是三元组！！！*/
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ) {
    int a = 0;   // 扫描 pM 的 data
    int b = 0;   // 扫描 pN 的 data
    int k = 0;   // pQ 当前写入位置
    ElemType sum;

    // // 空指针保护
    // if (pM == NULL || pN == NULL || pQ == NULL) {
    //     return false;
    // }

    // 行数或列数不同，矩阵不可加
    if (pM->m != pN->m || pM->n != pN->n) {
        return false;
    }

    // 设置结果矩阵的行数、列数
    pQ->m = pM->m;
    pQ->n = pM->n;
    pQ->len = 0;

    // 两个三元组表都没有扫完时，进行归并
    while (a < pM->len && b < pN->len) {

        // pM 当前元素位置更靠前
        if (pM->data[a].i < pN->data[b].i ||
            (pM->data[a].i == pN->data[b].i &&
             pM->data[a].j < pN->data[b].j)) {

            if (k >= MAXSIZE) {
//                pQ->len = 0; //这句话可以不写，
                return false;
            }

            pQ->data[k] = pM->data[a];
            k++;
            a++;
        }

        // pN 当前元素位置更靠前
        else if (pM->data[a].i > pN->data[b].i ||
                 (pM->data[a].i == pN->data[b].i &&
                  pM->data[a].j > pN->data[b].j)) {

            if (k >= MAXSIZE) {
                pQ->len = 0;
                return false;
            }

            pQ->data[k] = pN->data[b];
            k++;
            b++;
        }

        // 两个元素位置相同，值相加
        else {
            sum = pM->data[a].e + pN->data[b].e;

            // 相加后不为 0，才写入结果矩阵
            if (sum != 0) {
                if (k >= MAXSIZE) {
                    pQ->len = 0;
                    return false;
                }
                // 因为不和之前一样吧三元组放进来，所以，需要重新确定一下 ije
                pQ->data[k].i = pM->data[a].i;
                pQ->data[k].j = pM->data[a].j;
                pQ->data[k].e = sum;
                k++;
            }

            a++;
            b++;
        }
    }

    // pM 还有剩余，直接复制
    while (a < pM->len) {
        if (k >= MAXSIZE) {
            pQ->len = 0;
            return false;
        }

        pQ->data[k] = pM->data[a];
        k++;
        a++;
    }

    // pN 还有剩余，直接复制
    while (b < pN->len) {
        if (k >= MAXSIZE) {
            pQ->len = 0;
            return false;
        }

        pQ->data[k] = pN->data[b];
        k++;
        b++;
    }

    pQ->len = k;
    return true;
}



typedef struct {
    int i,j;		//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;		//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];// 非零元三元组表
    int    m, n, len;	// 矩阵的行数、列数和非零元个数
}TSMatrix;
/*pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，
函数返回 false，否则函数返回 true，且 pQ 指向两个矩阵的和。*/
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ) {
    int a = 0;
    int b = 0;
    int k = 0;
    
    if(pM->m != pN->m || pM->n != pN->n)
    {
        return false;
    }

    pQ->m =pM->m;
    pQ->n =pM->n;
    pQ->len = k;

    while(a<pM->len && b<pN->len)
    {
        //当PM的位置，小于PN的时候
        if(pM->data[a].i <pN->data[b].i ||
        (pM->data[a].i  == pN->data[b].i && 
        pM->data[a].j  < pN->data[b].j))
        {
            pQ->data[k] = pM->data[a];
            k++;
            a++;
        }

        else if(pN->data[a].i < pM->data[b].i ||
        (pN->data[a].i == pM->data[b].i && 
        pN->data[a].j < pM->data[b].j))
        {
            pQ->data[k] = pN->data[b];
            k++;
            b++;
        }
        else
        {
            pQ->data[k].e = pM->data[a].e +   pN->data[a].e;
            pQ->data[k].i = pM->data[a].i;
            pQ->data[k].j = pM->data[a].j;
            k++;
            a++;
            b++;
        }

    }


}
/*好了好了不写了，图书馆关闭了QAQ
*/



//确定变量
//不可加违规检查
//确定总体数组的 行 列 和个数
// 二者都有剩余的时候
// 一个没有弄完一个弄完了的时候
// 最终弄完，得到，最终长度的时候。