#include "GV.h"

void load(){
	SetCreateSoundDataType( DX_SOUNDDATATYPE_MEMPRESS ) ;

	img_board[0] = LoadGraph("./data/image/board/0.png");
	img_board[1] = LoadGraph("./data/image/board/1.png");
	img_board[2] = LoadGraph("./data/image/board/2.png");
	img_board[3] = LoadGraph("./data/image/board/3.png");
	img_board[4] = LoadGraph("./data/image/board/4.png");
	img_etc[0]	= LoadGraph( "./data/image/chara/atari.png" );
	LoadDivGraph( "./data/image/bullet/b0.png" ,  5 ,  5 , 1 , 76 ,  76 , img_bullet[0] ) ;
	LoadDivGraph( "./data/image/bullet/b1.png" ,  6 ,  6 , 1 , 22 ,  22 , img_bullet[1] ) ;
	LoadDivGraph( "./data/image/bullet/b2.png" , 10 , 10 , 1 ,  5 , 120 , img_bullet[2] ) ;
	LoadDivGraph( "./data/image/bullet/b3.png" ,  5 ,  5 , 1 , 19 ,  34 , img_bullet[3] ) ;
	LoadDivGraph( "./data/image/bullet/b4.png" , 10 , 10 , 1 , 38 ,  38 , img_bullet[4]  ) ;
	LoadDivGraph( "./data/image/bullet/b5.png" ,  3 ,  3 , 1 , 14 ,  16 , img_bullet[5] ) ;
	LoadDivGraph( "./data/image/bullet/b6.png" ,  3 ,  3 , 1 , 14 ,  18 , img_bullet[6] ) ;
	LoadDivGraph( "./data/image/bullet/b7.png" , 10 , 10 , 1 , 16 ,  16 , img_bullet[7] ) ;
	LoadDivGraph( "./data/image/bullet/b8.png" , 10 , 10 , 1 , 12 ,  18 , img_bullet[8] ) ;
	LoadDivGraph( "./data/image/bullet/b9.png" ,  3 ,  3 , 1 , 13 ,  19 , img_bullet[9] ) ;
	LoadDivGraph( "./data/image/bullet/b10.png",  8 ,  8 , 1 ,  8 ,   8 , img_bullet[10] ) ;
	LoadDivGraph( "./data/image/bullet/b11.png",  8 ,  8 , 1 , 35 ,  32 , img_bullet[11] ) ;
	LoadDivGraph( "./data/image/chara/0.png" , 12 , 4 , 3 , 73 , 73 , img_ch ) ;
	LoadDivGraph( "./data/image/enemy/0.png" , 9 , 3 , 3 , 32 , 32 , img_enemy ) ;
	LoadDivGraph( "./data/image/num/0.png" , 10 , 10 , 1 , 16 , 18 , img_num ) ;
	sound_se[0]=LoadSoundMem("./data/se/enemy_shot.wav");	//�G�V���b�g��
	sound_se[1]=LoadSoundMem("./data/se/hit.wav");			//��e��(�ʏ�)
	sound_se[2]=LoadSoundMem("./data/se/graze.wav");		//�O���C�Y��
	sound_se[3]=LoadSoundMem("./data/se/kettei.wav");		//���艹
	sound_se[4]=LoadSoundMem("./data/se/count.wav");		//10�J�E���g��
	sound_se[5]=LoadSoundMem("./data/se/spell_change.wav");	//�X�y���錾��
	sound_se[6]=LoadSoundMem("./data/se/boss_death.wav");	//���j(�N���A)��
	sound_se[7]=LoadSoundMem("./data/se/char_death.wav");	//����(���s)��
	sound_se[8]=LoadSoundMem("./data/se/spell_finish.wav");	//�X�y�J�I�����ESpell�X������
	sound_se[9]=LoadSoundMem("./data/se/spell_get.wav");	//�X�y�J�擾��
	sound_se[10]=LoadSoundMem("./data/se/hit_low.wav");		//��e��(���)
	sound_se[11]=LoadSoundMem("./data/se/charge.wav");		//Spell�X�`���[�W��

	ChangeVolumeSoundMem(150,sound_se[0]);
	ChangeVolumeSoundMem(150,sound_se[2]);
	ChangeVolumeSoundMem(170,sound_se[3]);
	ChangeVolumeSoundMem(170,sound_se[4]);
	ChangeVolumeSoundMem(120,sound_se[5]);
	ChangeVolumeSoundMem(150,sound_se[6]);
	ChangeVolumeSoundMem(170,sound_se[7]);
	ChangeVolumeSoundMem(170,sound_se[8]);
	ChangeVolumeSoundMem(170,sound_se[9]);
	ChangeVolumeSoundMem(228,sound_se[10]);
	ChangeVolumeSoundMem(170,sound_se[11]);

	color[0] = GetColor(255,255,255);//��
	color[1] = GetColor(  0,  0,  0);//��
	color[2] = GetColor(255,  0,  0);//��
	color[3] = GetColor(  0,255,  0);//��
	color[4] = GetColor(  0,  0,255);//��
	color[5] = GetColor(255,255,  0);//���F
	color[6] = GetColor(  0,255,255);//��
	color[7] = GetColor(255,  0,255);//��

	font[0] = CreateFontToHandle( "HGP�޼��E" , 15 , 2 , DX_FONTTYPE_ANTIALIASING_EDGE);//�ʏ�
	font[1] = CreateFontToHandle( "HGP�޼��E" , 35 , 4 , DX_FONTTYPE_ANTIALIASING_EDGE);//�啶��
	font[2] = CreateFontToHandle( "HGP�޼��E" , 13 , 2 , DX_FONTTYPE_ANTIALIASING_EDGE);//������
	font[3] = CreateFontToHandle( "HGP�޼��E" , 60 , 5 , DX_FONTTYPE_ANTIALIASING_EDGE);//���啶��
	font[4] = CreateFontToHandle( "HGP�޼��E" , 25 , 3 , DX_FONTTYPE_ANTIALIASING_EDGE);//������
}