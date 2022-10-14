#include<bits/stdc++.h>
using namespace std;

// Creating Segement Tree
int build(int index, int left, int right, vector<int> &seg, vector<int> &nums) {

    if (left == right) {
        seg[index] = nums[left];
        return nums[left];
    }

    int mid = (left + right) / 2;

    int l = build(2 * index + 1, left, mid, seg, nums);
    int r = build(2 * index + 2, mid + 1, right, seg, nums);

    return seg[index] = min(l, r);

}

int query(int index, int left, int right, int l, int r, vector<int> &seg) {

    //non-overlapping query
    if (right < l or left > r) return INT_MAX;
    // completely overlapping query
    if (left >= l and right <= r) return seg[index];
    // partially overlapping query

    int mid = (left + right) / 2;
    int x = query(2 * index + 1, left, mid, l, r, seg);
    int y = query(2 * index + 2, mid + 1, right, l, r, seg);

    return min(x, y);

}

void update(int index, int left, int right, int i, int val, vector<int> &seg) {

    if (left == right) {
        seg[index] = val;
        return;
    }

    int mid = (left + right) >> 1;

    if (i <= mid) update(2 * index + 1, left, mid, i, val, seg);
    else update(2 * index + 2, mid + 1, right, i, val, seg);

    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);

}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> seg(4 * n, -1);

    build(0, 0, nums.size() - 1, seg, nums);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // query
            int l, r;
            cin >> l >> r;
            cout << "Min is : " << query(0, 0, nums.size() - 1, l, r, seg) << endl;
        } else {
            int i, val;
            cin >> i >> val;
            update(0, 0, nums.size() - 1, i, val, seg);
        }
    }

}

int main() {

#ifndef ONLINE_JUDGE
    // //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // //for writing output in output.txt
    freopen("output.txt", "w", stdout);
#endif



    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}

/*



*/ 
