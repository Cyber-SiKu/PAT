/*L1-003. 个位数统计*/
#include<iostream>
#include<string>
#include<iterator>

void count_number(std::string N, int number[]);
void print(int number[]);

int main() {
	int number[10] = {0};   //从0-9 记录每个数出现的次数
	std::string  N;
	std::cin>>N;
	count_number(N,number);
	print(number);

	return 0;
}

void count_number(std::string  N, int number[]) {
	int N_size = N.size();
	for(int i = 0;i < N_size;i++){
		number[N[i]-'0']++;
	}
}

void print(int number[]){
	for(int i = 0;i < 10;i++){
		if(number[i]){
			std::cout<<i<<":"<<number[i]<<std::endl;
		}
	}
}
