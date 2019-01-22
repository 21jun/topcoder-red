#include <iostream>
using namespace std;

bool grid[100][100] = {false}; //DFS matrix (���� �ε����� �ʵ��� ������ ū ũ��� ����
int vx[] = {1, -1, 0, 0}; // �¿�� ������ ��츦 ���� �迭
int vy[] = {0, 0, 1, -1}; // ���Ʒ��� ������ ��츦 ���� �迭
double prob[4]; // ��,��,��,���� ������ Ȯ���� �����ϴ� �迭

class CrazyBot{
public:
	double getProbability(int n, int east, int west, int south, int north){
		prob[0] = east/100.0;
		prob[1] = west/100.0;
		prob[2] = south/100.0;
		prob[3] = north/100.0;

		return dfs(50, 50, n); //100*100 �������� ����� ������� �����ϵ��� 50, 50���� ����
	}

	double dfs(int x, int y, int n){
		if(grid[x][y]==true) return 0; //�Դ� ���� �� ���� Ȯ�� 0
		if(n == 0) return 1;//n�� 0�� �� ������ �����ϸ� 1�� �������� -> ���߿� �ؿ��� Ȯ���� ������

		grid[x][y] = true; //�湮�����Ƿ� true�� �ٲ���
		double ret = 0; // ���� Ȯ��
		for(int i=0;i<4;i++){ //��,��,��,���� �ֱ� ���� for���� 4�� ����
			ret += dfs(x + vx[i], y + vy[i], n-1) * prob[i]; // x + vx[i]�� i=0,1�� ���(��, ��) ��ġ�� �̵���Ű�� ���Ͽ� ���� ��
															 // y + vy[i]�� i=2,3�� ���(��, ��) ��ġ�� �̵���Ű�� ���Ͽ� ���� ��
															 // n=0���� ����Լ��� ���� ���� 1�� �����ϸ� ���� �ش��ϴ� Ȯ���� �����ְ�
															 // ret�� �����־� ���� Ȯ���� ������
		}
		grid[x][y] = false;	// �ٽ� ����� ��� ���� false�� ���ֱ� ���Ͽ�

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