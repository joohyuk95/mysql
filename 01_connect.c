#include <stdio.h>

//sudo apt install libmysqlclient-dev
#include "/usr/include/mysql/mysql.h"

int main(void)
{
	MYSQL mysql;
	mysql_init(&mysql);
	
	if (!mysql_real_connect(&mysql, "localhost", "root", "tlzk%%1217", "sys", 3306, NULL, 0))
		printf("connect error \n");
	else
		printf("connect success \n");

	mysql_close(&mysql);
	
	printf("test~! \n");
	
	return 0;
}
