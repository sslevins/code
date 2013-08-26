#include <stdio.h>
#include <stdlib.h>

#include "mysql .h"

MYSQL my_connection;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;

void display_header();
void display_row();

int main()
{
	int res;
	int first_row = 1;

	mysql_init(&my_connection);
	if (mysql_real_connect(&my_connection, "localhost", "root", "", "foo", 0, NULL, 0))
	{
		printf("Connection success\n");
	}
	else
	{
		printf("Connection failed\n");
		printf("Connection error %d: %s\n", 
			mysql_errno(&my_connection),
			mysql_error(&my_connection));

		return 1;
	}

	res = mysql_query(&my_connection, 
		"select childno, fname, age from children where age > 5");
	if (res) {
		printf("selecte error: %s\n", mysql_error(&my_connection));
		return 1;
	}

	res_ptr = mysql_use_result(&my_connection);
	if (res_ptr) {
		while ((sqlrow = mysql_fetch_row(res_ptr))) {
			if (first_row) {
				display_header();
				first_row = 0;
			}
			display_row();
		}
		if (mysql_errno(&my_connection)) 
			printf("Retrive error: %s\n", 
				mysql_error(&my_connection));

		mysql_free_result(res_ptr);
	}
}



