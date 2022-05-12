/*
 * @lc app=leetcode id=58 lang=rust
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (37.04%)
 * Likes:    966
 * Dislikes: 77
 * Total Accepted:    735.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of some words separated by some number of
 * spaces, return the length of the last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        s.split_whitespace().last().unwrap().len() as i32
    }
}
// @lc code=end

pub struct Solution;

pub fn main() {
    println!("{:?}", Solution::length_of_last_word("Hello World".to_string()));
}
