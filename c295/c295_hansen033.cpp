#include <iostream>
using namespace std;

int main(){
	int N, M;//尺寸
	cin >> N >> M;
	int data[N][M], chosen[N];
	for(int t1=0; t1<N; t1++){//輸入
		for(int t2=0; t2<M; t2++){
			cin >> data[t1][t2];
		}
	}

	int total=0;//其中一個答案
	for(int t1=0; t1<N; t1++){
		chosen[t1]=data[t1][0];//讓他有個東西比大小
		for(int t2=1; t2<M; t2++){
			if(data[t1][t2]>chosen[t1]){
				chosen[t1]=data[t1][t2];
			}
		}
		total+=chosen[t1];
	}

	cout << total << endl;//答案
	bool nooutput=true;
	for(int t=0; t<N; t++){
		if(chosen[t]!=0 && total%chosen[t]==0){//看能不能整除}
			if(!nooutput){//最後面才不會有空格
				cout << " ";
			}
			cout << chosen[t];
			nooutput=false;
		}
	}
	if(nooutput){//沒有分母時要輸出-1
		cout << "-1\n";
	}
}
