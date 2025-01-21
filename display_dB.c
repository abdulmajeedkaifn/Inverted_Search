#include "invertedsearch.h"

void rows(void)
{
    for(int i = 0; i < 76; i++)
        printf("=");

    printf("\n");
}

void row1(void)
{
    for(int i = 0; i < 76; i++)
        printf("-");

    printf("\n");
}

int Display_DataBase(main_t **arr)
{
    main_t *main_temp;
    sub_t *sub_temp;
    int i = 0;

    for(int j = 0; j < 27; j++)
    {
        if(arr[j] != NULL)
            i = 1;
    }

    if( !i )
    {
        red();
        printf("\nNo Data available in DATABASE to display......!\n\n");
        reset();
        return FAILURE;
    }

    printf("\n");
    rows();
    printf("| %-12s | %-12s | %-12s | %-12s | %-12s |\n", "Index", "Word", "File Count", "File Name", "Word Count");
    rows();

    for(int index = 0; index < 27; index++)
    {
        if(arr[index])
        {
            main_temp = arr[index];
            while(main_temp)
            {
                i = 0;
                sub_temp = main_temp->sub_link;

                while(sub_temp )
                {
                    if( !i )
                    {
                        printf("| %-12d | %-12s | %-12d | %-12s | %-12d |\n", index, main_temp->word, main_temp->filecount, sub_temp->filename, sub_temp->wordcount);
                        i = 1;
                    }
                    else if(i == 1)
                        printf("|              |              |              | %-12s | %-12d |\n", sub_temp->filename, sub_temp->wordcount);
                    sub_temp = sub_temp->slink;
                }
                
                row1();
                main_temp = main_temp->main_link;
            }
        }
    }

    green();
    printf("\n########    DISPLAY DATABASE SUCCESSFULL    ########\n\n");
    reset();
}