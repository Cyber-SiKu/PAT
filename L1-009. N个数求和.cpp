#include<iostream>
using namespace std;

struct fenshu {
	long fenzi;
	long fenmu;
};

long Max_Common_Divisor(long m,long n);

void sum(struct fenshu f[],int N);
void deal_to_simple(struct fenshu & f);	//把分数处理为最简
void print(struct fenshu f);

int main() {
	int N;
	struct fenshu fenzi[100];
	cin>>N;
	for(int i = 1; i <= N; i++) {
		char c;
		cin>>fenzi[i].fenzi>>c>>fenzi[i].fenmu;
	}
	sum(fenzi, N);
	print(fenzi[0]);
	return 0;
}

long Max_Common_Divisor(long m,long n) {
	if (n == 0)
		return m;

	return 	Max_Common_Divisor(n,m % n);
}
void sum(struct fenshu f[],int N) {
	f[0].fenzi = f[1].fenzi;
	f[0].fenmu = f[1].fenmu;
	for(int i = 2; i <= N; i++) {
		long mcd = Max_Common_Divisor(f[0].fenmu,f[i].fenmu);
		f[0].fenzi = f[0].fenzi*f[i].fenmu/mcd + f[i].fenzi*f[0].fenmu/mcd;
		f[0].fenmu *= (f[i].fenmu/mcd);
		deal_to_simple(f[0]);
	}
}

void deal_to_simple(struct fenshu & f) {
	long mcd = Max_Common_Divisor(f.fenzi, f.fenmu);
	while (mcd != 1) {
		f.fenzi /= mcd;
		f.fenmu /= mcd;
		mcd = Max_Common_Divisor(f.fenzi, f.fenmu);
	}
	if (f.fenmu < 0) {
		f.fenmu = -f.fenmu;
		f.fenzi = -f.fenzi;
	}
}

void print(struct fenshu f) {
    if(f.fenzi/f.fenmu != 0)
    {
		std::cout<<f.fenzi/f.fenmu;
	}
	if(f.fenzi/f.fenmu != 0&&f.fenmu != 1){
		std::cout<<" ";
	}
	if (f.fenmu != 1) {
		std::cout<<f.fenzi - f.fenzi/f.fenmu*f.fenmu
			<<"/"
			<<f.fenmu;
	}
	if(f.fenzi == 0){
		std::cout<<"0";
	}
}
