//�L�����N�^�[�Ɋւ���\����
typedef struct{
	int flag;		//�t���O
	int cnt;		//�J�E���^
	int type;		//���@�^�C�v
	int img;
	int slow;		//�X���[���ǂ���
	int slow_flag;	//�ᑬ�ړ��֎~�p�̃t���O
	double x,y;		//���W
	int graze;		//�O���C�Y
	double percent;	//�i�ʃQ�[�W
	int grade;		//���v�B���x
}ch_t;

//�G�Ɋւ���\����
typedef struct{
	int flag,cnt,img;
	//�t���O�A�J�E���^
	double x,y,vx,vy,sp,ang;
	//���W�A���xx�����A���xy�����A�X�s�[�h�A�p�x
}enemy_t;

//�p�b�h�Ɋւ���\����
typedef struct{
	int key[PAD_MAX];
}pad_t;

//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,shot,bom,slow,start;
}configpad_t;

//�e�Ɋւ���\����
typedef struct{
	//�t���O�A��ށA�J�E���^�A�F�A��ԁA���Ȃ��Ƃ������Ȃ����ԁA�G�t�F�N�g�̎�ށA�O���C�Y������
	int flag,knd,cnt,col,state,till,gflag;
	//���W�A�p�x�A���x
	double x,y,vx,vy,angle,spd;
}bullet_t;

//�e�̏��
typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;