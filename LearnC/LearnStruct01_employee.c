#include <stdio.h>

struct user{
    int userID;
    char firstName[25];
    char lastName[25];
    int age;
    float weight;
};

int main(){
    struct user bucky;
    struct user emily;

    bucky.userID = 1;
    emily.userID = 2;

    puts("Enter the first name of user 1");
    //printf("Enter the first name of user 1");
    
    //gets(bucky.firstName);
    scanf("%s", bucky.firstName);

    printf("User 1 id is %d\n", bucky.userID);
    printf("User 1 name: %s\n", bucky.firstName);
    
    return 0;
}
