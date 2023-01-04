SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)
HEADERS = $(filter-out main.h,$(SOURCES:%.c=%.h))
OUTPUT = ./build/duckos

# because sus
CC=clang

LDLIBS = ./libs/quickjs/libquickjs.lto.a -lSDL2 -lSDL2_ttf
CFLAGS = -flto

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS) build ./libs/quickjs/libquickjs.lto.a
	@echo "LINK	$@"
	@$(CC) $(CFLAGS) $(LDLIBS) -o $@ $(OBJECTS)

# sub-make knows when the code changes in the libs but we don't, so execute it every time
.PHONY: ./libs/quickjs/libquickjs.lto.a
./libs/quickjs/libquickjs.lto.a:
	@$(MAKE) -C ./libs/quickjs/ libquickjs.lto.a

.PHONY: build
build:
	@-rm -rf ./build
	@mkdir ./build
	@cp -r ./assets/ ./build/assets/
	@cp -r ./fs/ ./build/fs/

$(OBJECTS): $(SOURCES)
	@echo "CC	$@"
	@$(CC) $(CFLAGS) -c -o $@ $(@:%.o=%.c)

.PHONY: clean clean_all
clean:
	@-rm -rf $(OUTPUT) $(OBJECTS)
clean-all: clean
	@$(MAKE) -C ./libs/quickjs/ clean

.PHONY: run
run: ./build/duckos
	@sh -c "cd build; exec ./duckos"
