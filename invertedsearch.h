#ifndef INVERTEDSEARCH_H
#define  INVERTEDSEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct main_node
{
    int filecount;
    char word[20];
    struct main_node *main_link;
    struct sub_node *sub_link;
}main_t;

typedef struct sub_node
{
    int wordcount;
    char filename[10];
    struct sub_node *slink;
}sub_t;

typedef struct node
{
    char fname[10];
    struct node *link;
}filename_t;

//Reading and validating command line arguments
int read_and_validate(filename_t **head, char *argv[]);

//To create list containing file name
int create_file_dataBase(filename_t **head, char *data);

void print_list(filename_t *head);

//to create dataBase
int Create_DataBase(main_t **arr, filename_t *head, filename_t *updated_head);

//to compare updated and current files
void compare_list1_list2(filename_t **new_head, filename_t *head, filename_t *updated_head);

//To create main node
main_t *create_main_node(char *data, int file_count);

//To create sub node
sub_t *create_sub_node(char *fname, int word_count);

//To search word in database
main_t *search_word(main_t **arr, int index, char *get_word);

//To check word is in same file or different
int word_in_which_file(main_t *main_node, filename_t *head);

//Display Data Base Function
int Display_DataBase(main_t **arr);

void rows(void);
void row1(void);
void red();
void green();
void yellow();
void cyan();
void reset();

//Save Data Base Function
int Save_DataBase(main_t **arr);

//Search Data Base Function
int Search_DataBase(main_t **arr);

//Updata Data Base Function
int Update_DataBase(main_t **arr, filename_t **updated_head);

#endif