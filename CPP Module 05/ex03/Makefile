# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalazar <fsalazar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:01:05 by fsalazar          #+#    #+#              #
#    Updated: 2023/09/12 15:01:07 by fsalazar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g3

RM = rm -f

SRC =	Bureaucrat.cpp \
		AForm.cpp \
		Intern.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		main.cpp \

OBJ_DIR = OBJ

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0mss
CHECKMARK = ✔

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(CHECKMARK) $(NAME) created.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)$(CHECKMARK) $(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(CHECKMARK) $(NAME) removed.$(RESET)"
	@$(RM) Garden_shrubbery

re: fclean all

.PHONY: all clean fclean re