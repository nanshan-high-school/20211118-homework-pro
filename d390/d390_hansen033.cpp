#include <iostream>
using namespace std;

int main() {
	int timestorun;
	cin >> timestorun;
	for(int t = 0; t < timestorun; t ++){
		//初始輸入
		int amount;
		cin >> amount;
		int value[amount];
		for(int t = 0; t < amount; t ++) cin >> value[t];
		//計算總和、sizeDP是總價值的一半
		int sum = 0;
		for(int t = 0; t < amount; t ++) sum += value[t];
		int sizedp = sum / 2 + 1;
		//DP初始化
		bool dp[sizedp];
		for(int t = 1; t < sizedp; t ++) dp[t] = 0;
		dp[0] = 1;
		//如果這個金額是可以達到的，那加上第t1個摳摳也可以達到，但只要一半或以下
		for(int t1 = 0; t1 < amount; t1 ++){
			for(int t2 = sum / 2 - 1; t2 >= 0; t2 --){
				if(dp[t2] && t2 + value[t1] < sizedp) dp[t2 + value[t1]] = 1;
			}
		}
		//這樣比較好找最接近的，因為只要找一次
		for(int t = sizedp - 1; t >= 0; t --){
			if(dp[t]){
				cout << sum - t * 2 << endl;
				break;
			}
		}
	}
}
