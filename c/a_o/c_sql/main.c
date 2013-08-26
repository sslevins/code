#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char * argv[]) {
	MYSQL * conn_ptr;

	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) {
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}

	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "", "foo", 0, NULL, 0);
	if (conn_ptr) {
		printf("Connection success\n");
		int res = mysql_query(conn_ptr, "INSERT INTO children(fname, age) values('Ann', 3)");
		if (!res) {
			printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(conn_ptr));
		}
		else
			fprintf(stderr, "Connection error %d: %s", 
					mysql_errno(conn_ptr), mysql_error(conn_ptr));

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
