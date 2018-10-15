IDIR =../include
CC=gcc
CXX=g++
CFLAGS=-g -Wall -Wextra -lgtest -lpthread -fprofile-arcs -ftest-coverage -I$(IDIR) -std=c++11
CFLAGS2=-g -fprofile-arcs -ftest-coverage -I$(IDIR)

ODIR=obj
LDIR =../lib

_DEPS = conta_linhas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_conta_linhas.o conta_linhas.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

conta_linha_make conta_linhas: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 


