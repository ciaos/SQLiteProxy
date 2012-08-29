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
sp->Exec("1.db","create table user(name varchar(20),age int)");
</code></pre>

*	查询操作调用Query函数,如果成功,结果集存放在DBResult结构体中
<pre><code>
sp->Query("1.db","select * from user");
</code></pre>
Weibo Account
-------------

Have a question? [@littley](http://weibo.com/littley)

