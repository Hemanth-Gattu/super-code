#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <tuple>


using namespace std;
typedef long long ll;



int find_min_vertex( vector < int > &  dist, vector < bool > & vis, int n){
    int min_vertex = -1;
    for( int i = 0; i < n; i++){
        if( !vis[i] && (min_vertex == -1 || dist[i] < dist[min_vertex]))min_vertex = 1;
    }
    
    return min_vertex;
}

vector <int > root(10001);
int find_root(int v1){
    while( v1 != root[v1] ){
        v1 = root[v1];
    }
    return v1;
}

void union_find(int v1, int v2){
    int x = find_root(v1);
    int y = find_root(v2);
    if( x != y )root[v2] = root[y];
}

int kruskal(int e, vector < pair < int , pair < int , int > > >& m7){
    int x, y, cost, min_cost = 0;
    for( int i = 0; i < e; i++){
        x = m7[i].second.first;
        y = m7[i].second.second;
        cost = m7[i].first;
      
        if( find_root(x) != find_root(y) ){
            min_cost += cost;
            union_find(x, y);
        }
    }
    return min_cost;
}
bool comp( pair < int , pair < int , int > >&v1,  pair < int , pair < int , int > >&v2){
    return v1.first < v2.first ;
}

void swap( int& v1, int& v2){
        int temp = v2;
        v2 = v1;
        v1 = temp;
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
    int n;
    cin  >> n;
    vector < int > v(n);
    for( auto &x : v){
        cin >> x;

    }
    int i = 0, counter = 0;
    while(i < n-1 ){
        i += v[i];
        
        counter++;
    }

    cout << counter;
    return 0;
}