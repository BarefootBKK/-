// ranklist
#include "ranklist.h"

RankList::RankList()
{

}

QString RankList::GetRankList()
{
	return QString();
}

void RankList::ReadRankList()
{

	QDir dir(QDir::currentPath() + "/Account");
	QStringList nameFilters;
	nameFilters << "*.jpg" << "*.png";
	QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);

	for (int i = 0; i < files.length(); i++)
		qDebug() << files.at(i);
}