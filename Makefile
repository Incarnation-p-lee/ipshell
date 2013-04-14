.SUFFIXES:
.SUFFIXES:.c .o .a .so
CC     =          gcc
CFLAG  =          -c -g -Wall
TARGET =          ipshell
DEPENDS=          fdependent
SRC    =          main.c general.c exit.c pwd.c cd.c
incn   =          ./inc
srcn   =          ./src
OBJ    =          $(patsubst %.c,%.o,$(SRC))
OBJA   =          $(addprefix ./obj/,$(OBJ))
INC    =          -I$(incn) -I$(srcn)
Flg    =          MASK

vpath %.o ./obj

.PHONY:all clean link

all:$(TARGET)

include $(DEPENDS)

$(TARGET):$(OBJ)
	$(MAKE) link

$(OBJ):%.o:%.c
	$(CC) $(CFLAG) $(INC) -o $@ $<
	mv $@ ./obj/

$(DEPENDS):$(SRC)
	set -e;\
	$(CC) -MM $(INC) $^ >info.$$$$;\
	sed "s/[a-z|A-Z|_][a-z|A-Z|_|0-9|\/]*\.c//g" <info.$$$$ >$@;\
	rm *.$$$$;\

link:$(OBJ)
	$(CC) $(INC) -o $(TARGET) $^

clean:
	@rm -rf ./obj/* $(OBJ)
	@rm -f $(TARGET) $(DEPENDS)
