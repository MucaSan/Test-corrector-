#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// prototypes
void get_Right_answers(int n, char str[n]);
void get_User_answers(int n , char str[n], char str1[n]);
void get_numAnswers(int n, int array[n]);
void get_numUser_answers(int n, int array[n], int array1[n]);
void warning_1(void);

int 
main (void)
{

 int n; 
  printf("The number of questions: ");
  scanf("%d", &n);
  // get the input of the user with the right answers, using an n value for it.
    // string for the right answers

    warning_1();
    char ch;
    scanf (" %c", &ch);
    // simplify cases again.
    ch = toupper(ch);

    initialization:

     if (ch == 'Y')
       {
           char rgta[n];
           get_Right_answers(n, rgta);

           printf ("Insert, after this, your answers. \n ");
          // user answers for the test. 
          char userAnswer[n];
          get_User_answers(n, rgta, userAnswer);
       }

      else if (ch == 'N')
        {
           int rgta[n];
           get_numAnswers(n, rgta);

           printf ("Insert, after this, your answers. \n ");
          // user answers for the test. 
          int userAnswer[n];
          get_numUser_answers(n, rgta, userAnswer); 
        }

        else 
        {
            
                while (true)
                    {
                         printf("You chose a wrong option, try again (Y or N): ");
                         scanf (" %c", &ch);
                         ch = toupper(ch);
                         if (ch == 'N')
                          {
                                           goto initialization;
                          } 
                      else if (ch == 'Y')
                          {
                              // do something...
                          }
                         
                    }
            
        } 

            printf ("To finish the program, press [CTRL + C].\n");
            printf ("To restart the program, press [R]. \n");
            scanf(" %c", &ch);
            ch = toupper(ch);
        
               switch (ch)
                {
                    case 'R':
                    // loop while, to always get the value R or not
                    while (true)
                     {
                          int num;
                          printf("The number of questions: ");
                          scanf(" %d", &num);
                          warning_1();
                          scanf(" %c", &ch);
                          ch = toupper(ch);

                          if (ch == 'Y') 
                            { 
                                           char str1[num];
                                           get_Right_answers(num, str1);
                                           printf ("Insert, after this, your answers. \n ");
                                           char str2[num];
                                           get_User_answers(n, str1, str2);
                                           printf ("To stop running the program, press [CTRL + C].\n");
                                           printf ("To restart the program, press [R]. \n");
                                           scanf(" %c", &ch);
                                           ch = toupper(ch);
                          }

                          else if (ch == 'N')
                            {
                                           int str1[num];
                                           get_numAnswers(num, str1);
                                           printf ("Insert, after this, your answers. \n ");
                                           int str2[num];
                                           get_numUser_answers(n, str1, str2);
                                           printf ("To stop running the program, press [CTRL + C].\n");
                                           printf ("To restart the program, press [R]. \n");
                                           scanf(" %c", &ch);
                                           ch = toupper(ch);
            
                            }
                     }
                    break;
                    default:
                    // case it returns 0 in the function, it means that the user
                    // left directly
                    return 0;
                    break;

                }

    } 
     
void
get_Right_answers(int n, char str[n])
{
    for (int i = 0 ; i < n; i++)
     {
         printf ("Question %d: ", i+1);
         scanf(" %s", &str[i]);
         str[i] = toupper(str[i]);
         int check_Input = false;
          check_Input = (isalpha(str[i]) == false) ? true : false;
               while (check_Input == true) 
               {
                     printf ("You've done a wrong input, try again: ");
                     scanf(" %s", &str[i]);
                     check_Input = (isalpha(str[i]) == true) ? false : true;
              }
      }
}

void
get_User_answers(int n, char str[n], char str1[n])
{
    int correct_Answers = false;
        for (int j = 0 ; j < n; j++)
         {
              printf ("Q%d: \n", j+1);
              scanf(" %s", &str1[j]);
              str1[j] = toupper(str1[j]);
              int check_Input = false;
              check_Input = (isalpha(str1[j]) == false) ? true : false;
                   while (check_Input == true) 
                   {
                         printf ("You've done a wrong input, try again: ");
                         scanf(" %s", &str1[j]);
                         check_Input = (isalpha(str1[j]) == true) ? false : true;
                   }
                         if (str[j] == str1[j])
                          correct_Answers++;     
         }

         printf ("You've got %d right answer(s) out of %d questions \n", correct_Answers, n);

         if (correct_Answers >= n/2)
            printf ("Congratulations, but you always have something to improve! \n");
}

void
get_numAnswers(int n, int array[n])
{
    for (int i = 0 ; i < n; i++)
     {
         printf ("Question %d: ", i+1);
         scanf(" %s", &array[i]);
         array[i] = toupper(array[i]);
         int check_Input = false;
          check_Input = (isdigit(array[i]) == false) ? true : false;
               while (check_Input == true) 
               {
                     printf ("You've done a wrong input, try again: ");
                     scanf("%s", &array[i]);
                     check_Input = (isdigit(array[i]) == true) ? false : true;
              }
      }
}

void
get_numUser_answers(int n, int array[n], int array1[n])
{
    int correct_Answers = false;
        for (int j = 0 ; j < n; j++)
         {
              printf ("Q%d: \n", j+1);
              scanf(" %s", &array1[j]);
              array1[j] = toupper(array1[j]);
              int check_Input = false;
              check_Input = (isdigit(array1[j]) == false) ? true : false;
                   while (check_Input == true) 
                   {
                         printf ("You've done a wrong input, try again: ");
                         scanf(" %s", &array1[j]);
                         check_Input = (isdigit(array1[j]) == true) ? false : true;
                   }
                         if (array[j] == array1[j])
                          correct_Answers++;     
         }

         printf ("You've got %d right answer(s) out of %d questions \n", correct_Answers, n);

         if (correct_Answers >= n/2)
            printf ("Congratulations, but you always have something to improve! \n");

}

void warning_1
(void)
{
    printf ("Do you want the answers in letters? \n");
    printf ("Press [Y] to select the options of answers in letters (alphabet) \n");
    printf ("Press [N] to select the options of answers in numbers. (alphanumeric) \n");
}



