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

        vector<int> indegree(n, 0);  // how many people know person i
        vector<int> outdegree(n, 0); // how many people person i knows

        for (int i = 0; i < n; i++) // i is current person
        {
            for (int j = 0; j < n; j++) // j is other people
            {
                int x = mat[i][j]; // x=1 i knows j & x=0 i doesn't know j
                outdegree[i] += x; // add if i knows the person
                indegree[j] += x;  // add if j knows i
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == n && outdegree[i] == 1) // if i knows only ownself and everyone else knows i
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