#ifndef __SQLITEPROXY_H
#define __SQLITEPROXY_H

#include<map>

extern "C"
{
#include"sqlite3.h"
}

using std::map;

typedef struct _DBConn
{
	sqlite3 *dbc;
}DBConn;

typedef struct _DBResult
{
	bool status;
	char **result;
	int nRow;
	int nColumn;
}DBResult;

class SQLiteProxy{

private:
	std::map<char *,DBConn>pxs;

	DBConn OpenSQLite(char *dbname){
		map<char *,DBConn>::iterator it = pxs.find(dbname);
		if(it == pxs.end()){
			DBConn dbp;
			dbp.dbc = NULL;

			int res = sqlite3_open(dbname,&dbp.dbc);
			if(res != SQLITE_OK){
				exit(-1);
			}
			pxs.insert(map<char *,DBConn>::value_type(dbname,dbp));
			return dbp;
		}
		else
		{
			return it->second;
		}
	}

public:
	SQLiteProxy(){
	}

	~SQLiteProxy(){
		int status;
		for(map<char *,DBConn>::iterator it = pxs.begin(), ite = pxs.end();it != ite;it ++){
			status = sqlite3_close(it->second.dbc);
			if(status != SQLITE_OK){
				exit(-1);
			}
		}
		pxs.clear();
	}

	//create|insert|update|delete ...
	bool Exec(char *dbname,char *sql){
		int res;
		char *err = NULL;
		DBConn db = OpenSQLite(dbname);

		res = sqlite3_exec(db.dbc,sql,0,0,&err);
		if(res != SQLITE_OK){
			return false;
		}
		return true;
	}

	//select
	DBResult Query(char *dbname,char *sql){
		int res;
		char *err = NULL;
		DBConn db = OpenSQLite(dbname);
		DBResult dbr;

		res = sqlite3_get_table(db.dbc,sql,&dbr.result,&dbr.nRow,&dbr.nColumn,&err);
		if(res == SQLITE_OK)
		{
			dbr.status = true;
			return dbr;
		}
		dbr.status = false;
		return dbr;
	}
};

#endif