SRCS:=$(shell echo srcs/*.cpp)
OBJS=${SRCS:.cpp=.o}
FLAGS= -O2 -g -Wall -fmessage-length=0
LDFLAGS=
.SUFFIXES : .o .cpp
.cpp.o :
	cd ${<D}; g++ -c ${FLAGS} ${<F}
md : ${OBJS}
	g++ ${LDFLAGS} ${OBJS}
clean :
	rm -f srcs/*.o
	rm -f md
show :
	echo ${SRCS}
	echo ${OBJS}