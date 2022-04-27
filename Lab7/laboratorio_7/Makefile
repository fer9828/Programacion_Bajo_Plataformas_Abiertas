CC = gcc
RM = del

TARGET = listaexe

CFLAGS = -ggdb -I./include
VPATH=src:include
SRC_DIR = src
IMP_DIR = include
BUILD_DIR = build

C_SOURCES := $(wildcard $(SRC_DIR)/*.c)
C_IMPORT := -I$(wildcard $(IMP_DIR)/*.h)
C_OBJS = $(addprefix $(BUILD_DIR)/, $(C_SOURCES:.c=.o))
OBJS = $(C_OBJS) $(BUILD_DIR)/lista.o

all: $(TARGET)

$(TARGET): main.c lista.c lista.h
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJS)