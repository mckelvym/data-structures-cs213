CC=g++
CFLAGS=-I/usr/include -L/usr/lib
LDFLAGS=-lglui -lglut -lGLU -lGL -lXmu
BINDIR=~/bin
PROGS=gol

all: ${PROGS}
	make install -s
clean:
	rm -f ${PROGS} *.o *~
install:
	cp ${PROGS} ${BINDIR}


PARTICLE_SYSTEM_OBJECTS=gol.o random.o
gol : ${PARTICLE_SYSTEM_OBJECTS}
	${CC} -o $@ ${PARTICLE_SYSTEM_OBJECTS} ${CFLAGS} ${LDFLAGS}

