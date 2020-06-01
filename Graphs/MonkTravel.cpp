/* Akshat Mathur
	IIIT Allabahad */

// #include<fuck_you.h>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++) //for loop
#define si(x) scanf("%d",&x) // scan int
#define sll(x) scanf("%lld",&x) // scan ll
#define ss(x) scanf("%s",x) // scan string
#define pi(x) printf("%d\n",x) // print int
#define pll(x) printf("%lld\n",x) // print ll
#define ps(x) printf("%s\n",ch) // print string
#define INF 2000000000 // infinity
#define ll long long
#define mp make_pair
#define pb push_back
#define fr first
#define se second
typedef pair< long long, long long > PLL;
typedef pair< int, int > PII;
#define XXX 100069
#define XXXX 10000069
vector<int> g[100069];
int vis[100069];
vector<int> nodes;
map<pair<int,int>,int> cnt;
void dfs(int u){
    if(vis[u])
        return;
    vis[u]=1;
    nodes.pb(u);
    FOR(i,0,g[u].size()){
        dfs(g[u][i]);
    }
}
int n,m;
int main()
{
    si(n); si(m);

    FOR(i,0,m){
        int x,y;
        si(x); si(y);
        //x--; y--;
        g[x].pb(y);
        if(x!=y)
            g[y].pb(x);
    }
    int ans=-1;
    FOR(i,1,n+1){
      //  cout<<i<<endl;
        if(!vis[i]){
            nodes.clear();
            dfs(i);
            //cout<<"size="<<nodes.size()<<endl;
            cnt.clear();
            FOR(j,0,nodes.size()){
                int u = nodes[j];
                //cout<<"node="<<u<<endl;
                FOR(k,0,g[u].size()){
                  //  cout<<"nb="<<g[u][k]<<" ";
                    if(cnt[mp(g[u][k],u)]==0 || g[u][k]==u)
                        cnt[mp(u,g[u][k])]++;
                }
            }
         //   cout<<endl;
            int sum=0;

            map<pair<int,int>,int>::iterator it;
            it = cnt.begin();
            while(it!=cnt.end())
                sum += it->se,it++;
            //cout<<sum<<endl;
            ans = max(ans,sum);
        }
    }
    cout<<ans<<endl;
}
