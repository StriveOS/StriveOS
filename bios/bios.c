#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "exeload.h"
#include "osfunc.h"

static int (*genstart)(void (*exposfunc)(void *cbdata, int funccode, void *retptr, char *str), void *cbdata);

static void exposfunc(void *cbdata, int funccode, void *retptr, char *str);