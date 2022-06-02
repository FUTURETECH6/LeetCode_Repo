/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    2347
 * Dislikes: 472
 * Total Accepted:    422.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"/home/"'
 *
 * Given a string path, which is an absolute path (starting with a slash '/')
 * to a file or directory in a Unix-style file system, convert it to the
 * simplified canonical path.
 *
 * In a Unix-style file system, a period '.' refers to the current directory, a
 * double period '..' refers to the directory up a level, and any multiple
 * consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
 * problem, any other format of periods such as '...' are treated as
 * file/directory names.
 *
 * The canonical path should have the following format:
 *
 *
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period '.' or double period
 * '..')
 *
 *
 * Return the simplified canonical path.
 *
 *
 * Example 1:
 *
 *
 * Input: path = "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 *
 *
 * Example 2:
 *
 *
 * Input: path = "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 *
 *
 * Example 3:
 *
 *
 * Input: path = "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <vector>

class Solution {
  private:
    void process(string &s, vector<string> &resultList) {
        if (s == "" || s == ".") {
            return;
        } else if (s == "..") {
            if (!resultList.empty())
                resultList.pop_back();
        } else {
            resultList.push_back(s);
        }
    }

  public:
    string simplifyPath(string path) {
        vector<string> resultList;

        for (size_t pos = path.find('/'); pos != string::npos; pos = path.find('/')) {
            string token = path.substr(0, pos);
            process(token, resultList);
            path.erase(0, pos + 1);
        }
        process(path, resultList);

        path = resultList.empty() ? "/" : "";
        for (auto &s : resultList) {
            path += "/" + s;
        }

        return path;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    cout << "output: " << Solution().simplifyPath("/aaa/ssa///saas//sa") << endl;
    cout << "output: " << Solution().simplifyPath("/home/") << endl;
    cout << "output: " << Solution().simplifyPath("/../") << endl;
    cout << "output: " << Solution().simplifyPath("/home//foo/") << endl;
    cout << "output: " << Solution().simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}
