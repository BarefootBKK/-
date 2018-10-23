// music.h
#pragma once

#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <QtWidgets/QApplication>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QDir>
	
class Music : public QObject
{
	Q_OBJECT

public:

	Music();

public slots:
	void PlayMenuMusic();
	void PlayClickedMusic();
	void PlayWinMusic();
	void PlayPause();
	void NextSong();

private:
	QMediaPlayer * player;
	QMediaPlaylist * playlist;
};

#endif
