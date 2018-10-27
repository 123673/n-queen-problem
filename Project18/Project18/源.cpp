#include<iostream>
#include<cstring>
#include<cmath>
int queen[16];
int sum[13];
int count1 = 0;
int n;
using namespace std;
bool check(int row){
	  for (int i = 0; i < row;++i){
		if (queen[i] == queen[row] || (abs(queen[row] - queen[i]) == (row - i)))
			return false;
	  }
	 return true;
}
void calcu(int row){
	for (int i = 0; i < n;++i){
		queen[row] = i;
		if (check(row)){
			if (row == n - 1) {
				count1++;
			}
			else calcu(row+1);
		}
	}
}
int main(){
	int j;
	for (n = 1; n <= 12;++n){
		count1 = 0;
		calcu(0);
		sum[n] = count1;
	}
	while (scanf("%d", &j) && j){
		  printf("%d\n",sum[j]);
	}
}