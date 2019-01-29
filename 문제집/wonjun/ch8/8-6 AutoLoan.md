# 8-6 AutoLoan

    자동차 판매점은 "꿈의 마이카"를 쉽게 살 수 있게 하는 매력적인 대출 상담을 선전하고 있습니다. 
    전형적인 판매 방법은 다양한 차를 보고 각각의 지급 방법은 어떻게 할 것인지를 이야기했습니다. 
    그리고 실제 차의 가격이 얼마인지, 이자를 얼마나 지불할 것인지, 지불 기간이 어느 정도 인지를 상담했습니다.

    일반적으로 자동차 대출은 고정 금리로 계산됩니다. 또한 완전히 지불할 때까지 매달 같은 금액을 지불합니다.
    대출 잔액은 차의 원래 가격부터 시작됩니다. 매원 이자가 잔액에 추가됩니다.
    그리고 지불 분이 잔액에서 차감됩니다(지불액은 이자가 추가되고 차감됩니다).
    월 이자율은 연간 이자의 1/12입니다. 예를 들어 연간 금리가 12%라면 1%가 매달 이자로 부과됩니다.

    여러분은 TopAuto 지점의 판매점에서 자동차를 보고 있습니다.
    그러자 열정적인 직원이 바로 와서 보고 있는 차를 살 수 있는 방법을 열심히 설명합니다. 
    직원의 말에 의하면 monthlyPayment만큼의 금액을 loanTerm개월 정도 지불하면 된다고 합니다.
    대출의 연 이자율(%)을 double 자료형으로 리턴하세요. 단 대출 초기 잔액은 price라고 가정합니다

> 풀이

    수학적 접근법 보다는 이자율(구하자는 답)을 이분탐색으로 구한다
    100% 부터 시작해서 이자율에 맞게 잔액을 계산하여 오차율내의 이자율을 찾는다
    잔액이 남으면 이자율을 줄이고, 잔액이 부족하면 아지율을 늘린다

```cpp
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class AutoLoan {
public:
	double interestRate(double price, double monthlyPayment, int loanTerm)
	{
		double balance;
		double high = 100, low = 0, mid = 0;

		// 오차판정
		while ((1e-9 < high - low) && (1e-9 < (high - low) / high)) {
			balance = price;
			mid = (high + low) / 2;

			for (int j = 0; j<loanTerm; j++) {
				balance *= mid / 1200 + 1;
				balance -= monthlyPayment;
			}

			if (0 < balance)
				high = mid;
			else
				low = mid;
		}
		return mid;
	}
};
```
