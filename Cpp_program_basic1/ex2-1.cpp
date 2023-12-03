#include <iostream>

using namespace std;

class Xydata{
    private:
        int x, y;
    public:
        Xydata();
        Xydata(int m);
        Xydata(int m, int n);
        void output();
};

Xydata::Xydata(){
    x = 0; y = 0;
}
Xydata::Xydata(int m){
    x = m; y = 0;
}
Xydata::Xydata(int m, int n){
    x = m; y = n;
}

//データメンバーの表示
void Xydata::output(){
    cout << "(" << x << "," << y << ")"<< endl;
}

int main(void){
    Xydata xy1, xy2(3), xy3(5,2);

    cout << "点xy1 :";
    xy1.output();
    cout << "点xy2 :";
    xy2.output();
    cout << "点xy3 :";
    xy3.output();
    
    return 0;
}