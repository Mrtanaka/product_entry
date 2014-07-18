#include "GV.h"

//�G�̓����蔻��͈�
int enemy_range = 16;

//�����蔻��
//�V���b�g�̍��W:1  ������𔻒肷�镨��:2
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;
    double x=x1-x2;//�G�Ǝ��@�V���b�g�Ƃ̋���
    double y=y1-y2;
    //�G�̓����蔻��Ǝ��@�V���b�g�̓����蔻��̍��v�͈�
    double r=range1+range2;
    //���Ԃ��v�Z����K�v�������
    if(spd1>r){
        //�P�t���[���O�ɂ����ʒu���i�[����
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;
        for(j=0;j<spd1/r;j++){//�i�񂾕��������蔻�蕪���[�v
            px=pre_x-x2;
            py=pre_y-y2;
            if(px*px+py*py<r*r)
                return 1;
            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }
    if(x*x+y*y<r*r)//�����蔻����Ȃ�
        return 1;//������
    return 0;
}

//���@�ƓG�V���b�g�������������ǂ����𔻒肷��
int out_judge_enemyshot(int n){
	if(bullet[n].cnt>0){//�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
		int knd = (bullet[n].state==5) ? 0 : bullet[n].knd;	//���\����

		if(type == 0){
			if(out_judge(
				bullet[n].x,bullet[n].y,ch.x,ch.y,
				bullet_info[knd].range,CRANGE-1.0,
				bullet[n].spd,bullet[n].angle
				)){
					return 1;
			}
		}
		else{
			if(out_judge(
				bullet[n].x,bullet[n].y,ch.x,ch.y,
				bullet_info[knd].range,CRANGE,
				bullet[n].spd,bullet[n].angle
				)){
					return 1;
			}
		}
	}
	return 0;
}

//���@�ƓG�V���b�g���O���C�Y���Ă��邩�ǂ����𔻒肷��
int out_graze_enemyshot(int n){
    if(bullet[n].cnt>0){//�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
		int knd = (bullet[n].state==5) ? 0 : bullet[n].knd;	//���\����

        if(out_judge(
            bullet[n].x,bullet[n].y,ch.x,ch.y,
            bullet_info[knd].range,CRANGE11,
            bullet[n].spd,bullet[n].angle
            )){
                return 1;
        }
    }
    return 0;
}

//���@�ƓG�������������ǂ����𔻒f����
int out_judge_enemy(){
	if(type == 0){
		if(out_judge(
			enemy.x,enemy.y,ch.x,ch.y,
			enemy_range,CRANGE-1.5,
			0,0
			)){
				return 1;
		}
	}
	else{
		if(out_judge(
			enemy.x,enemy.y,ch.x,ch.y,
			enemy_range,CRANGE,
			0,0
			)){
				return 1;
		}
	}
	return 0;
}

//�G�V���b�g�Ǝ��@�Ƃ̏���
void enemyshot_and_ch(){
	int n;
	double dif[5]={1.5,1.0,0.75,0.5,0.3};//�Q�[�W�񕜗ʂ̓�Փx�␳
	double typ[3]={1.0,1.5,1.0};	//�Q�[�W�񕜗ʂ̎��@�^�C�v�␳
	double dtyp[3]={1.0,0.8,1.0};	//���Q�[�W�����ʂ̎��@�^�C�v�␳

	if(ch.flag==1){
		for(n=0;n<BULLET_MAX;n++){//�e����
			if(bullet[n].flag==1){//�e���o�^����Ă�����
				double state = (bullet[n].state==3) ? 0.7 : 1.0;	//���C���_�[�E���@�_���Ȃǂ̃_���[�W�����␳
				state = (bullet[n].state==4)		? 1.3 : state;	//��e�Ȃǂ̃_���[�W�����␳

				if(out_judge_enemyshot(n)==1){//���@�ɂ��̒e���ڐG���Ă�����
					bullet[n].flag=0;//�e������
					spell_flag=1;	//�X�y���擾���s����
					if(ch.percent <= 30.0){
						ch.percent-=(4.0*state*dtyp[type]);	//���␳
						se_flag[10]=1;
					}
					else{
						ch.percent-=7.0*state;
						se_flag[1]=1;
					}
				}
				if(out_graze_enemyshot(n)==1){//���@�ɂ��̒e���O���C�Y���Ă�����
					if(bullet[n].gflag==0){
						ch.graze++;
							ch.percent+=(0.5*dif[stage]*typ[type]);
						se_flag[2]=1;
						bullet[n].gflag=1;
					}
				}
			}
		}
	}
}

//�G�Ǝ��@�Ƃ̏���
void enemy_and_ch(){
	if(ch.flag==1){
		if(enemy.flag!=0){
			if(out_judge_enemy()==1){
				ch.percent-=1.0;
				spell_flag=1;	//�X�y���擾���s����
				if(ch.percent <= 30.0)
					se_flag[10]=1;
				else
					se_flag[1]=1;
			}
		}
	}
}



//�����蔻�胁�C��
void out_main(){
    enemyshot_and_ch();//�G�V���b�g�Ǝ��@�Ƃ̏���
	enemy_and_ch();//�G�Ǝ��@�Ƃ̏���
}