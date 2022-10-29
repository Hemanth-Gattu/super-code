
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimization ("unroll-loops")
 


#include <bits/stdc++.h>
 
using namespace std;

 
               
 



#define mod 1000000007
#define ll long long
 
#define pb push_back 
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define all(a)              a.begin(),a.end()
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define rsrtl(v) sort(v.begin(), v.end(), greater<ll>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
#define rfi(i, a, b) for (int i = int(a); i >= int(b); i--)
#define mxe(v) *max_element(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define mp make_pair
#define sz(x) (int)x.size()
#define sp " "
#define nl '\n'


 

// segement tree

 

vector<int> a;
vector<long long> t;
struct ST {
   
  static const int inf = 1e9;
  ST(int n) {
     a.resize(n+10);
     t.resize(4*(n+10));
  }
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int mid = (tl + tr)/2;
     
    build(2*v, tl, mid);
    build(2*v+1, mid + 1, tr);
     t[v] = (t[2*v]^t[2*v+1]);
  }
  void upd(int v, int tl, int tr, int pos, int new_val) {
    if (tl > pos || tr < pos) return;
    if (tl == tr && tl == pos) {
      t[v] = new_val;
      return;
    }
    int mid = (tl + tr)/2 ;
    upd(2*v, tl, mid, pos, new_val);
    upd(2*v+1, mid + 1, tr, pos, new_val);
    t[v] = (t[2*v]^t[2*v+1]);
  }
  long long query(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return 0ll;
    if (tl >= l && tr <= r) return t[v];
    int mid = (tl + tr)/2; 
    long long L = query(2*v, tl, mid, l, r);
    long long  R = query(2*v+1, mid + 1, tr, l, r);
    long long ans=(L^R);
    return ans;
  }
};



 
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    int n,q,i,j,k,l,r;
    cin>>n>>q;
    
    struct ST st(n);
    fi(i,0,n){
        cin>>a[i];
    }
    
    st.build(1,0,n-1);
    while(q--){
        cin>>l>>r;
        cout<<st.query(1,0,n-1,l-1,r-1)<<"\n";
        

    }



    return 0;

}