CREATE TABLE children (
	childno 	int 		NOT NULL 	AUTO_INCREMENT, 
	fname 	char(30)	NOT NULL, 
	age 		int(11)	NOT NULL, 
	primary key (childno) 
) ENGINE=InnoDB;

INSERT INTO children(fname, age) VALUES ('Jenny',21);
INSERT INTO children(fname, age) VALUES ('Andrew',17);
INSERT INTO children(fname, age) VALUES ('Gavin',8);
INSERT INTO children(fname, age) VALUES ('Duncan',6);
INSERT INTO children(fname, age) VALUES ('Emma',4);
INSERT INTO children(fname, age) VALUES ('Alex',15);
INSERT INTO children(fname, age) VALUES ('Adrian',9);

