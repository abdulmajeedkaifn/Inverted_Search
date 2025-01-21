#include "invertedsearch.h"

int main(int argc, char *argv[])
{
    int choice;

    main_t *arr[27] = {NULL};

    filename_t *head = NULL, *updated_head = NULL;

    if(read_and_validate(&head, argv) == FAILURE)
    {
        red();
        printf("File name missing in Command Line....!\n");
        reset();
        return 0;
    }

    yellow();
    row1();
    printf("                            INVERTED SEARCH                     \n");
    row1();
    reset();
    
    while(1)
    {
        printf("\nMain Menu:\n");
        printf("1. Create DataBase\n2. Display DataBase\n3. Search Data\n4. Save to DataBase\n5. Update Database\n6. Exit\n\n");
        cyan();
        printf("Enter your choice: ");
        reset();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: Create_DataBase(arr, head, updated_head);
                    break;

            case 2: Display_DataBase(arr);
                    break;

            case 3: Search_DataBase(arr);
                    break;
            
            case 4: Save_DataBase(arr);
                    break;

            case 5: Update_DataBase(arr, &updated_head);
                    break;

            case 6:     yellow();
                        printf("######      EXIT SUCCESSFUL     ######\n");
                        reset();
                        return 0;
            
            default:    red();
                        printf("Enter proper choice.....!\n");
                        reset();
        }
    }
}

int read_and_validate(filename_t **head, char *argv[])
{
    int i = 1;

    if(argv[i] == NULL)
        return FAILURE;

    while(argv[i])
    {
        if(strstr(argv[i], ".txt") != NULL)
        {
            FILE *fptr = fopen(argv[i], "r");
            if(fptr == NULL)
            {
                red();
                printf("Unable to open %s file / (File doesn't exist)\n", argv[i]);
                reset();
                i++; continue;
            }

            if(fgetc(fptr) == EOF)
            {
                red();
                printf("%s file is empty\n", argv[i]);
                reset();
                i++; continue;
            }

            rewind(fptr);

            if(create_file_dataBase(head, argv[i]) == FAILURE)
            {
                i++; continue;
            }
        }
        else
        {
            red();
            printf("Enter proper file format Eg: (file_name.txt) for %s\n", argv[i]);
            reset();
        }
        i++;
    }
    // print_list(*head);

    return SUCCESS;
}

int create_file_dataBase(filename_t **head, char *data)
{
    filename_t *duplicate = *head;

    while(duplicate && *head != NULL)
    {
        if(strcmp(duplicate->fname, data) == 0)
            return FAILURE;

        duplicate = duplicate->link;
    }

    filename_t *new = (filename_t *) malloc(sizeof(filename_t));
    
    filename_t *temp = *head;
    
    strcpy(new->fname, data);
    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        
        temp->link = new;
    }

    return SUCCESS;
}

void print_list(filename_t *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
        printf("head -> ");
	    while (head)		
	    {
		    printf("%s -> ", head -> fname);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}

void red ()
{
  printf("\033[1;31m");
}
void green()
{
    printf("\033[0;32m");
}
void yellow ()
{
  printf("\033[1;33m");
}
void blue ()
{
    printf("\033[0;34m ");
}
void cyan()
{
    printf("\033[0;36m ");
}

/* Function to reset text color to default */

void reset ()
{
  printf("\033[0m");
}