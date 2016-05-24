#include<iostream>
#include<cmath>

int factorial(const int & N){
	int factorial = 1;
	for(int i = 2;i <= N;i++){
		factorial *= i;
	}
	return factorial;
}

int main() {
    int N;
    int sum = 1;
    std::cin>>N;
    for(int i = 2;i <= N;i++){
    	sum += factorial(i);
	}
	std::cout<<sum;
	return 0;
}
