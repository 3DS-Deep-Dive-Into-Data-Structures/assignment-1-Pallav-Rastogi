#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

long long max_subarray_sum(int n, int a, int b, const vector<int>& x) {
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + x[i - 1];
    }
    deque<int> deq;
    long long max_sum = LLONG_MIN;
    for (int i = a; i <= n; ++i) {
        if (!deq.empty() && deq.front() < i - b) {
            deq.pop_front();
        }
        while (!deq.empty() && prefix_sum[deq.back()] >= prefix_sum[i - a]) {
            deq.pop_back();
        }
        deq.push_back(i - a);
        max_sum = max(max_sum, prefix_sum[i] - prefix_sum[deq.front()]);
    }
    return max_sum;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cout << max_subarray_sum(n, a, b, x) << endl;
    return 0;
}
