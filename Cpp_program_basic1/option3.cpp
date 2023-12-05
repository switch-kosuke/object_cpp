#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

//�G���[�I�u�W�F�N�g�N���X
class InputError{
    private:
        char m_message[256];
    public:
        InputError(char* message){strcpy(m_message, message);}
        virtual char* what(){return m_message;}
};

class Lend {
    private:
        int m_no; //�}���ԍ�
        char* m_name; //�}����
        char m_issue[11]; //���s��
        int m_yearissue; //���s�N
        int m_monthissue; //���s��
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
            throw InputError("���t�̓��͂�����������܂���iyyyy/mm/dd�j");
        }
    }

    m_no = no;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    strcpy(m_issue, issue);

    //���s������N�ƌ���؂�o��
    char* buff;
    char buffissue[11];
    strcpy(buffissue, m_issue);
    buff = strtok(buffissue, "/"); //��؂蕪��
    m_yearissue = atoi(buff); //������𐔒l�ɕϊ�
    buff = strtok(NULL, "/");
    m_monthissue = atoi(buff);
}

//�f�X�g���N�^
Lend::~Lend(){
    delete [] m_name;
}

void Lend::getToday(int& year, int& month){
    time_t current;
    tm *local;
    time(&current);
    local = localtime(&current); //�n�����̍\���̂ɕϊ�

    year = local -> tm_year+1900;
    month = local -> tm_mon + 1;
}

//�}���N���X�̍쐬
class Publication : public Lend{
    char m_publisher[32];
    public:
        Publication(int no=0, char* name="", char* issue="", char* publisher="");
};

////////////////////////
//�}���N���X�̃R���X�g���N�^
Publication :: Publication(int no=0, char* name="", char* issue="", char* publisher=""):Lend(no, name, issue){
    if(strlen(publisher) > 30){
        throw InputError("�o�ŎЖ��̕������I�[�o�[�ł��i�R�O�����ȓ��j");
    }
    strcpy(m_publisher, publisher);
}

//���ЃN���X
class Book : public Publication{
    private:
        char m_author[32];
    public:
        Book(int no=0, char* name="", char* issue="", char* publisher="", char* auther="");
        int getLendTerms();
};

////////////////////////
//���Ђ̃R���X�g���N�^
Book::Book(int no=0, char* name="", char* issue="", char* publisher="", char* author=""):Publication(no, name, issue, publisher){
    if(strlen(author) > 30){
        throw InputError("���҂̕������I�[�o�[�ł��i�R�O�����ȓ��j");
    }
    strcpy(m_author, author);
}

//���Ђ̑ݏo���Ԃ̌v�Z
int Book::getLendTerms(){
    int Term;
    Term = 14;
    return Term;
}



//�G���N���X
class Magazine : public Publication{
    public:
        Magazine(int no=0, char* name="", char* issue="", char* publisher="");
        int getLendTerms();
};

//�G���N���X�̃R���X�g���N�^
Magazine::Magazine(int no, char* name, char* issue, char* publisher) : Publication(no, name, issue, publisher){}

//�G���̑ݏo���Ԃ̌v�Z
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

//�����o�����N���X
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
        throw InputError("�ē��̕������I�[�o�[�ł��i�R�O�����ȓ��j");
    }
    strcpy(m_director, director);
    m_minits = minits;
    
}

//�����o�����N���X�̑ݏo���Ԃ̌v�Z
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
        Lend* lends[3]; //�|�C���^�z��錾

        //�I�u�W�F�N�g����
        lends[0] = new Book(1, "�I�u�W�F�N�g�w������", "1999/05/01", "���{��", "�R�c�֕v");
        lends[1] = new Magazine(2, "VC�}�K�W��", "2003/10/01", "�Z�p��");
        lends[2] = new Video(3, "LIFE IS BEAUTIFUL", "1980/12/24", "Roberto", 117);

        //�ݏo���Ԃ̕\��
        for(i=0; i<3; i++){
            cout << lends[i] -> getName() << ":" << lends[i] -> getLendTerms() << "��" << endl;
        }

        for(i=0; i<3; i++){
            delete lends[i];
        }
    }catch(InputError& e){
        cout << e.what() << endl;
    }

    return 0;
}