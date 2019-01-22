#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class MazeMaker{
public:
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol){
		int max = 0;
		int width = maze[0].size(), height = maze.size();
		int board[50][50];

		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
				board[i][j] = -1;

		board[startRow][startCol] = 0;//시작점은 0 앞으로 가면서 +1씩 해서 board에 숫자를 새김
		queue <int> queueX;
		queue <int> queueY;
		queueX.push(startCol);
		queueY.push(startRow);

		while(queueX.size() > 0){ // BFS
			int x = queueX.front(), y = queueY.front();
			queueX.pop();
			queueY.pop();
			for(int i=0;i<moveRow.size();i++){
				int nextX = x + moveCol[i], nextY = y + moveRow[i];
				if( 0 <= nextX && nextX < width 
					&& 0 <= nextY && nextY < height 
					&& board[nextY][nextX] == -1
					&& maze[nextY].substr(nextX, 1) == "."){	//갈 수 있는 곳이고 들렀던 곳이 아니고 미로 안 범위 내이면 그 곳으로 이동
						board[nextY][nextX] = board[y][x] + 1; //+1한 숫자 입력하기
						queueX.push(nextX);
						queueY.push(nextY);
				}
			}
		}

		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(maze[i].substr(j, 1) == "." && board[i][j] == -1){ //??
					return -1;
				}
				max = std::max(max, board[i][j]); // board에 새겨져 있는 숫자 중 가장 큰 것 반환
			}
		}

		return max;
	}
};

int main(){
	MazeMaker m;
	vector <string> maze;
	maze.push_back("...");
	maze.push_back("...");
	maze.push_back("...");

	int startRow = 0, startCol = 1;

	vector <int> moveRow, moveCol;

	moveRow.push_back(1);
	moveRow.push_back(0);
	moveRow.push_back(-1);
	moveRow.push_back(0);

	moveCol.push_back(0);
	moveCol.push_back(1);
	moveCol.push_back(0);
	moveCol.push_back(-1);

	cout<<m.longestPath(maze, startRow, startCol, moveRow, moveCol);

	return 0;
}