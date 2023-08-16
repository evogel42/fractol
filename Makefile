# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:47:44 by evogel            #+#    #+#              #
#    Updated: 2019/05/18 15:01:54 by evogel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#########
# FILES #
#########

SRCS = main.c \
	   init.c \
	   fun_tabs_init.c \
	   hook_functions.c \
	   event_funs1.c \
	   event_funs2.c\
	   event_funs3.c\
	   event_funs4.c\
	   colors1.c \
	   colors2.c \
	   make_image.c \
	   write_ppm.c \
	   mandelbrot.c \
	   julia.c \
	   thorn.c \
	   julia_sin.c \
	   zubieta.c \
	   mandel4.c \
	   julia6.c \
	   mandelverse.c \
	   buddhabrot.c \
	   info.c \
	   tools.c

OBJS = $(SRCS:.c=.o)

###############
# DIRECTORIES #
###############

INC = incs

P_SRCS = srcs

P_OBJS = objs

D_OBJS = $(addprefix $(P_OBJS)/, $(OBJS))

#############
# LIBRARIES #
#############

LIBS = libft.a \
	   libmlx_Linux.a

D_LIBS = $(foreach LIB, $(LIBS), $(basename $(LIB))/$(LIB))

############
# COMPILER #
############

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L/usr/X11 -L/usr/X11/lib /usr/X11/lib/libmlx_Linux.a -lXext -lX11

I_FLAGS = $(foreach LIB, $(LIBS),-I$(basename $(LIB))) -I$(INC)

L_FLAGS = $(foreach LIB, $(LIBS),-L$(basename $(LIB)) -l$(LIB:lib%.a=%)) -lm -lpthread

################
# COMPILE TEST #
################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

#########
# RULES #
#########

all: $(NAME)

$(NAME): $(D_LIBS) $(P_OBJS) $(D_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(D_OBJS) $(L_FLAGS) $(MLXFLAGS)

$(P_OBJS)/%.o: $(P_SRCS)/%.c $(INC)
	@$(call run_and_test, $(CC) $(CFLAGS) $(I_FLAGS) -o $@ -c $<)

$(P_OBJS):
	@$(call run_and_test, mkdir -p $(P_OBJS))

$(D_LIBS):
	@$(call run_and_test, make -C $(dir $@))

clean:
	@$(call run_and_test, rm -rf $(P_OBJS) $(foreach LIB, $(LIBS),&& make -C $(basename $(LIB)) clean))

fclean: clean
	@$(call run_and_test, rm -f $(NAME) $(foreach LIB, $(LIBS),&& make -C $(basename $(LIB)) fclean))

re: fclean all
