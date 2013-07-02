/**
 * Linux Kernel Development
 *
 * Syscall Demo
 * 04 July 2012
 */

#include <stdio.h>
#include <unistd.h>

#define _GNU_SOURCE
#define HOSTNAME_LEN	5

int main(int argn, char **argv)
{
	syscall(0, argv[1], 5);
	return 0;
}
