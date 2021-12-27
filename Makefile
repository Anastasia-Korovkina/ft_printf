NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_put_char_str_nbr_unsigned.c \
			ft_put_hex_pointer.c

B_SRCS	=	ft_check_and_proc_bonus.c \
			ft_extra_bonus.c \
			ft_lengths_bonus.c \
			ft_printf_bonus.c \
			ft_processor_int_bonus.c \
			ft_processor_int_neg_bonus.c \
			ft_processor_int_zero_bonus.c \
			ft_processor_unsign_bonus.c \
			ft_processor_hex_bonus.c \
			ft_processor_hex_sub_bonus.c \
			ft_processor_pers_char_str_p_bonus.c \
			ft_put_smth_bonus.c 

OBJS	=	$(SRCS:.c=.o)

B_OBJS	=	$(B_SRCS:.c=.o)

LIBH	=	ft_printf.h

B_LIBH	=	ft_printf_bonus.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		${NAME}
			@make -C ./libft all

${NAME}: ${OBJS}
			@make -C ./libft
			ar rcs ${NAME} ${OBJS} ./libft/libft.a

%.o:	%.c ${LIBH}
			${CC} ${FLAGS} -c $< -o $@ 

%_bonus.o:	%_bonus.c ${LIBH}
				${CC} ${FLAGS} -c $< -o $@ 

bonus:	${B_OBJS}
			@make -C ./libft
			ar rcs ${NAME} ${B_OBJS} ./libft/libft.a


clean:
		${RM} ${OBJS} ${B_OBJS}
		@make -C ./libft clean

fclean:	clean
		${RM} ${NAME}
		@make -C ./libft fclean

re:	fclean all

.PHONY:	all clean fclean re bonus