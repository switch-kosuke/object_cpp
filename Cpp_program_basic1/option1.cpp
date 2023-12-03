#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Lend {
    private:
        int m_no;
        char* m_name;
        char m_issue[11];
        int m_yearissue;
        int m_monthissue;
    public:
        Lend(int lno, char* lname, char* lissue);
        ~Lend();
        char* getName();
        int getIssueYear();
        int getIssueMonth();
        void getToday(int&, int&);
        int getLendTerms();
};

Lend::Lend(int lno, char* lname, char* lissue){
    m_no = lno;
    strcpy(m_name, lname);
    strcpy(m_issue, lissue);

    
}