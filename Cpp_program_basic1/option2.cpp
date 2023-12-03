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

//図書クラスの作成
class Publication : public Lend{
    char m_publisher[32];
    public:
        Publication(int no=0, char* name="", char* issue="", char* publisher="");
};

//書籍クラス
class Book : public Publication{
    private:
        char* m_author;
    public:
        Book(int no=0, char* name="", char* issue="", char* publisher="", char* auther="");
        int getLendTerms();
};

//雑誌クラス
class Magazine : public Publication{
    public:
        Magazine(int no=0, char* name="", char* issue="", char* publisher="");
        int getLendTerm();
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

//図書クラスのコンストラクタ
Publication :: Publication(int no=0, char* name="", char* issue="", char* publisher=""):Lend(no, name, issue){
    if(strlen(publisher) > 30){
        cout << "出版社名の文字数オーバーです（３０文字以内）" << endl;
        exit(1); //強制終了する
    }
    strcpy(m_publisher, publisher);
}

//書籍のコンストラクタ
Book::Book(int no=0, char* name="", char* issue="", char* publisher="", char* author=""):Publication(no, name, issue, publisher){
    if(strlen(author) > 30){
        cout << "著者の文字数オーバーです（３０文字以内）" << endl;
        exit(1);
    }
    strcpy(m_author, author);
}

//書籍の貸出期間の計算
int Book::getLendTerms(){
    int Term;
    Term = 14;
    return Term;
}

//雑誌クラスのコンストラクタ
Magazine::Magazine(int no, char* name, char* issue, char* publisher) : Publication(no, name, issue, publisher){}

//雑誌の貸出期間の計算
int Magazine::getLendTerms(){
    int Year, Month, Term;
    getToday(year, Month);

    if((getIssueYear()==Year) && (getIssueMonth() == Month)){
        Term = 7;
    }else{
        Term = 14;
    }
    return Term;
}

void Lend::getToday(int& year, int& month){
    time_t current;
    tm *local;
    time(&current);
    local = localtime(&current);

    year = local -> tm_year+1900;
    month = local -> tm_mon + 1;
}

int Book :: getLendTerms(){
    int Term;
    Term = 14;
    return Term;
}