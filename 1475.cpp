#include <iostream>
#include <algorithm>

const int MAX = 1000000;
const int MAXDISIT = 7;
int stock[10];

using namespace std;

int main(){
    int roomNum = 0;
    int setNum = 1;
    cin >> roomNum;
    //초기화
    for(int i = 0; i < 10 ; i++)
        stock[i] = 1;
    while(roomNum != 0){
        int tempNum = roomNum%10;
        if(stock[tempNum]!=0){
            stock[tempNum]--;
        }

        else{
            bool needFill = true;
            if(tempNum == 6){
                if(stock[9] != 0){
                    stock[9]--;
                    needFill = false;
                }


            }
            else if(tempNum == 9) {
                if (stock[6] != 0){
                    stock[6]--;
                    needFill = false;
                }
            }
            if(needFill){
                setNum++;
                for(int i = 0 ; i < 10 ; i++){
                    stock[i]++;
                }
                stock[tempNum]--;
            }

        }
        roomNum /= 10;
    }
    cout << setNum << endl;
}