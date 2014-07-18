#include "GV.h"

//�ᑬ�΂�܂��e
void N0(){
	int t=spcount;
	int k;

	for(int i=0;i<5;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=PI2/5*(t/2)+PI2/25*i+rang(PI2/50);//�p�x
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
void shot_N0(){
	int t=spcount;

	if(t>=120){
		if(t%2==0)
			N0();

		if(t%12==0)
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
void N1_0(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(30+rang(5))){
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
void N1_1(){
	int k;

	for(double i = FX;i<FX+FMX;i+=(40+rang(5))){
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
void shot_N1(){
	int t=spcount;

	if(t>=120){
		if((t-120)%60==0){
			N1_0();
			se_flag[0]=1;
		}

		if((t-120)%80==0){
			N1_1();
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
					bullet[i].vy+=0.07;
					break;
				}
			}
		}
	}
}

//�����O�̑S���ʒe
void N2(){
	int k;
	double angle=rang(PI);

	for(int j=0;j<2;j++){//�r������Q���􂷂镪
		for(int i=0;i<60;i++){
			if((k=shot_search())!=-1){
				bullet[k].knd    =8;//8�Ԃ̒e
				bullet[k].angle  =angle+PI2/60*i;
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
void shot_N2(){
	int t=spcount;

	if(t>=120){
		if(t<1200){
			if(t%60==0){
				N2();
				se_flag[0]=1;
			}
		}

		else{
			if(t%50==0){
				N2();
				se_flag[0]=1;
			}
		}
	}

	for(int i=0;i<BULLET_MAX;i++){//�S�e��
		if(bullet[i].flag>0){//�o�^����Ă���e�������
			if(30<bullet[i].cnt && bullet[i].cnt<120){//30�`120�J�E���g�Ȃ�
				bullet[i].spd-=1.6/90.0;//90�J�E���g������1.6���炷
				bullet[i].angle+=(PI/3)/90.0*(bullet[i].state?-1:1);//90�J�E���g������60���X����
			}
			if(bullet[i].cnt==120)
				bullet[i].state=3;	//�_���[�W�����␳
		}
	}
}

//�����΂�܂��e
void N3(){
	int t=spcount;
	int k;

	for(int i=0;i<5;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=7;
			bullet[k].angle	=PI2/5*(t/2)+PI2/25*i+rang(PI2/50);//�p�x
			bullet[k].spd	=2.6+rang(0.6);//�X�s�[�h
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
void shot_N3(){
	int t=spcount;

	if(t>=120){
		if(t%2==0)
			N3();

		if(t%12==0)
			se_flag[0]=1;
	}

	for(int i=0;i < BULLET_MAX;i++){
		if(bullet[i].flag==1){
			if(bullet[i].cnt<40){
				bullet[i].spd*=1.01;
			}
		}
	}
}

//��]���C���_�[
void N4_0(double ang){
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
void N4_1(){
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

double N4_ang=0;	//��]���C���_�[�p�p�x

//Spell�T���]���C���_�[�
void shot_N4(){
	int t=spcount;

	if(t>=120){
		if(t%3==0)
			N4_0(N4_ang);

		if(t%8==0)
			N4_1();

		if(t%12==0)
			se_flag[0]=1;

		N4_ang-=PI2/420;
	}
	else
		N4_ang=0;
}

//���@�_��
void N5_0(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=9;
		bullet[k].angle	=shotatan2();//�p�x
		bullet[k].spd	=2.8;//�X�s�[�h
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
void N5_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=11;
		bullet[k].angle	=rang(PI2);//�p�x
		bullet[k].spd	=0.6+rang(0.4);//�X�s�[�h
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
void shot_N5(){
	int t=spcount;

	if(t>=120){
		if(t%12==0)
			N5_0();

		if(t%2==0)
			N5_1();

		if(t%12==0)
			se_flag[0]=1;
	}
}

//��e�S���ʒe
void N6(){
	int k;
	double angle=rang(PI);

	for(int i=0;i<12;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=0;
			bullet[k].angle	=angle+PI2/12*i;//�p�x
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
void shot_N6(){
	int t=spcount;

	if(t>=120){
		if(t%30==0){
			N6();
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
void N7_0(double ang){
	int k;

	for(int i=0;i<12;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
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

//�����_������
void N7_1(){
	int k;

	if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
		bullet[k].knd	=1;
		bullet[k].angle	=0;//�p�x
		bullet[k].spd	=0;//�X�s�[�h
		bullet[k].vx	=rang(0.5);
		bullet[k].vy	=2+rang(0.5);
		bullet[k].flag	=1;//�t���O
		bullet[k].x		=FX+(FMX/2)+rang(130);//���W
		bullet[k].y		=FY+10;
		bullet[k].col	=5;//�F
		bullet[k].cnt	=0;//�J�E���^
		bullet[k].gflag	=0;
		bullet[k].state	=0;
	}
}

double N7_ang=-PI/12,N7_vang=-PI/4/90;	//���E���C���_�[�p�p�x�E�p���x

//Spell�W����E���C���_�[�
void shot_N7(){
	int t=spcount;

	if(t>=120){
		if(t%3==0)
			N7_0(N7_ang);

		if(t%8==0)
			N7_1();

		if(t%12==0)
			se_flag[0]=1;

		N7_ang+=N7_vang;
		if(N7_ang>=((PI/6)-(PI/12)) || N7_ang<=(-(PI/6)-(PI/12)))
			N7_vang=-N7_vang;
	}
	else
		N7_ang=-PI/12,N7_vang=-PI/4/90;
}

//�������̌Œ�e
void N8_0(int length,double speed,int joge){
	int k;

	for(double i=FX+rang(15);i<=FX+FMX+10;i+=length){
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
void N8_1(int length,double speed,int sayu){
	int k;

	for(double i=FY+rang(15);i<=FY+FMY+10;i+=length){
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
void shot_N8(){
	int t = spcount;

	if(t>=120){
		if(t<1200){
			if((t-120)%75==0){
				N8_1(30,2.1,0);
				N8_1(30,2.1,1);
				se_flag[0]=1;
			}
		}
		else{
			if(t==1200){
				bdelete();
				se_flag[8]=1;
			}

			if((t-1200)%55==0){
				N8_0(30,2.4,0);
				N8_0(30,2.4,1);
				se_flag[0]=1;
			}
		}
	}
}

//�g��̑S���ʒe
void N9(double x,double y){
	int k;
	double angle=rang(PI);

	for(int i=0;i<18;i++){
		if((k=shot_search())!=-1){//�e���o�^�\�Ȃ�
			bullet[k].knd	=8;
			bullet[k].angle	=angle+PI2/18*i;//�p�x
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

int N9_state=0;	//�g�䔭�ˈʒu�ύX�e�[�u��

//���ˈʒu�ݒ���܂߂��g��̑S���ʒe
void N9_1(){
	switch(N9_state){
	case 0:
		N9(enemy.x-(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		N9_state=1;
		break;
	case 1:
		N9(enemy.x+(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		N9_state=2;
		break;
	case 2:
		N9(enemy.x-(FMX/4)+rang(20),enemy.y+50+(rang(25)));
		N9_state=3;
		break;
	case 3:
		N9(enemy.x+(FMX/4)+rang(20),enemy.y-50+(rang(25)));
		N9_state=0;
		break;
	}
}

//Spell�P�O��g�䎾���
void shot_N9(){
	int t=spcount;

	if(t>=120){
		if(t<570){
			if(t%60==0){
				N9_1();
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

		else if(t<1100){
			if(t%40==0){
				N9_1();
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

		else{
			if(t%30==0){
				N9_1();
				se_flag[0]=1;
			}

			for(int i=0;i < BULLET_MAX;i++){
				if(bullet[i].flag==1){
					bullet[i].spd+=0.008;
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
		N9_state=0;
}