#include <iostream>

using namespace std;

//構造体の宣言
struct Student{
    char* name;
    int English, Math, Japanese;
    double Average;
};

//関数のプロトタイプ宣言
void input(Student& p);
void output(Student& p);
void average(Student& p);
double average(int v=0, int y=0, int z=0);

int main(void){
    Student a;

    //構造体のメンバー変数の初期化
    a.name = new char[40];
    a.English = 0;
    a.Math = 0;
    a.Japanese = 0;
    a.Average = 0;

    //名前と点数を入力する
    input(a);

    //平均点を計算する
    a.Average = average(a.English, a.Math, a.Japanese);

    //結果を出力する
    cout << endl;
    output(a);
    
    delete [] a.name;

    return 0;
}

void input(Student& p){
    cout << "名前を入力してください==>";
    cin >> p.name;
    cout << "英語の点数を入力してください==>";
    cin >> p.English;
    cout << "数学の点数を入力してください==>";
    cin >> p.Math;
    cout << "国語の点数を入力してください==>";
    cin >> p.Japanese;
}

void output(Student& p){
    cout << p.name << "さんの点数\n";
    cout << "英語：" << p.English <<"\n数学:" << p.Math << "\n国語:" << p.Japanese << "\n平均:" << p.Average << "\n" ;
}

void average( Student p){
    p.Average = ( p.English + p.Math + p.Japanese) /3.0;
}

double average( int x, int y, int z){
    return (x+y+z)/3.0;
}