#include <stdio.h>

void test(char *testd)
{
	printf("%lu\n", sizeof(*testd));
}

int main(void) {
	test("TEST12fadfsgewgegherydr3");
	return 0;
}
