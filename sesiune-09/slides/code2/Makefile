TEXFILES = inittraps.tex paging.tex interrupt.tex idle.tex skbuf.tex skbuff.tex create.tex rcv.tex sock.tex

ifeq (3, $(shell highlight --version | head -2 | tail -1 | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1))
	HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K tiny -S bash -c highlight.sty
else
	HIGHLIGHT_OPTS = -L -l -f -t 8 -K tiny -S bash -c highlight.sty
endif

all: $(TEXFILES)

create.tex: create.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

rcv.tex: rcv.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

sock.tex: sock.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

skbuff.tex: skbuff.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

skbuf.tex: skbuf.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

idle.tex: idle.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

interrupt.tex: interrupt.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

inittraps.tex: inittraps.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

paging.tex: paging.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

.PHONY: clean
clean:
	rm -f $(TEXFILES) highlight.sty *~
