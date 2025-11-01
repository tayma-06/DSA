#include <iostream>
#include <vector>

using namespace std;

// This approach uses the indegree and outdegree theory of a graph and implements that

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        vector<int> indegree(n, 0), outdegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x = mat[i][j];
                outdegree[i] += x;
                indegree[j] += x;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == n && outdegree[i] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}};
    cout << sol.celebrity(mat);
    return 0;
}