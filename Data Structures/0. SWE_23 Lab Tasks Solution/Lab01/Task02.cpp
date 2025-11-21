#include <bits/stdc++.h>
using namespace std;

vector<int> nsqrFindPairSum(vector<int> &vec, int target)
{
    vector<int> res;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == target)
            {
                res.push_back(vec[i]);
                res.push_back(vec[j]);
                return res;
            }
        }
    }
    return res;
}

vector<int> nFindPairSum(vector<int> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    vector<int> res;

    while (left < right)
    {
        int sum = vec[left] + vec[right];

        if (sum == target)
        {
            res.push_back(vec[left]);
            res.push_back(vec[right]);
            return res;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }

    return res;
}

void takeInput(vector<int> &vec, int n)
{
    for (int i = 0; i < n; i++)
        cin >> vec[i];
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    takeInput(vec, n);

    int target;
    cin >> target;

    // Call O(n^2) function
    vector<int> ans = nsqrFindPairSum(vec, target);

    // If not found by n^2, try O(n log n + n)
    if (ans.empty())
    {
        sort(vec.begin(), vec.end());
        ans = nFindPairSum(vec, target);
    }

    if (ans.empty())
        cout << "No pair found" << endl;
    else
        for (int val : ans)
            cout << val << endl;

    return 0;
}
