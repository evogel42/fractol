# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:47:44 by evogel            #+#    #+#              #
#    Updated: 2019/05/08 11:42:27 by evogel           ###   ########.fr        #
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
	   colors1.c \
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
	   info.c

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

LIBS = libft.a

D_LIBS = $(basename $(LIBS))

############
# COMPILER #
############

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

I_FLAGS = $(foreach LIB, $(D_LIBS),-I$(LIB)) -I$(INC)

L_FLAGS = $(foreach LIB, $(D_LIBS),-L$(LIB) -l$(LIB:lib%=%)) -lmlx -lm

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

$(NAME): $(addprefix $(basename $(LIBS))/, $(LIBS)) $(P_OBJS) $(D_OBJS)
	@$(call run_and_test, $(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(D_OBJS) $(L_FLAGS))

$(P_OBJS)/%.o: $(P_SRCS)/%.c $(INC)
	@$(call run_and_test, $(CC) $(CFLAGS) $(I_FLAGS) -o $@ -c $<)

$(P_OBJS):
	@mkdir -p $(P_OBJS)

$(addprefix $(basename $(LIBS))/, $(LIBS)):
	@$(call run_and_test, make -C $(dir $@))

clean:
	@$(call run_and_test, rm -rf $(P_OBJS) $(foreach LIB, $(D_LIBS),&& make -C $(LIB) clean))

fclean: clean
	@$(call run_and_test, rm -f $(NAME) $(foreach LIB, $(D_LIBS),&& make -C $(LIB) fclean))

re: fclean all
