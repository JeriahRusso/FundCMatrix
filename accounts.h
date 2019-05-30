
/*
 *      accounts.h
 *
 *      User account management header file for:
 *      Fundamentals of Programming with C Assignment 3 - Group Assignment
 *
 */



/* The file name of the database that stores username and
   password of all accounts */
#define DB_NAME "db.txt"

#define MAX_NUM_USERS 200
#define ENCRYPT_KEY "JwOFPbJ7mzEdqRH5scYq5nlREbRKcA4bGbjoZCp6886vFLwCo"
#define MAX_PASSWORD_LENGTH 50

/* The struct that contains all user accounts -
    to be used as a struct array i.e user[MAX_NUM_USERS] */
struct user {
  char username[50];
  char password[50];
};
typedef struct user user_t;


/* Creates a new user account.
 *
 * Takes the user_t user struct array created at runtime and the int
 * number_of_users (a variable in the main).
 *
 * First asks for user input of username and password (reads as string,
 * blocks echo of password insertion), then creates
 * a new user account at the array address pointed to by user[number_of_users]
 *
 * number_of_users is a runtime variable in the main function that
 * increments upon creation of a new user account and
 * after loading users from the db file
 */
void create_user(user_t* user, int number_of_users);


/* Logs a user in.
 *
 * 1. Takes the user_t user struct array created at runtime and the
 * int number_of_users (a variable in the main).
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
 * is printed, giving the user a choice of 1. trying their username again or 2.
 * creating a new account.
 *
 * 4. Asks for user input of a password. Echo is turned off via system call
 * "stty -echo" to hide user input of password from the terminal/stdout
 * Accepts as string and stores into a char array: char temp_password[50]
 *
 * 5. Loops over the user_t user struct array created at runtime.
 * Using string.h::strcmp to determine if the password provided
 * matches any passwords on-file. If it matches, the message "Login Successful"
 * is displayed to the user and the program menu initiates.
 * If the password input doesnt match an existing password, the message
 * "Login Unsuccessful - Try again?" appears, giving the user the option to
 * try their username and password again, cretae a new account,
 * or exit the program.
 */
void user_login(user_t* user, int number_of_users);


/* Saves the username and password of all user accounts to a database file.
 *
 * Prints each element of the user_t user struct array (username and password)
 * to the db file for storage.
 */
void save_users_to_db(user_t* user, int number_of_users);


/* Loads all users from the db file into the user_t
   user struct array on program startup. */
int load_users_from_file(user_t* user);


/* First level menu of the program */
void user_menu (void);


/*Encrypts the users password using XOR cryptography*/
void encryptPassword (user_t* user, int userToEncrypt);

/*Cleans a char[] to all 0*/
void cleanString (char* string);
