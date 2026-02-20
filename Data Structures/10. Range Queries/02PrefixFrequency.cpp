#include <bits/stdc++.h>
using namespace std;

struct PrefixFrequency
{
    vector<vector<int>> freq;
    PrefixFrequency(const string &s)
    {
        int n = s.size();
        freq.resize(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                freq[i + 1][j] = freq[i][j];
            }
            freq[i + 1][s[i] - 'a']++;
        }
    }
    char query(int l, int r)
    {
        vector<int> count(26, 0);
        for (int i = 0; i < 26; i++)
        {
            count[i] = freq[r + 1][i] - freq[l][i];
        }
        int max_freq = 0;
        int max_char = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > max_freq)
            {
                max_freq = count[i];
                max_char = i;
            }
        }

        return 'a' + max_char;
    }
};

int main()
{
    string s;
    cin >> s;
    PrefixFrequency pf(s);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << pf.query(l, r) << endl;
    }

    return 0;
}