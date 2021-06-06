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

	if (mysql_query(con, "SELECT * FROM Cars")) { // mysql client api , 
		finish_with_error(con);
	}	
	
	// machine language at memory which is query chunk, form is structure
	MYSQL_RES *result = mysql_store_result(con); 
	
	if (result == NULL) {
		finish_with_error(con);
	}
	
	int num_fields = mysql_num_fields(result); // catch number of column
	
	MYSQL_ROW row;
	
	while ((row  = mysql_fetch_row(result)))	// slice per row from result, this is momory chunk of row
	{ // row is type of array
		for (int i = 0; i < num_fields; ++i) {			// slice row chunk with column
			printf("%s ", row[i] ? row[i] : "NULL"); // if array has value, print that array
		}
		printf("\n");
	}
	
	// at last moment the condition of while comes to 0 , because there isn't row
	
	mysql_free_result(result); // return memory space
	mysql_close(con);

	return 0;
}
