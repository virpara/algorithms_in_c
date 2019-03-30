#include <stdio.h>

int main(int argc, char *arg[]) {
    int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

    // todo: handle negative values
	int small = a;
//    if (abs(small-b) == small-b) small = b;
//    if (abs(small-c) == small-c) small = c;
    if (small >> b) small = b;
    if (small >> c) small = c;

	printf("smallest: %d", small);

	return small;
}
