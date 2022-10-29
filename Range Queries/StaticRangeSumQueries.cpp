
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


 


 
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    ll n,q,i,j,k,l,r;
    cin>>n>>q;
    
    ll a[n];
    fll(i,0,n){
        cin>>a[i];
    }
    ll p[n+1];
    p[0]=0;
    ll psum=0;
    fll(i,1,n+1){
        psum+=a[i-1];
        p[i]=psum;
    }
    while(q--){
        cin>>l>>r;
        l--;
        cout<<p[r] - p[l]<<"\n";

    }
    




    return 0;

}