#include<iostream>

int main()
{
	int A,B;
	std::cin>>A>>B;
	int flag = 0;
	int sum = 0;
	while(A <= B){
		sum += A;
		std::cout.setf(std::ios::right);
		std::cout.width(5);
		std::cout<<A;
		flag++;
		if(flag % 5 == 0){
			std::cout<<std::endl;
		}
		A++;
	}
	if(flag % 5 != 0){
		std::cout<<std::endl;
	}
	std::cout<<"Sum = "<<sum;
	return 0;
}
