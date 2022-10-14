#include<bits/stdc++.h>
using namespace std;

class SGTree {
public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1, -1);
    }

    // Creating Segement Tree
    int build(int index, int left, int right, vector<int> &nums) {

        if (left == right) {
            seg[index] = nums[left];
            return nums[left];
        }

        int mid = (left + right) / 2;

        int l = build(2 * index + 1, left, mid,  nums);
        int r = build(2 * index + 2, mid + 1, right,  nums);

        return seg[index] = min(l, r);

    }

    int query(int index, int left, int right, int l, int r) {

        //non-overlapping query
        if (right < l or left > r) return INT_MAX;
        // completely overlapping query
        if (left >= l and right <= r) return seg[index];
        // partially overlapping query

        int mid = (left + right) / 2;
        int x = query(2 * index + 1, left, mid, l, r);
        int y = query(2 * index + 2, mid + 1, right, l, r);

        return min(x, y);

    }

    void update(int index, int left, int right, int i, int val) {

        if (left == right) {
            seg[index] = val;
            return;
        }

        int mid = (left + right) >> 1;

        if (i <= mid) update(2 * index + 1, left, mid, i, val);
        else update(2 * index + 2, mid + 1, right, i, val);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);

    }

};

void solve() {

    int n1, n2;
    //creating first array
    cin >> n1;
    vector<int> nums1(n1, -1);
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    //creating first SGTree
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, nums1);

    //creating second array
    cin >> n2;
    vector<int> nums2(n2, -1);
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    //creating second SGTree
    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, nums2);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // query
            int l1, l2, r1, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            cout << min(sg1.query(0, 0, n1 - 1, l1, r1), sg2.query(0, 0, n2 - 1, l2, r2)) << endl;
        } else { // update
            int i1, i2, val1, val2;
            cin >> i1 >> val1 >> i2 >> val2;
            sg1.update(0, 0, n1 - 1, i1, val1);
            sg2.update(0, 0, n2 - 1, i2, val2);
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
