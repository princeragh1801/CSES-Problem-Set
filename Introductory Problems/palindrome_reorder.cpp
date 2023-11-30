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
void print(vector<char> v){
    for(auto it : v){
        cout<<it;
    }
}
void _solve(){
    string str;
    cin>>str;
    int n = str.length();
    int arr[26] = {0};
    fo(i,0,n){arr[str[i]-65]++;}
    int c = 0;
    fo(i,0,26){
        if(arr[i]%2!=0){
            c++;
        }
        
    }
    if(c > 1){
        cout<<"NO SOLUTION";
    }
    else{
        vector<char> v1, v2;
        fo(i,0,26){
            if(arr[i]%2 == 0){
                int x = arr[i]/2;
                while(x--){
                    v1.push_back(65+i);
                }
            }
            else{
                int x = arr[i];
                while(x--){
                    v2.push_back(65+i);
                }
            }
        }
        print(v1);
        print(v2);
        reverse(beg(v1));
        print(v1);
 
    }
    cout<<endl;
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
