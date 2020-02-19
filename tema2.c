//Enache Anca-Mihaela 314CD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

void wrap(int max_line_length, char original[1000][1000], 
          int i, int original_line_count)
{
    char *cuvant, aux_matrix[1000][1000], rand[1000];
    int length = 0, L = 0, k;
    aux_matrix[0][0] = '\0';
    i = 0;
    k = 0;
    strcpy(rand, original[i]);
    cuvant = strtok(rand, " \n");
    while (cuvant != NULL && i < original_line_count)
    {
        L = strlen(cuvant);
        if (L > max_line_length)
        {
            printf("Cannot wrap!\n");
            break;
        }
        length = length + L;
        if (length <= max_line_length)
        {
            strcat(aux_matrix[k], cuvant);
            strcat(aux_matrix[k], " ");
            length++;
        }
        else
        {
            if (length > max_line_length)
            {
                L = strlen(aux_matrix[k]);
                aux_matrix[k][L - 1] = '\n';
                length = 0;
                strcat(aux_matrix[k], cuvant);
                strcat(aux_matrix[k], " ");
                L = strlen(cuvant);
                if (L > max_line_length)
                {
                    printf("Cannot wrap!\n");
                    break;
                }
                length = length + L;
                length++;
            }
        }
        cuvant = strtok(NULL, " \n");
        if (cuvant == NULL)
        {   
            i++;
            L = strlen(aux_matrix[k]);
            aux_matrix[k][L - 1] = '\n';
            k++;
            strcpy(rand, original[i]);
            if (rand[0] == '\n')
            {
                length = 0;
                strcat(aux_matrix[k], "\n");
                k++;
                i++;
                strcpy(rand, original[i]);
            }
            cuvant = strtok(rand, " \n");
        }
    }
    for (i = 0; i < k; i++)
    {
        strcpy(original[i], aux_matrix[i]);
    }
}

void center(int start, int end, char original[1000][1000], 
            int i, int original_line_count)
{
    int max_length = 0, nr = 0, j = 0, k;
    char spaces[1000], rand[1000];
    for (i = 0; i <= original_line_count; i++)
    {
        strcpy(rand, original[i]);
        j = strlen(rand);
        if (j > max_length)
        {
            max_length = j;
        } 
    }   
    for (i = start; i <= end; i++)
    {
        nr = 0;
        strcpy(rand, original[i]);
        if (rand[0] != '\n')
        {
            j = strlen(rand);
            nr = (max_length - j +1)/ 2;
            for (k = 0; k < nr; k++)
            {
                spaces[k]=' ';
            }
            strcpy(spaces + nr, rand);
            strcpy(original[i], spaces);
        }
    }   
}

void align_left(int start, int end, char original[1000][1000], 
                int i, int original_line_count)
{
    int nr = 0, j = 0;
    char rand[1000];
    for (i = start; i <= end; i++)
    {
        j = 0;
        nr = 0;
        strcpy(rand, original[i]);
        if (rand[0] != '\n')
        {
            while (original[i][j] == ' ')
            {
                nr++;
                j++;
            } 
            strcpy(rand, original[i] + nr);
            strcpy(original[i], rand); 
        }
    } 
}

void align_right(int start, int end, char original[1000][1000], 
                 int i, int original_line_count)
{
    int max_length = 0, nr = 0, j = 0, k;
    char spaces[1000], rand[1000];
    for (i = 0; i <= original_line_count; i++)
    {
        strcpy(rand, original[i]);
        j = strlen(rand);
        if (j > max_length)
        {
            max_length = j;
        } 
    }   
            
    for (i = start; i <= end; i++)
    {
        nr = 0;
        strcpy(rand, original[i]);
        if (rand[0] != '\n')
        {
            j = strlen(rand);
            nr = max_length - j;
            for (k = 0; k < nr; k++)
            {
                spaces[k]=' ';
            }
            strcpy(spaces + nr, rand);
            strcpy(original[i], spaces);
        }
    }
}

/*void justify()
{

}*/

void paragraphs(int indent_length, int start, int end, int i,
                char original[1000][1000], int original_line_count)
{
    int k;
    char rand[1000];
    rand[0] = '\0';
    for (i = start - 1; i <= end; i++)
    {
        if (i == 0)
        {
            for (k = 0; k < indent_length; k++)
            {
                rand[k] = 32;
            }
            strcpy(rand + indent_length, original[i]);
            strcpy(original[i], rand); 
        }
        else
        {
            if (strcmp(original[i], "\n") == 0)
            {   
                i++;
                for (k = 0; k < indent_length; k++)
                {
                    rand[k] = 32;
                }
                strcpy(rand + indent_length, original[i]);
                strcpy(original[i], rand);
            }
        }
    } 
}

void lists(int start, int end, char *list_type, char *special_character, 
           int i, char original[1000][1000], int original_line_count)
{
    char rand[1000], bullet[1010];  
    int nr = 0; 
    if (*list_type == 'n')//lista numerotata
    {
        int number = 1;
        for (i = start; i <= end; i++)
        {
            bullet[0] = '\0';
            strcpy(rand, original[i]);
            if (rand[0] != '\n')
            {
                sprintf(bullet, "%d%s ", number, special_character);
                if (number < 10)
                {
                    strcpy(bullet + 3, rand);
                }
                else
                {
                    strcpy(bullet + 4, rand);
                }
                strcpy(original[i], bullet);
                number++;
            }
        }   
    }
    if (*list_type == 'a')//lista alfabetica cu lit. mici
    {
        char litera = 'a';
        for (i = start; i <= end; i++)
        {
            bullet[0] = '\0';
            strcpy(rand, original[i]);
            if (rand[0] != '\n')
            {
                strcpy(rand, original[i] + nr);
                bullet[0] = litera;
                litera = litera + 1;
                strcpy(bullet + 1, special_character);
                strcpy(bullet + 2," ");
                strcpy(bullet + 3, rand);
                strcpy(original[i], bullet);
            }
        } 
    }
    if (*list_type == 'A')//lista alfabetica cu lit. mari
    {
        char litera = 'A';
        for (i = start; i <= end; i++)
        {
            bullet[0] = '\0';
            strcpy(rand, original[i]);
            if (rand[0] != '\n')
            {
                strcpy(rand, original[i] + nr);
                bullet[0] = litera;
                litera = litera + 1;
                strcpy(bullet + 1, special_character);
                strcpy(bullet + 2," ");
                strcpy(bullet + 3, rand);
                strcpy(original[i], bullet);
            }
        }
    }
    if (*list_type == 'b')//bullet list
    {
        for ( i = start; i <= end; i++)
        {
            bullet[0] = '\0';
            strcpy(rand, original[i]);
            if (rand[0] != '\n')
            {
                strcpy(rand, original[i] + nr);
                strcat(bullet, special_character);
                strcat(bullet," ");
                strcpy(bullet + 2, rand);
                strcpy(original[i], bullet);
            }
        } 
    }
}

int main (int argc, char *argv[])
{
    char buf[1000],               // buffer used for reading from the file
        original[1000][1000],     // original text, line by line
        result[1000][1000];       // text obtained after applying operations
    int original_line_count = 0,  // number of lines in the input file
        result_line_count = 0,    // number of lines in the output file
        i;

    if (argc != 4) 
    {  // invalid number of arguments
        fprintf(stderr,
                "Usage: %s operations_string input_file output_file\n",
                argv[0]);
        return -1;
    }

    // Open input file for reading
     FILE *input_file = fopen(argv[2], "r");

    if (input_file == NULL) 
    {
        fprintf(stderr, "File \"%s\" not found\n", argv[2]);
        return -2;
    }

    // Read data in file line by line
    while (fgets(buf, 1000, input_file)) 
    {
        strcpy(original[original_line_count], buf);
        original_line_count++;
    }

    fclose(input_file);

    char operations[100], ARGS[100][100];
    char *p, *litera, *aux;
    int j, start, end, n = 0, k;
    strcpy( operations, argv[1]);
    
    i = 0;
    p = strtok(operations,",");
    while(p != NULL)
    {
        strcpy(ARGS[i], p);
        i++;
        p = strtok(NULL,",");
    }
    
    n = i;
    for(k = 0; k < n; k++)
    {
        strcpy(operations, ARGS[k]);
        p = strtok(operations," \n");
        litera = p; //retin operatia ce urmeaza sa fie realizata
   
        if (*litera == 'W' || *litera == 'w')//WRAP
        {
            int max_line_length = 0;
            
            p = strtok(NULL," \n");
            if ( p != NULL)
            {
                aux = p;
                max_line_length = atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            wrap(max_line_length, original, i, original_line_count);
        }
        
        if (*litera == 'C' || *litera == 'c')//CENTER
        {
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            center(start, end,  original, i, original_line_count);
        }
        
        if (*litera == 'L' || *litera == 'l')//ALIGN LEFT
        {   
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            align_left(start, end,  original, i, original_line_count);
        }
        
        if (*litera == 'R' || *litera == 'r')//ALIGN RIGHT
        {
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            align_right(start, end,  original, i, original_line_count);
        }
        
        if (*litera == 'J' || *litera == 'j' )//JUSTIFY
        {
            int start = 0, end = 0;
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
        }
        
        if (*litera == 'P' || *litera == 'p' )//PARAGRAPHS
        {
            int start = 0, end = 0, indent_length = 0;
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                indent_length =  atoi(aux);
            }
            else
            {
                printf("Invalid operation!\n");
                break;
            }
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if (start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            paragraphs(indent_length, start, end, i, original,
                       original_line_count);
        }
        
        if (*litera == 'I' || *litera == 'i' )//LISTS
        {
            int start = 0, end = 0;
            char *list_type, *special_character;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                list_type = p;
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                special_character = p;
            }
            else
            {
                printf("Invalid operation!\n");
                break;
            }
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            if(start > end)
            {
                printf("Invalid operation!\n");
                break;
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            align_left(start, end,  original, i, original_line_count);
            lists(start, end, list_type, special_character, i, original,
                  original_line_count);
        }
        
        if (*litera == 'O' || *litera == 'o' )//ORDERED LISTS
        {
            int start = 0, end = 0;
            char *list_type, *special_character, *ordering;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                list_type = p;
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                special_character = p;
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                ordering = p;
            }
            else
            {
                printf("Invalid operation!\n");
                break;
            }
            start = 0;
            end = original_line_count;
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                start =  atoi(aux);
            }
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                aux = p;
                end =  atoi(aux);
            }
            
            p = strtok(NULL," \n");
            if (p != NULL)
            {
                printf("Invalid operation!\n");
            }
            if(start > end)
            {
                printf("Invalid operation!\n");
            }
            if(start < 0)
            {
                printf("Invalid operation!\n");
                break;
            }
            
            char aux[1000];
            if (*ordering == 'a')//sortare alfabetica
            {
                if ( start == 0 && end == original_line_count)
                {
                    for (i = 0; i < original_line_count - 1; i++)
                    {
                        for (j = i + 1; j < original_line_count; j++)
                        {
                            if(strcmp(original[i],original[j]) > 0)
                            {
                                strcpy(aux, original[i]);
                                strcpy(original[i], original[j]);
                                strcpy(original[j], aux);
                            } 
                        }
                    } 
                }
                else
                {
                    aux[0] = '\0';
                    for (i = start; i <= end; i++)
                    {
                        for (j = i + 1; j <= end; j++)
                        {
                            if(strcmp(original[i],original[j]) > 0)
                            {
                                strcpy(aux, original[i]);
                                strcpy(original[i], original[j]);
                                strcpy(original[j], aux);
                            }   
                    }
                    }
                }
            }
            else
            {
                if (*ordering == 'z')//sortare invers alfabetica
                {
                    if ( start == 0 && end == original_line_count)
                    {
                        for (i = 0; i < original_line_count - 1; i++)
                        {
                            for (j = i + 1; j < original_line_count; j++)
                            {
                                if(strcmp(original[i],original[j]) > 0)
                                {
                                    strcpy(aux, original[i]);
                                    strcpy(original[i], original[j]);
                                    strcpy(original[j], aux);
                                } 
                            }
                        }   
                    }
                    else
                    {
                        aux[0] = '\0';
                        for (i = start; i <= end; i++)
                        {
                            for (j = i + 1; j <= end; j++)
                            {
                                if(strcmp(original[i],original[j]) < 0)
                                {
                                    strcpy(aux, original[i]);
                                    strcpy(original[i], original[j]);
                                    strcpy(original[j], aux);
                                }   
                            }
                        }       
                    }
                }
            }
            align_left(start, end,  original, i, original_line_count);
            lists(start, end, list_type, special_character, i, original,
                  original_line_count);
        }
    }
        
    for (i = 0; i < original_line_count; i++) 
    {
        strcpy(result[i], original[i]);
    }
    result_line_count = original_line_count;

    // Open output file for writing
    FILE *output_file = fopen(argv[3], "w");

    if (output_file == NULL) 
    {
        fprintf(stderr, "Could not open or create file \"%s\"\n", argv[3]);
        return -2;
    }

    // Write result in output file
    for (i = 0; i < result_line_count; i++) 
    {
        fputs(result[i], output_file);
    }

  fclose(output_file);
}
