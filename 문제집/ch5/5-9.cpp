#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy{
public:
	int theNumber(string answer){
		int nums[16];

		for(int i=0;i<16;i++)
			nums[i] = 1; //다 1로 초기화

		if(answer[0] == 'Y'){//1~8일때
			for(int i=8;i<16;i++)
				nums[i] = -1;
		}
		else{//9~16일때
			for(int i=0;i<8;i++)
				nums[i] = -1;
		}

		if(answer[1] == 'Y'){//아까 나눈거의 앞의 4개임
			for(int i=4;i<8;i++)
				nums[i] = -1;
			for(int i=12;i<16;i++)
				nums[i] = -1;	
		}
		else{//아까 나눈거의 뒤에 4개임
			for(int i=0;i<4;i++)
				nums[i] = -1;
			for(int i=8;i<12;i++)
				nums[i] = -1;	
		}

		if(answer[2] == 'Y'){//아까 나눈거의 앞에 2개임
			int num;
			for(int i=0;i<16;i++){
				if(nums[i] != -1){
					num = i;
					break; // -1이 아닌 첫 지점 찾기
				}
			}

			nums[num+2] = -1;//아까 나눈거의 뒤 2개 -1로 바꿔즘
			nums[num+3] = -1;
		}

		else{//아까 나눈거의 뒤에 2개임
			int num;
			for(int i=0;i<16;i++){
				if(nums[i] != -1){
					num = i;
					break;
				}
			}

			nums[num] = -1;//아까 나눈거의 앞 2개 -1로 바꿔줌
			nums[num+1] = -1;
		}

		if(answer[3] == 'Y'){
			for(int i=0;i<16;i++){
				if(i%2==1)
					nums[i] = -1;
			}
		}

		else{
			for(int i=0;i<16;i++){
				if(i%2==0)
					nums[i] = -1;
			}
		}

		int findNum;
		for(int i=0;i<16;i++){
			if(nums[i]!=-1)
				findNum = i + 1;
		}

		return findNum;
	}
};

int main(){
	NumberMagicEasy num;

	cout<<num.theNumber("NYNY");

	return 0;
}