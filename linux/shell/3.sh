#!/bin/bash

echo '$0' is $0
echo '$1' is $1
echo '$2' is $2
echo '$3' is $3
echo '$*' is $*
echo '$#' is $#

#set $1 as 11; set $2 as 22; set $3 as 33 
#set $4 as 44; set $5 as 55
#set $* as 11 22 33 44 55
#set $# as 5
set 11 22 33 44 55
echo

echo '$0' is $0
echo '$1' is $1
echo '$2' is $2
echo '$3' is $3
echo '$*' is $*
echo '$#' is $#

