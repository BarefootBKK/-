// globalVal.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
/*
在这里定义全局变量
*/
#ifndef _GLOBALVAL_H_
#define _GLOBALVAL_H_

/*========================游戏模式=============================*/
#define PVP_ONLINE		1				// 联机对战
#define PVP_LOCAL		2				// 本地人人
#define PVE				3				// 人机对战
#define REPLAY			4				// 回放棋局
#define	PLAYER_1		0				// 玩家1先手
#define	PLAYER_2		1				// 玩家2/AI先手
/*=============================================================*/

/*========================棋盘变量==============================*/
// "C"表示chessboard
#define C_P_WIDTH		55				// 两颗棋子间的像素宽
#define C_WIDTH			770				// 棋盘像素宽
#define BOARD_SIZE		15				// 棋盘大小
#define PIXEL_ERROR		15				// 误差像素
#define MIN_ERROR		0.272727		// 最大误差( 误差像素 / 棋子间距, 如 0.0.272727 = 15 / 55，"15"是PIXEL_ERROR，"55"是C_P_WIDTH )
/*=============================================================*/

/*========================棋子变量=============================*/
#define CHESS_SIZE		44				// 棋子大小
#define CHESS_FREE		0				// 表示"无"
#define BLACK			1				// 黑棋
#define WHITE			2				// 白棋
/*=============================================================*/

/*========================棋子信息============================*/
typedef struct ChessNode
{
	int color;		// 棋子颜色
	int i, j;		// 棋子在棋盘的位置
	int x, y;		// 棋子坐标
}ChessNode;
/*===========================================================*/

/*========================账号信息============================*/
typedef struct
{
	QString account;		// 账号
	QString password;		// 密码
	QString nickname;		// 昵称
	QString winned_num;		// 胜场数
	QString failed_num;		// 负场数
	QString scores;			// 分数
}AccountInfo;
/*===========================================================*/

/*========================网络对战============================*/
// 连接
#define CONNECTED			1		// 连接成功
#define DISCONNCECTED		2		// 失去连接
// 登录和注册
#define SIGN_IN				11		// 注册
#define LOG_IN				12		// 登录
#define SIGN_IN_SUCC		13		// 注册成功
#define LOG_IN_SUCC			14		// 登录成功
// 匹配和房间(20~39)
#define MATCH				20		// 匹配
#define MATCH_SUCC			21		// 匹配成功
#define MATCH_CANCEL		22		// 匹配取消
#define ROOM_PU				23		// 公开房间
#define	ROOM_PR				24		// 私有房间
#define	ROOM_NEW			25		// 新房间
#define	ROOM_ADD			26		// 加入房间
#define	ROOM_ADD_SUCC		27		// 加入房间成功
#define	ROOM_LEAVE			28		// (成员)离开房间
#define	ROOM_CLOSE			29		// (房主)关闭房间
#define	ROOM_START_GAME		30		// 开始房间游戏
#define	ROOM_INFO_LIST		31		// 房间列表
#define	ACCINFO				32		// 账号信息
// 对战中信息
#define	VICTORY				40		// 胜利
#define DEFEAT				41		// 失败
#define CHESSED				42		// 下棋
/*===========================================================*/

/*========================账号异常信息=======================*/
// 登录和注册异常
#define ACC_EXIST			-10		// 账号已存在
#define ACC_NONE			-11		// 账号不存在
#define ACC_LOGINED			-12		// 账号已登录
#define LOG_IN_FAILED_A		-13		// 登录失败(账号或密码不正确)
#define LOG_IN_FAILED_S		-14		// 登录失败(服务器信息)
// 房间
#define ROOM_KEY_ERROR		-21		// 房间密码错误
// 信息储存
#define SAVE_ERROR			-51		// 保存失败
#define READ_ERROR			-52		// 读取失败
/*===========================================================*/

/*========================棋局回放===========================*/
#define NEXT_CHESS		1		// 下一颗棋子
#define LAST_CHESS		0		// 上一颗棋子
#define GO_PLAY			false	// 播放
#define PLAY_PAUSE		true	// 暂停
#define AUTO_PLAY		1		// 自动播放
#define MANUAL_PALY		2		// 手动播放
/*================================================*/

#endif
