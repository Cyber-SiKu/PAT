#include<iostream>
using namespace std;

int main()
{
	int a[3];
	for(int i = 0;i < 3;i++){
		cin>>a[i];
	}
	for(int i = 0;i < 3;i++){
		for(int j = i;j < 3;j++){
			int max = a[i]>a[j]?a[i]:a[j];
			int min = a[i]<a[j]?a[i]:a[j];
			a[i] = min;
			a[j] = max;
		}
	}
	std::cout<<a[0]<<"->"<<a[1]<<"->"<<a[2];
	return 0;
}
