#include <iostream>
using namespace std;

bool grid[100][100] = {false}; //DFS matrix (벽에 부딪히지 않도록 적당히 큰 크기로 선언
int vx[] = {1, -1, 0, 0}; // 좌우로 움직일 경우를 위한 배열
int vy[] = {0, 0, 1, -1}; // 위아래로 움직일 경우를 위한 배열
double prob[4]; // 동,서,남,북을 선택할 확률을 저장하는 배열

class CrazyBot{
public:
	double getProbability(int n, int east, int west, int south, int north){
		prob[0] = east/100.0;
		prob[1] = west/100.0;
		prob[2] = south/100.0;
		prob[3] = north/100.0;

		return dfs(50, 50, n); //100*100 사이즈의 행렬의 가운데에서 시작하도록 50, 50으로 해줌
	}

	double dfs(int x, int y, int n){
		if(grid[x][y]==true) return 0; //왔던 곳을 또 오면 확률 0
		if(n == 0) return 1;//n이 0이 될 때까지 성공하면 1을 리턴해줌 -> 나중에 밑에서 확률을 곱해줌

		grid[x][y] = true; //방문했으므로 true로 바꿔줌
		double ret = 0; // 최종 확률
		for(int i=0;i<4;i++){ //동,서,남,북을 넣기 위해 for문을 4번 돌림
			ret += dfs(x + vx[i], y + vy[i], n-1) * prob[i]; // x + vx[i]는 i=0,1인 경우(동, 서) 위치를 이동시키기 위하여 해준 것
															 // y + vy[i]는 i=2,3인 경우(남, 북) 위치를 이동시키기 위하여 해준 것
															 // n=0까지 재귀함수가 돌고 나면 1을 리턴하면 이제 해당하는 확률을 곱해주고
															 // ret에 더해주어 최종 확률을 구해줌
		}
		grid[x][y] = false;	// 다시 행렬의 모든 값을 false로 해주기 위하여

		return ret;
	}
};

int main(){
	int n, east, west, south, north;
	CrazyBot a;

	n = 2;
	east = 25;
	west = 25;
	south = 25;
	north = 25;

	cout<<a.getProbability(n, east, west, south, north);

}
