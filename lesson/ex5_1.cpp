#include <iostream>

using namespace std;

double calc_div(double a, double b);

int main(void){
    double val1, val2;
    double res;
    try{
        cout << "割られる数を入力してください==>";
        cin >> val1;
        cout << "割る数を入力してください==>";
        cin >> val2;

        res = calc_div( val1, val2);
        cout << "結果は" << res << "です" << endl;
    }catch(const char* e){
        cout << e << endl;
    }
    
    return 0;
}

/******************
除算（割り算）を計算する関数
　関数名　calc_div
　戻り値　割り算の結果（double）
　引数　　割られる数（double）
　　　　　割る数（double）
　処理内容　割り算を計算した結果を返す
　例外処理　割る数に０を指定すると、エラーメッセージを投げる
*****************/
double calc_div(double a, double b){
    double ret=0;
    if(b==0){
        throw "エラー：０で割るな、ハゲが！！！！";
    }else{
        ret = a/b;
    }
    
    return ret;
}