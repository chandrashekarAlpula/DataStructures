#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<queue>

#define FOR(i,k,n) for(int i = k; i <= n; i++)
#define ll long long
#define MOD 1000000007
#define FACT_MAXSIZE 1000003

using namespace std;
int mat[1005][1005];
bool isVisited[1005][1005];

//int movCor[8][2] = {{-1,-2},{1,-2},{-1,2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
int movCor[8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };
ll F[FACT_MAXSIZE];
ll fact(ll n){
	//cout << "Fact of " << n << " is " << F[n] << endl;
    return F[n];
}

void CalculateFact(){
    FOR(i,1,FACT_MAXSIZE)
        F[i] = (F[i-1] * i)%MOD;
}
struct point{
    int x, y;
    point(int a, int b){
        x = a;
        y = b;
    }
};

bool IsValidCoordinate(int x, int y, int N, int M){
    return (x >= 1 && x <= N && y >= 1 && y <= M && mat[x][y] == 1);
}
ll BFS(int x, int y, int N, int M){
    isVisited[x][y] = true;
    queue<point> q;
    ll cnt = 1;
    q.push(point(x, y));
    while(!q.empty()){
        point p = q.front();
        q.pop();
        int x = p.x;
        int y = p.y;
        for(int i = 0; i < 8; i++){
            int a = x + movCor[i][0];
            int b = y + movCor[i][1];
            if(!IsValidCoordinate(a, b, N, M) || isVisited[a][b]){
            	//printf("Invalid coordinate %d %d isVisited %d\n", a,b, isVisited[a][b]);
            	continue;
            }
        //    cout << a << " " << b << endl;
            isVisited[a][b]=true;
            q.push(point(a, b));
            cnt++;

        }
    }
   // cout << "Count " << cnt << endl;
    return cnt;
}

int main(){
    int T;
    cin >> T;
    F[0] = 1;
    CalculateFact();
    while(T--){
        int N, M, Q;
        cin >> N >> M >> Q;
        ll f = 1;
        FOR(i,1,N){
            FOR(j,1,M){
                mat[i][j] = 0;
                isVisited[i][j] = false;
            }
        }
        int x, y;
        while(Q--){
            cin >> x >> y;
             mat[x][y] = 1;
        }
        FOR(i,1,N){
            FOR(j,1,M){
                if((!isVisited[i][j]) && mat[i][j] ==  1){
                	ll c = BFS(i, j, N, M);
                		f = (f *F[c])%MOD;
                		//cout << "F " << f << " matValue " << mat[i][j] << endl;
                }
            }
        }
        cout << (f)%MOD << endl  ;
    }
    return 0;
}
