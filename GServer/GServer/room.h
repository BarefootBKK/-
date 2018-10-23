// room.h
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _ROOM_H_
#define _ROOM_H_

#include "socket.h"
#include "globalVal.h"

#define DEFAULT_ROOM_NUM	 1000	// 默认房间号
#define DEFAULT_ROOM_KEY	-1001	// 默认房间密码

class Room : public QObject
{
	Q_OBJECT

public:
	Room(Socket *);					// 构造函数

public:
/*=====================设置房间参数======================*/
	void SetRoomType(int);			// 设置房间类型
	void SetRoomKey(int);			// 设置房间密码
	void SetRoomName(QString);		// 设置房间名
	void SetRoomNum(int);			// 设置房间号
/*=====================获取房间参数======================*/
	int GetRoomType();				// 获取房间类型
	int GetRoomKey();				// 获取房间密码
	int GetRoomNum();				// 获取房间号
	QString GetRoomName();			// 获取房间名
/*=====================房间玩家参数======================*/
	void AddPlayer(Socket *);		// 添加玩家
	void LeaveRoom();				// 离开房间
	int GetPlayerNum();				// 获取房间玩家数
	Socket * GetRoomOwner();		// 获取房主socket标识符
	Socket * GetRoomMember();		// 获取房间成员标识符

private:
/*=====================私有成员变量======================*/
	int room_type;			// 房间类型
	int room_key;			// 房间密码
	int room_num;			// 房间号
	QString room_name;		// 房间名
	int players_num;		// 房间玩家数
	Socket * player_1;		// 玩家1，即房主
	Socket * player_2;		// 玩家2
};
#endif