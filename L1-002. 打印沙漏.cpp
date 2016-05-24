/*L1-002. ´òÓ¡É³Â©*/
#include<iostream>
#include<cmath>

void print(const int & N,const char & c) {
	const int MAX = sqrt((N+1)/2);
	for(int i = MAX;i > 0;i--){
		for(int j = 0;j < MAX-i;j++){
			std::cout<<" ";
		}
		for(int j = 0 ;j < 2*i-1;j++){
			std::cout<<c;
		}
		std::cout<<std::endl;
	}
	for(int i = 2;i <= MAX;i++){
		for(int j = 0;j < MAX-i;j++){
			std::cout<<" ";
		}
		for(int j = 0 ;j < 2*i-1;j++){
			std::cout<<c;
		}
		std::cout<<std::endl;
	}
	std::cout<<N+1-2*pow(MAX,2);
}

int main() {
	int N;
	char c;
	std::cin>>N>>c;
	print(N,c);
	return 0;
}
