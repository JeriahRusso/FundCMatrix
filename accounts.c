/*
 *        User Account Management Implementation File:
 *        accounts.c
 *
 *       Fundamentals of Programming with C Assessment Task 3 - Group Assignment
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "accounts.h"

/* Creates a new user account.
 *
 * Takes the user_t user struct array created at runtime and the
 * int number_of_users (a variable in the main).
 *
 * First asks for user input of username and password
 * (reads as string, blocks echo of password insertion), then creates
 * a new user account at the array address pointed to by user[number_of_users]
 *
 * number_of_users is a runtime variable in the main function
 * that increments upon creation of a new user account and
 * after loading users from the db file
 */
void create_user(user_t* user, int number_of_users){
  char dont_print[20];
  char do_print[20];
  char temp_username[50];

  strcpy(dont_print, "stty -echo");
  strcpy(do_print, "stty echo");

  printf("Enter a username>\n");
  fgetc(stdin);
  scanf("%s", temp_username);

  strcpy((user+number_of_users)->username, temp_username);

  printf("Enter a password\n");
  system(dont_print);
  scanf("%s", (user+number_of_users)->password);
  system(do_print);

}



/* Logs a user in.
 *
 * 1. Takes the user_t user struct array created at runtime and the int
 * number_of_users (a variable in the main).
 *
 * 2. Asks for user input of username, accepts a string,
 * then stores into a char array: char temp_user[50]
 *
 * 3. Loops over the user_t user struct array created at runtime.
 * Using string.h::strcmp to determine if the username provided
 * matches any usernames on-file. If it matches, the message "Username Matched"
 * is printed and it moves on to asking for a password.
 * If the username input doesn't match an existing username,
 * the message "username does not exist - create a new account?"
 * is printed, giving the user a choice of 1. trying their username again or
 * 2. creating a new account.
 *
 * 4. Asks for user input of a password. Echo is turned off via system call
 * "stty -echo" to hide user input of password from the terminal/stdout
 * Accepts as string and stores into a char array: char temp_password[50]
 *
 * 5. Loops over the user_t user struct array created at runtime.
 * Using string.h::strcmp to determine if the password provided
 * matches any passwords on-file. If it matches, the message
 * "Login Successful" is displayed to the user and the program menu initiates.
 * If the password input doesnt match an existing password, the message
 * "Login Unsuccessful - Try again?" appears, giving the user the option to
 * try their username and password again, cretae a new account,
 * or exit the program.
 */
int user_login(user_t* user, int number_of_users){
  char dont_print[20];
  char do_print[20];
  char username_input[50];
  char password_input[50];
  int i, username_not_matched = 1, password_not_matched = 1;

  if(number_of_users == 0){
      printf("There are no users, please create an account to login.\n");
      return 0;
  }

  strcpy(dont_print, "stty -echo");
  strcpy(do_print, "stty echo");

    printf("Enter your username:\n");
    scanf("%s", username_input);

    for(i = 0; i < number_of_users; i++){
      if(!strcmp(username_input, user[i].username)){
        username_not_matched = 0;
      }
    }

    printf("Enter your password:\n");

    system(dont_print);
    fgetc(stdin);
    scanf("%s", password_input);
    system(do_print);

    for(i = 0; i < number_of_users; i++){
      if(!strcmp(password_input, user[i].password)){
        password_not_matched = 0;
      }
    }

    if(password_not_matched || username_not_matched){
        printf("Username or password did not match.\n");
        return 0;
    }
  return 1;
}



/* Saves the username and password of all user accounts to a database file.
 *
 * Prints each element of the user_t user struct array (username and password)
 * to the db file for storage.
 */
void save_users_to_db(user_t* user, int number_of_users){
  FILE* fp;
  int i, j;

  fp = fopen(DB_NAME, "w");

  for(i = 0; i <= number_of_users; i++){
    encryptPassword(user, i);
    fprintf(fp, "%s ", user[i].username);
    for(j = 0; j < MAX_PASSWORD_LENGTH; j++){
        if(user[i].password[j] == '\0'){
            fprintf(fp, "\n");
            break;
        }
        fprintf(fp, "%i ", user[i].password[j]);
    }
  }
  fclose (fp);
}


/* Loads all users from the db file into the user_t user struct array
 * on program startup. */
int load_users_from_file(user_t* user){
    int i, isUsername, passLetter, data_counter;
    char dataHolder[MAX_PASSWORD_LENGTH];
    char passHolder[MAX_PASSWORD_LENGTH];
    char inChar;

    data_counter = 0;
    i = 0;
    passLetter = 0;
    isUsername = 1;
    FILE *input;

    if(!(input = fopen(DB_NAME, "r"))){
        input = fopen(DB_NAME, "w");
        fclose(input);
        return 0;
    }

    inChar = getc(input);
    while(inChar != EOF){
        if(inChar == ' '){
            if(isUsername){
                dataHolder[++i] = '\0';
                memcpy(user[data_counter].username, dataHolder,
                        sizeof(dataHolder));
                cleanString(dataHolder);
                i = 0;
                isUsername = 0;
            }else{
                dataHolder[++i] = '\0';
                passHolder[passLetter] = atoi(dataHolder);
                passLetter++;
                cleanString(dataHolder);
                i = 0;
            }
        }else if(inChar == '\n'){
            passHolder[++passLetter] = '\0';
            memcpy(user[data_counter].password, passHolder, sizeof(passHolder));
            encryptPassword(user, data_counter);
            data_counter++;
            i = 0;
            isUsername = 1;
            passLetter = 0;
            cleanString(passHolder);
            cleanString(dataHolder);
        }else{
            dataHolder[i] = inChar;
            i++;
        }
        inChar = getc(input);
    }
    fclose(input);
    return data_counter;
}



/* First level menu of the program */

void user_menu (void)
{
  printf("\n"
           "1. Create new user\n"
           "2. Login\n"
           "Enter choice>\n");
}

void encryptPassword (user_t* user, int userToEncrypt){
    int i;
    for(i = 0; i < MAX_PASSWORD_LENGTH; i++){
        if(user[userToEncrypt].password[i] == '\0'){
            break;
        }
        user[userToEncrypt].password[i] ^= ENCRYPT_KEY[i];
    }
}

void cleanString(char* string){
    int i;
    for(i = 0; i < sizeof(string) / sizeof(string[0]); i++){
        string[i] = 0;
    }
}
