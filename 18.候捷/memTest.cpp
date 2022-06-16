#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 32 * 1024 * 1024 * 1024

int main() {
    char* addr = (char*) malloc((long)MEM_SIZE);
    printf("主线程调用malloc后，目前共申请了 32gb 的虚拟内存\n");
    
    //循环频繁访问虚拟内存
    while(1) {
          printf("开始访问 32gb 大小的虚拟内存...\n");
          memset(addr, 0, (long)MEM_SIZE);
    }
    return 0;
}