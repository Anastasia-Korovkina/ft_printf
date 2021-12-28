NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_put_char_str_nbr_unsigned.c \
			ft_put_hex_pointer.c

B_SRCS	=	bonus/ft_check_and_proc_bonus.c \
			bonus/ft_extra_bonus.c \
			bonus/ft_lengths_bonus.c \
			bonus/ft_printf_bonus.c \
			bonus/ft_processor_int_bonus.c \
			bonus/ft_processor_int_neg_bonus.c \
			bonus/ft_processor_int_zero_bonus.c \
			bonus/ft_processor_unsign_bonus.c \
			bonus/ft_processor_hex_bonus.c \
			bonus/ft_processor_hex_sub_bonus.c \
			bonus/ft_processor_pers_char_str_p_bonus.c \
			bonus/ft_put_smth_bonus.c 

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

LIBH	=	ft_printf.h

B_LIBH	=	ft_printf_bonus.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		${NAME}

${NAME}: ${OBJS}
			ar rcs ${NAME} ${OBJS} 

%.o:	%.c ${LIBH}
			${CC} ${FLAGS} -c $< -o $@ 

%_bonus.o:	%_bonus.c ${B_LIBH}
				${CC} ${FLAGS} -c $< -o $@ 

bonus:	clean fclean
			@make OBJS="${B_OBJS}" all

clean:
		${RM} ${OBJS} ${B_OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus