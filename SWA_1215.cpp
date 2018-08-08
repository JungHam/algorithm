#include <iostream>
#include <algorithm>

const int WIDTH = 8;
char pannel[WIDTH][WIDTH];

using namespace std;

int palin(string a,int len){
    bool isPalin = true;
    for(int i = 0 ; i < len/2 ; i++){
        if(a[i] != a[len-i-1]){
            isPalin = false;
            break;
        }

    }
    return isPalin;
}

int main(){
    for(int i = 0 ; i < 10 ; i++){
        int len = 0;
        int count = 0;
        cin >> len;
        for(int i = 0 ; i < 8 ; i++){
            string temp;
            cin >> temp;
            for(int j = 0 ; j < 8 ; j++) {
                pannel[i][j] = temp[j];
            }
        }
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8-len+1 ; j++) {
                string temp ="";
                string temp2 = "";
                for(int k = j ; k < j+len ; k++){

                    temp+= pannel[i][k];
                    temp2 += pannel[k][i];
                }
                if(palin(temp,len))
                    count++;
                if(palin(temp2,len))
                    count++;

            }

        }

        cout <<"#" <<i+1 << " "<<count<<endl;
        count = 0;

    }

}