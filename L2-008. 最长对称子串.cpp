#include<iostream>
#include<string>

bool is_symmetry(std::string s);

int main() {
	std::string s;
	getline(std::cin,s);
	//��������²����Գ��Ӵ�����
	int s_size = s.size();
	int i ,j;
	for(i = s_size;i > 1;i--){
		//�ж�s��Ϊi���Ӵ��Ƿ�Ϊ�Գƴ�
		for(j = 0 ;j <= s_size-i;j++){
			std::string s_=s.substr(j,i);
			if(is_symmetry(s_)){
				std::cout<<i;
				return 0;
			}
		}
	}
	std::cout<<1;
	return 0;
}
bool is_symmetry(std::string s){
	int i =0,j = s.size()-1;
	for(;i < j;i++,j--){
		if(s[i] != s[j]){
			return false;
		}
	}
	return true;
}
