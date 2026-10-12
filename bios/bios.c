#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "exeload.h"
#include "osfunc.h"

static int (*genstart)(void (*exposfunc)(void *cbdata, int funccode, void *retptr, char *str), void *cbdata);

static void exposfunc(void *cbdata, int funccode, void *retptr, char *str);

int main(int argc, char **argv) 
{
    unsigned char *p;
    unsigned char *entry_point;
    int rc;
    printf("bios starting\n");
    if (argc < 3)
    {
        printf("Usage: bios os.exe disk.img\n");
        return (EXIT_FAILURE);
    }
