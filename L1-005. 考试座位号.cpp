#include<iostream>
#include<string>

struct student {
	std::string number;
	int kaoshi;
};

int main() {
	const int MAX = 10000;
	struct student s[MAX];
	int N;
	std::string number;
	int shiji;
	int kaoshi;
	int M;
	int temp[MAX];
	std::cin>>N;
	for(int i = 0; i < N; i++) {
		std::cin>>number>>shiji>>kaoshi;
		s[shiji].number = number;
		s[shiji].kaoshi = kaoshi;
	}
	std::cin >> M;
	for(int i = 0; i < M; i++) {
		std::cin>>temp[i];
	}
	for(int i = 0; i < M; i++) {
		std::cout<<s[temp[i]].number<<" "<<s[temp[i]].kaoshi<<std::endl;
	}
	return 0;
}
