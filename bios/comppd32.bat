del *.o
del osworld.exe

gccwin -S -Os -fno-common -I. -o osworld.s osworld.c
aswin -o osworld.o osworld.s
del osworld.s

gccwin -S -Os -fno-common -I. -o genstart.s genstart.c
aswin -o genstart.o genstart.s
del genstart.s
