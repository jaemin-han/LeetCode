#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < t.size(); i++)
            map[t[i]].push_back(i);

        for (const auto &pair : map)
        {
            cout << pair.first << ": ";
            for (const auto &i : pair.second)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        int recent = 0;
        for (const auto &c : s)
        {
            auto iter = lower_bound(map[c].begin(), map[c].end(), recent);
            if (iter == map[c].end())
                return false;
            recent = *iter + 1;
            cout << "recent: " << recent << endl;
        }
        return true;
    }
};

int main()
{
    // string s = "abc";
    // string t = "ahbgdc";
    // string s = "axc";
    // string t = "ahbgdc";
    string s = "aaaaaa";
    string t = "bbaaaa";

    Solution sol;

    cout << boolalpha << sol.isSubsequence(s, t) << endl;
}