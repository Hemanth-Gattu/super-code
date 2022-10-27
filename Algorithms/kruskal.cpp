#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
typedef long long ll;

vector < int > root(100);

int find_root(int a){
    while( a != root[a] ){
        a = root[a];
    }
    return a;
}

void union_find(int a, int b){
    int x = find_root(a);
    int y = find_root(b);
    if( x != y )root[b] = root[y];
}

int kruskal(int e, vector < pair < int , pair < int , int > > >& v){
    int x, y, cost, min_cost = 0;
    for( int i = 0; i < e; i++){
        x = v[i].second.first;
        y = v[i].second.second;
        cost = v[i].first;
        //cout << cost << " ";
        if( find_root(x) != find_root(y) ){
            min_cost += cost;
            union_find(x, y);
        }
    }
    return min_cost;
}
bool comp( pair < int , pair < int , int > >&a,  pair < int , pair < int , int > >&b){
    return a.first < b.first ;
}

void swap( int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
    void rotate_sub( vector < int > & nums, int start, int end){
        for ( int i = start; i<=(start+end)/2; i++){
            swap(nums[i], nums[end]);
            end--;
            
        }
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 100; i++ )root[i] = i;
    int n,e;
    cin >> n >> e;
    vector < pair < int , pair < int , int > > > v;
    int a, b, c;
    for( int i = 0; i < e; i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(), v.end(), comp);

    int answer = kruskal(e, v);
    cout << answer;
    return 0;
}












