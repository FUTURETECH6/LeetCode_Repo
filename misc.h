#include <iostream>
#include <vector>

namespace misc {
    template <typename T>
    void printVec(std::vector<T> vec) {
        using namespace std;
        for (auto &i : vec)
            cout << i << " ";
        cout << endl;
    }
    template <typename T>
    void printVec2D(std::vector<std::vector<T>> vec) {
        using namespace std;
        for (auto &i : vec) {
            for (auto &j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
};  // namespace misc