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

const int kmax = 1e6+5;
int a[kmax];
struct Segment {
    ll tree[kmax*4];

    void build(int id, int l, int r) {
        if (l==r) {
            tree[id] = a[r];
            return;
        }
        int mid = l+r>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id] = min(tree[id*2], tree[id*2+1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || r < pos) return;
        if (l==r) {
            tree[id] = val;
            return;
        }
        int mid = l+r>>1;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        tree[id] = min(tree[id*2], tree[id*2+1]);
    }

    ll get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return inf;
        if (u <= l && r <= v) return tree[id];
        int mid = l+r>>1;
        return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
    }
} segment;

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    segment.build(1,1,n);
    while(m--) {
        int type; cin >> type;
        if (type==1) {
            int pos, val; cin >> pos >> val;
            segment.update(1,1,n,pos+1,val);
        }
        else {
            int u, v; cin >> u >> v;
            cout << segment.get(1,1,n,u+1,v) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return (0^0);
}
