NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_puts.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -rf