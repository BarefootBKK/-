// room.cpp
#include "room.h"

// ���캯��
Room::Room(Socket * socket)
{
	this->player_1 = socket;
	this->players_num = 1;
}

// ���÷�������
void Room::SetRoomType(int room_type)
{
	this->room_type = room_type;
}

// ���÷�������
void Room::SetRoomKey(int room_key)
{
	this->room_key = room_key;
}

// ���÷�������
void Room::SetRoomName(QString room_name)
{
	this->room_name = room_name;
}

// ���÷����
void Room::SetRoomNum(int room_num)
{
	this->room_num = room_num;
}

// ���ط�������
int Room::GetRoomType()
{
	return room_type;
}

// ���ط�������
int Room::GetRoomKey()
{
	return room_key;
}

// ���ط����
int Room::GetRoomNum()
{
	return room_num;
}

// ���ط�������
QString Room::GetRoomName()
{
	return room_name;
}

// ������
void Room::AddPlayer(Socket * player)
{
	if (players_num < 2)
	{
		players_num++;
		this->player_2 = player;
		player_1->SetOpp(player_2);
		player_2->SetOpp(player_1);
	}
}

// �뿪����
void Room::LeaveRoom()
{
	players_num--;
	player_1->DeleteOpp();
	player_2->DeleteOpp();
}

// ��ȡ�����������
int Room::GetPlayerNum()
{
	return players_num;
}

// ��ȡ���1
Socket * Room::GetRoomOwner()
{
	return player_1;
}

// ��ȡ���2
Socket * Room::GetRoomMember()
{
	return player_2;
}
