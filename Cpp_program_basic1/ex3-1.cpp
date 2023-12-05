#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Xydata{
    protected:
        double x;
        double y;
    public:
        Xydata(double m = 0, double n = 0){ x = m; y = n;}
        void output();
};

class Xyzdata:public Xydata{
    private:
        double z;
    public:
        Xyzdata(double m = 0, double n = 0, double l = 0);
        void output();
        double length();
};

//データメンバーの表示
void Xydata::output(){
    cout << "(" << x << "," << y << ")"<< endl;
}

Xyzdata :: Xyzdata(double m, double n, double l) :Xydata(m, n){
    z = 1;
}

void Xyzdata ::output(){
    cout << "(" << x << "," << y << "," << z << ")"<< endl;
}

double Xyzdata::length(){
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int main(void){
    Xyzdata xyz(2,8,10);
    cout << "点xyz : ";
    xyz.output();
    
    cout << "点xyzと原点との距離は" << xyz.length();
    
}