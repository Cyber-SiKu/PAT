#include<iostream>

void spaek_number(const char & c){
	switch(c){
		case '-':
			std::cout<<"fu";
			break;
		case '0':
			std::cout<<"ling";
			break;
		case '1':
			std::cout<<"yi";
			break;
 		case '2':
			std::cout<<"er";
			break;
		case '3':
			std::cout<<"san";
			break;
		case '4':
			std::cout<<"si";
			break;
		case '5':
			std::cout<<"wu";
			break;
		case '6':
			std::cout<<"liu";
			break;
		case '7':
			std::cout<<"qi";
			break;
		case '8':
			std::cout<<"ba";
			break;
		case '9':
			std::cout<<"jiu";
			break;
	}
}

int main()
{
	char c;
	int flag = 0;
	while(std::cin>>c){
		if(flag){
			std::cout<<" ";
		}
		spaek_number(c);
		flag = 1;
		if(std::cin.peek() == '\n'){
			break;
		}
	}
	return 0;
}
