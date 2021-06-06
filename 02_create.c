#include <stdio.h>

#include "/usr/include/mysql/mysql.h"

int main(void)
{	
	MYSQL *con = mysql_init(NULL);
	
	//exception
	if (con == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));	
		exit(1); // value to OS
	}
	
	if (mysql_real_connect(con, "localhost", "root", "tlzk%%1217", NULL, 3306, NULL, 0) == NULL) {

		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}		
	
	if (mysql_query(con, "CREATE DATABASE testdb")) {
		
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}	
	
	mysql_close(con);

	return 0;
}
