
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

 

//Segement Tree Lazy Propogation
 
 vector<int> a;
vector<long long> t;
vector<long long> lazy;
struct ST {
  #define lc (v << 1)
  #define rc ((v << 1) | 1)
  
  ST(int n) {
    t.resize(4*(n+10));
    lazy.resize(4*(n+10));
    a.resize(n+10);
    
  }
  
  inline void push(int v, int l, int r) {
      
    if (lazy[v] == 0) {return;}
    
    //incase of t[v] stores sum of elements in range [tl , tr] 
    t[v] = t[v] + lazy[v] * (r - l + 1);
    

    // if given node is a leaf then we cannot update lc and rc

    if (l != r) {
      lazy[lc] += lazy[v];
      lazy[rc] += lazy[v];
    }
    
     
    lazy[v] = 0;
  }
  
  inline long long combine(long long a,long long b) {
    return a + b;
  }
  
  inline void pull(int v) {
    t[v] = t[lc] + t[rc];
  }
  
  void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int mid = (tl + tr)/2;
    build(lc, tl, mid);
    build(rc, mid + 1, tr);
    pull(v);
  }
  void upd(int v, int tl, int tr, int l, int r, long long addend) {
    push(v, tl, tr);
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
      lazy[v] = addend;  
      push(v, tl, tr);
      return;
    }
    int mid = (tl + tr)/2 ;
    upd(lc, tl, mid, l, r, addend);
    upd(rc, mid + 1, tr, l, r, addend);
    pull(v);
  }
  
  long long query(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > tr || tl > r) return 0; //return null
    if (l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    return combine(query(lc, tl, mid, l, r), query(rc, mid + 1, r, tl, tr));
  }

  long long query2(int v , int tl ,int tr ,int pos ){
    push(v,tl,tr);
    if (tl==tr){ return t[v] ;}
     
    int mid = (tl + tr)/2 ;
    if (pos<=mid){
        return query2(lc,tl,mid,pos);
    }
    else{
        return query2(rc,mid+1,tr,pos);
    }
  }
  
};

 
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    int n,q,i,j,k,l,r,x,pos;
    
    cin>>n>>q;
    
    struct ST st(n+1);
    fi(i,1,n+1){
        cin>>a[i];
    }
    st.build(1,1,n);
     
    while(q--){
        
        int type;
        cin>>type;
        if (type==1){
            cin>>l>>r>>x;
            
            
            st.upd(1,1,n,l,r,x);
             
        }
        else if (type==2){
            cin>>pos;
            
             
            cout<<st.query2(1,1,n,pos)<<"\n";
            
             
        }
        
        
    }
    




    return 0;
    // you should actually read the stuff at the bottom

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/