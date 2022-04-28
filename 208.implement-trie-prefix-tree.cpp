/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (57.61%)
 * Likes:    6869
 * Dislikes: 91
 * Total Accepted:    572.3K
 * Total Submissions: 985.4K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start

#include <unordered_map>

class Trie {
  private:
    unordered_map<char, Trie *> children;
    unordered_map<char, bool> end;

  public:
    Trie() {}

    void insert(string word) {
        if (word.size() == 1) {
            end[word.front()] = true;
            return;
        }

        // size >= 2
        if (!children[word.front()]) {
            children[word.front()] = new Trie();
        }
        children[word.front()]->insert(word.substr(1));
    }

    bool search(string word) {
        if (word.size() == 1) {
            return end[word.front()];
        }

        // size >= 2
        return children[word.front()] ? children[word.front()]->search(word.substr(1)) : false;
    }

    bool startsWith(string prefix) {
        if (prefix.size() == 1) {
            return end[prefix.front()] || children[prefix.front()];
        }

        // size >= 2
        return children[prefix.front()] ? children[prefix.front()]->startsWith(prefix.substr(1)) : false;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // return True
    cout << trie.search("app") << endl;      // return False
    cout << trie.startsWith("app") << endl;  // return True
    trie.insert("app");
    cout << trie.search("app") << endl;        // return True
    cout << trie.startsWith("apple") << endl;  // return True
    return 0;
}
