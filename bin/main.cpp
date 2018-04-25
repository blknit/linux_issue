#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void * h = dlopen("/home/tongqing.liu/git/linux_issue/build/bin/libtestso.so",RTLD_NOW);
	printf("libso=%x\n",h);
	getchar();
	if(h)dlclose(h);
	printf("dlclose libso\n");
	getchar();
}
