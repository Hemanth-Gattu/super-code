
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
// // Prime Numbers 

// bool IsPrime(int n)                 //O(sqrt(n))
// {
//     if (n == 2 || n == 3)
//         return true;

//     if (n <= 1 || n % 2 == 0 || n % 3 == 0)
//         return false;

//     for (int i = 5; i * i <= n; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }

//     return true;
// }

// void SieveOfEratosthenes(int n)                           //O(n*log(log(n)))   O(n)
// {
//     // spf[i] stores shortest prime number of i 

//     int spf[n + 1];
//     for(int i=0;i<n+1;i++){
//         spf[i]=i;  // every number has current itself as its spf
//     }
//     for (int p = 2; p * p <= n; p++)
//     {
//         if (spf[p]==p)
//         {   for (int i = p * p; i <= n; i += p){
//                 if (spf[i]>p){
//                     spf[i]=p;
//                 }
//             }
//         }
//     }
//     // Print all prime numbers
//     for (int p = 2; p <= n; p++){
//         if (spf[p]==p){cout << p << " ";}
//     }
// }

// void modifiedSieve(int N){                                 //O(n)  O(n + n/ln(n))
//     int spf[N+1]; vector<int> pr;
//     for(int i=0;i<N+1;i++){
//         spf[i]=i;  // every number has current itself as its spf
//     }
//     for (int i=2; i<=N; i++) {
//         if (spf[i] == i) {
           
//             pr.push_back (i);
//         }
//         for (int j=0; j<(int)pr.size() ; j++){
//             if (i*pr[j]<=N and pr[j] <=spf[i]){
//                 spf[i * pr[j]] = pr[j];
//             }
//         }
//     }   
// }

// vector<int> primeFactorization(int n)              //O(sqrt(n))
// {   vector <int> res;
//     while (n % 2 == 0)
//     {
//         res.push_back(2);
//         n = n/2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             res.push_back(i);
//             n = n/i;
//         }
//     }
 
//     if (n > 2)
//          res.push_back(n);
    
//     if (res.size()==1){cout<<"prime"<<"\n";}
//     return res;
    
// }


// void bfs(int s,int n, int d[],int p[],bool visited[],vector<int> adj[]){
//     queue<int> q;
// 	q.push(s);
// 	visited[s] = true;
//     p[s] = -1;
//     while (!q.empty()) {
//         int v = q.front();
//         q.pop();
//         for (int u : adj[v]) {
//             if (!visited[u]) {
//                 visited[u] = true;
//                 q.push(u);
//                 d[u] = d[v] + 1;
//                 p[u] = v;
//         }
//     }
//     }
    
// }

 
 

 

 

// void dfs(int v, int n, vector<int> adj[],int time_in[],int time_out[],int * dfs_timer,int color[]) {
//     time_in[v] = *dfs_timer;
//       *dfs_timer+=1;
//     color[v] = 1;
//     for (int u : adj[v])
//         if (color[u] == 0)
//             dfs(u,n,adj,time_in,time_out,dfs_timer,color);
//     color[v] = 2;
//     time_out[v] = *dfs_timer;
//       *dfs_timer+=1;
//     
// }


//Disjoint set union (union find)

// void make_set(int v,int parent[],int rank[]) {
//     parent[v] = v;
//     rank[v] = 0;
// }

// int find_set(int v,int parent[]) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v],parent);
// }

// void union_sets(int a, int b,int parent[],int rank[]) {
//     a = find_set(a,parent);
//     b = find_set(b,parent);
//     if (a != b) {
//         if (rank[a] < rank[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank[a] == rank[b])
//             rank[a]++;
//     }
// }

// Sparse Table

 void stoneGame(vector<ll>& piles) {
        ll n=piles.size();
        
        //dp[i][j] stores the maximum sum alice can make from piles[i....j] and it is alice turn
        ll dp[n][n];
        
        //Base Case : i>j dp[i][j]=0 No stones left to pick
        //            i==j : Alice can pick the only element
        //            i==j+1 : Alice the pick the max of two elements
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i>j){
                    dp[i][j]=0;
                }
                else if (i==j){
                    dp[i][j]=piles[i];
                }
                else if (i==j-1){
                    dp[i][j]=max(piles[i],piles[j]);
                }
                else{
                    dp[i][j]=-1e8;
                }
            }
        }
        
        //Dp Transition Idea : Bob picks such element as to minimize the alice total sum While Alice picks such element to maximize her total sum -- Maxmin problem
        
// dp[i][j]=max(min(dp[i+2][j],dp[i+1][j-1])+piles[i],min(dp[i+1][j-1],dp[i][j-2])+piles[j])
        
        for(int k=2;k<n;k++){
            for(int i=0;i<n;i++){
           
                int j=i+k;
                if (j<n){
                    dp[i][j]=max(min(dp[i+2][j],dp[i+1][j-1])+piles[i],min(dp[i+1][j-1],dp[i][j-2])+piles[j]);
                }
                else{
                    break;
                }
            }
        }
        cout<<dp[0][n-1];
 
        
    }
 
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,temp;
    vector<long long> piles;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        piles.push_back(temp);
    }
    stoneGame(piles);
    




    return 0;

}