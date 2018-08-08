#include <iostream>
#include <algorithm>

using namespace std;

const int HIGHTMAX = 255;
const int WIDTH = 1000;
int building[WIDTH];
int calDiff(int a, int b){
    if(a > b) return a-b;
    else if(a <= b) return 0;

}
int main(){
    int totalView = 0;
    int testWidth = 0;
    for(int i = 0 ; i < 10 ; i++){
        cin >> testWidth;
        for(int j = 0 ; j < 5 ; j++)
            cin >> building[j];
        totalView += min(min(min(calDiff(building[2],building[1]),calDiff(building[2],building[0])),calDiff(building[2],building[3])),calDiff(building[2],building[4]));
        for(int j = 5 ; j < testWidth; j++){
            cin >> building[j];
            totalView += min(min(min(calDiff(building[j-2],building[j-3]),calDiff(building[j-2],building[j-4])),calDiff(building[j-2],building[j-1])),calDiff(building[j-2],building[j]));
        }
        cout << "#"<<i+1 << " " << totalView << endl;
        totalView = 0;
    }

}
