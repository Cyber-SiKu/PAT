#include<iostream>
#include<map>
#include<utility>
#include<iterator>
#include<string>

void church(std::map<std::string, std::pair<const int, std::string>> & L1,
	const std::string & start1,
	std::string & start2);

int main() {
	std::map<std::string, std::pair<const int, std::string>> L1;
	//key : Adress;value :{Key,Next}
	std::string start1;
	int N;
	std::cin >> start1 >> N;
	for (int i = 0; i < N; i++) {
		std::string Adress, Next;
		int Key;
		std::cin >> Adress >> Key >> Next;

		L1.insert(std::pair<std::string, std::pair<const int, std::string>>(Adress,
			std::pair<const int, std::string>(Key, Next)));
	}

	std::string start2 = "-1";
	church(L1, start1, start2);

	while (start1 != "-1") {
		std::cout << start1 << " " << L1[start1].first << " " << L1[start1].second <<
			std::endl;
		start1 = L1[start1].second;
	}
	while (start2 != "-1") {
		std::cout << start2 << " " << L1[start2].first << " " << L1[start2].second <<
			std::endl;
		start2 = L1[start2].second;
	}
	return 0;
}

void church(std::map<std::string, std::pair<const int, std::string>> & L1,
	const std::string & start1,
	std::string & start2) {
	std::string flag = "-1";

	for (std::string i = start1; i != "-1"; i = L1[i].second) {
		for (std::string j = i; L1[j].second != "-1";) {
			if (L1[i].first == L1[L1[j].second].first
				|| L1[i].first == -L1[L1[j].second].first) {
				std::string temp = L1[j].second;
				L1[j].second = L1[temp].second;
				L1[temp].second = "-1";
				if (flag == "-1") {
					start2 = temp;
				}
				else {
					L1[flag].second = temp;
				}
				flag = temp;
				if (L1[j].second == "-1") {
					break;
				}
 				continue;
			}
			j = L1[j].second;
		}
	}
}
