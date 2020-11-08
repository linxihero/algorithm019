/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start

void moveZeroes(int* nums, int numsSize) {
    int zeroIdx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[zeroIdx] = nums[i];
            if (zeroIdx != i) {
                nums[i] = 0;
            }
            zeroIdx++;
        }
    }
    return;
}

// method 2
// void moveZeroes(int* nums, int numsSize) {
//     int zeroIdx = 0;
//     int zeroCont = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] != 0) {
//             nums[zeroIdx] = nums[i];
//             zeroIdx++;
//             zeroCont++;
//         }
//     }
//     for (int i = zeroCont; i < numsSize; i++) {
//         nums[i] = 0;
//     }
//     return;
// }

// @lc code=end

