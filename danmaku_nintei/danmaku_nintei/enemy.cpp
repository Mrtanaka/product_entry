#include "GV.h"

//�s���p�^�[����extern�錾
extern void act0();	extern void act1();	extern void act2();

//�G�̍s������
void enemy_act(){
	if(enemy.flag!=0){//���̓G�̃t���O���I���ɂȂ��Ă���
		enemy.x+=cos(enemy.ang)*enemy.sp;
		enemy.y+=sin(enemy.ang)*enemy.sp;//�O�p�֐��ɂ��ړ�
		enemy.x+=enemy.vx;
		enemy.y+=enemy.vy;//��Ηʂɂ��ړ�
		enemy.cnt++;
        enemy.img=3+(enemy.cnt%18)/6;//6�t���[������3�p�^�[���ŃA�j���[�V����
	}
}

//�G�������C��
void enemy_main(){
    enemy_act();

	//���v�t���[���ˑ��ňړ��p�^�[���̕ύX
	if(count>=7960 && count<=8060)
		act1();

	else if(count>=9940 && count<=10040)
		act2();

	else if(count>=11920 && count<=12020)
		act1();

	else if(count>=13900 && count<=14000)
		act2();

	else
		act0();
}