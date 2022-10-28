#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;

#define sqr(a) a*a
#define big2(a, b) (a>b)?a:b
#define sml2(a, b) (a>b)?b:a
#define big3(a, b, c) (((a>b)?a:b)>c)?((a>b)?a:b):c
#define sml3(a, b, c) (((a>b)?b:a)>c)?c:((a>b)?b:a)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define repv(it, v) for(auto it = v.begin(); it!=v.end(); it++)
#define dbg(a) cout<<a<<"\n";
#define negi -123456789
#define posi 123456789

using namespace std;

void solve(){
    int n;
    cin>>n;
    vll v;
    rep(i,0,n){
        ll a; cin>>a;
        v.push_back(a);
    }
    ll ai = *min_element(v.begin(), v.end());
    ll ans = 0;
    repv(it,v){
        if(1){
            cout<<"ashdahsd\n";
            cout<<ans<<*it<<__gcd(*it-ai,ans);
        }
        ans =  __gcd(*it-ai,ans);
    }
    if(ans==0){
        dbg(-1);
        return;
    }
    dbg(ans);

}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   int t;
   cin>>t;
   while(t--){
       solve();
   }
   return 0;
}