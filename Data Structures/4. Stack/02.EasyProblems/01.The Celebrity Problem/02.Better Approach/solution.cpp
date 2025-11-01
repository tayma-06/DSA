#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i); // storing all indices to store the persons
        }
        while (st.size() > 1) // as long as one person remaining
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            // Here what we did is selected person one and two to know if they know each other
            // If yes then non of them are celebrity
            // If no then one of them are potential celebrity
            if (mat[a][b]) // sees is a knows b
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        // potential celebrity
        int c = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i == c)
                continue;
            if (!mat[i][c] || mat[c][i])
            {
                return -1;
            }
        }
        return c;
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