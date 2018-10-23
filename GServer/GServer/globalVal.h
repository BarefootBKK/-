// globalVal.h
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _GLOBALVAL_H_
#define _GLOBALVAL_H_

/*========================��Ϸģʽ============================*/
#define	PLAYER_1		0				// ���1����
#define	PLAYER_2		1				// ���2����
/*============================================================*/

/*========================�˺���Ϣ============================*/
typedef struct
{
	QString account;	// �˺�
	QString password;	// ����
	QString nickname;	// �ǳ�
	QString winned_num;	// ʤ����
	QString failed_num;	// ������
	QString scores;		// ����

}PlayerInfo;
/*===========================================================*/

/*========================�����ս============================*/
// ����
#define CONNECTED			1		// ���ӳɹ�
#define DISCONNCECTED		2		// ʧȥ����
// ��¼��ע��
#define SIGN_IN				11		// ע��
#define LOG_IN				12		// ��¼
#define SIGN_IN_SUCC		13		// ע��ɹ�
#define LOG_IN_SUCC			14		// ��¼�ɹ�
// ƥ��ͷ���
#define MATCH				20		// ƥ��
#define MATCH_SUCC			21		// ƥ��ɹ�
#define MATCH_CANCEL		22		// ƥ��ȡ��
#define ROOM_PU				23		// ��������
#define	ROOM_PR				24		// ˽�з���
#define	ROOM_NEW			25		// �·���
#define	ROOM_ADD			26		// ���뷿��
#define	ROOM_ADD_SUCC		27		// ���뷿��ɹ�
#define	ROOM_LEAVE			28		// (��Ա)�뿪����
#define	ROOM_CLOSE			29		// (����)�رշ���
#define	ROOM_START_GAME		30		// ��ʼ������Ϸ
#define	ROOM_INFO_LIST		31		// �����б�
#define	ACCINFO				32		// �˺���Ϣ
// ��ս����Ϣ
#define	VICTORY				40		// ʤ��
#define DEFEAT				41		// ʧ��
#define CHESSED				42		// ����
// ���а�
#define RANK_LIST			50		// ���а�
/*===========================================================*/

/*========================�˺��쳣��Ϣ=======================*/
// ��¼��ע���쳣
#define ACC_EXIST			-10		// ע��ʧ��(�˺��Ѵ���)
#define ACC_NONE			-11		// ��¼ʧ��(�˺Ų�����)
#define ACC_LOGINED			-12		// ��¼ʧ��(�˺��ѵ�¼)
#define LOG_IN_FAILED_A		-13		// ��¼ʧ��(���벻��ȷ)
#define LOG_IN_FAILED_S		-14		// ��¼ʧ��(��������Ϣ)
// ����
#define ROOM_KEY_ERROR		-21		// �����������
// ��Ϣ����
#define SAVE_ERROR			-51		// ����ʧ��
#define READ_ERROR			-52		// ��ȡʧ��
/*===========================================================*/

#endif