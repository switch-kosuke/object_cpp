#include <iostream>
#include <cstring>

using namespace std;

/**Figureクラス**/
class Figure{
    public:
        virtual ~Figure(){};
        virtual void print(){};
        virtual double getArea(){};
};

class Rectangle:public Figure{
    private:
        int x1;
        int y1;
        int x2;
        int y2;
    public:
        Rectangle(int ix1, int iy1, int ix2, int iy2);
        void print();
        double getArea(){
            return (abs(x1-x2)*abs(y1-y2));
        }
};

class Circle:public Figure{
    public:
        int x;
        int y;
        int r;
    public:
        Circle(int ix, int iy, int ir);
        void print();
        double getArea(){
            return r*r*3.14;
        }
};

Rectangle::Rectangle(int ix1, int iy1, int ix2, int iy2){
    x1=ix1; y1=iy1;
    x2=ix2; y2=iy2;
}

void Rectangle::print(){
    Figure::print();
    cout << "長方形："<<
            "始点座標(" << x1 << "," << y1 << "), " <<
            "終点座標(" << x2 << "," << y2 << "), 面積 " << getArea() << endl;
            
}

Circle::Circle(int ix, int iy, int ir){
    x = ix;
    y = iy;
    r = ir;
}

void Circle::print(){
    Figure::print();
    cout << "円："<<
            "中心座標(" << x << "," << y << "), " <<
            "半径" << r << ", 面積 " << getArea() << endl;
}


int main(void){
    Figure* p[2];
    int i;

    p[0] = new Rectangle(1, 3, 8, 5);
    p[1] = new Circle(3, 4, 2);

    for(i=0; i<2; i++){
        p[i] -> print();
        cout << endl;
    }
}