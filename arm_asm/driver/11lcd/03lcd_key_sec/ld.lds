SECTIONS
{
	. = 0x0;
	.text : {*(.text);}
	
	. = ALIGN(4);
	.data : {*(.data);}

	. = ALIGN(4);
	.bss : {*(.bss);}
}
