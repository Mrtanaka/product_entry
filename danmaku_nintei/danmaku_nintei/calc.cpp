#include "GV.h"

//���j���[�����w�肵�A�I�𐧌�
void calc_menu(int menu){
	int up = CheckStatePad(configpad.up), down = CheckStatePad(configpad.down);

	if(up == 1 || (up >= 60 && up % 10 == 0)){
		if(menu_state > 0) menu_state--;
		else menu_state = menu-1;//�I�����j���[�����
	}

	if(down == 1 || (down >= 60 && down % 10 == 0)){
		if(menu_state < menu-1) menu_state++;
		else menu_state = 0;//�I�����j���[������
	}
}

void calc_main(){//�Q�[�����̐���
	if(CheckStatePad(configpad.start) == 1){
		se_flag[3] = 1;
		func_state = 2;//�|�[�Y
	}
}

pad_t padc;//�L�[�R��shot�{�^����ύX�h�~�̂��߂̃L�[���i�[�ϐ�
void calc_title(){//�^�C�g����ʂ̐���
	calc_menu(4);

	if(CheckStatePad(configpad.shot) == 1){
		switch(menu_state){
		case 0://��Փx�I����
			menu_state = 0;
			se_flag[3]=1;
			func_state = 7;
			break;
		case 1://�L�[�R���t�B�O��
			menu_state = 0;
			se_flag[3]=1;
			padc.key[configpad.shot] = 2;//shot�����t���[����2�ɂ���shot�{�^�����ύX�̖h�~
			func_state = 5;
			break;
		case 2://�}�j���A����
			menu_state = 0;
			se_flag[3]=1;
			func_state = 6;
			break;
		case 3://�Q�[���I��
			menu_state = 0;
			se_flag[3]=1;
			shut_flag = 1;//�Q�[���V���b�g�_�E���t���O����
			break;
		}
	}
}

void calc_pause(){//�|�[�Y���j���[�̐���
	calc_menu(3);

	if(CheckStatePad(configpad.shot) == 1){
		switch(menu_state){
		case 0://�|�[�Y����
			menu_state = 0;
			se_flag[3] = 1;
			func_state = 10;
			break;
		case 1://�^�C�g���֖߂�
			menu_state = 0;
			se_flag[3] = 1;
			func_state = 1;
			break;
		case 2://���g���C
			menu_state = 0;
			se_flag[3] = 1;
			func_state = 9;
			break;
		}
	}
}

void calc_result(){
	if(count == 120 || count == 180 || count == 240 || count == 300)
		se_flag[3] = 1;

	if(count >= 330){
		calc_menu(2);

		if(CheckStatePad(configpad.shot) == 1){
			switch(menu_state){
			case 0:
				menu_state = 0;
				se_flag[3]=1;
				func_state = 9;
				break;
			case 1:
				menu_state = 0;
				se_flag[3]=1;
				func_state = 1;
				break;
			}
		}
	}
}

void calc_difficult(){
	calc_menu(4);

	if(CheckStatePad(configpad.bom) == 1){
		menu_state = 0;
		func_state = 1;
	}
	else if((CheckStateKey(KEY_INPUT_L) >= 60) && (CheckStateKey(KEY_INPUT_R) >= 60)){
		stage = 4;
		menu_state = 0;
		se_flag[3] = 1;
		func_state = 8;
	}
	else if(CheckStatePad(configpad.shot) == 1){
		stage = menu_state;
		menu_state = 0;
		se_flag[3] = 1;
		func_state = 8;
	}
}

void calc_type(){
	calc_menu(3);

	if(CheckStatePad(configpad.bom) == 1){
		menu_state = 0;
		func_state = 7;
	}
	else if(CheckStatePad(configpad.shot) == 1){
		type = menu_state;
		menu_state = 0;
		se_flag[3] = 1;
		func_state = 9;
	}
}

void calc_key(){
	calc_menu(5);

	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//�p�b�h�̓��͏�Ԃ��擾
	for(i=0;i<16;i++){
		if(PadInput & mul)	padc.key[i]++;
		else				padc.key[i]=0;
		mul*=2;
	}

	for(int i=4;i<PAD_MAX;i++){
		if(padc.key[i] == 1){
			se_flag[3]=1;

			switch(menu_state){
				case 0:
					configpad.shot=i;
					break;
				case 1:
					configpad.bom=i;
					break;
				case 2:
					configpad.slow=i;
					break;
				case 3:
					configpad.start=i;
					break;
			}
		}
	}

	if((menu_state==4) && (CheckStatePad(configpad.shot) == 1)){
		menu_state=0;
		se_flag[3]=1;
		func_state=1;
	}
}

void calc_manual(){
	calc_menu(7);

	if(CheckStatePad(configpad.bom) == 1){
		menu_state = 0;
		func_state = 1;
	}
}