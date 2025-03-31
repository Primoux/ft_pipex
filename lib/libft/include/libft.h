/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:45:04 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/31 19:59:12 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define GOOD_ARG "0123456789-+"

typedef struct s_list_db_cir
{
	int						content;
	int						index;
	struct s_list_db_cir	*next;
	struct s_list_db_cir	*prev;
}							t_list_db_cir;

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

typedef enum e_bool
{
	FALSE,
	TRUE
}							t_bool;

int							ft_tolower(int c);
int							ft_toupper(int c);
int							ft_atoi(const char *str, int *error);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
size_t						ft_strlen(const char *s);
int							ft_isprint(int c);
int							ft_isascii(int c);
void						*ft_memset(void *s, int c, size_t n);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
char						*ft_strchr(const char *str, int srch_char);
char						*ft_strrchr(const char *str, int srch_char);
void						*ft_memchr(const void *mem_block, int srch_char,
								size_t size);
int							ft_memcmp(const void *ptr1, const void *ptr2,
								size_t size);
void						*ft_memmove(void *dest, const void *src,
								size_t size);
size_t						ft_strlcpy(char *dst, const char *src, size_t size);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
char						*ft_strnstr(const char *big, const char *little,
								size_t len);
int							ft_strncmp(const char *first, const char *second,
								size_t length);
void						*ft_calloc(size_t count, size_t size);
char						*ft_strdup(const char *src);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*str_free_to_join(char *s1, char *s2);
char						*ft_strtrim(char const *s1, char const *set);
void						*free_tab_return_null(char **tab);
int							free_tab_return_int(char **tab, int return_var);
char						**ft_split(char const *s, char c);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
int							ft_putchar_fd(char c, int fd);
int							ft_putstr_fd(char *s, int fd);
int							ft_putendl_fd(char *s, int fd);
int							ft_putnbr_fd(int n, int fd);
t_list						*ft_lstnew(void *content);
void						ft_lstadd_front(t_list **lst, t_list *new);
int							ft_lstsize(t_list *lst);
t_list						*ft_lstlast(t_list *lst);
void						ft_lstadd_back(t_list **lst, t_list *new);
void						ft_lstdelone(t_list *lst, void (*del)(void *));
void						ft_lstclear(t_list **lst, void (*del)(void *));
void						ft_lstiter(t_list *lst, void (*f)(void *));
t_list						*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

/*****************************LIST DB CIR******************************** */
void						ft_lstadd_back_db_cir(t_list_db_cir **lst,
								t_list_db_cir *new);
void						ft_lstclear_db_cir(t_list_db_cir **lst);
t_list_db_cir				*ft_lstnew_db_cir(int content);
int							ft_lstsize_db_cir(t_list_db_cir *lst);
void						ft_lstadd_front_db_cir(t_list_db_cir **lst,
								t_list_db_cir *new);

/********************GET_NEXT_LINE****************************/
char						*get_next_line(int fd);

/***************************PRINTF****************************/
int							ft_printf(const char *format, ...);
int							print_digit(long n, int base, char c);
int							print_hexa(unsigned long n);
int							print_pointer(void *ptr);

/*************************************************************/

#endif
