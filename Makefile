.SUFFIXES:
.SUFFIXES:.c .o .a .so
CC     =          gcc
CFLAG  =          -c -g -Wall
TARGET =          ipshell
SRC    =          main.c general.c exit.c pwd.c cd.c
incn   =          ./inc
srcn   =          ./src
OBJ    =          $(patsubst %.c,%.o,$(SRC))
OBJA   =          $(addprefix ./obj/,$(OBJ))
INC    =          -I$(incn) -I$(srcn)

.PHONY:all clean

all:$(OBJ) $(TARGET)

$(TARGET):$(OBJA)
	$(CC) -o $@ $^

$(OBJ):%.o:%.c
	$(CC) $(CFLAG) $(INC) -o $@ $<
	mv $@ ./obj/

clean:
	@rm -rf ./obj/*
	@rm -f $(TARGET)
