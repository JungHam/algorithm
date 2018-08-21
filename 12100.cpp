#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 21;

void memory_free(int **board, int r)
{
    for (int i = 0; i < r; i++) delete[] board[i];
    delete[] board;
}
int move(int level, int r, int ob[MAX][MAX], int direct){
    int tmax = 0;

    int b[MAX][MAX];

    for(int i =0; i<r; i++) {

        for(int j=0; j<r; j++) {

            b[i][j] = ob[i][j];

        }

    }
    if(direct == 1){

        for(int i = 0 ; i < r ; i++){
            vector<int>tempb;
            vector<int>tempa;
            for(int j = 0 ; j < r ; j++){

                if(b[i][j]!=0){
                    tempb.push_back( b[i][j]);
                }
            }

            if(tempb.size() != 0){
                for(int j = 0 ; j < tempb.size()-1 ; j++){
                    if(tempb[j] == tempb[j+1]){
                        tempb[j] = tempb[j]+tempb[j+1];
                        tempb[j+1] = 0;
                    }
                }

                for(int j = 0 ; j < tempb.size() ; j++){
                    if(tempb[j]!=0) {
                        tempa.push_back(tempb[j]);
                    }
                }

                for(int j = 0 ; j < r ; j++){
                    if(j < tempa.size()){
                        b[i][j] = tempa[j];
                    }
                    else
                        b[i][j] = 0;
                }

            }





        }
    }
    else if(direct == 2){

        for(int i = 0 ; i < r ; i++){
            vector<int>tempb;
            vector<int>tempa;
            for(int j = 0 ; j < r ; j++){
                if(b[i][j]!=0){
                    tempb.push_back(b[i][j]);
                }
            }

            if(tempb.size() != 0){
                for(int j = tempb.size()-1 ; j >=1 ; j--){
                    if(tempb[j] == tempb[j-1]){
                        tempb[j] = tempb[j]+tempb[j-1];
                        tempb[j-1] = 0;
                    }
                }

                for(int j = 0 ; j < tempb.size() ; j++){
                    if(tempb[j]!=0){
                        tempa.push_back(tempb[j]);
                    }
                }

                for(int j = 0 ; j < r; j++){
                    if(j < tempa.size()){
                        b[i][r-j-1] = tempa[tempa.size()-1-j];
                    }
                    else
                        b[i][r-j-1] = 0;
                }
            }

        }
    }
    else if(direct == 3){

        for(int i = 0 ; i < r ; i++){
            vector<int>tempb;
            vector<int>tempa;
            int tempCount = 0;
            for(int j = 0 ; j < r ; j++){
                if(b[j][i]!=0){
                    tempb.push_back(b[j][i]);
                }
            }
            if(tempb.size() != 0){
                for(int j = 0 ; j < tempb.size()-1 ; j++){
                    if(tempb[j] == tempb[j+1]){
                        tempb[j] = tempb[j]+tempb[j+1];
                        tempb[j+1] = 0;
                    }
                }

                for(int j = 0 ; j < tempb.size() ; j++){
                    if(tempb[j]!=0) {
                        tempa.push_back(tempb[j]);
                    }
                }

                for(int j = 0 ; j < r ; j++){
                    if(j < tempa.size())
                        b[j][i] = tempa[j];
                    else
                        b[j][i] = 0;
                }
            }


        }
    }
    else if(direct == 4){

        for(int i = 0 ; i < r ; i++){
            vector<int>tempb;
            vector<int>tempa;
            for(int j = 0 ; j < r ; j++) {
                if (b[j][i] != 0) {
                    tempb.push_back(b[j][i]);
                }
            }

            if(tempb.size() != 0){ 
                for(int j = tempb.size()-1 ; j >=1 ; j--){
                    if(tempb[j] == tempb[j-1]){
                        tempb[j] = tempb[j]+tempb[j-1];
                        tempb[j-1] = 0;
                    }
                }

                for(int j = 0 ; j < tempb.size() ; j++){
                    if(tempb[j]!=0){
                        tempa.push_back(tempb[j]);
                    }
                }

                for(int j = 0 ; j < r; j++){
                    if(j < tempa.size())
                        b[r-j-1][i] = tempa[tempa.size()-1-j];
                    else
                        b[r-j-1][i] = 0;
                }
            }

        }
    }

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            tmax = max(tmax,b[i][j]);
        }
    }

    if(level != 5){


        int result = max(tmax, max(move(level+1,r,b,1), max(move(level+1,r,b,2), max(move(level+1,r,b,3), move(level+1,r,b,4)))));
        //cout << "level : " << level << ", max :" << result << endl;
        //memory_free(b,r);
        return result;
    }
    else {
        //memory_free(b,r);
        //cout << "level : " << level << ", max :" << tmax << endl;
        return tmax;
    }
}
int main(){
    int num;
    cin >> num;
    //int** board = new int*[MAX];
    int board[MAX][MAX];
    //for(int i = 0 ; i < num ; i++){
    //   board[i] = new int[i];
    //}
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num ; j++){
            cin >> board[i][j];
        }
    }
    int result = max(move(1,num,board,1),max(move(1,num,board,2),max(move(1,num,board,3),move(1,num,board,4))));
    cout << result;

}