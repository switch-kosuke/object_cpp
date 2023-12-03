#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

//エラーオブジェクトクラス
class InputError{
    private:
        char m_message[256];
    public:
        InputError(char* message){strcpy(m_message, message);}
        virtual char* what(){return m_message;}
};

class Lend {
    private:
        int m_no; //図書番号
        char* m_name; //図書名
        char m_issue[11]; //発行日
        int m_yearissue; //発行年
        int m_monthissue; //発行月
    public:
        Lend(int no=0, char* name="", char* issue="");
        virtual ~Lend();
        char* getName(){return m_name;};
        int getIssueYear(){return m_yearissue;};
        int getIssueMonth(){return m_monthissue;};
        void getToday(int&, int&);
        virtual int getLendTerms()=0;
};

////////////////////////
Lend::Lend(int no, char* name, char* issue){
    int i;
    for(i=0; i<strlen(issue); i++){
        int num;
        num = issue[i] - '0';
        if(((num < 0) || (9 < num)) && (issue[i] != '/')){
            throw InputError("日付の入力が正しくありません（yyyy/mm/dd）");
        }
    }

    m_no = no;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    strcpy(m_issue, issue);

    //発行日から年と月を切り出す
    char* buff;
    char buffissue[11];
    strcpy(buffissue, m_issue);
    buff = strtok(buffissue, "/"); //区切り分割
    m_yearissue = atoi(buff); //文字列を数値に変換
    buff = strtok(NULL, "/");
    m_monthissue = atoi(buff);
}

//デストラクタ
Lend::~Lend(){
    delete [] m_name;
}

void Lend::getToday(int& year, int& month){
    time_t current;
    tm *local;
    time(&current);
    local = localtime(&current); //地方時の構造体に変換

    year = local -> tm_year+1900;
    month = local -> tm_mon + 1;
}

//図書クラスの作成
class Publication : public Lend{
    char m_publisher[32];
    public:
        Publication(int no=0, char* name="", char* issue="", char* publisher="");
};

////////////////////////
//図書クラスのコンストラクタ
Publication :: Publication(int no=0, char* name="", char* issue="", char* publisher=""):Lend(no, name, issue){
    if(strlen(publisher) > 30){
        throw InputError("出版社名の文字数オーバーです（３０文字以内）");
    }
    strcpy(m_publisher, publisher);
}

//書籍クラス
class Book : public Publication{
    private:
        char m_author[32];
    public:
        Book(int no=0, char* name="", char* issue="", char* publisher="", char* auther="");
        int getLendTerms();
};

////////////////////////
//書籍のコンストラクタ
Book::Book(int no=0, char* name="", char* issue="", char* publisher="", char* author=""):Publication(no, name, issue, publisher){
    if(strlen(author) > 30){
        throw InputError("著者の文字数オーバーです（３０文字以内）");
    }
    strcpy(m_author, author);
}

//書籍の貸出期間の計算
int Book::getLendTerms(){
    int Term;
    Term = 14;
    return Term;
}



//雑誌クラス
class Magazine : public Publication{
    public:
        Magazine(int no=0, char* name="", char* issue="", char* publisher="");
        int getLendTerms();
};

//雑誌クラスのコンストラクタ
Magazine::Magazine(int no, char* name, char* issue, char* publisher) : Publication(no, name, issue, publisher){}

//雑誌の貸出期間の計算
int Magazine::getLendTerms(){
    int Year, Month, Term;
    getToday(Year, Month);

    if((getIssueYear()==Year) && (getIssueMonth() == Month)){
        Term = 7;
    }else{
        Term = 14;
    }
    return Term;
}

//視聴覚資料クラス
class Video : public Lend{
    private:
        char m_director[32];
        int m_minits;
    public:
        Video(int no, char* name, char* issue, char* director, int minits);
        int getLendTerms();
};

Video::Video(int no, char* name, char* issue, char* director, int minits):Lend(no, name, issue){
    if(strlen(director) > 30){
        throw InputError("監督名の文字数オーバーです（３０文字以内）");
    }
    strcpy(m_director, director);
    m_minits = minits;
    
}

//視聴覚資料クラスの貸出期間の計算
int Video::getLendTerms(){
    int Year, Month, Term;
    getToday(Year, Month);
    if((getIssueYear() == Year) && (getIssueMonth() == Month)){
        Term = 2;
    }else{
        Term = 7;
    }
    return Term;
}



int main(void){
    int i;

    try{
        Lend* lends[3]; //ポインタ配列宣言

        //オブジェクト生成
        lends[0] = new Book(1, "オブジェクト指向入門", "1999/05/01", "小本社", "山田敦夫");
        lends[1] = new Magazine(2, "VCマガジン", "2003/10/01", "技術社");
        lends[2] = new Video(3, "LIFE IS BEAUTIFUL", "1980/12/24", "Roberto", 117);

        //貸出期間の表示
        for(i=0; i<3; i++){
            cout << lends[i] -> getName() << ":" << lends[i] -> getLendTerms() << "日" << endl;
        }

        for(i=0; i<3; i++){
            delete lends[i];
        }
    }catch(InputError& e){
        cout << e.what() << endl;
    }

    return 0;
}