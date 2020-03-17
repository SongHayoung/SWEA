#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
int fRI() {
    int ret = 0, N = gc();
    for (; 0x30>N || N>0x3A; N = gc());
    for (; 0x30 <= N && N <= 0x3A; N = gc()) ret = (ret << 3) + (ret << 1) + (N & 0b1111);
    return ret;
}
struct assign {
    int D;
    int T;
};
struct assign ass[1000000];
struct assign sorted[1000000];
void Merge(int left, int mid, int right) {
    int L = left, R = mid + 1, Index = 0;
    while (L <= mid && R <= right) {
        if (ass[L].D > ass[R].D) sorted[Index++] = ass[L++];
        else    sorted[Index++] = ass[R++];
    }
    if (L <= mid)
        for (; L <= mid;)
            sorted[Index++] = ass[L++];
    else
        for (; R <= right;)
            sorted[Index++] = ass[R++];
 
    for (Index = left; Index <= right; Index++)
        ass[Index] = sorted[Index - left];
}
 
void MergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}
void sort(int l, int r) {
    register int left = l;
    register int right = r;
    register int pivot = ass[(left + right)>>1].D;
    struct assign temp;
    do {
        while (ass[left].D > pivot&&left<=right) ++left;
        while (ass[right].D < pivot&&left <= right) --right;
        if (left <= right) {
            memcpy(&temp, &ass[left], sizeof(struct assign));
            memcpy(&ass[left], &ass[right], sizeof(struct assign));
            memcpy(&ass[right], &temp, sizeof(struct assign));
            ++left;
            --right;
        }
    } while (left <= right);
    if (l < right) sort(l, right);
    if (r > left) sort(left, r);
}
int compare(const void *A, const void *B) {
    return *(int*) A > *(int*)B ? -1 : 1;
}
int main(int argc, char** argv){
    register int T = fRI()+1, tc = 0, N, ans, i;
    while (--T) {
        N = fRI();
        for (i = 0; i < N; ++i)
            ass[i].T = fRI(), ass[i].D = fRI();
        //MergeSort(0, N-1);
        //qsort(ass, N, sizeof(struct assign), compare);
        sort(0, N-1);
        ans = ass[0].D - ass[0].T;
        for (i = 1; i < N; ++i)
            ans > ass[i].D ? (ans = ass[i].D - ass[i].T) : (ans -= ass[i].T);
        printf("#%d %d\n",++tc, ans);
    }
}
