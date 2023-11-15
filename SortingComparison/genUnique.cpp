#include<bits/stdc++.h>

using namespace std;

int main(){
    srand(time(0));
    int n;
    cin >> n;
    unordered_map<long long, int> checker;
    ofstream outfile;
    outfile.open("input.txt");
    int i = 0;
    while(i < n){
        long long x = ((long long) rand() << 32) | rand();
        if(checker.find(x) == checker.end()){
            outfile << x << endl;
            checker[x] = 1;
            i++;
        }
    }

    outfile.close();
    return 0;
}