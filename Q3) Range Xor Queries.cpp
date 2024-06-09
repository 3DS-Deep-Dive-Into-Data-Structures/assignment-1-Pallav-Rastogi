#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void buildTree(int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            buildTree(2 * idx + 1, left, mid);
            buildTree(2 * idx + 2, mid + 1, right);
            tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2];
        }
    }

    int query(int idx, int left, int right, int qLeft, int qRight) {
        if (qLeft > right || qRight < left) {
            return 0;
        } else if (qLeft <= left && qRight >= right) {
            return tree[idx];
        } else {
            int mid = (left + right) / 2;
            int leftXor = query(2 * idx + 1, left, mid, qLeft, qRight);
            int rightXor = query(2 * idx + 2, mid + 1, right, qLeft, qRight);
            return leftXor ^ rightXor;
        }
    }

public:
    SegmentTree(vector<int>& input) {
        n = input.size();
        tree.assign(4 * n, 0);
        arr = input;
        buildTree(0, 0, n - 1);
    }

    int getXorSum(int qLeft, int qRight) {
        return query(0, 0, n - 1, qLeft - 1, qRight - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for_each(arr.begin(), arr.end(), [](int &a) { cin >> a; });

    SegmentTree segmentTree(arr);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int result = segmentTree.getXorSum(a, b);
        cout << result << "\n";
    }

    return 0;
}
