#include <bits/stdc++.h>
using namespace std;

class JobScheduler
{
    queue<string> jobs;

public:
    bool isEmpty()
    {
        return jobs.empty();
    }
    void addJob(string jobName)
    {
        jobs.push(jobName);
        cout << "Job added: " << jobName << endl;
    }
    void runJob()
    {
        if (isEmpty())
        {
            cout << "No jobs to run.\n";
            return;
        }
        cout << "Running job: " << jobs.front() << endl;
        jobs.pop();
    }
    void upcomingJobs()
    {
        if (isEmpty())
        {
            cout << "No pending jobs.\n";
            return;
        }
        queue<string> temp = jobs;
        cout << "Pending Jobs: ";
        while (!temp.empty())
        {
            cout << temp.front() << " -> ";
            temp.pop();
        }
        cout << "NULL\n";
    }
    int countJobs()
    {
        return jobs.size();
    }
};

int main()
{
    JobScheduler js;
    js.addJob("Compile Code");
    js.addJob("Run Tests");
    js.addJob("Deploy Build");
    js.upcomingJobs();
    js.runJob();
    js.runJob();
    js.upcomingJobs();
    cout << "Jobs remaining: " << js.countJobs() << endl;
    return 0;
}
