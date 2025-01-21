#include "invertedsearch.h"

int control = 1;

int Create_DataBase(main_t **arr, filename_t *head, filename_t *updated_head)
{
    if(control)
    {
        control = 0;
        char get_word[20];
        int index;

        main_t *temp, *traverse;

        filename_t *new_head = NULL;

        if(updated_head != NULL)
        {
            compare_list1_list2(&new_head, head, updated_head);
            // print_list(new_head);
            head = new_head;
        }

        while(head)
        {
            FILE *fptr = fopen(head->fname, "r");

            while(fscanf(fptr, "%s", get_word) != EOF)
            {
                // printf("get word = %s\n", get_word);
                if(get_word[0] >= 'A' && get_word[0] <= 'Z')
                    index = get_word[0] - 'A';
                else if(get_word[0] >= 'a' && get_word[0] <= 'z')
                    index = get_word[0] - 'a';
                else
                    index = 26;

                // printf("arr[index] = %p\n", arr[index]);

                if(arr[index] == NULL)
                {
                    // create main node
                    main_t *new1 = create_main_node(get_word, 1);
                    // create sub node
                    sub_t *new2 = create_sub_node(head->fname, 1);

                    new1->sub_link = new2;
                    arr[index] = new1;
                }
                else
                {
                    if((temp = search_word(arr, index, get_word)) != NULL)
                        word_in_which_file(temp, head);
                    else
                    {
                        traverse = arr[index];

                        //To get last node present at index
                        while(traverse->main_link)
                        traverse = traverse->main_link;

                        // create main node
                        main_t *new1 = create_main_node(get_word, 1);
                        // create sub node
                        sub_t *new2 = create_sub_node(head->fname, 1);

                        new1->sub_link = new2;

                        traverse->main_link = new1;
                    }
                }
            }
            head = head->link;
        }
        green();
        printf("\n########    DATABASE CREATED SUCCESSFULLY    ########\n\n"); 
        reset();
    }
    else
    {
        red();
        printf("\nERROR: DATABASE created once can't create again\n\n");
        reset();
    }
}

void compare_list1_list2(filename_t **new_head, filename_t *head, filename_t *updated_head)
{
    int duplicate;
    filename_t *temp = updated_head;
    while(head)
    {
        temp = updated_head; duplicate = 0;
        while(temp)
        {
            if(strcmp(head->fname, temp->fname) == 0)
            {
                duplicate = 1; break;
            }
            temp = temp->link;
        }
        if( !duplicate )
            create_file_dataBase(new_head, head->fname);

        head = head->link;
    }
}

main_t *create_main_node(char *data, int file_count)
{
    main_t *new = (main_t *) malloc(sizeof(main_t));

    //copy word data into main node
    strcpy(new->word, data);

    new->filecount = file_count;

    new->main_link = NULL;
    new->sub_link = NULL;
    
    return new;
}

sub_t *create_sub_node(char *fname, int word_count)
{
    sub_t *new = (sub_t *) malloc(sizeof(sub_t));

    //copy file name into sub node
    strcpy(new->filename, fname);

    new->wordcount = word_count;
    new->slink = NULL;

    return new;
}

main_t *search_word(main_t **arr, int index, char *get_word)
{
    main_t *temp = arr[index];

    while(temp)
    {
        if(strcmp(temp->word, get_word) == 0)
            return temp;
        else
            temp = temp->main_link;        
    }

    return temp;
}

int word_in_which_file(main_t *main_node, filename_t *head)
{
    sub_t *temp = main_node->sub_link, *prev = NULL;

    while(temp)
    {
        if(strcmp(temp->filename, head->fname) == 0)
        {
            temp->wordcount++;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->slink;
    }

    //if word is in different file then create new sub node
    prev->slink = create_sub_node(head->fname, 1);
    main_node->filecount++;

    return SUCCESS;
}