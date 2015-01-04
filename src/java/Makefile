IN_EXT ?= .java
OUT_EXT ?= .class

INS := $(wildcard *$(IN_EXT))
OUTS_NOEXT := $(basename $(INS))
OUTS := $(addsuffix $(OUT_EXT), $(OUTS_NOEXT))

.PHONY: all clean

all: $(OUTS)

%$(OUT_EXT): %$(IN_EXT)
	javac -source 1.7 -g '$<'

clean:
	rm -f *$(OUT_EXT)
