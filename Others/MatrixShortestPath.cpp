/*
 * MatrixShortestPath.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: chandra.shekhar
 */
#include <iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<queue>

#define INTMAX  0XFFFF
//left, down, right, up
int rowMove[] = {0, -1, 0, 1};
int colMove[] = {-1, 0, 1, 0};

struct point{
	int x,y,cost;
	point(int a, int b, int c):x(a),y(b), cost(c){}
};

void PrintMat(char **mat, int N){
	cout << endl << "Printing matrix elements"  << endl ;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << mat[i][j] << "\t";
		}
		cout <<endl;
	}
}
bool isValidPoint(char **mat, int x, int y, int N){
	return (x  >= 0 && x < N && y >= 0 && y < N && mat[x][y] == 'D');
}
int BFS(char **mat, int N){

	bool visited[N][N];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			visited[i][j] = false;

	visited[0][0] = true;
	point pt = point(0,0,0);
	queue<point> que ;
	que.push(pt);
	while(!que.empty()){
		point currPoint = que.front();
		que.pop();
		int x = currPoint.x, y = currPoint.y;
		cout << "Point is " << x << "," << y << endl;
		if(x == N-1 && y == N-1){
			cout << endl << "return " << endl ;
			return currPoint.cost;
		}
		//Visit all the adjacent nodes
		for(int i=0; i<4; i++){
			int row = rowMove[i];
			int col = colMove[i];
			int adjX = x  + row, adjY  = y + col;
			//cout << "Adj Point is " << adjX << "," << adjY << endl;
			if(isValidPoint(mat,adjX, adjY, N)){
				//cout << "Adj Point1 is " << adjX << "," << adjY << " ,Visited " << visited[adjX][adjY] << " INTMAX"<< INTMAX << endl;
				if(!visited[adjX][adjY]){
					// add the adjecent vertex to queue
					cout << "Adj Point is " << adjX << "," << adjY << endl;
					que.push(point(adjX,adjY,(currPoint.cost +1)));
					visited[adjX][adjY] = true;
				}
			}
		}
	}
	return -1;
}

int main()
{
	int N =0;
	cin >> N;
//	int **matrix;
    char **mat = (char **)malloc(N * sizeof(char *));
  //  matrix = (int **)malloc(N * sizeof(int *));
    for(int i=0;i<N;i++){
    	mat[i] =  (char *)malloc(N * sizeof(char));
    //	matrix[i] = (int *)malloc(N * sizeof(int));
    }

    for(int i=0; i<N; i++){
    	//cout << endl << "Enter the elements row " << i  << endl ;
    	for(int j=0; j<N; j++){
    		cin >> mat[i][j];
    		//matrix[i][j] = INTMAX;
    	}
    }
    PrintMat(mat, N);
    int ret = BFS(mat, N);
    printf("%d",ret);
    return 0;
}


