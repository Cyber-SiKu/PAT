#include<iostream>
#include<stack>

const int MAX_N = 500;

int count_least_path(std::stack<int> path[],int map_city[][MAX_N],int city[],
                     const int & S,const int & D);
void update_length(int map_city[][MAX_N],bool visted[],std::stack<int> path[]
                   ,int city[],const int & S,const int & j,const int & k);   //after visted point k
//j-k is the short length

int main() {
	int map_city[MAX_N][MAX_N] = {0};
	int city[MAX_N] = {0};  //The number of rescue team
	int N,M,S,D;
	std::cin>>N>>M>>S>>D;

	for(int i = 0; i < N; i++) {
		std::cin>>city[i];
	}

	for(int i = 0; i < M; i++) {
		int s,d,length;
		std::cin>>s>>d>>length;
		map_city[d][s] = map_city[s][d] = length;
	}
	//store the path of the shorest path,without start and end point
	std::stack<int> path[MAX_N] ;

	count_least_path(path,map_city,city,S,D);
	return 0;
}
int count_least_path(std::stack<int> path[],int map_city[][MAX_N],int city[],
                     const int & S,const int & D) {
	bool visted[MAX_N] = {false};   //the point is visted or not
	int i = 0;  //record the point hase visted

	int min = MAX_N +1; //tips:the length is less than 500
	int min_j = MAX_N;
	int min_k = S;

	while(1) {  //if you want to find one path to change 1 to path[i] != N
		i++;
		//find the nearest point to visted
		for(int j = 0; j < i; j++) {    //visted point
			for(int k = 0; k < MAX_N; k ++) { //unvisted ponit
				if(visted[k]) {
					continue;
				}
				//TODO: when finished change follow to if ,to see which is quick;
				min = min > map_city[j][k] ? map_city[j][k] : min;
				min_j = min > map_city[j][k] ? j : min_j;
				min_k = min > map_city[j][k] ? k : min_k;
			}
		}

		// when min_k == N break so we can find all path
		if(min_k == D) {
			break;
		}
		update_length(map_city,visted,path,city,S,min_j,min_k);
		min = MAX_N +1;
	}

	int min_length = map_city[S][min_j] + map_city[min_j][min_k];
	int max_number_team = city[min_j];
	int count = 0;
	for(int i = 0; i < MAX_N; i++) {
		if(!visted[i]) {
			continue;
		}
		if(min_length == map_city[S][i] + map_city[i][D]) {
			count++;
			max_number_team = max_number_team > city[i] ? max_number_team : city[i];
		}
	}

	std::cout<<count<<" "<<max_number_team<<std::endl
	         <<S;
	while(!path[min_j].empty()) {
		int i;
		//TODO : ²é¿´stack¶¥ÔªËØ
		path[min_j].pop();
		std::cout<<" "<<i;
	}
	std::cout<<" "<<min_j<<" "<<D;
}
void update_length(int map_city[][MAX_N],bool visted[],std::stack<int> path[],
                   int city[],const int & S,const int & j,const int & k) {
	visted[k] = true;

	//store S->k's shortest length without start and end ponit
	path[k] = path[j];
	path[k].push(j);

	//store S->k's rescue team's number
	city[k] += city[j];

	for(int i = 0; i < MAX_N; i++) {
		if(visted[i] || !map_city[k][i]) {
			continue;
		}
		map_city[S][k] = map_city[k][S] = map_city[S][j] + map_city[k][i];
	}
}
