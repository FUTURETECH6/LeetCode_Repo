/*
 * @lc app=leetcode id=67 lang=rust
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (50.23%)
 * Likes:    4982
 * Dislikes: 546
 * Total Accepted:    833.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut c = "".to_string();

        let mut round = 0;

        for index in 0..std::cmp::max(a.len(), b.len()) {
            let mut sum = round;
            if index < a.len() {
                sum += a.as_bytes()[a.len() - 1 - index] - 48;
            }
            if index < b.len() {
                sum += b.as_bytes()[b.len() - 1 - index] - 48;
            }

            match sum {
                3 => {
                    c.push('1');
                    round = 1;
                }
                2 => {
                    c.push('0');
                    round = 1;
                }
                1 => {
                    c.push('1');
                    round = 0;
                }
                0 => {
                    c.push('0');
                    round = 0;
                }
                _ => break,
            }
        }
        if round == 1 {
            c.push('1');
        }

        return c.chars().rev().collect::<String>();
    }
}
// @lc code=end

pub struct Solution;

pub fn main() {
    println!("{}", Solution::add_binary("11".to_string(), "1".to_string())); // 100
    println!("{}", Solution::add_binary("1010".to_string(), "1011".to_string())); // 10101
    println!("{}", Solution::add_binary("1111".to_string(), "1111".to_string())); // 11110
    ()
}
