#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, a, b) for(int i = a; i < b; i++)
#define mod 1000000007
#define beg(x) x.begin(), x.end() 
#define nl '\n'
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
void _print(int a){cerr<<a;}
void _print(float a){cerr<<a;}
void _print(double a){cerr<<a;}
void _print(ll a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(bool a){cerr<<a;}
void _print(string a){cerr<<a;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T it : v){_print(it);cerr<<" ";}cerr<<"]";}
template<class T> void _print(set<T> s){cerr<<"[ ";for(T it : s){_print(it);cerr<<" ";}cerr<<"]";}
template<class T> void _print(unordered_set<T> s){cerr<<"[ ";for(T it:s){_print(it);cerr<<" ";}cerr<<"]";}
ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){ll g = gcd(a,b);return (a*b)/g;}
ll extendedGcd(ll a, ll b, ll x, ll y){if(a == 0){x = 0;y = 1;return b;}int x1, y1;return extendedGcd(b, a%b, x1, y1);}
/*********************** prince1801 ************************/

int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};
void dfs(int row, int col, vector<string> &arr, vector<vector<bool>> &vis){
  vis[row][col] = true;
  for(int dir = 0; dir < 4; dir++){
    int tr = row+dr[dir], tc = col+dc[dir];
    if((tr >= 0 && tr < arr.size() && tc >= 0 && tc < arr[0].size()) && !vis[tr][tc] && arr[tr][tc] == '.'){
      dfs(tr, tc, arr, vis);
    }
  }
}
void _solve(){ 
  int n, m;
  cin>>n>>m;
  vector<int> adj[n+1];
  for(int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> vis(n+1, 0);
  queue<int> q;
  int prev = 0;
  vector<pair<int, int>> arr;
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
        q.push(i);
        vis[i]=1;
        while (!q.empty())
        {
            int city = q.front();
            q.pop();
            for(auto it : adj[city]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        if(prev != 0){
            arr.push_back({prev, i});
        }
        prev = i;
    }
  }
  cout<<arr.size()<<nl;
  for(auto it : arr){
    cout<<it.first<<" "<<it.second<<nl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif
  int test_case_ = 1;
  // cin>>test_case_;
  while(test_case_--){ _solve(); }
  return 0;
}
