#pragma once

#include "database_global.h"
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")
#include <QString>
#include <qhash.h>
#include <qdebug.h>
class DATABASE_EXPORT Database
{
public:
	Database();
	int InitAdo();
	struct path
	{
		int weapon;
		int imageid;
		int level;
		QString imgpath;
		QString iconpath;
	};
	path getPath(int num, int lev, int weapon);
	int read(_ConnectionPtr m_pconnection);
private:
	_ConnectionPtr m_pconnection;  //连接指针
	_RecordsetPtr m_pRecordset;
	QHash<int, path> hashp;
};
