#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
#include<iterator>

float Similar_rate(std::vector<std::set<int>> & v,const int & number1,
                   const int & number2);

int main() {
	int N;
	std::cin>>N;
	std::vector<std::set<int>> v;
	for(int i = 0; i < N; i++) {
		int M;
		std::cin>>M;

		std::set<int> set_temp;
		for(int j = 0; j < M; j++) {
			int temp;
			std::cin>>temp;
			set_temp.insert(temp);
		}
		v.push_back(set_temp);
	}
	int K;
	std::cin>>K;
	for(int i = 0; i < K; i++) {
		int number1,number2;
		std::cin>>number1>>number2;
		printf("%0.2f%\n",100*Similar_rate(v,number1,number2));
	}
	return 0;
}

float Similar_rate(std::vector<std::set<int>> & v,const int & number1,
                   const int & number2) {
	float Nc = 0;
	for(std::set<int>::iterator i = v[number2-1].begin(); i != v[number2-1].end();
	        i++) {
		Nc += v[number1-1].count(*i);
	}
	
	v[number1-1].insert(v[number2-1].begin(),v[number2-1].end());

	float Nt = v[number1-1].size();
	return Nc / Nt;
}
