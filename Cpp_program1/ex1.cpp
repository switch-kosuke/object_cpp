#include <iostream>

using namespace std;

void swap();
void sort(int buff[], int size);

int main(void){
    int* buff;
    int size;
    int i;

    cout << "���בւ��鐔�ʂ̐�����͂��Ă�������������";
    cin >> size;

    buff = new int[size]; //�̈�̊m��

    for (i=0;i<size;i++){
        buff[i] =0;
    }

    //�����l�̓���
    for(i=0; i<size; i++){
        cout << "�����l����͂��Ă��������i�I���F�O�j==>";
        cin >> buff[i];
        if(buff[i]==0){
            size = i;
            break;
        }
    }

    sort(buff, size);
    cout << "���בւ�����..." << endl;
    for(i=0; i<size; i++){
        cout << buff[i] << endl;
    }

    delete [] buff;  //�̈�����
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