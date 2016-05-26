#include<iostream>
#include<queue>

const int MAX_N = 500;

void count_least_path(std::queue<int> path[],int map_city[][MAX_N],int city[],
                      const int & S,const int & D,const int & N);
void update_length(int map_city[][MAX_N],bool visted[],std::queue<int> path[]
                   ,int city[],const int & S,const int & j,const int & k,
                   const int & N);   //after visted point k
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
	//store the shorest path of the S to i,without end point
	std::queue<int> path[MAX_N] ;

	count_least_path(path,map_city,city,S,D,N);
	return 0;
}
void count_least_path(std::queue<int> path[],int map_city[][MAX_N],int city[],
                      const int & S,const int & D,const int & N) {
	bool visted[MAX_N] = {false};   //the point is visted or not
	int i = 0;  //record the point hase visted

	int min = MAX_N +1; //tips:the length is less than 500
	int min_j = MAX_N + 1;
	int min_k = S;
	visted[S] = true;

	while(1) {  
		//if you want to find one path to change 1 to path[i] != N
		i++;
		//find the nearest point to visted
		for(int j = 0; j < N; j++) {    
			//visted point
			if(visted[j]) {
				for(int k = 0; k < N; k ++) { 
					//unvisted ponit and connect with point j
					if(!visted[k] && map_city[j][k]) {
						min_j = min > map_city[j][k] ? j : min_j;
						min_k = min > map_city[j][k] ? k : min_k;
						min = min > map_city[j][k] ? map_city[j][k] : min;
					}
				}
			}
		}

		// when min_k == N break so we can find all path
		if(min_k == D) {
			break;
		}

		update_length(map_city,visted,path,city,S,min_j,min_k,N);
		min = MAX_N +1;
	}

	int min_length = map_city[S][min_j] + map_city[min_j][D];
	int max_number_team = city[min_j] + city[D];
	int count = 0;

	for(int i = 0; i < N; i++) {
		if(visted[i] && map_city[i][D]) {
			if(min_length == map_city[i][D]) {
				//find one match the require
				count++;
				min_j = max_number_team >= city[i]+city[D] ? min_j : i;
				max_number_team = max_number_team >= city[i]+city[D] ? max_number_team : city[i]
								  +city[D];
			}
		}
	}

	std::cout<<count<<" "<<max_number_team<<std::endl;
	while(!path[min_j].empty()) {
		std::cout<<path[min_j].front()<<" ";
		path[min_j].pop();
	}
	std::cout<<min_j<<" "<<D<<std::endl;
}
void update_length(int map_city[][MAX_N],bool visted[],std::queue<int> path[],
                   int city[],const int & S,const int & j,const int & k,const int & N) {
	visted[k] = true;

	//store S->k's shortest length without end ponit
	path[k] = path[j];
	path[k].push(j);

	//store S->k's rescue team's number
	city[k] += city[j];
	map_city[S][k] = map_city[k][S] = map_city[S][j] + map_city[j][k];

	for(int i = 0; i < N; i++) {
		if(!visted[i] && map_city[k][i]) {
			map_city[i][k] = map_city[k][i] = map_city[i][k] + map_city[S][k];
		}
	}
}
