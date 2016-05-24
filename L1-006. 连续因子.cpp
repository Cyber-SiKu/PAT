#include<iostream>

int main() {
	int N;
	int number[2][32] = {0};
	std::cin>>N;
	int old = 0;
	int MAX = 0;
	int product = 1;
	int j;
	for(int i = 2; i <= N&&i>0; i++) {
		if(N%i == 0) {
			if(i > old+1) {
				MAX = number[!MAX][0]>number[MAX][0]?(!MAX):MAX;
				number[!MAX][0] = 0;
				product = 1;
			}
			if(product*i > N) {
				MAX = number[!MAX][0]>number[MAX][0]?(!MAX):MAX;
				number[!MAX][0] = 0;
				product = 1;
			}
			old = i;
			j = ++number[!MAX][0];
			number[!MAX][j] = i;
			product *= i;
		}
	}
	MAX = number[!MAX][0]>number[MAX][0]?(!MAX):MAX;
	std::cout<<number[MAX][0]<<std::endl;
	for(int i = 1; i <= number[MAX][0]; i++) {
		if(i != 1) {
			std::cout<<"*";
		}
		std::cout<<number[MAX][i];
	}
	return 0;
}
