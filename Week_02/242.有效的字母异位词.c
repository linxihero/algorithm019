/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

// method1: sort and compare two string
// 时间复杂度：O(2*nlog(n) + n)
// int mySort(const void *p1, const void *p2) {
//     const char *t1 = (const char *)p1;
//     const char *t2 = (const char *)p2;
//     return (*t1 > *t2);
// }
// bool isAnagram(char * s, char * t) {
//     if (s == NULL && t == NULL) {
//         return true;
//     }
//     if (strlen(s) != strlen(t)) {
//         return false;
//     }
//     qsort(s, strlen(s), sizeof(s[0]), mySort);
//     qsort(t, strlen(t), sizeof(t[0]), mySort);
//     for (int i = 0; i < strlen(s); i++) {
//         if (s[i] != t[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// method2: hash
bool isAnagram(char * s, char * t) {
    if (s == NULL && t == NULL) {
        return true;
    }
    if (strlen(s) != strlen(t)) {
        return false;
    }
    char hashT[26] = {0}; 
    for (int i = 0; i < strlen(s); i++) {
        hashT[s[i]-'a']++;
        hashT[t[i]-'a']--;
    }
    for (char j = 0; j < 26; j++) {
        if (hashT[j] != 0) {
            return false;
        }
    }
    return true;
}

// @lc code=end

