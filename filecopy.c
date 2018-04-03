#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/uio.h>
//#include <sys/stat.h>


#define NAME "Junjie Lu"

int main(int argc, char** argv) {
    char msg[256];
    char buffer[27];
    ssize_t transfer;
    int count = 0;
    char input[10], output[10];
    int input_word = -1, output_word = -1;
    
    /*
     Program wrote by:
     */
    
    int welcome_word = -1;
    int welcome_printed = -1;
    
    welcome_word = sprintf(msg, "Welcome to the File Copy Program by %s!\n", NAME);
    if (welcome_word < 0) {
        perror("Error running sprintf..");
    }
    welcome_printed = write(STDOUT_FILENO, msg, welcome_word);
    if (welcome_printed < 0) {
        perror("Error printing to FD..");
    }
    
    /*
     Copy From:
     Acquire input file name
     */
    
    // Write prompt to screen
    printf("Enter the name of the file to copy from:\n");
    // Accept input
    scanf("%s",input);
    
    // Open the input file
    input_word =  open(input, O_RDONLY);
    
    // if file doesn't exist, abort
    if (input_word < 0) {
        perror("Error opening file..");
        exit(1);
    }
    
    /*
     Copy To:
     Acquire output file name
     */

    // Write prompt to screen
    printf("Enter the name of the file to copy to:\n");
    // Accept input
    scanf("%s", output);
    
    // Create output file
    output_word = open(output, O_WRONLY | O_CREAT | O_EXCL, 777);
    
    // if file exists, abort
    if (output_word < 0) {
        perror("Error copying file..");
        exit(1);
    }
    
    /*
     Loop:
     Read from input file
     Write to output file
     */
    
    while ((transfer = read(input_word, buffer, 27)) > 0) {
        write(output_word, buffer, transfer);
        count += transfer;
    }
    
    // Close output file
    close(input_word);
    close(output_word);
    
    // Write completion message to screen
    printf("File Copy Successful, %d bytes copied\n", count);
    
    
    return 0;
}


