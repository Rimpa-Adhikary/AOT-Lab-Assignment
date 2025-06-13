#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;       // Job ID
    int deadline;  // Deadline of job
    int profit;    // Profit if job is completed
};

// Function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];

    // Taking input
    for (int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline and Profit for job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    //  Sort jobs by descending profit
    sort(jobs, jobs + n, compare);

    // Find maximum deadline to define time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Create time slots and fill them
    bool slot[100] = {false};     // Keep track of filled time slots
    char result[100];             // Store job ids in scheduled order

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Try to place job in the latest possible free slot before its deadline
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print results
    cout << "\nScheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}

