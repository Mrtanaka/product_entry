#define GLOBAL_INSTANCE 
#include "GV.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen()!=0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	GetHitPadStateAll();  //���݂̃p�b�h���͏������s��
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	SetMainWindowText("�e���i�ʔF��ver1.10");//�E�C���h�E�\����
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�

	while(ProcessLoop()==0){//���C�����[�v
		music_ini();
		switch(func_state){
			case 0://����̂ݓ��鏈��
				load();		//�f�[�^���[�h
				first_ini();//����̏�����
				func_state=1;
				break;
			case 1://�^�C�g�������[�h�Z���N�g
				graph_title();
				calc_title();
				break;
			case 2://�|�[�Y���
				calc_pause();
				graph_pause();
				break;
			case 3://���U���g���
				calc_result();
				graph_result();
				count++;
				break;
			case 4://�Q�[���I�[�o�[���
				calc_result();
				graph_result();
				count++;
				break;
			case 5://�L�[�R���t�B�O
				calc_key();
				graph_key();
				break;
			case 6://�}�j���A��
				calc_manual();
				graph_manual();
				break;
			case 7://��Փx�̑I��
				graph_difficult();
				calc_difficult();
				break;
			case 8://���@�^�C�v�̑I��
				graph_type();
				calc_type();
				break;
			case 9://�e��f�[�^�̏�����
				ini();
				func_state=10;
				break;
			case 10://�ʏ폈��
				calc_main();
				ch_main();
				enemy_main();
				shot_main();
				out_main();
				graph_main();
				count++;
				break;
			default:
				printfDx("�s����func_state\n");
				break;
		}
		music_play();
		fps_wait();
		if(shut_flag == 1)break;//�I�����삪��������u���C�N
		ScreenFlip();//����ʔ��f
	}
	DxLib_End();//�c�w���C�u�����I������
	return 0;
}
