// Password dictionary

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *strrev(char *s);
char encrypt_string(char *string);
void decrypt_string();
int encrypt_int(int integer);
int decrypt_int(int integer);
void add_password();
void click_img();
void timer(int time);
void display_passwords();
void change_pin(int list_pin);
void display_menu();
int read_pin(int main_code_pin);
void view_suspect_img();
void install_packs();
void set_new_pin();
void reset();
void permission_open();
void permission_close();

int main()
{
    system("clear");
    permission_open();

    // attempts
    int menu_attempts = 3;
    // setted pins for program execution in .pin.txt file
    int main_code_pin;
    main_code_pin = read_pin(main_code_pin);
    // user entered pins
    int entered_code_pin;
    // choices
    int choose_menu;
    char go_back;

    if (main_code_pin == 0)
    {
        printf("Startup:\n");
        install_packs();
        set_new_pin();
    }
    else
    {
        // 3 attempts for entering start pin{entered_code_pi}
        while (menu_attempts != 0)
        {
            printf("Enter the pin:");
            scanf("%d", &entered_code_pin);
            system("clear");

            if (entered_code_pin == main_code_pin)
            {

            menu:
                display_menu();
                printf("Enter your choice [1-9]: ");
                scanf("%d", &choose_menu);
                system("clear");

                switch (choose_menu)
                {
                case 1:
                    display_passwords();
                    break;
                case 2:
                    decrypt_string();
                    break;
                case 3:
                    change_pin(main_code_pin);
                    break;
                case 4:
                    view_suspect_img();
                    break;
                case 5:
                    add_password();
                    break;
                case 6:
                    install_packs();
                    break;
                case 7:
                    main_code_pin = read_pin(main_code_pin);
                    printf("\nCurrent pin is: %d\n", main_code_pin);
                    break;
                case 8:
                    printf("Reseting...\n");
                    reset();
                    exit(1);

                    break;
                case 9:
                    printf("exiting...\n");
                    sleep(1);
                    exit(1);
                    break;

                default:
                    printf("Invalid Input!!\n");
                    break;
                }

                printf("<--Go back to menu! [Y]:");
                fflush(stdin);
                scanf("%c", &go_back);
                getchar();
                printf("\n");
                system("clear");

                goto menu;

                menu_attempts = 0;
            }
            else
            {
                click_img();                                                  // clicking image of user in he/she enters wrong password
                printf("Wrong pin!!! %d attempts left\n", menu_attempts - 1); // for user convience subtracting 1 from menu_attempts

                menu_attempts--; // decrementing the attempts when pin is incorrect
            }
        }
    }
    permission_close();
    return 0;
}

// Functions

// Reverses the string
char *strrev(char *string)
{
    if (string && *string)
    {
        char *b = string, *e = string + strlen(string) - 1;
        while (b < e)
        {
            char t = *b;
            *b++ = *e;
            *e-- = t;
        }
    }
    return string;
}

// Decrypts the string
void decrypt_string()
{
    char code[100];
    printf("Enter encrypted password:");
    scanf("%s", code);
    getchar();
    // decrypt_string(string);
    char *ptr = code;
    int i = 0;
    // decrypting string by 1

    while (code[i] != '\0')
    {
        *ptr = *ptr - 1;
        ptr++;
        i++;
    }

    strrev(code);
    printf("The decrypted password is: ");
    puts(code);
    printf("\n");
}

// Encrypts the string
char encrypt_string(char *string)
{
    char *ptr = string;
    int i = 0;
    while (string[i] != '\0')
    {
        *ptr = *ptr + 1;
        ptr++;
        i++;
    }

    strrev(string);
}

int encrypt_int(int integer)
{
    int reverse = 0, remainder;

    while (integer != 0)
    {
        remainder = integer % 10;
        reverse = reverse * 10 + remainder;
        integer /= 10;
    }
    int encrypt = (reverse * 2);
    return encrypt;
}

int decrypt_int(int integer)
{
    int reverse = 0, remainder;

    int decrypt = (integer / 2);
    while (decrypt != 0)
    {
        remainder = decrypt % 10;
        reverse = reverse * 10 + remainder;
        decrypt /= 10;
    }
    return reverse;
}

// Adds the new password to .passwords_list
void add_password()
{
    char choose_menu = 'y';
    while (choose_menu == 'y')
    {
        system("clear");
        system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary");
        system("chmod 644 .passwords_list.txt");
        FILE *ptr;
        ptr = fopen(".passwords_list.txt", "a");
        char name[100];
        char password[100];

        printf("Enter the name for the password: ");
        scanf("%s", name);
        getchar();

        printf("Ok!\n");
        sleep(1);

        printf("\nEnter the password of %s: ", name);
        fflush(stdin);
        scanf("%[^\n]s", password);

        // char *str = password;

        encrypt_string(password);

        fputs(name, ptr);
        fprintf(ptr, " --> ");
        fputs(password, ptr);
        fprintf(ptr, "\n");

        printf("Password successfully added!\n");

        fclose(ptr);
        system("chmod 444 .passwords_list.txt");
        printf("Do you want to add new password again in dictionary? [Y/n]:");
        scanf("%s", &choose_menu);
    }
}

// clicks the image with opening new another window
void click_img()
{
    // system("sudo apt install streamer");
    system("streamer -f jpeg -o .image.jpeg");
    system("mv image.jpeg /home/$USER/Desktop/programming/code/Projects/Password_dictionary/");
    system("clear");
}

// sets given timer
void timer(int time)
{
    while (time != 0)
    {
        printf("\nwait for: %d sec", time);
        time--;
        sleep(1);
        system("clear");
    }
}

void display_passwords()
{
    FILE *ptr;
    ptr = fopen(".passwords_list.txt", "r");
    // ptr = fopen(".passwords_list.txt", "r");

    char whole_string[1000], c;
    int i = 0;
    // fgets(read_all_passwords, 100, ptr);
    // puts(read_all_passwords);

    while ((c = fgetc(ptr)) != EOF)
    {
        whole_string[i] = c;
        i++;
    }
    whole_string[i] = '\0';
    printf("**********************************************************************\n");
    puts(whole_string);
    printf("**********************************************************************\n");
}

void change_pin(int list_pin)
{
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 222 .pin.txt");
    // int *list_pin;
    int new_list_pin;
    int attempt = 3;
    int current_list_pin;
    char choose_menu;
    char try = 'y';

    FILE *ptr;
    ptr = fopen(".pin.txt", "w");
    printf("Warning: Don't exit while setting new pin else pin will set as 0 by default!\n");

pin:
    printf("\nEnter current pin:");
    scanf("%d", &current_list_pin);

    if (current_list_pin == list_pin)
    {
        printf("\nEnter new pin:");
        scanf("%d", &new_list_pin);
        printf("Password successfully changed to: %d\n", new_list_pin);
        new_list_pin = encrypt_int(new_list_pin);
        fprintf(ptr, "%d", new_list_pin);
        attempt = 0;
    }
    else
    {
        click_img();
        printf("\nWarning: Wrong pin! %d attempts left!", attempt - 1);
        attempt--;
        if (attempt > 0)
        {
            goto pin;
        }
        else
        {
            fprintf(ptr, "%d", list_pin);
        }
    }

    system("chmod 444 .pin.txt");
    fclose(ptr);
}

void display_menu()
{
    printf("**************************************************************************\n");
    printf("Menu: \n");
    printf("[1] Passwords list\n");
    printf("[2] Decrypt_string password\n");
    printf("[3] Change pin\n");
    printf("[4] view suspect's picture\n");
    printf("[5] Add password\n");
    printf("[6] Install necessary packages\n");
    printf("[7] Show my pin\n");
    printf("[8] Reset\n");
    printf("[9] Exit\n");
    printf("**************************************************************************\n");
}

int read_pin(int main_code_pin)
{
    FILE *ptr;
    ptr = fopen(".pin.txt", "r");
    fscanf(ptr, "%d", &main_code_pin);
    fclose(ptr);
    main_code_pin = decrypt_int(main_code_pin);
    // printf("%d\n", main_code_pin);
    return main_code_pin;
}

void view_suspect_img()
{
    // system("sudo apt install feh");
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/");
    system("feh .image.jpeg");
}

void install_packs()
{
    printf("Installing necessary packages for program\n");
    sleep(2);
    system("sudo apt install streamer");
    sleep(2);
    system("sudo apt install feh");
    // printf("\nsuccessfully installed necessary packages\n");
}

void set_new_pin()
{
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 222 .pin.txt");
    FILE *ptr;
    int new_pin;
    ptr = fopen(".pin.txt", "w");
    printf("Setting pin required!\n");
    printf("Enter the pin:");
    scanf("%d", &new_pin);
    new_pin = encrypt_int(new_pin);
    fprintf(ptr, "%d", new_pin);
    printf("Done! exiting....");
    sleep(1);
    fclose(ptr);
    system("chmod 444 .pin.txt");
    exit(1);
}

void reset()
{
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 666 .passwords_list.txt");
    FILE *list;
    list = fopen(".passwords_list.txt", "w");
    fclose(list);
    system("chmod 444 .passwords_list.txt");

    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 666 .pin.txt");
    FILE *pin;
    pin = fopen(".pin.txt", "w");
    fclose(pin);
    system("chmod 444 .pin.txt");
}

void permission_open()
{
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 666 .passwords_list.txt");
    system("chmod 666 .pin.txt");
}
void permission_close()
{
    system("cd /home/$USER/Desktop/programming/code/Projects/Password_dictionary/codes");
    system("chmod 444 .passwords_list.txt");
    system("chmod 444 .pin.txt");
}