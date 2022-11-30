#include "disk.c"

int main() {

    printf("Starting program...\n");
    
    // Name of the disk from input
    char* diskNameInput = malloc(sizeof(char) * MAX_LENGTH_NAMES);
    printf("$ Insert the name of the disk (30 characters max): ");
    fgets(diskNameInput, MAX_LENGTH_NAMES, stdin);
    diskNameInput[strlen(diskNameInput) - 1] = '\0';
    
    // Disk creation
    Disk* disk = Disk_create(diskNameInput);

    // Disk opening
    printf("Opening disk [%s] in the 'os/disks/' folder.\n", disk->name);
    if (Disk_open(disk) != DISK_OK) 
        exit(DISK_ERROR);

    printf("Loading filesystem...\n");
    
    printf("FAT Filesystem by Tamer Hayek\n");
    
    char* commandInput = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    char* splitToken;

    // STARTING PROGRAM
    printf("Type 'help' for the list of available commands.\n");
    while (1) {
        printf("$ ");
        fgets(commandInput, MAX_INPUT_LENGTH, stdin);
        commandInput[strlen(commandInput) - 1] = '\0';
        if (strcmp(commandInput, "exit") == 0 || strcmp(commandInput, "quit") == 0) { // exit, quit commands
            printf("Exiting program...\n");
            break;
        } else if (strcmp(commandInput, "clear") == 0) { // clear commands
            system("@cls||clear");
            printf("FAT Filesystem by Tamer Hayek\n");
        } else if (strcmp(commandInput, "help") == 0) { // help command
            printf("Available commands:\n");
            // Shell commands
            printf("- Shell commands:\n");
            printf("    clear -> clear the output of this shell\n");
            printf("    exit -> close the program\n");
            printf("    quit -> close the program\n");
            // File commands
            printf("- File commands:\n");
            printf("    touch -> creates a new file\n");
            printf("    rm -> removes a file\n");
            printf("    cat -> displays the contents of a file\n");
            // Directory commands
            printf("- Directory commands:\n");
            printf("    ls -> lists the contents of the current directory\n");
            printf("    cd -> changes the current directory\n");
            printf("    mkdir -> creates a new directory\n");
            printf("    rmdir -> removes a directory\n");
        } else { // other commands
            splitToken = strtok(commandInput, " ");
            if (strcmp(splitToken, "ls") == 0) {
                // display list of files in current directory
                splitToken = strtok(NULL, " ");
                if (splitToken != NULL) {
                    printf("Contents of '%s' directory", splitToken);
                } else {
                    printf("Contents of current directory");
                }
            } else if (strcmp(splitToken, "cd") == 0) {
                // change current directory
                splitToken = strtok(NULL, " ");
                if (splitToken != NULL) {
                    printf("Change current directory to '%s'", splitToken);
                } else {
                    printf("Change current directory to home");
                }
            } else if (strcmp(splitToken, "touch") == 0) {
                // create file in current directory
                splitToken = strtok(NULL, " ");
                if (splitToken != NULL) {
                    printf("Created file '%s'", splitToken);
                    do {
                        splitToken = strtok(NULL, " ");
                        if (splitToken != NULL) {
                            printf("\nCreated another file '%s'", splitToken);
                        }
                    } while (splitToken != NULL);
                } else {
                    printf("Expecting name of file to create.");
                }
            } else {
                printf("Unknown command. Type 'help' for a list of available commands.");
            }
            printf("\n");
        }
    }
    // Disk Destroy
    if (Disk_destroy(disk) != DISK_OK)
        exit(DISK_ERROR);
    return 0;  
}