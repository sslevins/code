#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char * argv[]) {
	MYSQL * conn_ptr;
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;

	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}

	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "", "foo", 0, NULL, 0);
	if (conn_ptr) {
		printf("Connection success\n");
		int res = mysql_query(conn_ptr, "select childno, fname, age from children where age > 5");
		if (res)
			printf("Select error: %s", mysql_error(conn_ptr));
		else
		{
			res_ptr = mysql_store_result(conn_ptr);
			if (res_ptr) {
				printf("Retrieved %lu rows\n", (unsigned long)mysql_num_rows(res_ptr));
				while ((sqlrow = mysql_fetch_row(res_ptr)))
					printf("Fetched data...\n");
			}
			mysql_free_result(res_ptr);
		}

		mysql_close(conn_ptr);
	}
	else {
		printf("Connection failed\n");
		if (mysql_errno(conn_ptr)) {
			fprintf(stderr, "Connection error %d: %s", 
					mysql_errno(conn_ptr), mysql_error(conn_ptr));
		}
	}

	
	
	return EXIT_SUCCESS;
}
