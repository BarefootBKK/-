// room.h
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _ROOM_H_
#define _ROOM_H_

#include "socket.h"
#include "globalVal.h"

#define DEFAULT_ROOM_NUM	 1000	// Ĭ�Ϸ����
#define DEFAULT_ROOM_KEY	-1001	// Ĭ�Ϸ�������

class Room : public QObject
{
	Q_OBJECT

public:
	Room(Socket *);					// ���캯��

public:
/*=====================���÷������======================*/
	void SetRoomType(int);			// ���÷�������
	void SetRoomKey(int);			// ���÷�������
	void SetRoomName(QString);		// ���÷�����
	void SetRoomNum(int);			// ���÷����
/*=====================��ȡ�������======================*/
	int GetRoomType();				// ��ȡ��������
	int GetRoomKey();				// ��ȡ��������
	int GetRoomNum();				// ��ȡ�����
	QString GetRoomName();			// ��ȡ������
/*=====================������Ҳ���======================*/
	void AddPlayer(Socket *);		// ������
	void LeaveRoom();				// �뿪����
	int GetPlayerNum();				// ��ȡ���������
	Socket * GetRoomOwner();		// ��ȡ����socket��ʶ��
	Socket * GetRoomMember();		// ��ȡ�����Ա��ʶ��

private:
/*=====================˽�г�Ա����======================*/
	int room_type;			// ��������
	int room_key;			// ��������
	int room_num;			// �����
	QString room_name;		// ������
	int players_num;		// ���������
	Socket * player_1;		// ���1��������
	Socket * player_2;		// ���2
};
#endif