#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string chemical;
long long global_count = 0;
long long calcChemical(string part_c){
    long long local_count= 0;
    long long previous_count = 0;
    int i = 0;
    while(global_count < part_c.size()){ //전역변수로 index 체크하는 경우에는 for문은 괜히 한바퀴 돌고 계속 index를 증감해야 되서 계산하기 헷갈리니까 while문을 쓰자.
        if(part_c.at(global_count) == ')'){
            local_count += previous_count;
            global_count++;
            return local_count;
        }

        if(part_c.at(global_count) == '(') {
            local_count += previous_count;
            global_count++;
            previous_count = calcChemical(part_c);

            continue;
        }
        else if(isdigit(part_c.at(global_count))){
            local_count += previous_count * (int)(part_c.at(global_count) - '0');
            previous_count = 0;
            global_count++;
        }
        else{
            local_count += previous_count;
            previous_count = 0;
            if(part_c.at(global_count) == 'H')
                previous_count = 1;
            else if(part_c.at(global_count) == 'C')
                previous_count = 12;
            else if(part_c.at(global_count) == 'O')
                previous_count = 16;
            global_count++;
        }
    }
    local_count += previous_count;
    return local_count;
}

int main() {
    while(cin >> chemical){
        long long cost = calcChemical(chemical);
        cout << cost << endl;
        global_count = 0;
    }
    return 0;
}