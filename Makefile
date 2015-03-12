SOURCES = test.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = test

CFLAGS += `pkg-config --cflags termkey`
LDFLAGS += `pkg-config --libs termkey`

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
