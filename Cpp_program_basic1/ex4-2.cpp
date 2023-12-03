#include <iostream>
#include <cstring>

using namespace std;

//社員クラスの定義
class Employee {
    private:
        int m_no;
        char m_name[40];
        char m_belong[40];

    public:
        Employee(int no, char* name, char* belong);
        virtual ~Employee();
        virtual void output();
};

//営業クラスの定義
class Business:public Employee{
    private:
        char m_kname[40];
    public:
        Business(int no, char* name, char* belong, char* kname);
        virtual ~Business();
        virtual void output();
};

//開発クラスの定義
class Development:public Employee{
    private:
        char m_sname[40];
    public:
        Development(int no, char* name, char* belong, char* sname);
        virtual ~Development();
        virtual void output();
};

Employee::Employee(int no, char* name, char* belong){
    m_no = no;
    strcpy(m_name, name);
    strcpy(m_belong, belong);
}

Employee::~Employee(){
    delete [] m_name;
    cout << "社員クラスのデストラクタが呼ばれました";
}

Business::Business(int no, char* name, char* belong, char* kname):Employee(no, name, belong){
    strcpy(m_kname, kname);
}

Business::~Business(){
    delete [] m_kname;
    cout << "ビジネスクラスのデストラクタが呼ばれました";
}

Development::Development(int no, char* name, char* belong, char* sname):Employee(no, name, belong){
    strcpy(m_sname, sname);
}

Development::~Development(){
    delete [] m_sname;
    cout << "開発クラスのデストラクタが呼ばれました";
}

// 言葉の出力
void Employee::output(){
    cout << "No. " << m_no << endl;
    cout << "名前： " << m_name << endl;
    cout << "所属： " << m_belong << endl;
}

void Business::output(){
    Employee::output();
    cout << "担当顧客：" << m_kname << endl;
}

void Development::output(){
    Employee::output();
    cout << "担当システム：" << m_sname << endl;
}

int main(void){
    // Employee型のポインタを３個定義
    Employee* emp[3];
    int i;

    //各クラスのオブジェクトを生成し、Employee型のポインタに代入
    emp[0] = new Employee(1, "山田", "総務部");
    emp[1] = new Business(2, "佐藤", "営業部", "ABC株式会社");
    emp[2] = new Development(3, "鈴木", "開発部", "受注システム");
    
    for(i=0; i<3; i++){
        emp[i] -> output();
        cout << endl;
    }

    for(i=0; i<3; i++){
        cout << "emp[" << i << "]をdeleteします";
        delete emp[i];
        cout << endl;
    }
    
    return 0;
}