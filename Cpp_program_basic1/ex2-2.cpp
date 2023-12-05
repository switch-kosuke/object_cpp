#include <iostream>
#include <cstring>

using namespace std;

class Employee {
    private:
        int m_no;
        char m_name[40];
        char m_belong[40];

    public:
        Employee(int no, char* name, char* belong);
        void output();
};

Employee::Employee(int no, char* name, char* belong){
    m_no = no;
    strcpy(m_name, name);
    strcpy(m_belong, belong);
}

// 言葉の出力
void Employee::output(){
    cout << "No. " << m_no << endl;
    cout << "名前： " << m_name << endl;
    cout << "所属： " << m_belong << endl;
}

int main(void){
    Employee e(1, "山田", "総務部");
    e.output();
    return 0;
}