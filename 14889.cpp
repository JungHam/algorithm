#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[20][20];
int N;
int minCost = 100000000;
int list[20] = { 0 };
//dfs 문제
int cal(){
	int team1 = 0;
	for (int i = 0; i < N / 2; i++){
		for (int j = 0; j < N / 2; j++){
			team1 += map[list[i]][list[j]];
		}
	}
	vector<int>list2;
	int check[20] = { 0 };
	for (int i = 0; i < N / 2; i++){
		check[list[i]]++;
	}
	for (int i = 0; i < N; i++){
		if (check[i] == 0){
			list2.push_back(i);
		}
	}
	int team2 = 0;
	for (int i = 0; i < N / 2; i++){
		for (int j = 0; j < N / 2; j++){
			team2 += map[list2[i]][list2[j]];
		}
	}
	int diff = abs(team1 - team2);
	if (minCost > diff){
		minCost = diff;
	}
	return diff;


}

void df(int index, int depth){
	if (depth == N){
		if (index == N / 2){
			cal();
		}
		return;
	}

	df(index, depth + 1);
	list[index] = depth;
	df(index + 1, depth + 1);
	return;
}

int main(){
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}

	df(0, 0);
	cout << minCost;
}