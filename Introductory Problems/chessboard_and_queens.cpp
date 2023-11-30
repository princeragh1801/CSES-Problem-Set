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

bool isSafe(int row, int col, int n, vector<string> board){
  for(int i = 0; i <= col; i++){
    if(board[row][i] == 'Q'){
      return false;
    }
  }
  for(int i = 1; min(row-i, col-i) >= 0; i++){
    if(board[row-i][col-i] == 'Q'){
      return false;
    }
  }
  for(int i = 1; row+i < n && col-i >= 0; i++){
    if(board[row+i][col-i] == 'Q'){
      return false;
    }
  }
  
  return true;
}
int solve(int col, vector<string> &board){
  if(col == 8){
    // ans.push_back(board);
    return 1;
  }
  int total = 0;
  for(int row = 0; row < 8; row++){
    if(board[row][col] == '.'){
      if(isSafe(row, col, 8, board)){
        board[row][col] = 'Q';
        total += solve(col+1, board);
        board[row][col] = '.';
      }
    }
  }
  return total;
}
 
void _solve(){
  vector<string> str(8);
  string temp;
  for(int i = 0; i < 8; i++){
    cin>>temp;
    str[i] = temp;
  }
  cout<<solve(0, str)<<nl;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif
  int test_case_ = 1;
  cin>>test_case_;
  while(test_case_--){ _solve(); }
  return 0;
}
