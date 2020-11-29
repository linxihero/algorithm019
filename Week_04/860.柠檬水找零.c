/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start

bool charge(int *nums, int m) {
    if (m == 20) {
        if (nums[0] < 1) {
            return false;
        }
        if (nums[1] > 0) {
            nums[0]--;
            nums[1]--;
            return true;
        } else if (nums[0] >= 3) {
            nums[0] -= 3;
            return true;
        }
        return false;
    } else if (m == 10) {
        if (nums[0] > 0) {
            nums[0]--;
            return true;
        }
        return false;
    }
    return false; 
}

bool lemonadeChange(int *bills, int billsSize)
{
    if (bills == NULL || billsSize == 0) {
        return true;
    }
    int nums[2] = {0}; //存放5/10的张数，对应下标0，1
    // 20 -> 10+5 或者 3*5
    // 10 -> 5
    // 5 -> 0
    for (int i = 0; i < billsSize; i++) {
        int m = bills[i];
        if (m != 20) {
            nums[m/5 - 1]++;
        }
        if (m == 5) {
            continue;
        } 
        if (!charge(nums, m)) {
            return false;
        }
    }
    return true;
}

// @lc code=end
