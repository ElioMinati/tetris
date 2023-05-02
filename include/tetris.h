/*
** EPITECH PROJECT, 2022
** tetris.h
** File description:
** header for tetris with prototypes
*/

#include <time.h>
#include <stdbool.h>

#ifndef TETRIS_H_
    #define TETRIS_H_

typedef struct pos_i {
    int x;
    int y;
} pos2i;

typedef struct vector_i {
    int row;
    int col;
} vector2i;

typedef struct shape_s {
    char **shape;
    int width;
    int height;
    int color;
    int current_shape;
    int nb_shapes;
    int is_changed;
    pos2i offset;
} shape_t;

typedef struct tetris_s {
    int start_level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    vector2i map;
    bool without_next;
    bool debug;
    shape_t *shapes;
    shape_t next_shape;
    shape_t current_shape;
    char **all_shapes;
    clock_t clock;
    int elapsed_time;
    int *max_col_height;
    int is_lost;
    int score;
    int level;
} tetris_t;

void tetris(int ac, char **av);

void param_handler(int ac, char **av, tetris_t *tetris);

void display_help(void);

void display_game(tetris_t *game, int key);

void debug_mode(tetris_t *tetris);

char **get_tetrimino_files(void);

void display_tetri(void);

int get_nb_files(char *directory);

int get_shape_width(char *path);

int get_shape_height(char *path);

int get_shape_color(char *path);

void get_param(char **av, int c, tetris_t *tetris);

int is_file_valid(char *path);

char **get_tetrimino_content(char **path);

char **get_shape(char *str);

void display_shape(tetris_t *game, int key);

int is_valid_file(char *str);

char *get_file_content(char *path);

int is_valid_file(char *str);

char **init_map(tetris_t *tetris);

void display_tetrimino(shape_t shape, int col);

void get_max_height_cols(tetris_t *game);

void detect_full_line(char **map, tetris_t *game);

void display_next_shape(shape_t shape, int col);

void init_current_shape(tetris_t *game);

char *parsearg(char *str, int w);

void detect_loss(tetris_t *game);

int is_hit(tetris_t *game, char **map, int i, vector2i size);

void add_into_map(shape_t current_shape, int i, char **map, vector2i size);

void detect_rotation(tetris_t *game, int key);

void detect_down(tetris_t *game, int key);

int is_done(tetris_t *game, char **map, vector2i size);

void display_game_info(tetris_t *game);

void init_game(int ac, char **av, tetris_t *game);

void init_colors(void);

#endif /* !TETRIS_H_ */
