#include "GV.h"

//�e���p�^�[����extern�錾
extern void shot_E0();extern void shot_E1();extern void shot_E2();extern void shot_E3();extern void shot_E4();
extern void shot_E5();extern void shot_E6();extern void shot_E7();extern void shot_E8();extern void shot_E9();
extern void shot_N0();extern void shot_N1();extern void shot_N2();extern void shot_N3();extern void shot_N4();
extern void shot_N5();extern void shot_N6();extern void shot_N7();extern void shot_N8();extern void shot_N9();
extern void shot_H0();extern void shot_H1();extern void shot_H2();extern void shot_H3();extern void shot_H4();
extern void shot_H5();extern void shot_H6();extern void shot_H7();extern void shot_H8();extern void shot_H9();
extern void shot_L0();extern void shot_L1();extern void shot_L2();extern void shot_L3();extern void shot_L4();
extern void shot_L5();extern void shot_L6();extern void shot_L7();extern void shot_L8();extern void shot_L9();
extern void shot_K0();extern void shot_K1();extern void shot_K2();extern void shot_K3();extern void shot_K4();
extern void shot_K5();extern void shot_K6();extern void shot_K7();extern void shot_K8();extern void shot_K9();

//�G�Ǝ��@�Ƃ̊p�x��Ԃ�
double shotatan2(){
	return atan2(ch.y-enemy.y,ch.x-enemy.x);
}

//�n���ꂽ-ang�`ang�܂ł̃����_���Ȑ��l��Ԃ�
double rang(double ang){
    return ( -ang + ang*2 * GetRand(10000)/10000.0 );
}

//�󂢂Ă���e��T��
int shot_search(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		if(bullet[i].flag==0){
			return i;
		}
	}
	return -1;
}

//��ʏ�̒e������
void bdelete(){
	int i;
	for(i=0;i<BULLET_MAX;i++)
		if(bullet[i].flag>0)
			bullet[i].flag=0;
}

//�X�y���I������
void spell_finish(){
	if(spell_flag == 0){//�擾���萬����
		spell++;
		sg_flag=1;
		se_flag[9]=1;
	}
	else{
		spell_flag=0;
		se_flag[8]=1;
	}
}

//�e���̌v�Z����
void shot_calc(){
	int i;
	for(i=0;i<BULLET_MAX;i++){//n�Ԗڂ̒e���f�[�^�̒e���v�Z
		if(bullet[i].flag>0){//���̒e���o�^����Ă�����
			bullet[i].x+=cos(bullet[i].angle)*bullet[i].spd;
			bullet[i].y+=sin(bullet[i].angle)*bullet[i].spd;//�O�p�֐��ł̌v�Z
			bullet[i].x+=bullet[i].vx;
			bullet[i].y+=bullet[i].vy;//�ړ��ʂł̌v�Z
			bullet[i].cnt++;
			if(bullet[i].x<-60 || bullet[i].x>FMX+60 ||
				bullet[i].y<-60 || bullet[i].y>FMY+60){//��ʊO�ɊO�ꂽ��
				if(bullet[i].till<bullet[i].cnt)//�Œ�����Ȃ����Ԃ�蒷�����
					bullet[i].flag=0;//����
			}
		}
	}
}

//�e���W�J�p�^�[��
void shot_pattern(){
	switch(stage){
		case 0://Easy
			if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
			   count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
				spcount=0;
				sg_flag=0;
				se_flag[5]=1;
			}

			if(count >= 180 && count < 1980){
				shot_E0();
			}
			if(count >= 2160 && count < 3960){
				shot_E1();
			}
			if(count >= 4140 && count < 5940){
				shot_E2();
			}
			if(count >= 6120 && count < 7920){
				shot_E3();
			}
			if(count >= 8100 && count < 9900){
				shot_E4();
			}
			if(count >= 10080 && count < 11880){
				shot_E5();
			}
			if(count >= 12060 && count < 13860){
				shot_E6();
			}
			if(count >= 14040 && count < 15840){
				shot_E7();
			}
			if(count >= 16020 && count < 17820){
				enemy.flag=0;
				shot_E8();
			}
			if(count == 17820){
				enemy.flag=1;
			}
			if(count >= 18000 && count < 19800){
				shot_E9();
			}
			
			break;

		case 1://Normal
			if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
			   count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
				spcount=0;
				sg_flag=0;
				se_flag[5]=1;
			}

			if(count >= 180 && count < 1980){
				shot_N0();
			}
			if(count >= 2160 && count < 3960){
				shot_N1();
			}
			if(count >= 4140 && count < 5940){
				shot_N2();
			}
			if(count >= 6120 && count < 7920){
				shot_N3();
			}
			if(count >= 8100 && count < 9900){
				shot_N4();
			}
			if(count >= 10080 && count < 11880){
				shot_N5();
			}
			if(count >= 12060 && count < 13860){
				shot_N6();
			}
			if(count >= 14040 && count < 15840){
				shot_N7();
			}
			if(count >= 16020 && count < 17820){
				enemy.flag=0;
				shot_N8();
			}
			if(count == 17820){
				enemy.flag=1;
			}
			if(count >= 18000 && count < 19800){
				shot_N9();
			}
			
			break;

		case 2://Hard
			if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
			   count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
				spcount=0;
				sg_flag=0;
				se_flag[5]=1;
			}

			if(count >= 180 && count < 1980){
				shot_H0();
			}
			if(count >= 2160 && count < 3960){
				shot_H1();
			}
			if(count >= 4140 && count < 5940){
				shot_H2();
			}
			if(count >= 6120 && count < 7920){
				shot_H3();
			}
			if(count >= 8100 && count < 9900){
				shot_H4();
			}
			if(count >= 10080 && count < 11880){
				shot_H5();
			}
			if(count >= 12060 && count < 13860){
				shot_H6();
			}
			if(count >= 14040 && count < 15840){
				shot_H7();
			}
			if(count >= 16020 && count < 17820){
				ch.slow_flag=1;	//�ᑬ�ړ��̋֎~
				enemy.flag=0;
				shot_H8();
			}
			if(count == 17820){
				ch.slow_flag=0;	//�ᑬ�ړ��֎~�̉���
				enemy.flag=1;
			}
			if(count >= 18000 && count < 19800){
				shot_H9();
			}

			break;

		case 3://Lunatic
			if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
			   count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
				spcount=0;
				sg_flag=0;
				se_flag[5]=1;
			}

			if(count >= 180 && count < 1980){
				shot_L0();
			}
			if(count >= 2160 && count < 3960){
				shot_L1();
			}
			if(count >= 4140 && count < 5940){
				shot_L2();
			}
			if(count >= 6120 && count < 7920){
				shot_L3();
			}
			if(count >= 8100 && count < 9900){
				shot_L4();
			}
			if(count >= 10080 && count < 11880){
				shot_L5();
			}
			if(count >= 12060 && count < 13860){
				shot_L6();
			}
			if(count >= 14040 && count < 15840){
				shot_L7();
			}
			if(count >= 16020 && count < 17820){
				ch.slow_flag=1;	//�ᑬ�ړ��̋֎~
				enemy.flag=0;
				shot_L8();
			}
			if(count == 17820){
				ch.slow_flag=0;	//�ᑬ�ړ��֎~�̉���
				enemy.flag=1;
			}
			if(count >= 18000 && count < 19800){
				shot_L9();
			}
			
			break;

		case 4://�F�`
			if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
				count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
					spcount=0;
					sg_flag=0;
					se_flag[5]=1;
			}

			if(count >= 180 && count < 1980){
				shot_K0();
			}
			if(count >= 2160 && count < 3960){
				shot_K1();
			}
			if(count >= 4140 && count < 5940){
				shot_K2();
			}
			if(count >= 6120 && count < 7920){
				shot_K3();
			}
			if(count >= 8100 && count < 9900){
				shot_K4();
			}
			if(count >= 10080 && count < 11880){
				shot_K5();
			}
			if(count >= 12060 && count < 13860){
				shot_K6();
			}
			if(count >= 14040 && count < 15840){
				shot_K7();
			}
			if(count >= 16020 && count < 17820){
				ch.slow_flag=1;	//�ᑬ�ړ��̋֎~
				enemy.flag=0;
				shot_K8();
			}
			if(count == 17820){
				ch.slow_flag=0;	//�ᑬ�ړ��֎~�̉���
				enemy.flag=1;
			}
			if(count >= 18000 && count < 19800){
				shot_K9();
			}

			break;
	}

	if(spcount == 1800){//�X�y���I������
		spell_finish();
		bdelete();
	}

	if(spcount >= 1260 && spcount < 1800 && spcount % 60 == 0)//�e���J�E���g
		se_flag[4]=1;

	spcount++;
}

void shot_main(){
	shot_calc();
	shot_pattern();
}