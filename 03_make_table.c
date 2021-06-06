#include <stdio.h>

#include "/usr/include/mysql/mysql.h"

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(void)
{	
	MYSQL *con = mysql_init(NULL);
	
	//exception 
	if (con == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));	
		exit(1); // return value to OS
	}
	
	if (mysql_real_connect(con, "localhost", "root", "tlzk%%1217", NULL, 3306, NULL, 0) == NULL) {

		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}		
	
	if (mysql_query(con, "USE testdb")) { // this is not neccessry, at function real_connect already selected

		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if (mysql_query(con, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(1,'Audi',52642)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(3,'Skoda',9000)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(4,'Volvo',29000)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(5,'Bentley',350000)")) {
		finish_with_error(con);
	}
	if (mysql_query(con, "INSERT INTO Cars VALUES(6,'Citroen',21000)")) {
		finish_with_error(con);
	}
	mysql_close(con);

	return 0;
}
