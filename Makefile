SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)
HEADERS = $(filter-out main.h,$(SOURCES:%.c=%.h))
OUTPUT = ./build/duckos

LDLIBS = /usr/lib/quickjs/libquickjs.lto.a -lSDL2 -lSDL2_ttf
CFLAGS = -flto

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS) build
	@echo "LINK	$@"
	@$(CC) $(CFLAGS) $(LDLIBS) -o $@ $(OBJECTS)

build:
	@mkdir build

tools/mkhdr: tools/mkhdr.c
	@echo "HOSTCC	$@"
	@$(HOSTCC) -o $@ $^

$(OBJECTS): $(HEADERS) main.c
	@echo "CC	$@"
	@$(CC) $(CFLAGS) -c -o $@ $(@:%.o=%.c)

$(HEADERS): $(SOURCES)
	@echo "MKHDR	$@"
	@./tools/mkhdr $(@:%.h=%.c) -H > $@


.PHONY: clean
clean:
	@-rm -rf $(OUTPUT) $(OBJECTS)

.PHONY: run
run: ./build/duckos
	@sh -c "cd build; exec ./duckos"
