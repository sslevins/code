#include <stdio.h>

#include "mysql.h"

int main(int argc, char* argv[])
{
	MYSQL connection;
	mysql_init(&connection);

	if (!mysql_real_connect(&connection, 
				"localhost", 
				"root", "123456", "crashcourses", 
				0, NULL, 0))
	{
		printf("connect failed\n");
		printf("errer %d: %s\n", 
					mysql_errno(&connection), 
					mysql_error(&connection));
		
		return 1;
	}
	else
		printf("connect success\n");

	// char * sql = "INSERT INTO \
	products(prod_id, vend_id, prod_name, prod_price, prod_desc) \
	VALUES('TNT3', 1003, 'TNT (10 sticks)', 20, 'TNT, red, pack of 10 sticks')";
	// char * sql = "update products \
				set prod_desc = 'TNT, red, pack of 5 sticks' \
				where prod_id like 'TNT2'";
	char * sql = "select * from products where prod_id like 'TNT%'";

	int ret = mysql_query(&connection, sql);
	if (ret)
	{
		printf("query error %d: %s", 
					mysql_errno(&connection), 
					mysql_error(&connection));
	}
	else
		printf("query success\n");

	MYSQL_RES * res = mysql_use_result(&connection);
	MYSQL_ROW row; 
	int num = mysql_field_count(&connection);
	int i;
	while ((row = mysql_fetch_row(res)))
	{
		for (i = 0; i < num; i++)
			printf("%s \t", row[i]);

		printf("\n");
	}

	mysql_close(&connection);	
	
}

