all: build

CC=gcc
CC_FLAGS=-W -Wall -Wextra -Werror

objects=utils.c player.c monster.c main.c

build:
	$(CC) $(CC_FLAGS) $(objects) -o exec
