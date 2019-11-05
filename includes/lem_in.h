/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:53:30 by zchatoua          #+#    #+#             */
/*   Updated: 2019/06/25 20:46:42 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_minheap
{
	int				elems;
	struct s_room	*root;
}					t_minheap;

typedef	struct		s_path
{
	int				length;
	long long		inter;
	int				inodes;
	int				ants;
	int				done;
	int				found;
	int				time;
	int				use;
	struct s_room	**path;
	struct s_room	**id;
	struct s_path	*next;
}					t_path;

typedef struct		s_paths
{
	int				count;
	struct s_path	*first;
	struct s_path	*last;
	struct s_path	*potential;
}					t_paths;

typedef struct		s_room
{
	char			*name;
	int				ant;
	int				x;
	int				y;
	int				stat;
	int				vis;
	int				mark;
	int				used;
	int				dist;
	int				children;
	struct s_room	*parent;
	struct s_room	**child;
	struct s_room	*left;
	struct s_room	*right;
	struct s_room	*pheap;
	struct s_room	*rheap;
	struct s_room	*lheap;
	int				in_heap;
	int				height;
}					t_room;

typedef struct		s_info
{
	int				ant;
	int				room_nb;
	t_room			***path;
	char			**file;
	t_room			*root;
	struct s_room	*end;
	struct s_room	*start;
}					t_info;

typedef struct		s_tuple
{
	int				x;
	int				y;
	int				stat;
}					t_tuple;

typedef struct		s_queue
{
	t_room			*room;
	struct s_queue	*next;
}					t_queue;

t_room				*create_room(char *name, int x, int y, int stat);
t_room				*avl_insert(char *name, t_tuple data, t_room *root,
		t_info *info);
t_room				*find(char *name, t_room *root);
void				free_avl(t_room **root);
void				display_avl(t_room *root);
int					parse_rooms(t_info *info, char **line);
int					parse_links(t_info *info, char **line);
int					add_edge(t_room *parent, t_room *child);
int					height(t_room *root);
int					max(int l, int r);
void				error();
int					free_tab(char	**tab);
void				file_concat(t_info *info, char	*line);
int					ft_tablen(char	**tab);
void				init(t_info *info);
void				read_input(t_info *info);
void				remove_min_elem(t_minheap **minh);
void				to_last(t_room *x, t_room *y);
int					update_heap(t_minheap **minh, t_room *changed);
void				add_to_heap(t_minheap **minh, t_room *new);
void				init_room(t_room **tmp, t_room *x);
char				*to_binary(int x);
void				heapify(t_minheap **minh, char *str);
void				heap_swap(t_minheap *a, t_room *x, t_room *y);
t_minheap			*init_heap(t_room *start);
int					not_used(t_room **used, t_room *node1, t_room *node2);
t_room				**join(t_room **one, t_room **two, int i, int j);
void				unmark_avl(t_room *root);
t_room				**gen_used(t_room *a, t_room *b);
t_path				*output_path(t_room *x, t_room *y);
t_path				*dijkstra_len(t_info info);
t_path				*dijkstra_inter(t_info info);
t_paths				*find_and_erase(t_info info, t_path *sp, int x);
void				add_path(t_paths **total, t_path *new, t_info info);
int					*scoring(t_paths *all, int *tab, int inter, int ants);
void				zero_set(int *score, int count);
t_path				*find_kth_path(t_paths *all, int x);
int					choose_sol(t_info info, t_paths *all);
void				unmark_path(t_room *root);
t_room				**gen_used(t_room *a, t_room *b);
void				add_path(t_paths **total, t_path *new, t_info info);
int					*scoring(t_paths *all, int *tab, int inter, int ants);
void				zero_set(int *score, int count);
t_path				*find_kth_path(t_paths *all, int x);
void				calculate_inodes(t_path *new, t_info info);
void				id_path(t_path *new, t_info info);
void				update_qpath(t_paths **total, t_path *new);
t_paths				*find_k_paths(t_info info, t_path *sp, int i);
t_room				**cancel_edge(t_paths *all_paths, t_path *sp, int i);
t_room				**cancel_nodes(t_path *sp, int i);
t_path				*dijkstra_three(t_info info, t_room **used, t_room **nodes,
	t_room *spur);
void				add_qpath(t_paths **total, t_path *new);
t_path				*concat(t_path *sp, t_path *new, int n);
t_paths				*find_solution(t_info info, t_paths *all);
int					carry_over(int **tab, int inter, int count);
int					already_chosen(t_room **chosen, t_room *inode);
t_room				**choose(t_room **chosen, t_room *inode);
int					repeated(int *pab, int inter, int *dp);
int					check_combination(int *tab, t_paths *all, int dummy);
t_room				*find(char *name, t_room *root);
int					find_shortest(t_paths *all);
void				find_index(int *stat, t_paths *all);
void				result(t_info *info, t_paths *all, int i, int end);
int					move(t_info *info, t_path *path, int *i, int *end);
void				free_path(t_path *abc);
void				free_paths(t_paths *all);
int					free_tab_stat(int **tab, int *stat);
void				despair(t_paths *all, int x, int *tab);
void				ajouter_room(t_info *info, char **tab, int old);
int					check_nametag(char **tab);
void				manage_error(char **tab, char **line);
void				insert_room(t_info *info, char **tab, int stat);
int					check_comment(char *line);
int					**init_tabz(int **tab, t_info info);
int					*init_stats(int *stat);
void				choose_p(int **tab, int *stat, t_info info, t_paths *all);
void				update_last(int **tab, int *stat);
void				print_all(t_info *info);

/*
** Visualization part
*/

void				add_to_queue(t_queue **head, t_room *room, t_room *parent);
void				getcord(t_queue **head, int depth);
void				edges(t_queue **head);
void				print_path(t_path *path);
void				visu(t_info *info, t_paths *all);

#endif
