NAMES = server
NAMEC = client

BNAMES = server_bonus
BNAMEC = client_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = server.c
SRCC = client.c

BSRCS = server_bonus.c
BSRCC = client_bonus.c

OBJS = ${SRCS:.c=.o}
OBJC = ${SRCC:.c=.o}

BOBJC = ${BSRCC:.c=.o}
BOBJS = ${BSRCS:.c=.o}

all: ${NAMEC} ${NAMES}

${NAMEC} : ${OBJC}
	${CC} -g ${OBJC} ${CFLAGS} -o ${NAMEC}

${NAMES} : ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAMES}

bonus: ${BNAMEC} ${BNAMES}
	
${BNAMEC}: ${BOBJC}
	${CC} ${BOBJC} ${CFLAGS} -o ${BNAMEC}

${BNAMES}: ${BOBJS}
	${CC} ${BOBJS} ${CFLAGS} -o ${BNAMES}

clean:
	${RM} ${OBJS} ${OBJC} ${BOBJC} ${BOBJS}

fclean: clean
	${RM} ${NAMES} ${NAMEC} ${BNAMES} ${BNAMEC}

re: fclean all

.PHONY: all clean fclean re bonus