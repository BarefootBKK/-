// room.cpp
#include "room.h"

// 构造函数
Room::Room(Socket * socket)
{
	this->player_1 = socket;
	this->players_num = 1;
}

// 设置房间类型
void Room::SetRoomType(int room_type)
{
	this->room_type = room_type;
}

// 设置房间密码
void Room::SetRoomKey(int room_key)
{
	this->room_key = room_key;
}

// 设置房间名称
void Room::SetRoomName(QString room_name)
{
	this->room_name = room_name;
}

// 设置房间号
void Room::SetRoomNum(int room_num)
{
	this->room_num = room_num;
}

// 返回房间类型
int Room::GetRoomType()
{
	return room_type;
}

// 返回房间密码
int Room::GetRoomKey()
{
	return room_key;
}

// 返回房间号
int Room::GetRoomNum()
{
	return room_num;
}

// 返回房间名称
QString Room::GetRoomName()
{
	return room_name;
}

// 添加玩家
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

// 离开房间
void Room::LeaveRoom()
{
	players_num--;
	player_1->DeleteOpp();
	player_2->DeleteOpp();
}

// 获取房间玩家人数
int Room::GetPlayerNum()
{
	return players_num;
}

// 获取玩家1
Socket * Room::GetRoomOwner()
{
	return player_1;
}

// 获取玩家2
Socket * Room::GetRoomMember()
{
	return player_2;
}
