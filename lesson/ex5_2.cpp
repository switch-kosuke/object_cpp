#include <iostream>

using namespace std;

//スタックに関するエラーを表す例外（基本クラス）
class stack_error{
    public:
        virtual const char* what(){
            return "stack error.";
        }
};

//スタックが容量を超えたことを表す例外
class full_error : public stack_error{
    public:
        virtual const char* what(){
            return "stack error. stack is full!";
        }
};

//からのスタックから値を取得しようとしたことを表す例外
class empty_error : public stack_error{
    public:
        virtual const char* what(){
            return "stack error. stack is empty";
        }
};

const int size = 3;

class stack{
    private:
        int buf[size]; //int型の要素を格納する配列
        int sp; //スタックポイント
    public:
        stack(){sp = 0;} //コンストラクタ
        void push(int element){
            if(sp ==size){
                full_error e;
                throw e; //スタックが満杯の時例外を投げる
            }
            buf[sp++] = element;
        }
        int pop(){
            if(sp == 0){
                empty_error e;
                throw e; //スタックが空の時例外を投げる
            }
            return buf[--sp];
        }
};

int main(void){
    try{
        int i;
        stack s;
        //値を３つ投げる
        s.push(1);
        s.push(2);
        s.push(3);

        //値を４つ取り出そうとする
        for(i=0; i<4; i++){
            cout << s.pop() << endl;
        }
    }catch(stack_error& e){
        cout << e.what() << endl;
    }catch(...){
        cout << "システムエラーが発生したよん、ドンマイ小西ｗｗｗｗ\n";
    }
    return 0;

}
