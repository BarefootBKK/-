// music.cpp
#include "music.h"

Music::Music()
{

}

void Music::PlayMenuMusic()
{
	QString path = QDir::currentPath();

	player = new QMediaPlayer(this);

	playlist = new QMediaPlaylist(this);//��ʼ�������б�

	playlist->setPlaybackMode(QMediaPlaylist::Loop);//���ò���ģʽ(˳�򲥷ţ�����ѭ����������ŵ�)

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/menu_bgm.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/QiFengLe.wav"));//��Ӹ�����������ӵ��Ǹ�����·��

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/He's a pirate.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

	player->setPlaylist(playlist);  //���ò����б�

	player->play();//���Ÿ���
}

void Music::PlayClickedMusic()
{

}

void Music::PlayWinMusic()
{

}

void Music::PlayPause()
{
	player->pause();
}

void Music::NextSong()
{
	int currentIndex = playlist->currentIndex();
	if (++currentIndex == playlist->mediaCount()) currentIndex = 0;
	playlist->setCurrentIndex(currentIndex);
	player->play();
}
