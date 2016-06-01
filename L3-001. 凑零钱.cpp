#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>

bool Is_Able(std::vector<int> & coin,const int & M);
void print(std::vector<int> & coin,std::stack<int> & temp);

int main() {
	int N,M;
	std::cin>>N>>M;
	std::vector<int> coin;
	for(int i = 0; i < N; i++) {
		int temp;
		std::cin>>temp;
		coin.push_back(temp);
	}
	if(!Is_Able(coin,M)) {
		std::cout<<"No Solution";
	}
	return 0;
}

bool Is_Able(std::vector<int> & coin,const int & M) {
	std::sort(coin.begin(),coin.end()); //sort ,the answer is <

	std::stack<int> temp;
	//save the index to stack
	//when it need to backtrace,let i = temp.top() then temp.pop()

	int i = 0;
	int sum = 0;
	while(temp.size() < coin.size()) {
		while(i < coin.size()) {
			if(sum + coin[i] < M) {
				sum += coin[i];
				temp.push(i);
				i++;
			} else if(sum + coin[i] > M) {
				if(sum == 0) {
					return false;
				}
				i = temp.top() + 1;
				sum -= coin[i - 1];
				temp.pop();
			} else {
				temp.push(i);
				print(coin,temp);
				return true;
			}
		}
		if(i >= coin.size()) {
			return false;
		}
	}
}

void print(std::vector<int> & coin,std::stack<int> & temp) {
	int i = temp.top();
	temp.pop();
	if(temp.size() == 0) {
		std::cout<<coin[i];
		return ;
	}
	print(coin,temp);
	std::cout<<" "<<coin[i];
}
