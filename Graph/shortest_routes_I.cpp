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

void _solve(){
  ll n, m;
  cin>>n>>m;
  vector<pair<ll, ll>> adj[n+1];
  for(int i = 0; i < m; i++){
    ll a, b, d;
    cin>>a>>b>>d;
    adj[a].push_back({b, d});
  }
  priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 1});
  vector<ll> dis(n+1, 1e18);
  dis[1] = 0;
  while (!pq.empty()){
    auto it = pq.top();
    pq.pop();
    ll dist = it.first;
    ll node = it.second;
    for(auto itr : adj[node]){
        ll nextDis = dist+itr.second;
        ll tempNode = itr.first;
        if(dis[tempNode] > nextDis){
            dis[tempNode] = nextDis;
            pq.push({nextDis, tempNode});
        }
    }
  }
  for(int i = 1; i <= n; i++){
    if(dis[i] == 1e18){
        dis[i] = -1;
    }
    cout<<dis[i]<<" ";
  }cout<<nl;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif
  int test_case_ = 1;
//   cin>>test_case_;
  while(test_case_--){ _solve(); }
  return 0;
}
