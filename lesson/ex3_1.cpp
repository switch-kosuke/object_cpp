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

/**Economic クラス**/
class Economic:public Student{
    private:
        char* seminar;
    public:
        Economic(int ino=0, char* iname="", char* iseminar="");
        ~Economic();
        void output();
};

/**Technologyクラス**/
class Technology:public Student{
    private:
        char* research; //卒業研究名
    public:
        Technology(int ino=0, char* iname="", char* iresearch="");
        ~Technology();
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

Economic::Economic(int ino, char* iname, char* iseminar):Student(ino, iname){
    seminar = new char[strlen(iseminar) + 1];
    strcpy(seminar, iseminar);
}

Economic::~Economic(){
    delete [] seminar;
}

void Economic::output(){
    Student::output();
    cout << "ゼミ" << seminar << endl;
}

Technology::Technology(int ino, char* iname, char* iresearch):Student(ino, iname){
    research = new char[strlen(iresearch) + 1];
    strcpy( research, iresearch);
}

Technology::~Technology(){
    delete [] research;
}

void Technology::output(){
    Student::output();
    cout << "研究:" << research << endl;
}

int main(void){
    //Student a; //デフォルトコンストラクタ
    Student a(123, "うすい");
    Economic b(211, "臼井", "数学");
    Technology c(335, "こうすけ", "微分積分解析");

    a.output(); cout<<endl;
    b.output(); cout<<endl;
    c.output(); cout<<endl;
    return 0;
}