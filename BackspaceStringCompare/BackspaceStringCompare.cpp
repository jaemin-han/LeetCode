#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1;
        stack<char> s2;

        for (const char &c : s)
        {
            if (c == '#' && !s1.empty())
                s1.pop();
            else if (c != '#')
                s1.push(c);
        }

        for (const char &c : t)
        {
            if (c == '#' && !s2.empty())
                s2.pop();
            else if (c != '#')
                s2.push(c);
        }

        // s1 s2 모두 차 있는 동안 (비어 있지 않는 동안)
        while (!s1.empty())
        {
            char c1 = s1.top();
            s1.pop();

            if (s2.empty())
                return false;

            char c2 = s2.top();
            s2.pop();

            if (c1 != c2)
                return false;
        }

        // s1 이 남아있는 경우와, s1, s2 둘다 끝까지 쓴 경우
        if (s2.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    // string s = "ab#c";
    // string t = "ad#c";
    // string s = "ab##";
    // string t = "c#d#";
    // string s = "a#c";
    // string t = "b";
    // string s = "a##c";
    // string t = "#a#c";
    // string s = "c##vnvr";  // vnvr
    // string t = "#c##vnvr"; // vnvr
    string s = "aaa###a";  // a
    string t = "aaaa###a"; // aa

    Solution sol;

    cout << boolalpha << sol.backspaceCompare(s, t) << endl;
}