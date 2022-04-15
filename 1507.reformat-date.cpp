/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 *
 * https://leetcode.com/problems/reformat-date/description/
 *
 * algorithms
 * Easy (61.71%)
 * Likes:    245
 * Dislikes: 330
 * Total Accepted:    38.9K
 * Total Submissions: 63K
 * Testcase Example:  '"20th Oct 2052"'
 *
 * Given a date string in the form Day Month Year, where:
 *
 *
 * Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
 * Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
 * "Sep", "Oct", "Nov", "Dec"}.
 * Year is in the range [1900, 2100].
 *
 *
 * Convert the date string to the format YYYY-MM-DD, where:
 *
 *
 * YYYY denotes the 4 digit year.
 * MM denotes the 2 digit month.
 * DD denotes the 2 digit day.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: date = "20th Oct 2052"
 * Output: "2052-10-20"
 *
 *
 * Example 2:
 *
 *
 * Input: date = "6th Jun 1933"
 * Output: "1933-06-06"
 *
 *
 * Example 3:
 *
 *
 * Input: date = "26th May 1960"
 * Output: "1960-05-26"
 *
 *
 *
 * Constraints:
 *
 *
 * The given dates are guaranteed to be valid, so no error handling is
 * necessary.
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start

#include <map>
#include <numeric>

class Solution {
  private:
    map<string, unsigned> month = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

    string zeroPadding(const string s, const size_t n) { return string(n - min(n, s.length()), '0') + s; }

  public:
    string reformatDate(string date) {
        auto day_end   = date.find(' ');
        auto month_end = date.find(' ', day_end + 1);
        return zeroPadding(date.substr(month_end + 1), 4) + "-" + zeroPadding(to_string(month[date.substr(day_end + 1, month_end - day_end - 1)]), 2) + "-" +
               zeroPadding(date.substr(0, day_end - 2), 2);
    }
};
// @lc code=end
