/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 */

// @lc code=start

int myCompare(const void *p1, const void *p2) {
    return *(int*)p1 - *(int*)p2;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    if (s == NULL || sSize == 0) {
        return 0;
    }
    int res = 0;
    qsort(g, gSize, sizeof(int), myCompare);
    qsort(s, sSize, sizeof(int), myCompare);
    int is = 0;
    int ig = 0;
    while (is < sSize && ig < gSize) {
        if (s[is] >= g[ig]) {
            ig++;
            res++;
        }
        is++;
    }
    return res;
}
// @lc code=end

