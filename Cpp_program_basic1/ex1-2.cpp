#include <iostream>

using namespace std;

int maxof(int a, int b);
int maxof(int a, int b, int c);
int maxof(int buff[], int size);

int main(void){
    int x, y, z;
    int buff[5];
    int i;

    cout << "xの値を入力してください =>";
    cin >> x;
    cout << "yの値を入力してください =>";
    cin >> y;
    cout << "xとyの大きいほうの値は" << maxof(x, y) << "です\n";
    
    cout << "zの値を入力してください =>";
    cin >> z;
    cout << "x,y,zの最大値は" << maxof(x, y, z) << "です\n";
    
    cout << "5個の値を入力してください\n";
    for(i=0; i<5; i++){
        cout << "buff[" << i <<"]=";
        cin >> buff[i];
    }

    cout << "入力した値の最大値は" << maxof(buff, 5) << "です\n";
}

// 2つの値の最大値
int maxof(int a, int b){
    if(b>a) return b;
    else return a;
}

// 3つの値の最大値
int maxof(int a, int b, int c){
    int max = a;
    if(b>a) max = b;
    if(c>a) max = c;
    return max;
}

int maxof(int buff[], int size){
    int max = buff[0];
    int i;
    for(i=1; i<size; i++){
        if(buff[i]>max) max = buff[i];
    }
    return max;
}