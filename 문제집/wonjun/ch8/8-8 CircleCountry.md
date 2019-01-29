# 8-8 CircleCountry

    Circles Country는 원형으로 구분된 지역이 있는 나라입니다. 어떤 지역은 다른 지역 내부에 있을 수도 있습니다. 하지만 지
	역의 경계가 교차하거나 접하는 일은 없습니다. Qatam은 Circles Country에 살고 있습니다. 지역의 경계를 넘어 이동할 때는
	귀찮은 것이 많으므로 두 지역 사이를 이동할 때 최대한 경계를 조금만 이동하도록 주의합니다.

	Circle Country가 무한히 펼쳐지는 평면이라고 생각해주세요. 구역 i의 중심이 (X[i], Y[i])이고 반경 R[i]이 되는 int[] X.
	int[] Y, int[] R이 주어집니다. Qatam의 형재 위치 (x1, y1)에서 목적 위치 (x2, y2)로 이동해야 합니다. 두 위치 모두 경계에
	위에 있지는 않습니다. 목적지에 도착할 때까지 지나가는 최소의 경계 수를 리턴해주세요.

> 풀이
    
	원의 경계가 닿는 경우 + 겹치는 경우는 없으므로
	한 원에서 다른 원으로 이동하는 중 다른원을 지나가야할 경우는 없다
	그러므로 모든 원을 검사하면서, 시작점에서 끝점이 같은 원에 있다면 횟수추가 없고 
	시작점과 끝점이 다른원에 있다면 횟수를 1 추가한다.


```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class CirclesCountry
{
public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
	{
		int num = 0;

		for (int i = 0; i < X.size(); i++)
		{
			// 시작점 끝점이 서로 다른원에 있을때만 ++
			if (inside(X[i], Y[i], x1, y1, R[i]) != inside(X[i], Y[i], x2, y2, R[i]))
				num++;
		}

		return num;
	}

	bool inside(int x1, int y1, int x2, int y2, int r)
	{
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r;
	}
};
```
