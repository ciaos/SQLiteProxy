SQLiteProxy
=====================
封装一个简单的C++操作SQLite类
* * *

功能描述
-----------

> 操作SQLite数据库,维持多个SQLite数据库连接不关闭

使用方法
----------

*	声明一个操作对象
<pre><code>
SQLiteProxy *sp = new SQLiteProxy();
</code></pre>

*	创建数据表,插入更新删除等操作调用Exec函数,返回成功或失败信息
<pre><code>
bool res;
res = sp->Exec("1.db","create table user(name varchar(20),age int)");
cout << res << endl; // print 1 or 0
res = sp->Exec("1.db","insert into user values('ciaos',25)");
cout << res << endl; // print 1 or 0
res = sp->Exec("1.db","delete from user");
cout << res << endl; // print 1 or 0
res = sp->Exec("1.db","insert into user values('ciaos',25)");
cout << res << endl; // print 1 or 0
</code></pre>

*	查询操作调用Query函数,如果成功,结果集存放在DBResult结构体中
<pre><code>
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
}</code></pre>
Weibo Account
-------------

Have a question? [@littley](http://weibo.com/littley)

