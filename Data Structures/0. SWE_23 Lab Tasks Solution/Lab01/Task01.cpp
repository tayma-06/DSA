#include <bits/stdc++.h>
using namespace std;

void nsqrSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void nSort(vector<int> &vec)
{
    int n = vec.size();
    if (n == 0)
        return;

    int maxVal = *max_element(vec.begin(), vec.end());

    vector<int> freq(maxVal + 1, 0);

    for (int x : vec)
        freq[x]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (freq[i]--)
        {
            vec[index++] = i;
        }
    }
}

void takeInput(vector<int> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}

void printOutput(const vector<int> &vec)
{
    for (int val : vec)
        cout << val << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    // First test Bubble Sort (O(n^2))
    takeInput(vec, n);
    nsqrSort(vec);
    printOutput(vec);

    // Second test Counting Sort (O(n))
    takeInput(vec, n);
    nSort(vec);
    printOutput(vec);

    return 0;
}
