// This task is incomplete

#include <bits/stdc++.h>
using namespace std;

bool canSit(vector<vector<int>> &mark, int i, int j)
{
    return mark[i][j];
}

int main()
{
    cout << "Task 03" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        queue<int> person, seat;
        for (int i = 0; i < n; i++)
        {
            person.push(i);
        }
        for (int i = 0; i < m; i++)
        {
            seat.push(i);
        }
        int changes = 0, count = 0;
        vector<vector<int>> mark(n, vector<int>(m, 1));
        while (changes != n * m)
        {
            int i = person.front();
            int s = seat.front();
            if (canSit(mark, i, s))
            {
                mark[i][s] = true;
                changes++;
                person.pop();
                seat.pop();
            }
            else
            {
                person.pop();
                person.push(i);
            }
            count++;
        }
        cout << count << endl;
        // for (int i = 0; i < n; i++)
        //  {
        //      if (canSit(mark, i, 0))
        //      {
        //          mark[person.front()][seat.front()]=0;
        //          person.push(person.front());
        //          person.pop();
        //          seat.push(seat.front());
        //          seat.pop();
        //          changes++;

        //     }
        //     else
        //     {
        //         person.push(person.front());
        //         person.pop();
        //     }
        // }
    }
    return 0;
}