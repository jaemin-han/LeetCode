#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> char_density_map;

        for (char c : s)
            char_density_map[c]++;

        auto compare = [](const pair<char, int> &a, const pair<char, int> &b) -> bool
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);

        for (const auto &pair : char_density_map)
        {
            pq.push(pair);
        }

        string answer;
        while (!pq.empty())
        {
            auto pair = pq.top();
            pq.pop();
            answer += string(pair.second, pair.first);
        }

        return answer;
    }
};

int main()
{
    // string s("tree");
    // string s("cccaaa");
    string s("Aabb");

    Solution sol;

    cout << sol.frequencySort(s) << endl;

    return 0;
}