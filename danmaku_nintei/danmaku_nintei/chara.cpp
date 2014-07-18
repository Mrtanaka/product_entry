#include "GV.h"

void calc_ch(){
    ch.cnt++;//�L�����N�^�J�E���g�A�b�v
    ch.img=(ch.cnt%24)/6;//���݂̉摜����
}

void calc_percent(){
	if(ch.percent > 100.0)//�Q�[�W��100%�𒴂��Ȃ�
		ch.percent = 100.0;
	if(ch.percent < 0){//�Q�[�W���s�����ꍇ�̏���
		ch.percent = 0;

		bdelete();//�S�Ă̒e������
		ch.flag=0;//���@������
		enemy.flag=0;//�G������

		se_flag[7] = 1;
		scount = count;
		count = 0;
		func_state = 4;//�Q�[���I�[�o�[��ʂ�
	}
}

//���v�B���x�̌v�Z
void calc_grade(){
	ch.grade = (count*100)/19800;

	if(ch.grade == 100){
		if(spell_flag == 0)
			spell++;
		se_flag[6] = 1;
		count = 0;
		func_state = 3;
	}
}

void ch_move(){
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    if(CheckStatePad(configpad.left)>0)//���L�[��������Ă�����
        ch.img+=4*2;//�摜����������
    else if(CheckStatePad(configpad.right)>0)//�E�L�[��������Ă�����
        ch.img+=4*1;//�摜���E������

    for(i=0;i<2;i++)//���E��
        if(inputpad[i]>0)//���E�ǂ��炩�̓��͂������
            sayu_flag=1;//���E���̓t���O�𗧂Ă�
    for(i=2;i<4;i++)//�㉺��
        if(inputpad[i]>0)//�㉺�ǂ��炩�̓��͂������
            joge_flag=1;//�㉺���̓t���O�𗧂Ă�
    if(sayu_flag==1 && joge_flag==1)//���E�A�㉺�����̓��͂�����Ύ΂߂��ƌ�����
        naname=sqrt(2.0);//�ړ��X�s�[�h��1/���[�g2��

    for(int i=0;i<4;i++){//4���������[�v
        if(inputpad[i]>0){//i�����̃L�[�{�[�h�A�p�b�h�ǂ��炩�̓��͂������
            x=ch.x , y=ch.y;//���̍��W���Ƃ肠����x,y�Ɋi�[
            mx=move_x[i];    my=move_y[i];//�ړ�����mx,my�ɑ��
            if(CheckStatePad(configpad.slow)>0 && ch.slow_flag==0){//�ᑬ�ړ��Ȃ�
                mx=move_x[i]/3;    my=move_y[i]/3;//�ړ��X�s�[�h��1/3��
            }
            x+=mx/naname , y+=my/naname;//���̍��W�ƈړ����𑫂�
            if(!(x<FX+10 || x>FX+FMX-10 || y<FY+10 || y>FY+FMY-10)){//�v�Z���ʈړ��\�͈͓��Ȃ�
                ch.x=x , ch.y=y;//���ۂɈړ�������
            }
        }
    }
}

void ch_main(){
	calc_ch();
	calc_percent();
	calc_grade();
	ch_move();
}