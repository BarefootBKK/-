// ChessBoard.cpp
#include "chessboard.h"

// ���캯��
ChessBoard::ChessBoard(QWidget* parent)
	: QLabel(parent)
{
	// ���� 15x15 ������
	this->chessboard = new int *[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
		this->chessboard[i] = new int[BOARD_SIZE];

	loadMaps();
	setBoardPattern(DEFAULT_PATTERN);

	this->c_Manager = new CManager();	// ʵ����
}

// ��������
// ɾ������(����)
ChessBoard::~ChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		delete[] chessboard[i];

	delete[] chessboard;
}

// ��ʼ��������Ϣ
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

	// ��ʼ����Ӧλ�����ӵı�ǣ���Ϊ 1�����ʾ��λ�������ӣ�Ϊ 0 ��û��
	// ���̴�С 15x15
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->chessboard[i][j] = CHESS_FREE;
		}
	}
}

// ������Ϸģʽ(����/�˻�/��������)
void ChessBoard::SetPattern(const int pattern)
{
	this->pattern = pattern;
}

// �����������
void ChessBoard::SetMyChess(const int chess)
{
	this->my_chess = chess;
}

// ��������������ʽ
void ChessBoard::SetLinePattern(QColor line_color, int line_size)
{
	this->line_color = line_color;
	this->line_size = line_size;
}

// �����������СԲ����ʽ
void ChessBoard::SetPointPattern(QColor point_color, int point_size)
{
	this->point_color = point_color;
	this->point_size  = point_size;
}

// �����˻��Ѷ�
void ChessBoard::SetAILevel(int level)
{
	this->level = level;
}

// ������Ϸ��ͼ
void ChessBoard::loadMaps()
{
	pix_BlackChess.load(":/Gobang/Image/Chess/black_chess.png");	// ���غ�����ͼ
	pix_WhiteChess.load(":/Gobang/Image/Chess/white_chess.png");	// ���ذ�����ͼ
	pix_Mark.load(":/Gobang/Image/Chess/mark4.png");				// ���ر����ͼ
}

// ����������ʽ
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

// ����paintEvent(��ͼ�¼�)
void ChessBoard::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	if (!flag)
	{
		// ��ʼ��ƫ����
		this->board_offset = (this->width() - C_WIDTH) / 2;
		this->chess_offset = CHESS_SIZE / 2;
	}

	QPainter * painter = new QPainter(this);
	painter->setRenderHint(QPainter::Antialiasing, true);	// ������
	painter->setPen(QPen(QBrush(line_color), line_size, Qt::SolidLine));	// ������������ɫ����ϸ���Ƿ�ʵ��(����)
	drawCheckerboard(painter);	// ������

	if (flag)
	{
		drawChess(painter);		// ������
	}
}

// ����mousePressEvent(������¼�)
void ChessBoard::mousePressEvent(QMouseEvent *event)
{
	// �����������
	if (event->button() == Qt::LeftButton && winner == 0 && !isLocked && pattern != REPLAY)
	{
		pos_x = event->pos().x();
		pos_y = event->pos().y();
		// �����ź�
		emit clicked();
	}
	//�����¼��������ദ��
	QLabel::mousePressEvent(event);
}

// ��ͼ
void ChessBoard::Draw()
{
	pix_CurrentChess = getChessPixmap(color);

	this->flag = 1;
	this->update();		// ˢ��
}

// ������
void ChessBoard::drawCheckerboard(QPainter * painter)
{
	// ������label�߽�ľ���(���������Ͻ�����)
	int start_pos = board_offset;

	// ������	x1��y1:��ʼ���ꣻx2,y2:�յ�����
	// ������
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		int x1 = start_pos;
		int x2 = start_pos + C_WIDTH;
		int y1 = C_P_WIDTH * i + start_pos;
		int y2 = C_P_WIDTH * i + start_pos;

		painter->drawLine(x1, y1, x2, y2);
	}
	// ������
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		int x1 = C_P_WIDTH * j + start_pos;
		int x2 = C_P_WIDTH * j + start_pos;
		int y1 = start_pos;
		int y2 = start_pos + C_WIDTH;

		painter->drawLine(x1, y1, x2, y2);
	}

	// ���������ʽ
	painter->setPen(point_color);		// ����ɫ
	painter->setBrush(point_color);		// �����ɫ

										// �������ϵ�5��СԲ��
	int pos = start_pos - point_size;	// "5"��Բ�뾶
	painter->drawEllipse(C_P_WIDTH * 3 + pos, C_P_WIDTH * 3 + pos, 10, 10);	// ����Բ��
	painter->drawEllipse(C_P_WIDTH * 11 + pos, C_P_WIDTH * 3 + pos, 10, 10);	// ����Բ��
	painter->drawEllipse(C_P_WIDTH * 7 + pos, C_P_WIDTH * 7 + pos, 10, 10);	// ����Բ��
	painter->drawEllipse(C_P_WIDTH * 3 + pos, C_P_WIDTH * 11 + pos, 10, 10);	// ����Բ��
	painter->drawEllipse(C_P_WIDTH * 11 + pos, C_P_WIDTH * 11 + pos, 10, 10);	// ����Բ��
}

// ������
/*
�˺�����Ҫʵ�����¹��ܣ�
1.���ݻ�ȡ�����������������ǰ���Ӹ������ĸ�λ��
2.���浱ǰ���ӵ�λ�ú���ͼ��Ϣ
3.��������״̬�����Ǹ����������ĸ���û�£�
4.��֮ǰ����������ػ�һ��
*/
void ChessBoard::drawChess(QPainter * painter)
{
	// ��֮ǰ��������������
	for (int i = 0; i < chesses.size(); i++)
	{
		painter->drawPixmap(chesses[i].x, chesses[i].y, CHESS_SIZE, CHESS_SIZE, getChessPixmap(chesses[i].color));
	}
	// �ж�����Ƿ�λ�������ڣ�������������⣬��������
	if (pos_x >= board_offset - PIXEL_ERROR && pos_x <= C_WIDTH + board_offset + PIXEL_ERROR &&
		pos_y >= board_offset - PIXEL_ERROR && pos_y <= C_WIDTH + board_offset + PIXEL_ERROR &&
		pos_x >= 0 && pos_y >= 0)
	{
		double x = (pos_x - board_offset) / C_P_WIDTH;
		double y = (pos_y - board_offset) / C_P_WIDTH;
		/*
		round() : ��������
		abs() : ����ֵ
		r_x:������������ (r_x + 1) ������
		r_y:������������ (r_y + 1) ������
		*/
		int r_x = round(x);
		int r_y = round(y);
		// ��������λ�����������Χ�ڣ����Ҹõ�û��������
		if (abs(x - r_x) <= MIN_ERROR && abs(y - r_y) <= MIN_ERROR && chessboard[r_x][r_y] == CHESS_FREE)
		{
			// ��������ӵ���Ϣ
			chessInfo.i = r_x;
			chessInfo.j = r_y;
			chessInfo.x = C_P_WIDTH * r_x + board_offset - chess_offset;
			chessInfo.y = C_P_WIDTH * r_y + board_offset - chess_offset;
			chessInfo.color = color;
			chesses.push_back(chessInfo);

			chessboard[r_x][r_y] = color;		// �������״̬

			painter->drawPixmap(chessInfo.x, chessInfo.y, CHESS_SIZE, CHESS_SIZE, pix_CurrentChess);	// ������
			painter->drawPixmap(chessInfo.x, chessInfo.y, CHESS_SIZE, CHESS_SIZE, pix_Mark);			// �����

			analysisGame();		// ������֣��ж��Ƿ���ʤ��
		}
	}
}

// ������֣�����Ƿ���ʤ��
void ChessBoard::analysisGame()
{
	// ��Ϊ�����˻����������������������Ϣ��һ��ʤ��ʱ������Ϣ��Ľ��̶���
	if (pattern == PVP_ONLINE)
	{
		emit chessed();
	}

	// �ж�ʤ��
	winner = c_Manager->getWinner(GetChessBoard(), chessInfo.i, chessInfo.j, color);

	if (winner == BLACK)
	{
		messageDialog.SetMsgText("����ʤ��");
	}
	else if (winner == WHITE)
	{
		messageDialog.SetMsgText("����ʤ��");
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

// �¿�������ɫ
void ChessBoard::getNextColor()
{
	if (color == BLACK)
		color = WHITE;
	else
		color = BLACK;
}

// ai�߳�
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

// �����߳�
void ChessBoard::threadStop()
{
	ai_thread->quit();
}

// ��Ϸ(ai)����
void ChessBoard::Gameover()
{
	if (pattern == PVE)
	{
		emit ai_gameover();
		disconnect(levelDialog);
	}
}

// ����ai�����������
void ChessBoard::AI_Step(int x, int y)
{
	pos_x = x * C_P_WIDTH + board_offset;
	pos_y = y * C_P_WIDTH + board_offset;

	Draw();
}

// ��ȡ������ͼ
QPixmap ChessBoard::getChessPixmap(int current_color)
{
	if (current_color == BLACK)
		return pix_BlackChess;		// ����
	else
		return pix_WhiteChess;		// ����
}

// ����
void ChessBoard::Undo()
{
	if (chesses.size() > 0)
	{
		// ��ԭ��һ�����״̬
		winner = CHESS_FREE;
		int x = chesses.back().x / C_P_WIDTH;
		int y = chesses.back().y / C_P_WIDTH;
		color = chesses.back().color;
		chessboard[x][y] = CHESS_FREE;
		// ��������
		pos_x = -1;
		pos_y = -1;
		chesses.pop_back();

		if (pattern == PVE)
			emit ai_undo();

		// ������һ�������
		Draw();
	}
}

// ���¿�ʼ
void ChessBoard::Restart()
{
	if (pattern == PVE)
	{
		emit ai_gameover();
		disconnect(levelDialog);
	}
	InitChessBoard(pattern, first);	// ��ʼ�����

	Draw();
}

// ����
void ChessBoard::DrawOpponent(ChessNode * chess)
{
	pos_x = chess->i * C_P_WIDTH + board_offset;
	pos_y = chess->j * C_P_WIDTH + board_offset;
	color = chess->color;

	Draw();
}

// ����һ��������
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

// ��ס�ҷ�����
void ChessBoard::LockMyChess()
{
	isLocked = true;
	getNextColor();
}

// �����ҷ�����
void ChessBoard::UnlockMyChess()
{
	isLocked = false;
	getNextColor();
}

// ��ȡ��ǰ������ɫ
int ChessBoard::GetChessColor()
{
	return color;
}

// ��ȡ��ǰ����
int ** ChessBoard::GetChessBoard()
{
	return chessboard;
}

// ��ȡʤ��
int ChessBoard::GetWinner()
{
	return winner;
}

// ��ȡ����
QVector<ChessNode> ChessBoard::GetBoardInfo()
{
	return chesses;
}

// ��ȡ��ǰ�µ�������Ϣ
ChessNode * ChessBoard::GetChessInfo()
{
	return &chessInfo;
}
