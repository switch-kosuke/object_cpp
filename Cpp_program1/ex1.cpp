#include <iostream>

using namespace std;

void swap();
void sort(int buff[], int size);

int main(void){
    int* buff;
    int size;
    int i;

    cout << "並べ替える数位の数を入力してください＝＝＞";
    cin >> size;

    buff = new int[size]; //領域の確保

    for (i=0;i<size;i++){
        buff[i] =0;
    }

    //整数値の入力
    for(i=0; i<size; i++){
        cout << "整数値を入力してください（終了：０）==>";
        cin >> buff[i];
        if(buff[i]==0){
            size = i;
            break;
        }
    }

    sort(buff, size);
    cout << "並べ替え結果..." << endl;
    for(i=0; i<size; i++){
        cout << buff[i] << endl;
    }

    delete [] buff;  //領域を解放
    return 0;

}

void swap(int x, int y){
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void sort( int buff[], int size){
    int i,j;
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(buff[i] > buff[j]){
                swap( buff[i], buff[j]);
            }
        }
    }
}