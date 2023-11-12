#include <iostream>

using namespace std;

//�X�^�b�N�Ɋւ���G���[��\����O�i��{�N���X�j
class stack_error{
    public:
        virtual const char* what(){
            return "stack error.";
        }
};

//�X�^�b�N���e�ʂ𒴂������Ƃ�\����O
class full_error : public stack_error{
    public:
        virtual const char* what(){
            return "stack error. stack is full!";
        }
};

//����̃X�^�b�N����l���擾���悤�Ƃ������Ƃ�\����O
class empty_error : public stack_error{
    public:
        virtual const char* what(){
            return "stack error. stack is empty";
        }
};

const int size = 3;

class stack{
    private:
        int buf[size]; //int�^�̗v�f���i�[����z��
        int sp; //�X�^�b�N�|�C���g
    public:
        stack(){sp = 0;} //�R���X�g���N�^
        void push(int element){
            if(sp ==size){
                full_error e;
                throw e; //�X�^�b�N�����t�̎���O�𓊂���
            }
            buf[sp++] = element;
        }
        int pop(){
            if(sp == 0){
                empty_error e;
                throw e; //�X�^�b�N����̎���O�𓊂���
            }
            return buf[--sp];
        }
};

int main(void){
    try{
        int i;
        stack s;
        //�l���R������
        s.push(1);
        s.push(2);
        s.push(3);

        //�l���S���o�����Ƃ���
        for(i=0; i<4; i++){
            cout << s.pop() << endl;
        }
    }catch(stack_error& e){
        cout << e.what() << endl;
    }catch(...){
        cout << "�V�X�e���G���[�������������A�h���}�C������������\n";
    }
    return 0;

}
