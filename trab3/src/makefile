IDIR =../include
CC=gcc
CXX=g++
CFLAGS=-fprofile-arcs -ftest-coverage -I$(IDIR)

ODIR=obj
LDIR =../lib

_DEPS = conta_linhas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_conta_linhas.o conta_linhas.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

conta_linhas_make cont_linhas: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 


