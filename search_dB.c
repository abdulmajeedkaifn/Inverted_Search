#include "invertedsearch.h"

int Search_DataBase(main_t **arr)
{
    int i = 0;

    for(int j = 0; j < 27; j++)
    {
        if(arr[j] != NULL)
            i = 1;
    }

    if( !i )
    {
        red();
        printf("\nNo Data available in DATABASE to Search......!\n\n");
        reset();
        return FAILURE;
    }

    char find_word[20];

    printf("Enter the Word to Search: ");
    scanf(" %s", find_word);
    
    main_t *main_temp;
    sub_t *sub_temp;

    int index, flag = 0;

    if(find_word[0] >= 'A' && find_word[0] <= 'Z')
        index = find_word[0] - 'A';
    else if(find_word[0] >= 'a' && find_word[0] <= 'z')
        index = find_word[0] - 'a';
    else
        index = 26;

    if(arr[index])
    {
        main_temp = arr[index];

        while(main_temp)
        {
            if(strcmp(main_temp->word, find_word) == 0)
            {
                flag = 1;
                printf("\nThe word '%s' is present in %d file(s)\n", find_word, main_temp->filecount);
                sub_temp = main_temp->sub_link;

                while(sub_temp )
                {
                    printf("In File: %s with word count: %d\n", sub_temp->filename, sub_temp->wordcount);

                    sub_temp = sub_temp->slink;
                }
                printf("\n");
            }
            main_temp = main_temp->main_link;
        }
    }
    
    if( !flag )
    {
        red();
        printf("The word %s is not available in our DataBase......!\n", find_word);
        reset();
    }
}