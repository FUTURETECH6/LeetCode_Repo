/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 *
 * https://leetcode.com/problems/snapshot-array/description/
 *
 * algorithms
 * Medium (36.98%)
 * Likes:    1658
 * Dislikes: 250
 * Total Accepted:    107.7K
 * Total Submissions: 291.8K
 * Testcase Example:  '["SnapshotArray","set","snap","set","get"]\n[[3],[0,5],[],[0,6],[0,0]]'
 *
 * Implement a SnapshotArray that supports the following interface:
 *
 *
 * SnapshotArray(int length) initializes an array-like data structure with the
 * given length.  Initially, each element equals 0.
 * void set(index, val) sets the element at the given index to be equal to
 * val.
 * int snap() takes a snapshot of the array and returns the snap_id: the total
 * number of times we called snap() minus 1.
 * int get(index, snap_id) returns the value at the given index, at the time we
 * took the snapshot with the given snap_id
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["SnapshotArray","set","snap","set","get"]
 * [[3],[0,5],[],[0,6],[0,0]]
 * Output: [null,null,0,null,5]
 * Explanation:
 * SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
 * snapshotArr.set(0,5);  // Set array[0] = 5
 * snapshotArr.snap();  // Take a snapshot, return snap_id = 0
 * snapshotArr.set(0,6);
 * snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return
 * 5
 *
 *
 * Constraints:
 *
 *
 * 1 <= length <= 50000
 * At most 50000 calls will be made to set, snap, and get.
 * 0 <= index < length
 * 0 <= snap_id < (the total number of times we call snap())
 * 0 <= val <= 10^9
 *
 *
 */

#include <iostream>
using namespace std;

// @lc code=start

#include <utility>
#include <vector>

class SnapshotArray {
  private:
    vector<vector<pair<int, int>>> array;  // {<snapid, val>}
    int snap_id = 0;
    vector<vector<int>> snapshots;

  public:
    SnapshotArray(int length) { array.resize(length, {{0, 0}}); }

    void set(int index, int val) {
        if (array[index].back().first == snap_id)
            array[index].back().second = val;
        else
            array[index].push_back({snap_id, val});
    }

    int snap() { return snap_id++; }

    int get(int index, int snap_id) {
        for (auto l = array[index].begin(), r = array[index].end();;) {
            auto m = l + (r - l) / 2;
            if (m->first <= snap_id && (m + 1 == array[index].end() || (m + 1)->first > snap_id))
                return m->second;
            else {
                if (m->first < snap_id)
                    l = m;
                else
                    r = m;
            }
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

int main(int argc, char const *argv[]) {
    SnapshotArray snapshotArr = SnapshotArray(3);  // set the length to be 3
    snapshotArr.set(0, 5);                         // Set array[0] = 5
    snapshotArr.snap();                            // Take a snapshot, return snap_id = 0
    snapshotArr.set(0, 6);
    snapshotArr.get(0, 0);  // Get the value of array[0] with snap_id = 0, return 5
    return 0;
}
