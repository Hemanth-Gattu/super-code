
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
    ll n,m,i,j,k;
    cin>>n>>m;
    ll a[n];
    fll(i,0,n){
        cin>>a[i];
    }
    
    ll dp[n][m+1];
    mem0(dp);
    if(a[0]==0){
         fll(i,1,m+1){
             dp[0][i]=1;
         }
    }
    else{
        dp[0][a[0]]=1;
    }

    fll(i,1,n){
        if(a[i]==0){
            fll(j,1,m+1){
                dp[i][j]=dp[i-1][j];
                if(j-1>=1){
                    dp[i][j]=((dp[i][j]%mod)+(dp[i-1][j-1]%mod))%mod;
                
                }
                if(j+1<=m){
                    dp[i][j]=((dp[i][j]%mod)+(dp[i-1][j+1]%mod))%mod;
                }
            }
        }
        else{
           
                dp[i][a[i]]=dp[i-1][a[i]];
                if(a[i]-1>=1){
                    dp[i][a[i]]=((dp[i][a[i]]%mod)+(dp[i-1][a[i]-1]%mod))%mod;;
                     
                
                }
                if(a[i]+1<=m){
                    dp[i][a[i]]=((dp[i][a[i]]%mod)+(dp[i-1][a[i]+1]%mod))%mod;
                    
                } 
        }
    }
    
    // fll(i,0,n){
    //     fll(j,0,m+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll ans=0;
    
    fll(i,1,m+1){
        ans=((ans%mod)+(dp[n-1][i]%mod))%mod;
    
    }
    cout<<ans<<"\n";
    
    


     
    
    




    return 0;

}