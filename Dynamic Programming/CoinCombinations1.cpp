
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimization ("unroll-loops")
 


#include <bits/stdc++.h>
 
using namespace std;

#ifdef SET
// header files for policy based data structures in g++ 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// ordered_Set - same as set but allows 
               //order_of_key (k) : Number of items strictly smaller than k    O(logn)
               //find_by_order(k) : K-th element in a set (counting from zero).  O(logn)
// change less<int> to less_equal<int> to have a ordered set behaving as multi set but in this case erase operation does not work    
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multi_set;
#endif
               
 



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
    ll sum,n,i,j,k;
    cin>>n>>sum;
    ll c[n];
    fll(i,0,n){
        cin>>c[i];
    }
    vll dp(sum+1,0);
  
    dp[0]=1;
    sort(c,c+n);
    fll(i,1,sum+1){
        fll(j,0,n){
            if(i-c[j]>=0){
                dp[i]=((dp[i]%mod)+(dp[i-c[j]]%mod))%mod;
            }
            else{
                break;
            }
        }
    }
    cout<<dp[sum]<<"\n";




    return 0;

}