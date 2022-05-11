/*
 * @lc app=leetcode id=53 lang=rust
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    20507
 * Dislikes: 1009
 * Total Accepted:    2.3M
 * Total Submissions: 4.7M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 * G
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let mut max_count = 0;
        for i in nums.iter() {
            if *i < 0 && count > max_count {
                max_count = count;
            }
            count += *i;
            if count < 0 {
                count = 0;
            }
        }

        if count > max_count {
            max_count = count;
        }

        if max_count == 0 {
            max_count = *nums.iter().max().unwrap();
        }

        return max_count;
    }
}
// @lc code=end

pub struct Solution;

fn main() {
    println!("{}", Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4])); // 6
    println!("{}", Solution::max_sub_array(vec![5, 4, -1, 7, 8])); // 23
    println!("{}", Solution::max_sub_array(vec![-1])); // -1
    println!("{}", Solution::max_sub_array(vec![1, 1, -2])); // 2
    println!("{}", Solution::max_sub_array(vec![-2, 1])); // 1
    println!("{}", Solution::max_sub_array(vec![-2, -1])); // -1
    println!("{}", Solution::max_sub_array(vec![-1, -2, -3, 1])); // 1
    println!("{}", Solution::max_sub_array(vec![0, -3, 1, 1])); // 2
    println!("{}", Solution::max_sub_array(vec![-1, 0])); // 0
    println!("{}", Solution::max_sub_array(vec![-2, 1, 0, -3])); // 1
    println!("{}", Solution::max_sub_array(vec![-2, -2, -3, 0, -3, 1, -3])); // 1
    println!("{}", Solution::max_sub_array(vec![0, -3, -2, -3, -2, 2, -3, 0, 1, -1])); // 2
}
