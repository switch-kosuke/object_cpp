#include <iostream>
#include <cstring>

using namespace std;

/**Studentクラス**/
class Student{
    private:
        int no;
        char* name;
    public:
        Student();
        Student( int ino, char* iname);
        ~Student();
        void output();
};

Student::Student(){
    no = 0;
    name = new char[1];
    strcpy(name, "");
};

Student::Student(int ino, char* iname){
    no = ino;
    name = new char[strlen(iname) + 1]; //領域を空ける
    strcpy(name, iname); //nameにinameをコピーしている
}

Student::~Student(){
    delete [] name;
}

void Student::output(){
    cout << "番号:" << no << "\n名前:" << name <<endl;
}

int main(void){
    //Student a; //デフォルトコンストラクタ
    Student a(123, "うすい");
    a.output();
    return 0;
}