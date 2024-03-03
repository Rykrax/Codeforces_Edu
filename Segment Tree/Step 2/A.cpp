#include <bits/stdc++.h>
#define For(dl,i,a,b) for (dl i=a; i<=b; i++)
#define Fore(dl,i,a,b) for (dl i=a; i>=b; i--)
#define prec(n) fixed<<setprecision(n)
#define bit(mask,i) ((mask>>i)&1)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int inf = 1e9+7;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};

const int kmax = 1e5+5;
struct node {
    ll res, pre, suf, sum;
};
int n, m, a[kmax];

struct Segment {
    node tree[kmax*4];

    node merges(node a, node b) {
        node ans;
        ans.res = max({a.res, b.res, a.suf + b.pre});
        ans.pre = max({a.pre, a.sum + b.pre});
        ans.suf = max({b.suf, b.sum + a.suf});
        ans.sum = a.sum + b.sum;
        return ans;
    }

    void build(int id, int l, int r) {
        if (l==r) {
            tree[id] = {max(a[r],0), max(a[r],0), max(a[r],0), a[r]};
            return;
        }
        int mid = l+r>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id] = merges(tree[id*2], tree[id*2+1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || r < pos) return;
        if (l==r) {
            tree[id] = {max(val,0), max(val,0), max(val,0), val};
            return;
        }
        int mid = l+r>>1;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        tree[id] = merges(tree[id*2],  tree[id*2+1]);
    }

    node get() {}
} segment;


void solve() {
    cin>> n >> m;
    For(int,i,1,n) cin >> a[i];
    segment.build(1,1,n);
//    segment.update(1,1,n,5,3);
//    For(int,i,1,n*4) cout << segment.tree[i].res << " " << segment.tree[i].pre << " " << segment.tree[i].suf << " " << segment.tree[i].sum << endl;
    cout << segment.tree[1].res << endl;
    for(;m--;) {
       int pos, val; cin >> pos >> val;
       segment.update(1,1,n,pos+1,val);
       cout << segment.tree[1].res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return (0^0);
}
