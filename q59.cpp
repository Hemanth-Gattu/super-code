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


using namespace std;

void solve(){
    ll k, n, c=0;
    cin>>n>>k;
    vi x;
    rep(i,0,k){
        int a; cin>>a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    ll m=0;
    for(;;){
        if(c>=*x.begin()){
            dbg(m);
            return;
        }
        auto it = x.begin();
        c = c+ (n - *it);
        x.erase(it);
        m++;
        if((n - *x.begin())>(c+ (n - *x.begin()))){
            dbg(m);
            return;
        }
    }

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