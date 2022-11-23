CC=gcc
CCOPTS=--std=gnu99 -Wall -g

HEADERS=common.h\
	disk.h

OBJS=disk.o

LIBS=libs.a

BINS=filesystem

.phony: clean all

all:	$(LIBS) $(BINS)

%.o:	%.c $(HEADERS)
	$(CC) $(CCOPTS) -c -o $@ $<

libs.a: $(OBJS) $(HEADERS) 
	$(AR) -rcs $@ $^
	$(RM) $(OBJS)

filesystem:	main.c $(LIBS)
	$(CC) $(CCOPTS) -o $@ $^

clean:
	rm -rf *.o *~ $(LIBS) $(BINS)