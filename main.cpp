#include<iostream>
#include"sqliteproxy.h"

using namespace std;

int main()
{
	// new
	SQLiteProxy *sp = new SQLiteProxy();

	bool res;
	res = sp->Exec("1.db","create table user(name varchar(20),age int)");
	cout << res << endl; // print 1 or 0
	res = sp->Exec("1.db","insert into user values('ciaos',25)");
	cout << res << endl; // print 1 or 0
	res = sp->Exec("1.db","delete from user");
	cout << res << endl; // print 1 or 0
	res = sp->Exec("1.db","insert into user values('ciaos',25)");
	cout << res << endl; // print 1 or 0

	DBResult dbr = sp->Query("1.db","select * from user");
	if(dbr.status){
		int index = dbr.nColumn;
		for(int i =1;i<=dbr.nRow;i++){
			for(int j =0;j<dbr.nColumn;j++){
				cout << dbr.result[j] << "=" << dbr.result[index] << "  ";
				// print "name=ciaos  age=25"
				index ++;
			}
			cout << endl;
		}
	}

	// delete
	delete sp;

	return 0;
}
