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
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2){
        no;
    }
    else{
        yes;
        ll target = sum/2;
        
        int i = n;
        vector<ll> arr;
        set<ll> st;
        while(i > 0 && target > 0){
            if(target <= i){
                arr.push_back(target);
                st.insert(target);
                target = 0;
                
                
                break;
            }
            else{
                arr.push_back(i);
                target -= i;
                
                st.insert(i);
            }
            
            i--;
        }
        i = 1;
        
        vector<ll> arr2;
        int t = 0;
        while(i <= n && t < (sum/2)){
            if(st.find(i) == st.end()){
                t += i;
                arr2.push_back(i);
            }
            i++;
        }
        ll x = arr.size();
        ll y = arr2.size();
        cout<<x<<endl;
        for(auto it : arr){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<y<<endl;
        for(auto it : arr2){
            cout<<it<<" ";
        }
        cout<<endl;
        
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
  cin>>test_case_;
  while(test_case_--){ _solve(); }
  return 0;
}
