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
    p = calloc(1, 1000000);
    if (p == NULL)
    {
        printf("insufficient memory\n");
        return (EXIT_FAILURE);
    }
    if (exeloadDoload(&entry_point, argv[1], &p) != 0)
    {
        printf("failed to load executable\n");
        return (EXIT_FAILURE);
    }
    genstart = (void *)entry_point;

    #if 1
    rc = genstart(exposfunc, NULL)
    #else
    rc = 0; 
    #endif
    printf("return from called program is %d\n", rc);
    printf("bios exiting\n");
    return (0);
}

static void exposfunc(void *cbdata, int funccode, void *retptr, char *str) 
{
     if (funccode == OS_PRINTF) printf(str);
    else if (funccode == OS_FOPEN)
    {
        printf("request received to open file %s\n", str);
    }
    else
    {
        printf("unknown request %d\n", funccode);
    }
    return;
}
