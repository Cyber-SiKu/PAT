#include<iostream>
#include<vector>
#include<queue>
#include<iterator>

class Tree {
	public:
		std::vector<int> suf_order_;
		std::vector<int> infix_order_;
};
void Hierarchy_Traversal(std::queue<Tree> & s);
//N is not change,n is the range of array

int main() {
	int N;
	std::cin>>N;
	Tree t;
	for(int i = 0; i < N; i++) {
		int temp;
		std::cin>>temp;
		t.suf_order_.push_back(temp);
	}

	for(int i = 0; i < N; i++) {
		int temp;
		std::cin>>temp;
		t.infix_order_.push_back(temp);
	}

	std::queue<Tree> s;
	s.push(t);

	Hierarchy_Traversal(s);
	return 0;
}

void Hierarchy_Traversal(std::queue<Tree> & s) {
	Tree temp = s.front();
	s.pop();
	
	static int flag = 0;
	if(flag){
		std::cout<<" ";
	}
	flag = 1;
	
	std::vector<int>::reverse_iterator i = temp.suf_order_.rbegin();
	std::cout<<*i;

	std::vector<int>::iterator j = temp.infix_order_.begin();
	Tree left;
	while(*j != *i) {
		left.infix_order_.push_back(*j);
		++j;
	}
	Tree right;
	
	for(j++; j != temp.infix_order_.end(); j++) {
		right.infix_order_.push_back(*j);
	}
	int k;
	for(k = 0; k < left.infix_order_.size(); k++) {
		left.suf_order_.push_back(temp.suf_order_[k]);
	}
	for(; k < right.infix_order_.size()+ left.infix_order_.size(); k++) {
		right.suf_order_.push_back(temp.suf_order_[k]);
	}
	
	if(left.infix_order_.size()) {
		s.push(left);
	}
	if(right.infix_order_.size()) {
		s.push(right);
	}
	
	if(s.size() == 0) {
		return ;
	}
	Hierarchy_Traversal(s);
}
