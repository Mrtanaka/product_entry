#include "GV.h"

//�ᑬ�΂�܂��e
void E0(){
	int t=spcount;
	int k;

		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=PI2/10*t+rang(PI2/20);//�p�x
			bullet[k].spd	=0.5;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=enemy.x;//���W
			bullet[k].y		=enemy.y;
			bullet[k].col	=GetRand(4);//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=0;
		}
}

//Spell�P��ᑬ�΂�܂��e�
void shot_E0(){
	int t=spcount;

	if(t>=120){
		E0();

		if(t%20==0)
			se_flag[0]=1;
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<20){
				bullet[i].spd+=0.02;
			}
		}
	}
}

//�ᑬ�����e
void E1_0(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(50+rang(5))){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =0;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=-1;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=i;//���W
			bullet[k].y		=200+rang(90);
			bullet[k].col	=0;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//���������e
void E1_1(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(60+rang(10))){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =1;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=-2;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=i;//���W
			bullet[k].y		=40+rang(30);
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//Spell�Q���i�������e�
void shot_E1(){
	int t=spcount;

	if(t>=120){
		if((t-120)%60==0){
			E1_0();
			se_flag[0]=1;
		}

		if((t-120)%120==0){
			E1_1();
		}
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<90){
				switch(bullet[i].state){//state�ɍ��킹�ė������x�̕ύX
				case 0:
					bullet[i].vy+=0.03;
					break;
				case 1:
					bullet[i].vy+=0.06;
					break;
				}
			}
		}
	}
}

//�����O�̑S���ʒe
void E2(){
	int k;
	double angle=rang(PI);

	for(int j=0;j<2;j++){//�r������Q���􂷂镪
		for(int i=0;i<30;i++){
			if((k=shot_search())!=-1){
				bullet[k].knd    =8;//8�Ԃ̒e
				bullet[k].angle  =angle+PI2/30*i;
				bullet[k].spd    =2.5;
				bullet[k].vx	=0;
				bullet[k].vy	=0;
				bullet[k].flag   =1;
				bullet[k].x      =enemy.x;
				bullet[k].y      =enemy.y;
				bullet[k].col    =1;
				bullet[k].cnt    =0;
				bullet[k].state  =j;//�X�e�[�^�X�B0��1���ŉ�]�������
				se_flag[0]=1;//���ˉ��炷
			}
		}
	}
}

//Spell�R������e�
void shot_E2(){
	int t=spcount;

	if(t>=120){
		if(t%70==0){
			E2();
			se_flag[0]=1;
		}
	}

	for(int i=0;i<BULLET_MAX;i++){//�S�e��
		if(bullet[i].flag>0){//�o�^����Ă���e�������
			if(30<bullet[i].cnt && bullet[i].cnt<120){//30�`120�J�E���g�Ȃ�
				bullet[i].spd-=1.7/90.0;//90�J�E���g������1.7���炷
				bullet[i].angle+=(PI/4)/90.0*(bullet[i].state?-1:1);//90�J�E���g������45���X����(state�ŕ���)
			}
			if(bullet[i].cnt==120)
				bullet[i].state=3;	//�_���[�W�����␳
		}
	}
}

//�����΂�܂��e
void E3(){
	int t=spcount;
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=7;
		bullet[k].angle	=PI2/10*t+rang(PI2/20);//�p�x
		bullet[k].spd	=2+rang(0.3);//�X�s�[�h
		bullet[k].vx	=0;
		bullet[k].vy	=0;
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=enemy.x;//���W
		bullet[k].y		=enemy.y;
		bullet[k].col	=GetRand(4);//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=0;
	}
}

//Spell�S������΂�܂��e�
void shot_E3(){
	int t=spcount;

	if(t>=120){
		E3();

		if(t%20==0)
			se_flag[0]=1;
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<20){//20�t���[���ԉ���
				bullet[i].spd*=1.01;
			}
		}
	}
}

//��]���C���_�[
void E4_0(double ang){
	int k;

	for(int i=0;i<6;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=ang+((PI2/6)*i);//�p�x
			bullet[k].spd	=4;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=enemy.x;//���W
			bullet[k].y		=enemy.y;
			bullet[k].col	=5;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=3;//�_���[�W�����␳
		}
	}
}

//��؂΂�܂��e
void E4_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=10;
		bullet[k].angle	=rang(PI2);//�p�x
		bullet[k].spd	=0.5;//�X�s�[�h
		bullet[k].vx	=0;
		bullet[k].vy	=0;
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=enemy.x;//���W
		bullet[k].y		=enemy.y;
		bullet[k].col	=0;//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=3;//�_���[�W�����␳
	}
}

double E4_ang=0;	//��]���C���_�[�p�p�x

//Spell�T���]���C���_�[�
void shot_E4(){
	int t=spcount;

	if(t>=120){
		if(t%4==0)
			E4_0(E4_ang);

		if(t%20==0)
			E4_1();

		if(t%20==0)
			se_flag[0]=1;

		E4_ang-=PI2/600;
	}
	else
		E4_ang=0;
}

//���@�_��
void E5_0(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=9;
		bullet[k].angle	=shotatan2();//�p�x
		bullet[k].spd	=2;//�X�s�[�h
		bullet[k].vx	=0;
		bullet[k].vy	=0;
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=enemy.x;//���W
		bullet[k].y		=enemy.y;
		bullet[k].col	=2;//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=3;//�_���[�W�����␳
	}
}

//��؂΂�܂��e
void E5_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=11;
		bullet[k].angle	=rang(PI2);//�p�x
		bullet[k].spd	=0.6+rang(0.2);//�X�s�[�h
		bullet[k].vx	=0;
		bullet[k].vy	=0;
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=enemy.x;//���W
		bullet[k].y		=enemy.y;
		bullet[k].col	=GetRand(5);//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=0;
	}
}

//Spell�U����@�_�������e�
void shot_E5(){
	int t=spcount;

	if(t>=120){
		if(t%30==0)
			E5_0();

		if(t%6==0)
			E5_1();
			
		if(t%20==0)
			se_flag[0]=1;
	}
}

//��e�S���ʒe
void E6(){
	int k;
	double angle=rang(PI);

	for(int i=0;i<8;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=0;
			bullet[k].angle	=angle+PI2/8*i;//�p�x
			bullet[k].spd	=5;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=enemy.x;//���W
			bullet[k].y		=enemy.y;
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=4;//�_���[�W�����␳
		}
	}
}

//Spell�V����\����e�
void shot_E6(){
	int t=spcount;

	if(t>=120){
		if(t%30==0){
			E6();
			se_flag[0]=1;
		}
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<60){
				bullet[i].spd-=0.08;
			}

			if(bullet[i].cnt==60){
				bullet[i].knd	=1;
				bullet[i].spd	=0.8;
				bullet[i].col	=0;
				bullet[i].state	=5;	//���\���艻
			}
		}
	}
}

//���E���C���_�[
void E7_0(double ang){
	int k;

	for(int i=0;i<8;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=ang+((PI2/8)*i);//�p�x
			bullet[k].spd	=4;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=enemy.x;//���W
			bullet[k].y		=enemy.y;
			bullet[k].col	=0;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=3;//�_���[�W�����␳
		}
	}
}

//�����_������
void E7_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=1;
		bullet[k].angle	=0;//�p�x
		bullet[k].spd	=0;//�X�s�[�h
		bullet[k].vx	=rang(0.1);
		bullet[k].vy	=1.5+rang(0.5);
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=FX+(FMX/2)+rang(130);//���W
		bullet[k].y		=FY+10;
		bullet[k].col	=5;//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=0;
	}
}

double E7_ang=-PI/8,E7_vang=-PI/4/180;	//���E���C���_�[�p�p�x�E�p���x

//Spell�W����E���C���_�[�
void shot_E7(){
	int t=spcount;

	if(t>=120){
		if(t%4==0)
			E7_0(E7_ang);

		if(t%20==0)
			E7_1();

		if(t%20==0)
			se_flag[0]=1;

		E7_ang+=E7_vang;
		if(E7_ang>=((PI/6)-(PI/8)) || E7_ang<=(-(PI/6)-(PI/8)))
			E7_vang=-E7_vang;
	}
	else
		E7_ang=-PI/8,E7_vang=-PI/4/180;
}

//�������̌Œ�e
void E8_0(int length,double speed,int joge){
	int k;

	for(double i = FX+rang(17.5);i<=FX+FMX+10;i+=length){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =0;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=(joge)? speed:-speed;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=i;//���W
			bullet[k].y		=(joge)? 0:480;
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//�c�����̌Œ�e
void E8_1(double length,double speed,int sayu){
	int k;

	for(double i = FY+rang(20);i<=FY+FMY+10;i+=length){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =0;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=(sayu)? speed:-speed;
			bullet[k].vy	=0;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=(sayu)? 0:FX+FMX+10;//���W
			bullet[k].y		=i;
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//spell�X����E���㉺�S���e�
void shot_E8(){
	int t = spcount;

	if(t>=120){
		if(t<1200){
			if((t-120)%80==0){
				E8_1(38,1.5,0);
				E8_1(38,1.5,1);
				se_flag[0]=1;
			}
		}
		else{
			if(t==1200){
				bdelete();
				se_flag[8]=1;
			}

			if((t-1200)%60==0){
				E8_0(43,2,0);
				E8_0(43,2,1);
				se_flag[0]=1;
			}
		}
	}
}

//�g��̑S���ʒe
void E9(double x,double y){
	int k;
	double angle=rang(PI);

	for(int i=0;i<14;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=angle+PI2/14*i;//�p�x
			bullet[k].spd	=2;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=x+15*cos(bullet[k].angle);//���W
			bullet[k].y		=y+15*sin(bullet[k].angle);
			bullet[k].col	=0;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=1;
		}
	}
}

int E9_state=0;	//�g�䔭�ˈʒu�ύX�e�[�u��

//���ˈʒu�ݒ���܂߂��g��̑S���ʒe
void E9_1(){
	switch(E9_state){
	case 0:
		E9(enemy.x-(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		E9_state=1;
		break;
	case 1:
		E9(enemy.x+(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		E9_state=2;
		break;
	case 2:
		E9(enemy.x-(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		E9_state=3;
		break;
	case 3:
		E9(enemy.x+(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		E9_state=0;
		break;
	}
}

//Spell�P�O��g�䎾���
void shot_E9(){
	int t=spcount;

	if(t>=120){
		if(t<600){
			if(t%90==0){
				E9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.002;
					if(bullet[i].y<FY && bullet[i].state==1){
						bullet[i].angle=-bullet[i].angle;
						bullet[i].state=0;
					}
					if(bullet[i].x<FX && bullet[i].state==1){
						bullet[i].angle=PI/2-(bullet[i].angle-PI/2);
						bullet[i].state=0;
					}
					if(bullet[i].x>FX+FMX && bullet[i].state==1){
						bullet[i].angle=PI/2+(PI/2-bullet[i].angle);
						bullet[i].state=0;
					}
				}
			}
		}

		else if(t<1200){
			if(t%75==0){
				E9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.003;
					if(bullet[i].y<FY && bullet[i].state==1){
						bullet[i].angle=-bullet[i].angle;
						bullet[i].state=0;
					}
					if(bullet[i].x<FX && bullet[i].state==1){
						bullet[i].angle=PI/2-(bullet[i].angle-PI/2);
						bullet[i].state=0;
					}
					if(bullet[i].x>FX+FMX && bullet[i].state==1){
						bullet[i].angle=PI/2+(PI/2-bullet[i].angle);
						bullet[i].state=0;
					}
				}
			}
		}

		else{
			if(t%60==0){
				E9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.005;
					if(bullet[i].y<FY && bullet[i].state==1){
						bullet[i].angle=-bullet[i].angle;
						bullet[i].state=0;
					}
					if(bullet[i].x<FX && bullet[i].state==1){
						bullet[i].angle=PI/2-(bullet[i].angle-PI/2);
						bullet[i].state=0;
					}
					if(bullet[i].x>FX+FMX && bullet[i].state==1){
						bullet[i].angle=PI/2+(PI/2-bullet[i].angle);
						bullet[i].state=0;
					}
				}
			}
		}
	}
	else
		E9_state=0;
}