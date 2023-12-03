#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Err{
    public:
        virtual char* what() = 0; //純粋仮想関数
};

class Err1 : public Err{
    public:
        virtual char* what(){
            return "error1";
        }
};

class Err2 : public Err{
    public:
        virtual char* what(){
            return "error2";
        }
};

class Err3 : public Err{
    public:
        virtual char* what(){
            return "error3";
        }
};

void g(){
    try{
        //Err1 e;      //エラー１
        Err2 e;     //エラー２
        //Err3 e;     //エラー２
        throw e;
    } catch(Err1& e){
        cout << "-- 関数 g() --" <<endl;
        cout << e.what() << endl;
    //} catch(Err2& e){
    //    cout << "-- 関数 g() --" <<endl;
    //    cout << e.what() << endl;
    //} catch(Err3& e){
    //    cout << "-- 関数 g() --" <<endl;
    //    cout << e.what() << endl;
    }
}

void f() {
    try {
        g();
    //} catch(Err1& e){
    //    cout << "-- 関数 f() --" <<endl;
    //    cout << e.what() << endl;
    } catch(Err2& e){
        cout << "-- 関数 f() --" <<endl;
        cout << e.what() << endl;
    //} catch(Err3& e){
    //    cout << "-- 関数 g() --" <<endl;
    //    cout << e.what() << endl;
    }
}

int main(void){
    try{
        f();
    //} catch(Err1& e){
    //    cout << "-- 関数 main() --" <<endl;
    //    cout << e.what() << endl;
    //} catch(Err2& e){
    //    cout << "-- 関数 main() --" <<endl;
    //    cout << e.what() << endl;
    } catch(Err3& e){
        cout << "-- 関数 main() --" <<endl;
        cout << e.what() << endl;
    }

    return 0;
}