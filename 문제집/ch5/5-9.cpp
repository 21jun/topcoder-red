#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy{
public:
	int theNumber(string answer){
		int nums[16];

		for(int i=0;i<16;i++)
			nums[i] = 1; //�� 1�� �ʱ�ȭ

		if(answer[0] == 'Y'){//1~8�϶�
			for(int i=8;i<16;i++)
				nums[i] = -1;
		}
		else{//9~16�϶�
			for(int i=0;i<8;i++)
				nums[i] = -1;
		}

		if(answer[1] == 'Y'){//�Ʊ� �������� ���� 4����
			for(int i=4;i<8;i++)
				nums[i] = -1;
			for(int i=12;i<16;i++)
				nums[i] = -1;	
		}
		else{//�Ʊ� �������� �ڿ� 4����
			for(int i=0;i<4;i++)
				nums[i] = -1;
			for(int i=8;i<12;i++)
				nums[i] = -1;	
		}

		if(answer[2] == 'Y'){//�Ʊ� �������� �տ� 2����
			int num;
			for(int i=0;i<16;i++){
				if(nums[i] != -1){
					num = i;
					break; // -1�� �ƴ� ù ���� ã��
				}
			}

			nums[num+2] = -1;//�Ʊ� �������� �� 2�� -1�� �ٲ���
			nums[num+3] = -1;
		}

		else{//�Ʊ� �������� �ڿ� 2����
			int num;
			for(int i=0;i<16;i++){
				if(nums[i] != -1){
					num = i;
					break;
				}
			}

			nums[num] = -1;//�Ʊ� �������� �� 2�� -1�� �ٲ���
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