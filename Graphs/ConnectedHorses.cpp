#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int ad[1003][1003];
int factorial[1000003];
int n,m;
int visit[1003][1003];
int dir [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

/*Given N ,M number of rows and columns in a chess board
Given Q queries each query contain co-ordinates of horses in a chess board.
Find the number of ways horses swap their position */

//Solution
/*Use Breadth First Search(BFS) to find the total number of horses in each connected groups,
 * then find the factorial of this number. Apply same in each group and multiplication of all gives the result.
 * Use DP for calculation of factorials.
 *
 */
long long BFS(int a, int b){
    visit[a][b] = 1;
    long long count =1;
    queue <pair<int ,int > > q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int x = a + dir[i][0];
            int y = b + dir[i][1];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;
            if(ad[x][y]==3 and !visit[x][y]){
                count++;
                q.push(make_pair(x,y));
                visit[x][y]=1;
            }


        }

    }
    //cout << count << endl ;
    return count;
}
void initialize(){
    for(int i=0;i<1003;i++){
        for(int j=0;j<1003;j++){
            ad[i][j]=1;
            visit[i][j]=0;
        }
    }
}
int main()
{
    int t,q;

    factorial[0] = 1;
    cin>>t;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    while(t--){
        initialize();
        cin>>n>>m>>q;
        int x,y;
        while(q--){
            cin>>x>>y;
            ad[x][y] = 3;
        }
        long long c ;
        long long ans = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ad[i][j]==3 and !visit[i][j]){
                    c=BFS(i,j);
                    ans = (ans*factorial[c])%MOD;
                }
            }
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}


