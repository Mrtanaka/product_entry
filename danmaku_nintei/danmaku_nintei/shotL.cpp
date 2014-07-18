#include "GV.h"

//�ᑬ�΂�܂��e
void L0(){
	int t=spcount;
	int k;

	for(int i=0;i<5;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=PI2/10*t+PI2/50*i+rang(PI2/100);//�p�x
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
}

//Spell�P��ᑬ�΂�܂��e�
void shot_L0(){
	int t=spcount;

	if(t>=120){
		L0();

		if(t%8==0)
			se_flag[0]=1;
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<20){
				bullet[i].spd+=0.025;
			}
		}
	}
}

//�ᑬ�����e
void L1_0(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(30+rang(10))){
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
void L1_1(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(30+rang(10))){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =1;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=-2;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=i;//���W
			bullet[k].y		=150+rang(60);
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//���������e
void L1_2(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(40+rang(15))){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].state =2;
			bullet[k].angle	=0;//�p�x
			bullet[k].spd	=0;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=-3;//�������x
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=i;//���W
			bullet[k].y		=40+rang(30);
			bullet[k].col	=3;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
		}
	}
}

//Spell�Q��O�i�������e�
void shot_L1(){
	int t=spcount;

	if(t>=120){
		if((t-120)%40==0){
			L1_0();
		}

		if((t-120)%60==0){
			L1_1();
			se_flag[0]=1;
		}

		if((t-120)%80==0){
			L1_2();
		}
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<90){
				switch(bullet[i].state){
				case 0:
					bullet[i].vy+=0.03;
					break;
				case 1:
					bullet[i].vy+=0.065;
					break;
				case 2:
					bullet[i].vy+=0.1;
					break;
				}
			}
		}
	}
}

//�����O�̑S���ʒe
void L2(){
	int k;
	double angle=rang(PI);

	for(int j=0;j<2;j++){//�r������Q���􂷂镪
		for(int i=0;i<90;i++){
			if((k=shot_search())!=-1){
				bullet[k].knd    =8;//8�Ԃ̒e
				bullet[k].angle  =angle+PI2/90*i;
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
void shot_L2(){
	int t=spcount;

	if(t>=120){
		if(t<600){
			if(t%60==0){
				L2();
				se_flag[0]=1;
			}
		}

		else if(t<1200){
			if(t%50==0){
				L2();
				se_flag[0]=1;
			}
		}

		else if(t%40==0){
			L2();
			se_flag[0]=1;
		}
	}

	for(int i=0;i<BULLET_MAX;i++){//�S�e��
		if(bullet[i].flag>0){//�o�^����Ă���e�������
			if(30<bullet[i].cnt && bullet[i].cnt<120){//30�`120�J�E���g�Ȃ�
				bullet[i].spd-=1.5/90.0;//90�J�E���g������1.5���炷
				bullet[i].angle+=(PI/2)/90.0*(bullet[i].state?-1:1);//90�J�E���g������90���X����
			}
			if(bullet[i].cnt==120)
				bullet[i].state=3;	//�_���[�W�����␳
		}
	}
}

//�����΂�܂��e
void L3(){
	int t=spcount;
	int k;

	for(int i=0;i<3;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].angle	=PI2/10*t+PI2/30*i+rang(PI2/60);//�p�x
			bullet[k].spd	=3+rang(1);//�X�s�[�h
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
}

//Spell�S������΂�܂��e�
void shot_L3(){
	int t=spcount;

	if(t>=120){
		L3();

		if(t%8==0)
			se_flag[0]=1;
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<80){
				bullet[i].spd*=1.008;
			}
		}
	}
}

//��]���C���_�[
void L4_0(double ang){
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
void L4_1(){
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

//�t�������C���_�[
void L4_2(double ang2){
	int k;

	for(int i=0;i<10;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=4;
			bullet[k].angle	=ang2+((PI2/10)*i);//�p�x
			bullet[k].spd	=1.2;//�X�s�[�h
			bullet[k].vx	=0;
			bullet[k].vy	=0;
			bullet[k].flag	=1;//�t���O
			bullet[k].x		=enemy.x;//���W
			bullet[k].y		=enemy.y;
			bullet[k].col	=1;//�F
			bullet[k].cnt	=0;//�J�E���^
			bullet[k].gflag	=0;
			bullet[k].state	=0;
		}
	}
}

double L4_ang=0,L4_ang2=0;	//��]���C���_�[�p�p�x

//Spell�T���]���C���_�[�
void shot_L4(){
	int t=spcount;

	if(t>=120){
		if(t%2==0)
			L4_0(L4_ang);

		if(t%10==0)
			L4_1();

		if(t%60==0)
			L4_2(L4_ang2);

		if(t%8==0)
			se_flag[0]=1;

		L4_ang-=PI2/360;
		L4_ang2+=PI2/540;
	}
	else
		L4_ang=0,L4_ang2=0;
}

//���@�_��
void L5_0(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=6;
		bullet[k].angle	=shotatan2();//�p�x
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

//��؂΂�܂��e
void L5_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=11;
		bullet[k].angle	=rang(PI2);//�p�x
		bullet[k].spd	=0.8+rang(0.7);//�X�s�[�h
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
void shot_L5(){
	int t=spcount;

	if(t>=120){
		if(t%8==0)
			L5_0();

		L5_1();

		if(t%8==0)
			se_flag[0]=1;
	}
}

//��e�S���ʒe
void L6(){
	int k;
	double angle=rang(PI);

	for(int i=0;i<14;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=0;
			bullet[k].angle	=angle+PI2/14*i;//�p�x
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
void shot_L6(){
	int t=spcount;

	if(t>=120){
		if(t%22==0){
			L6();
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
				bullet[i].spd	=1;
				bullet[i].col	=0;
				bullet[i].state	=5;	//���\���艻
			}
		}
	}
}

//���E���C���_�[
void L7_0(double ang){
	int k;

	for(int i=0;i<12;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=6;
			bullet[k].angle	=ang+((PI2/12)*i);//�p�x
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

//��e���@�_��
void L7_1(){
	int k;

	for(int i=0;i<3;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=0;
			bullet[k].angle	=(shotatan2()-PI/4)+(PI/4*i);//�p�x
			bullet[k].spd	=2.5;//�X�s�[�h
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

//�����_������
void L7_2(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=1;
		bullet[k].angle	=0;//�p�x
		bullet[k].spd	=0;//�X�s�[�h
		bullet[k].vx	=rang(0.6);
		bullet[k].vy	=3+rang(1);
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=FX+(FMX/2)+rang(130);//���W
		bullet[k].y		=FY+10;
		bullet[k].col	=5;//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=0;
	}
}

double L7_ang=-PI/12,L7_vang=-PI/4/90;	//���E���C���_�[�p�p�x�E�p���x

//Spell�W����E���C���_�[�
void shot_L7(){
	int t=spcount;

	if(t>=120){
		if(t%3==0)
			L7_0(L7_ang);

		if(t%60==0)
			L7_1();

		if(t%5==0)
			L7_2();

		if(t%8==0)
			se_flag[0]=1;

		L7_ang+=L7_vang;
		if(L7_ang>=((PI/4)-(PI/12)) || L7_ang<=(-(PI/4)-(PI/12)))
			L7_vang=-L7_vang;
	}
	else
		L7_ang=-PI/12,L7_vang=-PI/4/90;
}

//�������̌Œ�e
void L8_0(int length,double speed,int joge){
	int k;

	for(int i = FX;i<=FX+FMX+10;i+=length){
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
void L8_1(int length,double speed,int sayu){
	int k;

	for(int i = FY;i<=FY+FMY+10;i+=length){
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

//spell�X��ᑬ�ړ��֎~���S���e�
void shot_L8(){
	int t = spcount;

	if(t>=120){
		if(t<1200){
			if((t-120)%60==0){
				L8_0(35,1.8,0);
				L8_1(35,1.5,0);
				se_flag[0]=1;
			}

			if((t-300)%240==0){
				se_flag[11]=1;
			}

			if((t-300)%240==60){
				for(int i=0;i < BULLET_MAX;i++){
					if(bullet[i].flag==1){
						bullet[i].knd=0;	//��e��
						bullet[i].state=4;	//�_���[�W�����␳
					}
				}
				se_flag[8]=1;
			}

			if((t-300)%240==120){
				for(int i=0;i < BULLET_MAX;i++){
					if(bullet[i].flag==1){
						bullet[i].knd=7;
						bullet[i].state=0;	//�␳����
					}
				}
			}
		}
		else{
			if(t==1200){
				bdelete();
				se_flag[8]=1;
			}

			if((t-1200)%45==0){
				L8_0(45,2.5,1);
				L8_1(45,2,1);
				se_flag[0]=1;
			}

			if((t-1260)%180==0){
				se_flag[11]=1;
			}

			if((t-1260)%180==60){
				for(int i=0;i < BULLET_MAX;i++){
					if(bullet[i].flag==1){
						bullet[i].knd=0;	//��e��
						bullet[i].state=4;	//�_���[�W�����␳
					}
				}
				se_flag[8]=1;
			}

			if((t-1260)%180==120){
				for(int i=0;i < BULLET_MAX;i++){
					if(bullet[i].flag==1){
						bullet[i].knd=7;
						bullet[i].state=0;	//�␳����
					}
				}
			}
		}
	}
}

//�g��̑S���ʒe
void L9(double x,double y){
	int k;
	double angle=rang(PI);

	for(int i=0;i<22;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=angle+PI2/22*i;//�p�x
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

int L9_state=0;	//�g�䔭�ˈʒu�ύX�e�[�u��

//���ˈʒu�ݒ���܂߂��g��̑S���ʒe
void L9_1(){
	switch(L9_state){
	case 0:
		L9(enemy.x-(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		L9_state=1;
		break;
	case 1:
		L9(enemy.x+(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		L9_state=2;
		break;
	case 2:
		L9(enemy.x-(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		L9_state=3;
		break;
	case 3:
		L9(enemy.x+(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		L9_state=0;
		break;
	}
}

//Spell�P�O��g�䎾���
void shot_L9(){
	int t=spcount;

	if(t>=120){
		if(t<600){
			if(t%40==0){
				L9_1();
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

		else if(t<1200){
			if(t%30==0){
				L9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.007;
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
			if(t%20==0){
				L9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.01;
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
		L9_state=0;
}