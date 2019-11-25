CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

card_effects.o: card_effects.h card_effects.c dominion.h
	gcc -c card_effects.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o card_effects.o
	gcc -c dominion.c -g card_effects.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o card_effects.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o card_effects.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o card_effects.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o card_effects.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o card_effects.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o card_effects.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

unittest5: unittest5.c dominion.o rngs.o card_effects.o
	gcc -o unittest5 unittest5.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

tests: unittest1 unittest2 unittest3 unittest4 unittest5 randomtestcard1 randomtestcard2 randomtestcard3 dominion.c
	./unittest1 &> testresult.out
	./unittest2 &> testresult.out
	./unittest3 &> testresult.out
	./unittest4 &> testresult.out
	./unittest5 &> testresult.out
	./randomtestcard1 &> testresult.out
	./randomtestcard2 &> testresult.out
	./randomtestcard3 &> testresult.out
	gcov -b -f dominion.c >> testresult.out

unittestresult: unittest1 unittest2 unittest3 unittest4 unittest5 dominion.c
	./unittest1 &> unittestresult.out
	./unittest2 &> unittestresult.out
	./unittest3 &> unittestresult.out
	./unittest4 &> unittestresult.out
	./unittest5 &> unittestresult.out
	gcov -b -f dominion.c >> unittestresult.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o card_effects.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o card_effects.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

randomtestcard3: randomtestcard3.c dominion.o rngs.o card_effects.o
	gcc -o randomtestcard3 randomtestcard3.c -g dominion.o rngs.o card_effects.o $(CFLAGS)

randomtestresults: randomtestcard1 randomtestcard2 randomtestcard3 dominion.c
	./randomtestcard1 &> randomtestresults.out
	./randomtestcard2 &> randomtestresults.out
	./randomtestcard3 &> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o card_effects.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe