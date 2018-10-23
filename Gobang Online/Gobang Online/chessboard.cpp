// ChessBoard.cpp
#include "chessboard.h"

// 构造函数
ChessBoard::ChessBoard(QWidget* parent)
	: QLabel(parent)
{
	// 开辟 15x15 的棋盘
	this->chessboard = new int *[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
		this->chessboard[i] = new int[BOARD_SIZE];

	loadMaps();
	setBoardPattern(DEFAULT_PATTERN);

	this->c_Manager = new CManager();	// 实例化
}

// 析构函数
// 删除棋盘(数组)
ChessBoard::~ChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		delete[] chessboard[i];

	delete[] chessboard;
}

// 初始化棋盘信息
void ChessBoard::InitChessBoard(int pattern, int first)
{
	this->flag = 0;
	this->pos_x = -1;
	this->pos_y = -1;
	this->color = BLACK;
	this->first = first;
	this->winner = CHESS_FREE;
	this->chesses.clear();
	this->pattern = pattern;

	if (pattern == PVE)
	{
		levelDialog = new LevelDialog();
		levelDialog->setModal(true);
		levelDialog->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
		connect(levelDialog, SIGNAL(ai_level(int)), this, SLOT(aiThread(int)));
		levelDialog->show();
	}

	if (first == PLAYER_1)
	{
		this->my_chess = BLACK;
		this->isLocked = false;
	}
	else
	{
		this->my_chess = WHITE;
		this->isLocked = true;
	}

	// 初始化对应位置棋子的标记，若为 1，则表示该位置有棋子，为 0 则没有
	// 棋盘大小 15x15
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->chessboard[i][j] = CHESS_FREE;
		}
	}
}

// 设置游戏模式(联机/人机/本地人人)
void ChessBoard::SetPattern(const int pattern)
{
	this->pattern = pattern;
}

// 设置先手玩家
void ChessBoard::SetMyChess(const int chess)
{
	this->my_chess = chess;
}

// 设置棋盘线条样式
void ChessBoard::SetLinePattern(QColor line_color, int line_size)
{
	this->line_color = line_color;
	this->line_size = line_size;
}

// 设置棋盘五个小圆点样式
void ChessBoard::SetPointPattern(QColor point_color, int point_size)
{
	this->point_color = point_color;
	this->point_size  = point_size;
}

// 设置人机难度
void ChessBoard::SetAILevel(int level)
{
	this->level = level;
}

// 加载游戏贴图
void ChessBoard::loadMaps()
{
	pix_BlackChess.load(":/Gobang/Image/Chess/black_chess.png");	// 加载黑棋贴图
	pix_WhiteChess.load(":/Gobang/Image/Chess/white_chess.png");	// 加载白棋贴图
	pix_Mark.load(":/Gobang/Image/Chess/mark4.png");				// 加载标记贴图
}

// 设置棋盘样式
void ChessBoard::setBoardPattern(int board_pattern)
{
	if (board_pattern == DEFAULT_PATTERN)
	{
		this->line_color = QColor(255, 255, 255, 255);
		this->line_size = 2;
		this->point_color = Qt::gray;
		this->point_size = 5;
	}
}

// 重载paintEvent(绘图事件)
void ChessBoard::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	if (!flag)
	{
		// 初始化偏移量
		this->board_offset = (this->width() - C_WIDTH) / 2;
		this->chess_offset = CHESS_SIZE / 2;
	}

	QPainter * painter = new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing, true);	// 反走样
	painter->setPen(QPen(QBrush(line_color), line_size, Qt::SolidLine));	// 设置线条的颜色、粗细、是否实线(虚线)
	drawCheckerboard(painter);	// 画棋盘

	if (flag)
	{
		drawChess(painter);		// 画棋子
	}
}

// 重载mousePressEvent(鼠标点击事件)
void ChessBoard::mousePressEvent(QMouseEvent *event)
{
	// 若鼠标左键点击
	if (event->button() == Qt::LeftButton && winner == 0 && !isLocked && pattern != REPLAY)
	{
		pos_x = event->pos().x();
		pos_y = event->pos().y();
		// 发射信号
		emit clicked();
	}
	//将该事件传给父类处理
	QLabel::mousePressEvent(event);
}

// 绘图
void ChessBoard::Draw()
{
	pix_CurrentChess = getChessPixmap(color);

	this->flag = 1;
	this->update();		// 刷新
}

// 画棋盘
void ChessBoard::drawCheckerboard(QPainter * painter)
{
	// 棋盘离label边界的距离(即棋盘左上角坐标)
	int start_pos = board_offset;

	// 画棋盘	x1，y1:起始坐标；x2,y2:终点坐标
	// 画横线
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		int x1 = start_pos;
		int x2 = start_pos + C_WIDTH;
		int y1 = C_P_WIDTH * i + start_pos;
		int y2 = C_P_WIDTH * i + start_pos;

		painter->drawLine(x1, y1, x2, y2);
	}
	// 画竖线
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		int x1 = C_P_WIDTH * j + start_pos;
		int x2 = C_P_WIDTH * j + start_pos;
		int y1 = start_pos;
		int y2 = start_pos + C_WIDTH;

		painter->drawLine(x1, y1, x2, y2);
	}

	// 设置填充样式
	painter->setPen(point_color);		// 边颜色
	painter->setBrush(point_color);		// 填充颜色

										// 画棋盘上的5个小圆点
	int pos = start_pos - point_size;	// "5"是圆半径
	painter->drawEllipse(C_P_WIDTH * 3 + pos, C_P_WIDTH * 3 + pos, 10, 10);	// 左上圆点
	painter->drawEllipse(C_P_WIDTH * 11 + pos, C_P_WIDTH * 3 + pos, 10, 10);	// 右上圆点
	painter->drawEllipse(C_P_WIDTH * 7 + pos, C_P_WIDTH * 7 + pos, 10, 10);	// 中心圆点
	painter->drawEllipse(C_P_WIDTH * 3 + pos, C_P_WIDTH * 11 + pos, 10, 10);	// 左下圆点
	painter->drawEllipse(C_P_WIDTH * 11 + pos, C_P_WIDTH * 11 + pos, 10, 10);	// 右下圆点
}

// 画棋子
/*
此函数主要实现以下功能：
1.根据获取到的鼠标坐标计算出当前棋子该下在哪个位置
2.保存当前棋子的位置和贴图信息
3.更新棋盘状态（即那个点下了棋哪个点没下）
4.把之前保存的棋子重绘一遍
*/
void ChessBoard::drawChess(QPainter * painter)
{
	// 画之前保存下来的棋子
	for (int i = 0; i < chesses.size(); i++)
	{
		painter->drawPixmap(chesses[i].x, chesses[i].y, CHESS_SIZE, CHESS_SIZE, getChessPixmap(chesses[i].color));
	}
	// 判断鼠标是否位于棋盘内，若鼠标点击棋盘外，不能下棋
	if (pos_x >= board_offset - PIXEL_ERROR && pos_x <= C_WIDTH + board_offset + PIXEL_ERROR &&
		pos_y >= board_offset - PIXEL_ERROR && pos_y <= C_WIDTH + board_offset + PIXEL_ERROR &&
		pos_x >= 0 && pos_y >= 0)
	{
		double x = (pos_x - board_offset) / C_P_WIDTH;
		double y = (pos_y - board_offset) / C_P_WIDTH;
		/*
		round() : 四舍五入
		abs() : 绝对值
		r_x:从左往右数第 (r_x + 1) 个棋子
		r_y:从上往下数第 (r_y + 1) 个棋子
		*/
		int r_x = round(x);
		int r_y = round(y);
		// 如果鼠标点击位置在误差允许范围内，并且该点没下有棋子
		if (abs(x - r_x) <= MIN_ERROR && abs(y - r_y) <= MIN_ERROR && chessboard[r_x][r_y] == CHESS_FREE)
		{
			// 保存该棋子的信息
			chessInfo.i = r_x;
			chessInfo.j = r_y;
			chessInfo.x = C_P_WIDTH * r_x + board_offset - chess_offset;
			chessInfo.y = C_P_WIDTH * r_y + board_offset - chess_offset;
			chessInfo.color = color;
			chesses.push_back(chessInfo);

			chessboard[r_x][r_y] = color;		// 更新棋局状态

			painter->drawPixmap(chessInfo.x, chessInfo.y, CHESS_SIZE, CHESS_SIZE, pix_CurrentChess);	// 画棋子
			painter->drawPixmap(chessInfo.x, chessInfo.y, CHESS_SIZE, CHESS_SIZE, pix_Mark);			// 画标记

			analysisGame();		// 分析棋局，判断是否有胜者
		}
	}
}

// 分析棋局，检查是否有胜者
void ChessBoard::analysisGame()
{
	// 若为联网人机，先向服务器发送棋子信息，一方胜利时产生消息框的进程堵塞
	if (pattern == PVP_ONLINE)
	{
		emit chessed();
	}

	// 判断胜负
	winner = c_Manager->getWinner(GetChessBoard(), chessInfo.i, chessInfo.j, color);

	if (winner == BLACK)
	{
		messageDialog.SetMsgText("黑棋胜利");
	}
	else if (winner == WHITE)
	{
		messageDialog.SetMsgText("白棋胜利");
	}

	if (!winner)
	{
		getNextColor();

		if (pattern != PVP_LOCAL)
		{
			if (color != my_chess)
				isLocked = true;
			else
				isLocked = false;
		}
		
		if (pattern == PVE)
		{
			if (color != my_chess && isLocked)
			{
				emit ai_step(chessInfo.i, chessInfo.j);
			}
		}
	}
}

// 下颗棋子颜色
void ChessBoard::getNextColor()
{
	if (color == BLACK)
		color = WHITE;
	else
		color = BLACK;
}

// ai线程
void ChessBoard::aiThread(int ai_level)
{
	ai_thread = new AIThread(Q_NULLPTR, first, ai_level);
	connect(ai_thread, SIGNAL(result(int, int)), this, SLOT(AI_Step(int, int)));
	connect(ai_thread, SIGNAL(thread_stop()), this, SLOT(threadStop()));
	connect(this, SIGNAL(ai_step(int, int)), ai_thread, SLOT(StartThinking(int, int)));
	connect(this, SIGNAL(ai_undo()), ai_thread, SLOT(AIUndo()));
	connect(this, SIGNAL(ai_restart(int)), ai_thread, SLOT(AIRestart(int)));
	connect(this, SIGNAL(ai_gameover()), ai_thread, SLOT(GameOver()));

	ai_thread->start();
}

// 结束线程
void ChessBoard::threadStop()
{
	ai_thread->quit();
}

// 游戏(ai)结束
void ChessBoard::Gameover()
{
	if (pattern == PVE)
	{
		emit ai_gameover();
		disconnect(levelDialog);
	}
}

// 画出ai计算出的棋子
void ChessBoard::AI_Step(int x, int y)
{
	pos_x = x * C_P_WIDTH + board_offset;
	pos_y = y * C_P_WIDTH + board_offset;

	Draw();
}

// 获取棋子贴图
QPixmap ChessBoard::getChessPixmap(int current_color)
{
	if (current_color == BLACK)
		return pix_BlackChess;		// 黑棋
	else
		return pix_WhiteChess;		// 白棋
}

// 悔棋
void ChessBoard::Undo()
{
	if (chesses.size() > 0)
	{
		// 还原上一步棋局状态
		winner = CHESS_FREE;
		int x = chesses.back().x / C_P_WIDTH;
		int y = chesses.back().y / C_P_WIDTH;
		color = chesses.back().color;
		chessboard[x][y] = CHESS_FREE;
		// 弹出棋子
		pos_x = -1;
		pos_y = -1;
		chesses.pop_back();

		if (pattern == PVE)
			emit ai_undo();

		// 画出上一步的棋局
		Draw();
	}
}

// 重新开始
void ChessBoard::Restart()
{
	if (pattern == PVE)
	{
		emit ai_gameover();
		disconnect(levelDialog);
	}
	InitChessBoard(pattern, first);	// 初始化棋局

	Draw();
}

// 对手
void ChessBoard::DrawOpponent(ChessNode * chess)
{
	pos_x = chess->i * C_P_WIDTH + board_offset;
	pos_y = chess->j * C_P_WIDTH + board_offset;
	color = chess->color;

	Draw();
}

// 画下一步的棋子
void ChessBoard::DrawNextChess(ChessNode chess, int play_mode)
{
	if (play_mode == NEXT_CHESS)
	{
		chesses.push_back(chess);
	}
	else if (play_mode == LAST_CHESS)
	{
		if (chesses.size() > 0)
			chesses.pop_back();
	}

	Draw();
}

// 锁住我方棋子
void ChessBoard::LockMyChess()
{
	isLocked = true;
	getNextColor();
}

// 解锁我方棋子
void ChessBoard::UnlockMyChess()
{
	isLocked = false;
	getNextColor();
}

// 获取当前棋子颜色
int ChessBoard::GetChessColor()
{
	return color;
}

// 获取当前棋盘
int ** ChessBoard::GetChessBoard()
{
	return chessboard;
}

// 获取胜者
int ChessBoard::GetWinner()
{
	return winner;
}

// 获取棋盘
QVector<ChessNode> ChessBoard::GetBoardInfo()
{
	return chesses;
}

// 获取当前下的棋子信息
ChessNode * ChessBoard::GetChessInfo()
{
	return &chessInfo;
}
