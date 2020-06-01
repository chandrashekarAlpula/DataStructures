#include<iostream>
#include<string>
#include<deque>
using namespace std;

template<typename T>
void Print(T **mat, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
struct cord{
	int x, y;
	cord(int x = 0, int y = 0) : x{x}, y{y}{}
	friend std::ostream &operator<<(std::ostream &out, const cord &c){
		out << "(" << c.x << "," << c.y <<")" ;
		return out;
	}
};

int **solMat;
std::deque<cord> Q;

int dir[8][2] = { {-1,0}, {1,0}, {0,1}, {0,-1}, {-1,-1}, {1,1},{1, -1}, {-1, 1}};
bool IsIndexValid(int rid, int cid, int n ){
    return (rid >= 0 && rid < n) && (cid >= 0 && cid < n);
}


bool FindWord(char **M, int n, int r, int c, const char *word, int wordlen){

	if(!IsIndexValid(r, c, n) || M[r][c] != *word)
		return false;
	printf("Found char %c at %d, %d\n", *word, r, c);
	solMat[r][c] = 1;
	Q.push_back(cord(r,c));
	if(wordlen == 1){
		cout << "match found " << endl ;
		return true;
	}

	for(const auto D : dir ){
		if(FindWord(M, n, r + D[0], c + D[1], word+1, wordlen-1))
			return true;
	}
	solMat[r][c] = 0;
	Q.pop_back();
	return false;
}
void  solution_function(){
	//make modifications in the code below for accepting input from console /
	int n;
	cin>>n;
	char **mat;
	mat = new char*[n];
	solMat = new int*[n];
	for(int i = 0; i < n; i++){
		mat[i] = new char[n];
		solMat[i] = new int[n];

	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> mat[i][j] ;
			solMat[i][j] = 0;
		}

	std::string str;
	cin >> str;
	cout << "Str " << str << endl;
	const char *word = str.c_str();
	Print(mat, n, n);

	for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				FindWord(mat, n, i, j, word, str.size());
	Print(solMat, n, n);
	for(auto q : Q)
			cout << q << endl ;
}
int main(){
	solution_function();
	return 0;
}
