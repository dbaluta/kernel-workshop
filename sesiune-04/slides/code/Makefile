TEXFILES = sysex.tex entry.tex ret.tex save.tex rest.tex list.tex

ifeq (3, $(shell highlight --version | head -2 | tail -1 | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1))
	HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K small -S bash -c highlight.sty
else
	HIGHLIGHT_OPTS = -L -l -f -t 8 -K small -S bash -c highlight.sty
endif

all: $(TEXFILES)

sysex.tex: sysex.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

entry.tex: entry.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

ret.tex: ret.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

save.tex: save.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

rest.tex: rest.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

list.tex: list.c
	highlight $(HIGHLIGHT_OPTS) -K tiny -i $< -o $@

.PHONY: clean
clean:
	rm -f $(TEXFILES) highlight.sty *~
