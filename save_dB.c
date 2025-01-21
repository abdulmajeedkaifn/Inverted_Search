#include "invertedsearch.h"

int Save_DataBase(main_t **arr)
{
    char new_file[20];

    printf("Enter File Name: ");
    scanf(" %[^\n]", new_file);

    if(strstr(new_file, ".txt") == NULL)
    {
        red();
        printf("\nInvalid File name entered please enter file name like file_name.txt......!\n\n");
        reset();
        return 0;
    }

    FILE *fptr = fopen(new_file, "w");
    
    main_t *main_temp;
    sub_t *sub_temp;

    for(int index = 0; index < 27; index++)
    {
        if(arr[index])
        {
            main_temp = arr[index];
            while(main_temp)
            {
                sub_temp = main_temp->sub_link;
                fprintf(fptr, "#;%d;%s;%d;", index, main_temp->word, main_temp->filecount);

                while(sub_temp )
                {
                    fprintf(fptr, "%s;%d;", sub_temp->filename, sub_temp->wordcount);
                    sub_temp = sub_temp->slink;
                }
                fprintf(fptr, "#\n");
                main_temp = main_temp->main_link;
            }
        }
    }
    fclose(fptr);
    green();
    printf("\n########    DATABASE SAVED SUCCESSFULLY    ########\n\n");
    reset();
}