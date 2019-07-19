#/* -*- mode: fundamental; tab-width: 4; indent-tabs-mode: nil;  -*- */

SRCD = ../src
INCD = ../includes
GCCD = ../bat
LIBD = ../lib
OBJD = debug
TEST = ../test

BINDIR = ../bin
LIBDIR = ../lib

CC       = gcc
CINCLUDE = $(SRCD)/

CFLAGS  = -x c -Wextra -fno-builtin -std=c99
CFLAGS += -I $(CINCLUDE)
CFLAGS += -O2
CFLAGS += -fdiagnostics-show-option
CFLAGS += -W
CFLAGS += -Wno-long-long
LDFLAGS = -L.
CDEFS   =

RM     = rm
LS     = ls
MV     = mv
ERR    = .err
MKDIR  = mkdir
SLEEP  = sleep 3
DOS2UNIX = dos2unix

NAME   = main
T      = $(OBJD)/$(NAME).exe

OBJS = \
	$(OBJD)/main.o 
LIBS = \
	$(LIBD)/libboot.a

$(OBJS) : $(SRCD)/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(CDEFS) $< -o $@ 2>&1 | tee $(GCCD)/$(notdir $<$(ERR))	
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

all: prebuild clean $(OBJS) 

.PHONY: prebuild clean

prebuild:
	$(MKDIR) -p $(GCCD)/$(OBJD)

clean:
	$(RM) -f $(OBJS) $(GCCD)/*$(ERR)
	$(RM) -rf *.o *.bb *.bbg *.da *.gcno *.gcda *.info descriptions
	$(RM) -rf $(OBJD)/$(NAME).map $(T)

$(T): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CLGCOV) -Xlinker -Map=$(OBJD)/$(NAME).map 
