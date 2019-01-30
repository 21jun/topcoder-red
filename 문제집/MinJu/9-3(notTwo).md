## 9-3(NotTwo)

>문제
```
Bob has a width x height rectangular board divided into 1 x 1 cells. Rows of the board are numbered 0 to height-1 and columns are numbered 0 to width-1. 

Each cell can contain at most one stone, and the Euclidean distance between each pair of stones must not equal 2. 
The Euclidean distance between cell in row x1, column y1 and cell in row x2, column y2 is defined as the square root from (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2). 

Return the maximal number of stones he can place on the board.
```

>코드
``` cpp
#include <iostream>
using namespace std;

class NotTwo{
	int maxStones(int width, int height){
		int i, j, res = 0;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				res += (((width + i)/2)*((height + j)/2+1)/2;
			}
		}
		return res;
	}
};
```
