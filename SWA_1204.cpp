#include <iostream>
#include <algorithm>

const int STUDENTNUM = 1000;
const int MAXSCORE = 100;
int scoreList[MAXSCORE+1];

using namespace std;

int main(){
    int caseNum = 0;
    cin >> caseNum;
    for(int i = 0 ; i < caseNum ; i++){
        int tempcase = 0;
        cin >> tempcase;
        int maxScore = 0;//출현횟수 저장
        int maxNum = 0;
        for(int j = 0 ; j <= 100 ; j++)
            scoreList[j] = 0;
        for(int j = 0 ; j < STUDENTNUM ; j++){
            int tempScore;
            cin >> tempScore;
            scoreList[tempScore]++;
        }
        maxScore = 100;
        for(int j = 100 ; j >=0 ; j--){
            if(scoreList[maxScore] < scoreList[j]){
                maxScore = j;
            }

        }
        cout << "#" << i+1 << " "<<maxScore<<endl;
        maxScore = 100;

    }

}