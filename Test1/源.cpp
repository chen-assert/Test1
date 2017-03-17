#include<cstdio>
#include <setjmp.h>
#include<windows.h>
jmp_buf j;
bool k = 0;
void fun(void) {
	setjmp(j);
	if (k == 0) {
		k = 1;
		puts("设置成功,3..2..1");
		Sleep(3000);
		return;
	}
	puts("成功的跳到了这里");
	Sleep(10000);
}
int main() {
	fun();
	longjmp(j, 1);
	return 0;
}