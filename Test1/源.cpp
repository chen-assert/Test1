#include<cstdio>
#include <setjmp.h>
#include<windows.h>
jmp_buf j;
bool k = 0;
void fun(void) {
	setjmp(j);
	if (k == 0) {
		k = 1;
		puts("���óɹ�,3..2..1");
		Sleep(3000);
		return;
	}
	puts("�ɹ�������������");
	Sleep(10000);
}
int main() {
	fun();
	longjmp(j, 1);
	return 0;
}