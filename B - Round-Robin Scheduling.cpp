#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree to count active tasks
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

struct Task {
    int id;
    long long time;
};

bool compareTasks(const Task& a, const Task& b) {
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id; // Finish in order of index if times are equal
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Task> tasks(N);
    for (int i = 0; i < N; i++) {
        tasks[i].id = i + 1;
        cin >> tasks[i].time;
    }

    vector<Task> sorted_tasks = tasks;
    sort(sorted_tasks.begin(), sorted_tasks.end(), compareTasks);

    FenwickTree ft(N);
    for (int i = 1; i <= N; i++) ft.add(i, 1);

    vector<long long> results(N + 1);
    long long total_time = 0;
    long long prev_time = 0;
    long long active_tasks = N;

    for (int i = 0; i < N; i++) {
        long long current_T = sorted_tasks[i].time;
        int current_idx = sorted_tasks[i].id;

        // 1. Time spent in full rounds since the last task finished
        total_time += (current_T - prev_time - 1) * active_tasks;
        
        // 2. Add the count of active tasks up to the current task's index 
        // in its final round
        results[current_idx] = total_time + ft.query(current_idx);

        // 3. Prepare for the next task:
        // Re-add the remaining full-round time for the tasks that didn't finish yet
        total_time += active_tasks; 
        
        // Remove this task from the active set
        ft.add(current_idx, -1);
        active_tasks--;
        prev_time = current_T;
        
        // Adjust total_time: since the task is removed, the "base" time for the next 
        // calculation should reflect that this task is no longer in the loop.
        total_time -= (active_tasks - ft.query(current_idx) + 1);
    }

    for (int i = 1; i <= N; i++) {
        cout << results[i] << "\n";
    }

    return 0;
}