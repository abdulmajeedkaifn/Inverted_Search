#include "invertedsearch.h"

int control1 = 1;

int Update_DataBase(main_t **arr, filename_t **updated_head)
{
    if( control1 )
    {
        control1 = 0;
        for(int i = 0; i < 27; i++)
        {
            if(arr[i] != NULL)
            {
                red();
                printf("\nERROR: DATABASE is not empty, unable to update DATABASE......!\n\n");
                reset();
                return FAILURE;
            }
        }

        char back_up[10];

        printf("Enter Backup File Name: ");
        scanf("  %s", back_up);

        if(strstr(back_up, ".txt") == NULL)
        {
            red();
            printf("\nInvalid File name entered please enter file name like file_name.txt......!\n\n");
            reset();
            control1 = 1;
            return FAILURE;
        }

        FILE *fptr = fopen(back_up, "r");

        if(fptr == NULL)
        {
            control1 = 1;
            red();
            printf("Unable to open file %s\n", back_up);
            reset();
            return FAILURE;
        }

        char first = fgetc(fptr);
        fseek(fptr, -1, SEEK_END);
        char last = fgetc(fptr);
        
        if(first != '#' && last != '#')
        {
            control1 = 1;
            red();
            printf("This is not a Backup file......!\n");
            reset();
            return FAILURE;
        }

        rewind(fptr);

        char line[100];

        int index, filecount, wordcount;
        char word[20]; char filename[20];

        sub_t *new1, *prev = NULL;
        main_t *new;

        while(fscanf(fptr, "%s\n", line) != EOF)
        {
            index = atoi(strtok(line, "#;"));

            new = (main_t *) malloc(sizeof(main_t));

            //copy word data into main node
            strcpy(new->word, strtok(NULL, "#;"));

            new->filecount = atoi(strtok(NULL, "#;"));

            new->main_link = NULL;
            new->sub_link = NULL;

            for(int i = 0; i < new->filecount; i++)
            {
                new1 = (sub_t *) malloc(sizeof(sub_t));

                //copy file name into sub node
                strcpy(new1->filename, strtok(NULL, "#;"));

                create_file_dataBase(updated_head, new1->filename);

                new1->wordcount = atoi(strtok(NULL, "#;"));

                new1->slink = NULL;

                if(new->sub_link == NULL)
                    new->sub_link = new1;
                else
                    prev->slink = new1;

                prev = new1;
            }

            if(arr[index] == NULL)
                arr[index] = new;
            else
            {
                main_t *temp = arr[index];

                while(temp->main_link)
                    temp = temp->main_link;

                temp->main_link = new;
            }
        }

        // print_list(*updated_head);
        green();
        printf("\n########    DATABASE UPDATED SUCCESSFULLY    ########\n\n");
        reset();
    }
    else
    {
        red();
        printf("\nERROR: DATABASE updated once can't update again\n\n");
        reset();
    }
}