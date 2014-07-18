#include "GV.h"

extern void draw_fps(int,int);

int DrawRotaGraphF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
	return DrawRotaGraphF((float)xd,(float)yd,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}
int DrawModiGraphF( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int GrHandle, int TransFlag ){
	return DrawModiGraphF( (float)x1, (float)y1, (float)x2, (float)y2, (float)x3, (float)y3, (float)x4, (float)y4, GrHandle, TransFlag ) ;
}

//���@�`��
void graph_ch(){
	if(ch.flag!=0){
		DrawRotaGraphF(ch.x,ch.y,1.0f,0.0f,img_ch[ch.img],TRUE);
		if(CheckStatePad(configpad.slow)>0 && ch.slow_flag==0){ //�ᑬ�ړ����Ȃ瓖���蔻��\��
			DrawRotaGraphF( ch.x, ch.y, 1.0f, 2.0*PI*(count%120)/120, img_etc[0], TRUE );
		}
	}
}

//�G�̕`��
void graph_enemy(){
	if(enemy.flag != 0){
		DrawRotaGraphF( enemy.x, enemy.y, 1.0f, 0.0f, img_enemy[enemy.img], TRUE );
	}
}

//�e�ۂ̕`��
void graph_bullet(){
	int j;
	double disp_angle;
	SetDrawMode( DX_DRAWMODE_BILINEAR );//���`�⊮�`��
	for(j=0;j<BULLET_MAX;j++){//���̒e�������e�̍ő吔�����[�v
		if(bullet[j].flag!=0){//�e�f�[�^���I���Ȃ�
			disp_angle=bullet[j].angle+PI/2;

			DrawRotaGraphF(bullet[j].x, bullet[j].y, 1.0, disp_angle,
				img_bullet[bullet[j].knd][bullet[j].col],TRUE);
		}
	}
}

//�X�R�A�{�[�h�\��
void graph_board_states(){
	int i;
	int graze=ch.graze;
	int percent=int(ch.percent);
	int grade=ch.grade;

	switch(stage){
		case 0:
			DrawFormatString(505,12,color[0],"EASY");
			break;
		case 1:
			DrawFormatString(500,12,color[3],"NORMAL");
			break;
		case 2:
			DrawFormatString(505,12,color[2],"HARD");
			break;
		case 3:
			DrawFormatString(495,12,color[7],"LUNATIC");
			break;
		case 4:
			DrawFormatString(505,12,color[0],"�F�`");
	}

	DrawFormatString(425,42,color[0],"Graze");
	DrawFormatString(425,72,color[0],"�B���x");
	DrawFormatString(545,72,color[0],"��");

	DrawFormatString(480,122,color[0],"TYPE");
	switch(type){
		case 0:
			DrawFormatString(525,122,color[0],"A");
			break;
		case 1:
			DrawFormatString(525,122,color[0],"B");
			break;
		case 2:
			DrawFormatString(525,122,color[0],"C");
			break;
	}

	DrawFormatString(425,172,color[0],"�F��Q�[�W");
	DrawFormatString(575,172,color[0],"��");
	
	for(i=0;i<4;i++){//�O���C�Y�\��
		DrawRotaGraph(550-15*i,50,1.0f,0.0f,img_num[graze%10],TRUE);
		graze/=10;
	}
	
	for(i=0;i<3;i++){ //���v�B���x�\��
		DrawRotaGraph(535-15*i,80,1.0f,0.0f,img_num[grade%10],TRUE);
		grade/=10;
	}

	for(i=0;i<3;i++){ //�i�ʃQ�[�W�\��
		DrawRotaGraph(565-15*i,180,1.0f,0.0f,img_num[percent%10],TRUE);
		percent/=10;
	}
	
	DrawStringToHandle(445,230,"�e��",color[0],font[3]);
	DrawStringToHandle(470,305,"�i��",color[0],font[3]);
	DrawStringToHandle(495,380,"�F��",color[0],font[3]);
}

//�{�[�h�`��
void graph_board(){
	DrawGraph(	0,	0,img_board[0],FALSE);
	DrawGraph(	0, 16,img_board[1],FALSE);
	DrawGraph(	0,464,img_board[2],FALSE);
	DrawGraph(416,	0,img_board[3],FALSE);
}

//�^�C�g���w�i�`��
void graph_back(){
	DrawGraph(	0,	0,img_board[4],FALSE);
}

//�X�y�������E�c�莞�Ԃ̕`��
void graph_cut(char *string,int length){//�X�y�����A�������̒���
	int t = spcount;

	if(t >= 0 && t < 100){
		DrawStringToHandle(100,215,string,color[0],font[0]);
		DrawLine(100,232,100+length,232,color[2]);
	}

	else{
		DrawStringToHandle(FX,FY,string,color[0],font[0]);
		DrawLine(FX,FY+17,FX+length,FY+17,color[2]);
	}

	DrawFormatStringToHandle(395,FY,color[0],font[0],"%d",(1860-spcount)/60);
}

//�X�y�������\���p�^�[���̕`��
void graph_spell(){
	if(count == 180	  || count == 2160	|| count == 4140  || count == 6120  || count == 8100 ||
		count == 10080 || count == 12060 || count == 14040 || count == 16020 || count == 18000){
			spcount=0;
			se_flag[5]=1;
	}

	if(count >= 180 && count < 1980){
		graph_cut("Spell�P��ᑬ�΂�܂��e�",215);
	}
	if(count >= 2160 && count < 3960){
		if(stage<=1)
			graph_cut("Spell�Q���i�������e�",195);
		else
			graph_cut("Spell�Q��O�i�������e�",195);
	}
	if(count >= 4140 && count < 5940){
		graph_cut("Spell�R������e�",140);
	}
	if(count >= 6120 && count < 7920){
		graph_cut("Spell�S������΂�܂��e�",215);
	}
	if(count >= 8100 && count < 9900){
		graph_cut("Spell�T���]���C���_�[�",215);
	}
	if(count >= 10080 && count < 11880){
		graph_cut("Spell�U����@�_�������e�",215);
	}
	if(count >= 12060 && count < 13860){
		if(stage<=3)
			graph_cut("Spell�V����\����e�",175);
		else
			graph_cut("Spell�V���e���ʎE���",195);
	}
	if(count >= 14040 && count < 15840){
		graph_cut("Spell�W����E���C���_�[�",215);
	}
	if(count >= 16020 && count < 17820){
		if(stage<=1)
			graph_cut("Spell�X����E���㉺�S���e�",235);
		else
			graph_cut("Spell�X��ᑬ�ړ��֎~���S���e�",275);

	}
	if(count >= 18000 && count < 19800){
		graph_cut("spell�P�O��g�䎾���",175);
	}

	if(count>=30 && count<180){
		DrawStringToHandle(135,185,"����e����",color[0],font[1]);
		DrawStringToHandle(120,225,"����������I",color[0],font[1]);
	}
	if(spcount>=1800 && sg_flag==1)
		DrawStringToHandle(55,185,"Get Spell Bonus!!",color[0],font[1]);
}

void graph_main(){
	graph_enemy();//�G�̕`��
	graph_ch();//���@�̕`��
	graph_bullet();//�e�̕`��
	graph_board();//�{�[�h�̕`��
	graph_board_states();//�{�[�h���̕`��
	draw_fps(620,465);//fps�`��
	graph_spell();//�X�y�������̕`��
}

void graph_title(){
	graph_back();

	DrawStringToHandle(140,120,"�e���i�ʔF��",color[0],font[3]);
	DrawStringToHandle(270,240,"START",color[0],font[1]);
	DrawStringToHandle(220,290,"KEY CONFIG",color[0],font[1]);
	DrawStringToHandle(260,340,"MANUAL",color[0],font[1]);
	DrawStringToHandle(280,390,"QUIT",color[0],font[1]);
	DrawStringToHandle(175,240+(menu_state*50),"��",color[0],font[1]);

	switch(menu_state){
		case 0:
			DrawStringToHandle(255,450,"�Q�[�����J�n���܂�",color[0],font[2]);
			break;
		case 1:
			DrawStringToHandle(190,450,"�p�b�h�̊e��{�^���ݒ��ύX���܂�",color[0],font[2]);
			break;
		case 2:
			DrawStringToHandle(165,450,"�Q�[���̃��[���⑀����@�Ȃǂ�\�����܂�",color[0],font[2]);
			break;
		case 3:
			DrawStringToHandle(255,450,"�Q�[�����I�����܂�",color[0],font[2]);
			break;
	}
}

void graph_pause(){
	graph_board();//�{�[�h�̕`��
	graph_board_states();//�{�[�h���̕`��
	draw_fps(620,465);//fps�`��

	DrawStringToHandle(170,120,"PAUSE",color[0],font[1]);
	DrawStringToHandle(160,240,"�Q�[���𑱂���",color[0],font[0]);
	DrawStringToHandle(160,280,"�^�C�g���ɖ߂�",color[0],font[0]);
	DrawStringToHandle(160,320,"�ŏ�����n�߂�",color[0],font[0]);
	DrawStringToHandle(140,240+(menu_state*40),"��",color[0],font[0]);
}

void graph_result(){
	graph_board();//�{�[�h�̕`��

	if(count >= 120){
		if(func_state == 3)
			DrawStringToHandle(170,80,"CLEAR",color[0],font[1]);
		else
			DrawStringToHandle(140,80,"GAME OVER",color[0],font[1]);

		DrawStringToHandle(125,160,"��Փx",color[0],font[0]);
		switch(stage){
			case 0:
				DrawStringToHandle(295,160,"EASY",color[0],font[0]);
				break;
			case 1:
				DrawStringToHandle(290,160,"NORMAL",color[3],font[0]);
				break;
			case 2:
				DrawStringToHandle(295,160,"HARD",color[2],font[0]);
				break;
			case 3:
				DrawStringToHandle(275,160,"LUNATIC",color[7],font[0]);
				break;
			case 4:
				DrawStringToHandle(295,160,"�F�`",color[0],font[0]);
		}
	}

	if(count >= 180){
		DrawStringToHandle(125,190,"�O���C�Y��",color[0],font[0]);
		DrawFormatStringToHandle(290,190,color[0],font[0],"%d",ch.graze);
		DrawStringToHandle(330,190,"��",color[0],font[0]);
	}

	if(count >= 240){
		DrawStringToHandle(125,220,"�X�y���擾��",color[0],font[0]);
		DrawFormatStringToHandle(310,220,color[0],font[0],"%d",spell);
		DrawStringToHandle(330,220,"��",color[0],font[0]);
	}

	if(count >= 300){
		DrawStringToHandle(125,250,"�����B���x",color[0],font[0]);
		if(func_state == 3){
			int dif[4]={1,3,6,10};//�O���C�Y�{�[�i�X�̓�Փx�ʊ
			int grb = (ch.graze/dif[stage] < 200)? ch.graze/dif[stage]:200;//�O���C�Y�{�[�i�X

			ch.grade = int(100 + ((spell*20)+grb)*(ch.percent/100));
		}
		else
			ch.grade = (scount*100)/19800;
		DrawFormatStringToHandle(300,250,color[0],font[0],"%d",ch.grade);
		DrawFormatStringToHandle(330,250,color[0],font[0],"��");

		DrawStringToHandle(125,295,"�����N",color[0],font[0]);
		if(type == 2){
			if(ch.grade >= 250){
				DrawFormatStringToHandle(260,285,color[5],font[1],"AAA+");
			}
			else if(ch.grade >= 200){
				DrawFormatStringToHandle(275,285,color[5],font[1],"AAA");
			}
			else if(ch.grade >= 140){
				DrawFormatStringToHandle(290,285,color[5],font[1],"AA");
			}
			else if(ch.grade >= 100){
				DrawFormatStringToHandle(305,285,color[5],font[1],"A");
			}
			else if(ch.grade >= 60){
				DrawFormatStringToHandle(305,285,color[4],font[1],"B");
			}
			else if(ch.grade >= 30){
				DrawFormatStringToHandle(305,285,color[7],font[1],"C");
			}
			else{
				DrawFormatStringToHandle(305,285,color[0],font[1],"D");
			}
		}
		else{
			if(ch.grade >= 210){
				DrawFormatStringToHandle(275,285,color[5],font[1],"AAA");
			}
			else if(ch.grade >= 150){
				DrawFormatStringToHandle(290,285,color[5],font[1],"AA");
			}
			else if(ch.grade >= 100){
				DrawFormatStringToHandle(305,285,color[5],font[1],"A");
			}
			else if(ch.grade >= 70){
				DrawFormatStringToHandle(305,285,color[4],font[1],"B");
			}
			else if(ch.grade >= 40){
				DrawFormatStringToHandle(305,285,color[7],font[1],"C");
			}
			else{
				DrawFormatStringToHandle(305,285,color[0],font[1],"D");
			}
		}
	}

	if(count >= 330){
		DrawStringToHandle(155,370,"������x���킷��",color[0],font[0]);
		DrawStringToHandle(160,410,"�^�C�g���ɖ߂�",color[0],font[0]);
		DrawStringToHandle(140,370+(menu_state*40),"��",color[0],font[0]);

		if(ch.grade>=100.0){
			switch(stage){
			case 0:
				DrawStringToHandle(475,190,"EASY�N���A",color[0],font[0]);
				DrawStringToHandle(470,210,"���߂łƂ��I",color[0],font[0]);
				DrawStringToHandle(470,260,"����Ă�����",color[0],font[0]);
				DrawStringToHandle(480,280,"NORMAL�ɂ�",color[0],font[0]);
				DrawStringToHandle(455,300,"���킵�Ă݂悤�I",color[0],font[0]);
				break;
			case 1:
				DrawStringToHandle(465,190,"NORMAL�N���A",color[0],font[0]);
				DrawStringToHandle(470,210,"���߂łƂ��I",color[0],font[0]);
				DrawStringToHandle(460,260,"�]�T������Ȃ�",color[0],font[0]);
				DrawStringToHandle(470,280,"HARD�N���A��",color[0],font[0]);
				DrawStringToHandle(455,300,"�ڎw���Ă݂悤�I",color[0],font[0]);
				break;
			case 2:
				DrawStringToHandle(480,190,"HARD�N���A",color[0],font[0]);
				DrawStringToHandle(475,210,"���߂łƂ��I",color[0],font[0]);
				DrawStringToHandle(445,260,"�Ȃ��Ȃ����܂���",color[0],font[0]);
				DrawStringToHandle(455,280,"�M����LUNATIC��",color[0],font[0]);
				DrawStringToHandle(455,300,"�U���ł��邩�ȁH",color[0],font[0]);
				break;
			case 3:
				DrawStringToHandle(460,190,"LUNATIC�N���A",color[0],font[0]);
				DrawStringToHandle(470,210,"���߂łƂ��I",color[0],font[0]);
				DrawStringToHandle(450,260,"��Փx�I����ʂ�",color[0],font[0]);
				DrawStringToHandle(460,280,"L�L�[��R�L�[��",color[0],font[0]);
				DrawStringToHandle(430,300,"1�b�ԉ���������Ɓc�H",color[0],font[0]);
				break;
			case 4:
				DrawStringToHandle(475,190,"�F�`�N���A",color[0],font[0]);
				DrawStringToHandle(470,210,"���߂łƂ��I",color[0],font[0]);
				DrawStringToHandle(480,260,"�����M���A",color[0],font[0]);
				DrawStringToHandle(425,280,"�l�Ԃ���Ȃ��ł��傤�H",color[0],font[0]);
				break;
			}
		}
	}
}

void graph_difficult(){
	graph_back();

	DrawStringToHandle(140,120,"�e���i�ʔF��",color[0],font[3]);
	DrawStringToHandle(280,250,"EASY",color[0],font[1]);
	DrawStringToHandle(260,290,"NORMAL",color[3],font[1]);
	DrawStringToHandle(280,330,"HARD",color[2],font[1]);
	DrawStringToHandle(250,370,"LUNATIC",color[7],font[1]);
	DrawStringToHandle(210,250+(menu_state*40),"��",color[0],font[1]);
	
	switch(menu_state){
		case 0:
			DrawStringToHandle(90,450,"��ɗD������Փx�ł��BSTG�����E��������ƂȂ��l�͂�����B",color[0],font[2]);
			break;
		case 1:
			DrawStringToHandle(75,450,"��r�I�Ղ�����Փx�ł��B�m�[�}���V���[�^�[�Ȃ�Ȃ�Ƃ��Ȃ�͂��B",color[0],font[2]);
			break;
		case 2:
			DrawStringToHandle(100,450,"�������������Փx�ł��B�񐔂����Ȃ��΂Ȃ�Ƃ��Ȃ�͂��B",color[0],font[2]);
			break;
		case 3:
			DrawStringToHandle(50,450,"�{�C�ȓ�Փx�ł��B�o���o���̃V���[�^�[����͍������N��_���܂��傤�B",color[0],font[2]);
			break;
	}
}

void graph_type(){
	graph_back();

	DrawStringToHandle(140,120,"�e���i�ʔF��",color[0],font[3]);
	DrawStringToHandle(265,270,"TYPE A",color[0],font[1]);
	DrawStringToHandle(265,310,"TYPE B",color[0],font[1]);
	DrawStringToHandle(265,350,"TYPE C",color[0],font[1]);
	DrawStringToHandle(225,270+(menu_state*40),"��",color[0],font[1]);
	
	switch(menu_state){
		case 0:
			DrawStringToHandle(170,450,"���@�̓����蔻�肪�����������Ȃ�܂�",color[0],font[2]);
			break;
		case 1:
			DrawStringToHandle(60,450,"�O���C�Y���̃Q�[�W�񕜗ʁE�s���`���̃Q�[�W�����ʂɕ␳��������܂�",color[0],font[2]);
			break;
		case 2:
			DrawStringToHandle(10,450,"�ǂ���̃{�[�i�X���󂯂��Ȃ�����ɍ������N�����₷���Ȃ�܂��B�㋉�Ҍ���",color[0],font[2]);
			break;
	}
}

void graph_key(){
	graph_back();

	DrawStringToHandle(140,120,"�e���i�ʔF��",color[0],font[3]);

	DrawStringToHandle(245,240,"����",color[0],font[1]);
	DrawFormatStringToHandle(390,240,color[0],font[1],"%d",configpad.shot);

	DrawStringToHandle(190,280,"�L�����Z��",color[0],font[1]);
	DrawFormatStringToHandle(390,280,color[0],font[1],"%d",configpad.bom);

	DrawStringToHandle(205,320,"�ᑬ�ړ�",color[0],font[1]);
	DrawFormatStringToHandle(390,320,color[0],font[1],"%d",configpad.slow);

	DrawStringToHandle(225,360,"�|�[�Y",color[0],font[1]);
	DrawFormatStringToHandle(390,360,color[0],font[1],"%d",configpad.start);

	DrawStringToHandle(180,410,"�^�C�g���ɖ߂�",color[0],font[1]);
	DrawStringToHandle(140,240+(menu_state*40),"��",color[0],font[1]);
}

void graph_manual(){
	graph_back();

	switch(menu_state){
		case 0:
			DrawStringToHandle(200,40,"���̃Q�[����",color[0],font[1]);
			DrawStringToHandle(25,120,"���̃Q�[���́A�e��STG(�V���[�e�B���O�Q�[��)�ł��颓���project���",color[0],font[0]);
			DrawStringToHandle(25,140,"�C���[�W���Đ��삳�ꂽ�A�e�������Q�[���ł��B",color[0],font[0]);

			DrawStringToHandle(25,180,"�v���C���[�͎��@�𑀍삵�A�G�̕��e����������Ă��������B",color[0],font[0]);
			DrawStringToHandle(25,200,"10���̃X�y����F��Q�[�W(��ʉE�ɕ\��)���s���Ȃ��悤�ɔ���������",color[0],font[0]);
			DrawStringToHandle(25,220,"���Ƃ��ł���΃N���A�ƂȂ�܂��I",color[0],font[0]);

			DrawStringToHandle(25,280,"�S����4�i�K�̓�Փx��p�ӂ��Ă���̂ŁA�����̎��͂�D�݂ɍ��킹��",color[0],font[0]);
			DrawStringToHandle(25,300,"�I�����Ă��������B",color[0],font[0]);

			DrawStringToHandle(25,340,"������Փx�̃N���A��ڎw���̂��悵�A",color[0],font[0]);
			DrawStringToHandle(25,360,"�Ⴂ��Փx���ɂ߂č������N��@�������̂��悵�ł��I",color[0],font[0]);
			break;
		case 1:
			DrawStringToHandle(215,40,"���[������",color[0],font[1]);
			DrawStringToHandle(30,110,"�F��Q�[�W��؂炳����10���̃X�y������������邱�Ƃ��ł���΃N��",color[0],font[0]);
			DrawStringToHandle(30,130,"�A�A�r���ŔF��Q�[�W���s���Ă��܂��ƃQ�[���I�[�o�[�ɂȂ�܂��B",color[0],font[0]);

			DrawStringToHandle(30,170,"�F��Q�[�W�͓G�Ƃ̐ڐG���e�ɂ���Č������A�O���C�Y(����M���M",color[0],font[0]);
			DrawStringToHandle(30,190,"���Œe�ɂ����邱��)�ɂ���ď������񕜂��Ă����܂��B",color[0],font[0]);
			DrawStringToHandle(30,210,"TYPE B�̎��@�͂��̃O���C�Y�ɂ��F��Q�[�W�̉񕜗ʂɃ{�[�i�X��",color[0],font[0]);
			DrawStringToHandle(30,230,"���܂��B",color[0],font[0]);

			DrawStringToHandle(30,270,"�܂��A���@�_���E���C���_�[�E�T�C�Y�̏����Ȓe�Ȃǂ͎󂯂�_���[�W",color[0],font[0]);
			DrawStringToHandle(30,290,"�����Ȃ߂ɁA��e�͎󂯂�_���[�W�����߂ɂȂ��Ă���̂Œ��ӂ��܂�",color[0],font[0]);
			DrawStringToHandle(30,310,"�傤�B",color[0],font[0]);

			DrawStringToHandle(30,350,"�Q�[���I�[�o�[�ɂȂ����ꍇ�͑S�̂Ɣ�ׂĐ����c�������Ԃ̊����ŁA",color[0],font[0]);
			DrawStringToHandle(30,370,"�N���A�����ꍇ�̓v���C���e�ɂ���Č��܂鑍���B���x�ƁA�����B���x",color[0],font[0]);
			DrawStringToHandle(30,390,"���画�肳���N���A�����N�����U���g��ʂɕ\������܂��B",color[0],font[0]);
			DrawStringToHandle(30,410,"(�N���A�����N�͑����B���x�ɉ�����D�`AAA�܂ŗp�ӂ���Ă��܂��B)",color[0],font[0]);
			break;
		case 2:
			DrawStringToHandle(215,40,"��Փx����",color[0],font[1]);

			DrawStringToHandle(30,85,"EASY",color[0],font[4]);
			DrawStringToHandle(30,110,"��ԊȒP�ȓ�Փx�ł��B���i����STG������Ă���l�ɂ͕�����Ȃ���",color[0],font[0]);
			DrawStringToHandle(30,130,"�����Փx�ł����ASTG����������Ƃ̂Ȃ��l�E��邯�ǋ��Ȑl�͂�",color[0],font[0]);
			DrawStringToHandle(30,150,"�����̓�Փx����v���C���Ă݂ė��K���Ă݂܂��傤�B",color[0],font[0]);

			DrawStringToHandle(30,180,"NORMAL",color[3],font[4]);
			DrawStringToHandle(30,205,"��r�I�ȒP�ȕ��ŁA�W���I�ȓ�Փx�ł��B�m�[�}���V���[�^�[�̐l��",color[0],font[0]);
			DrawStringToHandle(30,225,"����΂�����x���΃N���A���\�ɂȂ�Ǝv���܂��B�m�[�}������",color[0],font[0]);
			DrawStringToHandle(30,245,"��Ƃ�����STG���o���̐l���I舂ɑI������ƒɂ��ڂ����܂���H",color[0],font[0]);

			DrawStringToHandle(30,275,"HARD",color[2],font[4]);
			DrawStringToHandle(30,300,"�������������Փx�ł��BHARD�ȏォ��͐V���Ȓe���p�^�[�����ǉ�",color[0],font[0]);
			DrawStringToHandle(30,320,"�����X�y��������܂����A�m�[�}���V���|�^�[�̐l�ł��\������ł�",color[0],font[0]);
			DrawStringToHandle(30,340,"���Փx���Ƃ͎v���܂��BLUNATIC�ւ̋��n���E�\�s���K�ɂ��ǂ����B",color[0],font[0]);

			DrawStringToHandle(30,370,"LUNATIC",color[7],font[4]);
			DrawStringToHandle(30,395,"���񑩂̓�Փx�ł��B����œ`���Ȃ��l�͒��킵�Ȃ���������ł��B",color[0],font[0]);
			DrawStringToHandle(30,415,"�S�{��Փx�ł͂Ȃ��̂ŁA�C���͂̂���l��b����ꂽ�V���[�^�[�ł�",color[0],font[0]);
			DrawStringToHandle(30,435,"��΃N���A�ł���͂��ł��B�ł��A��ʐl�ɂƂ��Ă͂��Ԃ�N�\�Q�[�B",color[0],font[0]);
			break;
		case 3:
			DrawStringToHandle(185,40,"���@�^�C�v����",color[0],font[1]);

			DrawStringToHandle(30,100,"TYPE A",color[0],font[4]);
			DrawStringToHandle(30,130,"�W���I�ȋ@�́A�얲�݊��ł��B�����蔻�肪�����������Ȃ�܂��B",color[0],font[0]);
			DrawStringToHandle(30,150,"�����蔻��k�����̓N���A�_���ł��������N�_���ł�����ɂ����\�͂�",color[0],font[0]);
			DrawStringToHandle(30,170,"�����₷���̂ŁA�������炱�̃^�C�v��I�ׂΊԈႢ�Ȃ��ł��傤�B",color[0],font[0]);

			DrawStringToHandle(30,210,"TYPE B",color[0],font[4]);
			DrawStringToHandle(30,240,"�O���C�Y�ɂ��F��Q�[�W�̏㏸�ʂ��������A�����Ē���s���ɔ�e",color[0],font[0]);
			DrawStringToHandle(30,260,"�������̔F��Q�[�W�̌����ʂ��y������܂��B�O���C�Y���҂���X�y��",color[0],font[0]);
			DrawStringToHandle(30,280,"�ł̉񕜂�I�Ր�̒���s�̔S�苭�������͂ȃN���A�����@�̂ł��B",color[0],font[0]);

			DrawStringToHandle(30,320,"TYPE C",color[0],font[4]);
			DrawStringToHandle(30,350,"TYPE A��TYPE B�ǂ���̃{�[�i�X���󂯂��Ȃ�����Ƀ����N�㏸",color[0],font[0]);
			DrawStringToHandle(30,370,"�ɕK�v�ȑ����B���x�������y������܂��B���肵���N���A���ł���΁A",color[0],font[0]);
			DrawStringToHandle(30,390,"�������N���擾���₷���Ȃ�@�̂ł��B�܂��A���̋@�̂ł̂݋ɂ߂č�",color[0],font[0]);
			DrawStringToHandle(30,410,"�������B���x�ŃN���A�����AAA+�����N���擾���邱�Ƃ��ł��܂��B",color[0],font[0]);
			break;
		case 4:
			DrawStringToHandle(245,40,"�q���g",color[0],font[1]);
			DrawStringToHandle(30,100,"�E�F��Q�[�W��30%�����̎��ɂ͒���s��ԂƂȂ��Ď󂯂�_���[�W",color[0],font[0]);
			DrawStringToHandle(30,120,"�@���������܂��B�Ō�܂Œ��߂��ɔ��������܂��傤�B",color[0],font[0]);

			DrawStringToHandle(30,150,"�E�����B���x�́A��葽���̔F��Q�[�W���c������ԂŃN���A���邱��",color[0],font[0]);
			DrawStringToHandle(30,170,"�@�ŏ㏸���܂��B���̑��ɂ��A�����̃X�y���{�[�i�X(1�����e����",color[0],font[0]);
			DrawStringToHandle(30,190,"�@�ɃX�y������肷�������ƂŃ{�[�i�X���l���ł��܂�)�̊l������O",color[0],font[0]);
			DrawStringToHandle(30,210,"�@���C�Y�̉񐔂ɉ����ď㏸���Ă����܂��B",color[0],font[0]);

			DrawStringToHandle(30,240,"�ESpell�T�͕ė��e�̃��C���_�[�ɍ��킹�ēG�̎���������ɁA",color[0],font[0]);
			DrawStringToHandle(30,260,"�@Spell�W�͕ė��e�܂��͞��e�̃��C���_�[�ɍ��킹�ēG�̐��ʂ����E",color[0],font[0]);
			DrawStringToHandle(30,280,"�@�ɓ����܂��傤�B����2�X�y���̓��C���_�[�Ɋ������܂��Ǝ�ɂ�",color[0],font[0]);
			DrawStringToHandle(30,300,"�@�_���[�W���󂯂�̂Ń��C���_�[���ŗD��Ŕ����Ă����܂��傤�B",color[0],font[0]);

			DrawStringToHandle(30,330,"�ESpell�V�͌����ڂ͕ω����܂������̂܂ܑ�e�������Ă��Ă��܂��B",color[0],font[0]);
			DrawStringToHandle(30,350,"�@���������x���ꂸ�A�e�Ƃ̓K�؂ȋ�����ۂ��܂��傤�B",color[0],font[0]);

			DrawStringToHandle(30,380,"�ESpell�X�͓�Փx�ɂ���ăp�^�[���Ƒ΍􂪑傫���قȂ�܂��B",color[0],font[0]);
			DrawStringToHandle(30,400,"�@NORMAL�ȉ���2��𓯎��ɑ���ɂ��Ȃ��悤�ȏꏊ��T���܂��傤�B",color[0],font[0]);
			DrawStringToHandle(30,420,"�@HARD�ȏ�͈��Ԋu�ŏo�������e����̑�_���[�W���ł��邾��",color[0],font[0]);
			DrawStringToHandle(30,440,"�@���炵�܂��傤�B�ᑬ�ړ����֎~����Ă���_�ɂ����ӂł��B",color[0],font[0]);
			break;
		case 5:
			DrawStringToHandle(210,40,"�N���W�b�g",color[0],font[1]);
			DrawStringToHandle(135, 90,"�v���O���~���O�����낢��",color[0],font[4]);
			DrawStringToHandle(245,120,"Mrtanaka",color[0],font[4]);
			DrawStringToHandle(210,165,"���C�u�����g�p",color[0],font[4]);
			DrawStringToHandle(225,195,"DX���C�u����",color[0],font[4]);
			DrawStringToHandle(130,240,"�v���O�����Q�l�E�摜�f��",color[0],font[4]);
			DrawStringToHandle(105,270,"����_�^�v���O���~���O�̊٣�l",color[0],font[4]);
			DrawStringToHandle(210,300,"(http://dixq.net/rp/)",color[0],font[0]);
			DrawStringToHandle(240,335,"���ʉ��f��",color[0],font[4]);
			DrawStringToHandle( 85,365,"���̂ւ񂩂�E���Ă����t���[�f��",color[0],font[4]);
			DrawStringToHandle(185,410,"�X�y�V�����T���N�X",color[0],font[4]);
			DrawStringToHandle(127,440,"�e�X�g�v���C���[�݂̂Ȃ���",color[0],font[4]);
			break;
		case 6:
			DrawStringToHandle(230,40,"�R�����g",color[0],font[1]);
			DrawStringToHandle(30, 80,"�@�ǂ������߂܂��āAMrtanaka�Ɛ\���܂��B",color[0],font[0]);
			DrawStringToHandle(30,100,"���i�̓��i�V���[�^�[���特�Q�[�}�[(SDVX)�A�v���f���[�T�[�A��A",color[0],font[0]);
			DrawStringToHandle(30,120,"�N�b�L�[�E�l�A��w���c�ƁA�Z�����������߂����Ă��܂��B",color[0],font[0]);
			DrawStringToHandle(30,140,"�@���̍�i�́A���̢1�l�̓����V���[�^�[�Ƃ��Ă����񎟑n�삩�I��",color[0],font[0]);
			DrawStringToHandle(30,160,"�W�i����STG�𐧍삵�Ă݂����c��Ƃ�����]�̑��X�e�b�v�Ƃ��ăQ�[",color[0],font[0]);
			DrawStringToHandle(30,180,"���V�X�e����e���̍\�z���@���w�ڂ��Ǝ����I�ɐ��삳�ꂽ���̂ł��B",color[0],font[0]);
			DrawStringToHandle(30,200,"�@��������Ƃ���STG��p�ӂ���̂͂ǂ����������낤�Ǝv���A�����",color[0],font[0]);
			DrawStringToHandle(30,220,"�Ƃ����e���~�j�Q�[���Ƃ����W�������ɗ�������������ł����A�Q�[��",color[0],font[0]);
			DrawStringToHandle(30,240,"�����Ƃ����s�׎��̂����߂Ăł������́A�����Ƌ�J�������܂����B",color[0],font[0]);
			DrawStringToHandle(30,260,"�@���āA������ƌy���m���Ő��삳�ꂽ(�͂��Ȃ̂ɂ����������Ԃ�����",color[0],font[0]);
			DrawStringToHandle(30,280,"�Ă���)����ł����A�ǂ��������ł��傤���H���Ƃ��ẮA����̃e�[�}",color[0],font[0]);
			DrawStringToHandle(30,300,"�Ƃ��ċC�������n�̒e���΂���̍\���ƂȂ��Ă����̂ŁA�l�����o����",color[0],font[0]);
			DrawStringToHandle(30,320,"�l�ɂ���Ă͂܂�Ȃ������ɂȂ������ȁ[�Ƃ͎v���Ă��܂����c",color[0],font[0]);
			DrawStringToHandle(30,340,"�@�悯��΁A������̒e���͂ǂ�������������̓m�[�}������Ȃ��",color[0],font[0]);
			DrawStringToHandle(30,360,"�ȂǂƂ��������z��`���Ă����ƁA���������������ł��B�K�؂ȓ�Փx",color[0],font[0]);
			DrawStringToHandle(30,380,"�̒����ɂ��Ă��A���ꂩ��w��ł��������ł��ˁB",color[0],font[0]);
			DrawStringToHandle(30,400,"�@�Ō�ɁA�킴�킴����ȂƂ���܂œǂ�ł��ꂽ�f�G�ȋM���Ɋ��ӁB",color[0],font[0]);
			DrawStringToHandle(30,420,"�@����ł́A�f�G�Ȓe�����C�t���c",color[0],font[0]);

			DrawStringToHandle(215,450,"Mrtanaka(@Mrtanaka1)",color[0],font[0]);
			break;
	}
	DrawFormatStringToHandle(590,460,color[0],font[2],"P %d/7",menu_state+1);
}