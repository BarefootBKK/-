// music.cpp
#include "music.h"

Music::Music()
{

}

void Music::PlayMenuMusic()
{
	QString path = QDir::currentPath();

	player = new QMediaPlayer(this);

	playlist = new QMediaPlaylist(this);//初始化播放列表

	playlist->setPlaybackMode(QMediaPlaylist::Loop);//设置播放模式(顺序播放，单曲循环，随机播放等)

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/menu_bgm.mp3"));//添加歌曲，这里添加的是歌曲的路径

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/QiFengLe.wav"));//添加歌曲，这里添加的是歌曲的路径

	playlist->addMedia(QUrl::fromLocalFile(path + "/Music/He's a pirate.mp3"));//添加歌曲，这里添加的是歌曲的路径

	player->setPlaylist(playlist);  //设置播放列表

	player->play();//播放歌曲
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
