all: tokenizer


tokenizer: tokenizer.o history.o mainui.o
	cc -o tokenizer tokenizer.o mainui.o history.o


clean:
	rm -f *.o tokenizer

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h tokenizer.h history.c

mainui.o: mainui.c tokenizer.h history.h
