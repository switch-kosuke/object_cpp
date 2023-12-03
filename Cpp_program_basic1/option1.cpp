#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Lend {
    private:
        int m_no; //図書番号
        char* m_name; //名前
        char m_issue[11];
        int m_yearissue;
        int m_monthissue;
    public:
        Lend(int lno, char* lname, char* lissue);
        ~Lend();
        char* getName(){return m_name;};
        int getIssueYear(){return m_yearissue;};
        int getIssueMonth(){return m_monthissue;};
        void getToday(int&, int&);
        int getLendTerms(){return 0;};
};

Lend::Lend(int lno, char* lname, char* lissue){
    int i;
    for(i=0; i<strlen(lissue); i++){
        int num;
        num = lissue[i] - '0';
        if(((num < 0) || (9 < num)) && (lissue[i] != '/')){
            cout << "日付の入力が正しくありません（yyyy/mm/dd）" << endl;
            exit(1);
        }
    }

    m_no = lno;
    strcpy(m_name, lname);
    strcpy(m_issue, lissue);

    //発行日から年と月を切り出す
    char* buff;
    char buffissue[11];
    strcpy(buffissue, m_issue);
    buff = strtok(buffissue, "/"); //区切り分割
    m_yearissue = atoi(buff); //文字列を数値に変換
    buff = strtok(NULL, "/");
    m_monthissue = atoi(buff);
}

void Lend::getToday(int& year, int& month){
    time_t current;
    tm *local;
    time(&current);
    local = localtime(&current);

    year = local -> tm_year+1900;
    month = local -> tm_mon + 1;
}
