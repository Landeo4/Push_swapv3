NAME	=	Push_Swap

SRCS	=	srcs/main.c\
			srcs/Libft/ft_isdigit.c\
			srcs/Libft/ft_strlen.c\
			srcs/Libft/ft_atoi.c\
			srcs/Libft/ft_atol.c\
			srcs/Libft/ft_putchar.c\
			srcs/Libft/ft_putnbr_base.c\
			srcs/Libft/ft_putnbr.c\
			srcs/Libft/ft_putstr.c\
			srcs/Libft/ft_printf.c\
			srcs/Libft/ft_strlcpy.c\
			srcs/Libft/ft_putnbr_void.c\
			srcs/Libft/ft_itoa.c\
			srcs/Libft/ft_swap.c\
			srcs/Libft/ft_putstr_fd.c\
			srcs/Libft/ft_error_writer.c\
			srcs/Libft/ft_split.c\
			srcs/Libft/ft_split_free.c\
			srcs/Libft/ft_isminus.c\
			srcs/Libft/ft_is_whitespace.c\
			srcs/Libft/ft_int_overflow_checker.c\
			srcs/List/ft_addAt.c\
			srcs/List/ft_add_at.c\
			srcs/List/ft_create_cell.c\
			srcs/List/ft_first_list.c\
			srcs/List/ft_free_both.c\
			srcs/List/ft_free_list.c\
			srcs/List/ft_freeAt.c\
			srcs/List/ft_getAt.c\
			srcs/List/ft_len_lista.c\
			srcs/List/ft_print_list.c\
			srcs/List/ft_init_struct.c\
			srcs/Parsing/args_handler.c \
	   		srcs/Parsing/multi_args_handler.c \
	   		srcs/Parsing/single_args_handler.c \
	   		srcs/Parsing/init_stacks.c \
	   		srcs/Parsing/single_args_utils/s_checker_utils.c \
	   		srcs/Parsing/single_args_utils/s_str_checker.c \
	   		srcs/Parsing/single_args_utils/s_charset_checker.c \
	   		srcs/Parsing/single_args_utils/s_digits_checker.c \
	   		srcs/Parsing/single_args_utils/s_duplicate_checker.c \
	   		srcs/Parsing/single_args_utils/s_put_to_lst.c \
	   		srcs/Parsing/multi_args_utils/m_str_checker.c \
	   		srcs/Parsing/multi_args_utils/m_digits_checker.c \
	   		srcs/Parsing/multi_args_utils/m_duplicate_checker.c \
	   		srcs/Parsing/multi_args_utils/m_put_to_lst.c \
			srcs/Action/sa.c\
			srcs/Action/sb.c\
			srcs/Action/ss.c\
			srcs/Action/pa.c\
			srcs/Action/pb.c\
			srcs/Action/ra.c\
			srcs/Action/rb.c\
			srcs/Action/rr.c\
			srcs/Action/rra.c\
			srcs/Action/rrb.c\
			srcs/Action/rrr.c\
			srcs/Algorithm/ft_algo_manager.c\
			srcs/Algorithm/ft_algo_3.c\
			srcs/Algorithm/ft_algo_10.c\
			srcs/Algorithm/ft_algo_10helper.c\
			srcs/Algorithm/ft_algo_100.c\
			srcs/Algorithm/ft_algo_100_helper1.c\
			srcs/Algorithm/ft_algo_100_helper2.c\
			srcs/Algorithm/ft_algo_100_helper3.c\
			srcs/Algorithm/ft_algo_100_b.c\
			srcs/Algorithm/ft_algo_100_b2.c\
			srcs/Algorithm/ft_algo_100helper.c\
			srcs/Algorithm/ft_algo_100reduce.c\
			srcs/Algorithm/ft_algo_500.c\
			srcs/Algorithm/ft_algo_500_b.c\
			srcs/Algorithm/ft_algo_500_helper1.c\
			srcs/Algorithm/ft_algo_500_helper2.c\
			srcs/Algorithm/ft_algo_500_helper3.c\
			srcs/Algorithm/ft_algo500helper4.c\
			srcs/Algorithm/ft_algo_500helper.c\
			srcs/Algorithm/ft_algo_500reduce.c\
			srcs/Algorithm/ft_algo_500opti.c\
			srcs/Algorithm/ft_trie500_test.c\
			srcs/Algorithm/ft_chunk.c\
			srcs/Algorithm/ft_take_25_algo500.c\
			srcs/Algorithm/ft_trie_la_1.c\
			srcs/Algorithm/ft_trie_lb_1.c\



OBJS = $(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3 -g
.c.o:
		${CC} ${CFLAGS} -Iincludes -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re