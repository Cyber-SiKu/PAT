#include<iostream>

int main() {
	const int MAX_N = 500;
	int map_city[MAX_N][MAX_N] = {0};
	int city[MAX_N] = {0};
	int N,M,S,D;
	std::cin>>N>>M>>S>>D;
	for(int i = 0; i < N; i++) {
		std::cin>>city[i];
	}
	for(int i = 0; i < M; i++) {
		int s,d,length;
		std::cin>>s>>d>>length;
		map_city[s][d] = length;
		map_city[d][s] = length;
	}
	return 0;
}
