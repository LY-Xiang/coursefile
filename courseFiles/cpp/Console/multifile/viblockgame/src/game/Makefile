include ../src-conf.mk

OBJS = blockgame.o $(blockgame2p_obj) game.o wonlost.o
HEADERS = blockgame.h ../timer.h ../input/input.h ../draw/draw.h

game.a: $(OBJS)
	ar rs game.a $(OBJS)

blockgame.o: blockgame.c $(HEADERS)
	$(CC) $(CCFLAGS) -I..  -c blockgame.c

blockgame2p.o: blockgame2p.c blockgame2p.h $(HEADERS) ../netw/sock.h ../src-conf.mk
	$(CC) $(CCFLAGS) -I.. $(DSOCKET) -c blockgame2p.c

game.o: game.c game.h blockgame.h blockgame2p.h ../options.h ../input/input.h \
	../netw/sock.h ../hiscore.h ../menu/menu.h ../src-conf.mk
	$(CC) $(CCFLAGS) -I.. $(DTWOPLAYER) $(DJOYSTICK) $(DSOCKET) $(DNO_MENU) -c game.c

wonlost.o: wonlost.c game.h ../options.h
	$(CC) $(CCFLAGS) -c wonlost.c

clean:
	rm -f game.a blockgame.o blockgame2p.o game.o wonlost.o

.PHONY: clean
