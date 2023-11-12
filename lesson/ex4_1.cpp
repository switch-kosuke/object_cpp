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
        Student( int ino, const char* iname);
        virtual ~Student();
        virtual void output();
        void whoami(){
            cout << "studentクラスのwhoami関数です\n";
        }
};

/**Economic クラス**/
class Economic:public Student{
    private:
        char* seminar;
    public:
        Economic(int ino=0, const char* iname="", const char* iseminar="");
        ~Economic();
        void output(); //オーバーライド
        void whoami(){
            cout << "Economicクラスのwhoami関数です\n";
        }
};

/**Technologyクラス**/
class Technology:public Student{
    private:
        char* research; //卒業研究名
    public:
        Technology(int ino=0, const char* iname="", const char* iresearch="");
        ~Technology();
        void output();
        void whoami(){
            cout << "Technologyクラスのwhoami関数です\n";
        }
};

Student::Student(){
    no = 0;
    name = new char[1];
    strcpy(name, "");
};

Student::Student(int ino, const char* iname){
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

Economic::Economic(int ino, const char* iname, const char* iseminar):Student(ino, iname){
    seminar = new char[strlen(iseminar) + 1];
    strcpy(seminar, iseminar);
}

Economic::~Economic(){
    delete [] seminar;
}

void Economic::output(){
    Student::output();
    cout << "ゼミ:" << seminar << endl;
}

Technology::Technology(int ino, const char* iname, const char* iresearch):Student(ino, iname){
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
    Student* p[3];
    int i;

    //Student a; //デフォルトコンストラクタ
    p[0] = new Student(123, "生徒");
    p[1] = new Economic(211, "生徒名", "ゼミ名");
    p[2] = new Technology(355, "研究員名" "研究名");

    //a.output(); cout<<endl;
    //b.output(); cout<<endl;
    //c.output(); cout<<endl;
    
    for(i=0; i<3; i++){
        p[i] -> output();
        cout << endl;
    }

    for(i=0; i<3; i++){
        p[i] -> whoami();
        cout << endl;
    }
    for(i=0; i<3; i++){
        delete p[i];
    }
    
    return 0;
}