// Segment Tree Questions

// Question 1 D - Xenia and Bit Operations

/*

#include<bits/stdc++.h>
using namespace std;

void build(int index, int left, int right, vector<int> &seg, vector<int> &nums, int flag) {
    if (left == right) {
        seg[index] = nums[left];
        return;
    }

    int mid = left + (right - left) / 2;

    build(2 * index + 1, left, mid, seg, nums, !flag);
    build(2 * index + 2, mid + 1, right, seg, nums, !flag);

    if (flag) seg[index] = seg[2 * index + 1] | seg[2 * index + 2]; // OR
    else seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2]; // XOR
}

void update(int index, int left, int right, int i, int val, int flag, vector<int> &seg) {
    if (left == right) {
        seg[index] = val;
        return;
    }

    int mid = left + (right - left) / 2;

    if (i <= mid) update(2 * index + 1, left, mid, i, val, !flag, seg);
    else update(2 * index + 2, mid + 1, right, i, val, !flag, seg);

    if (flag) seg[index] = seg[2 * index + 1] | seg[2 * index + 2]; // OR
    else seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2]; // XOR

}


void solve() {

    int n, m;
    cin >> n >> m;
    int el = pow(2, n);
    vector<int> nums(el, -1);
    for (int i = 0; i < el; i++) cin >> nums[i];

    vector<int> seg(4 * el + 1, -1);

    if (n % 2 == 0) build(0, 0, el - 1, seg, nums, 0);
    else build(0, 0, el - 1, seg, nums, 1);

    while (m--) {
        int i, val;
        cin >> i >> val;
        i--;
        if (n % 2 == 0) update(0, 0, el - 1, i, val, false, seg);
        else update(0, 0, el - 1, i, val, true, seg);
        cout << seg[0] << endl;
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

*/

// ***************************************************************

//Question 2

// C. Sereja and Brackets

// In this problem there comes a concept of nodes in segment Tree
// Storing multiple details in a single segment tree

/*
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Node {
public:
  ll open;
  ll close;
  ll complete;

  Node(int _open = 0,int _close = 0,int _complete = 0) {
    open = _open;
    close = _close;
    complete = _complete;
  }
};

Node merge(Node left,Node right) {
  Node tmp = Node(0,0,0);
  tmp.open = left.open + right.open - min(left.open,right.close);
  tmp.close = left.close + right.close - min(left.open,right.close);
  tmp.complete = left.complete + right.complete + min(left.open,right.close);

  return tmp;
}

//building segment Tree
void build(ll index,ll left,ll right,vector<Node> &seg,string &s) {
  //base case
  if(left == right) {
    seg[index] = Node(s[left] == '(',s[left] == ')',0);
    return;
  }

  ll mid = left + (right - left)/2;
  build(2*index+1,left,mid,seg,s);
  build(2*index+2,mid+1,right,seg,s);



  seg[index] = merge(seg[2*index+1],seg[2*index+2]);

}

Node query(ll index,ll left,ll right,ll l,ll r,vector<Node> &seg) {
  if(r < left || l > right) {
    return Node(0,0,0);
  }
  if(l <= left && r >= right) return seg[index];

  ll mid = left + (right-left)/2;
  Node x = query(2*index+1,left,mid,l,r,seg);
  Node y = query(2*index+2,mid+1,right,l,r,seg);

  return merge(x,y);
}

void solve() {
  string s;
  cin>>s;

  vector<Node> seg(4*s.length()+1);

  build(0,0,s.length()-1,seg,s);

  ll m;
  cin>>m;
  while(m--) {
    int l,r;
    cin>>l>>r;
    l = l-1;
    r = r-1;
    Node tmp = query(0,0,s.length()-1,l,r,seg);
    cout<<2*tmp.complete<<endl;
  }

}

int main() {
  solve();
  return 0;
}
*/

/****************************************************************/

// Lazy Propogation in SGTree

//Range Sum Query

/*

#include<bits/stdc++.h>
using namespace std;

class SGTree {
    vector<int> seg, lazy;
public:
    SGTree(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void build(int index, int left, int right, vector<int> &nums) {
        if (left == right) {
            seg[index] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * index + 1, left, mid, nums);
        build(2 * index + 2, mid + 1, right, nums);

        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    // lazy propogation code
    void update(int index, int left, int right, int l, int r, int val) {
        //first step update prev val is there is any
        if (lazy[index] != 0) {
            // number of nodes responsible
            seg[index] += (right - left + 1) * lazy[index];
            // propogate down
            if (left != right) { // if left != right then there will be a children in SGTree
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            lazy[index] = 0;
        }

        //three options
        //no overlap
        if (r < left or l > right) return;

        //complete overlap
        if (left >= l and right <= r) {
            seg[index] += (right - left + 1) * val;
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            return;
        }

        int mid = left + (right - left) / 2;
        update(2 * index + 1, left, mid, l, r, val);
        update(2 * index + 2, mid + 1, right, l, r, val);

        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];


    }

    int query(int index, int left, int right, int l, int r) {

        // if any update remaining just do it
        if (lazy[index] != 0) {
            seg[index] += (right - left + 1) * lazy[index];
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            lazy[index] = 0;
        }


        if (r < left or l > right) return 0;

        if (left >= l and right <= r) return seg[index];

        int mid = left + (right - left) / 2;
        int x = query(2 * index + 1, left, mid, l, r);
        int y = query(2 * index + 2, mid + 1, right, l, r);

        return x + y;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SGTree sg(n);
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << endl;
        } else if (type == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            sg.update(0, 0, n - 1, l, r, val);
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


    solve();
    return 0;
}

*/

/*******************************************************/

//Lazy Propogation
// Range Min Query

/*
#include<bits/stdc++.h>
using namespace std;

// Range Query Min
class SGTree {
    vector<int> seg, lazy;
public:
    SGTree(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void build(int index, int left, int right, vector<int> &nums) {
        if (left == right) {
            seg[index] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * index + 1, left, mid, nums);
        build(2 * index + 2, mid + 1, right, nums);

        seg[index] = min(seg[2 * index + 1] , seg[2 * index + 2]);
    }

    // lazy propogation code
    void update(int index, int left, int right, int l, int r, int val) {
        //first step update prev val is there is any
        if (lazy[index] != 0) {
            // number of nodes responsible
            seg[index] += lazy[index];
            // propogate down
            if (left != right) { // if left != right then there will be a children in SGTree
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            lazy[index] = 0;
        }

        //three options
        //no overlap
        if (r < left or l > right) return;

        //complete overlap
        if (left >= l and right <= r) {
            seg[index] += (right - left + 1) * val;
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            return;
        }

        int mid = left + (right - left) / 2;
        update(2 * index + 1, left, mid, l, r, val);
        update(2 * index + 2, mid + 1, right, l, r, val);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);


    }

    int query(int index, int left, int right, int l, int r) {

        // if any update remaining just do it
        if (lazy[index] != 0) {
            seg[index] += lazy[index];
            if (left != right) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            lazy[index] = 0;
        }


        if (r < left or l > right) return 0;

        if (left >= l and right <= r) return seg[index];

        int mid = left + (right - left) / 2;
        int x = query(2 * index + 1, left, mid, l, r);
        int y = query(2 * index + 2, mid + 1, right, l, r);

        return min(x, y);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SGTree sg(n);
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << endl;
        } else if (type == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            sg.update(0, 0, n - 1, l, r, val);
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


    solve();
    return 0;
}


*/
