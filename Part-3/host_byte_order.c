#include "unp.h"

int main(int argc, char *argv[])
{
	union {
		short n;
		char c[sizeof(short)];
	} un;

	un.n = 0x0102;
	printf("%s: ", CPU_VENDOR_OS);
	if (sizeof(short) == 2) {
		if (un.c[0] == 1 && un.c[1] == 2) {
			printf("big-endian\n");
		} else if (un.c[0] == 2 && un.c[1] == 1) {
			printf("little-endian\n");
		} else {
			printf("unknow\n");
		}
	} else {
		printf("sizeof(short) = %d\n", sizeof(short));
	}

	return 0;
}
