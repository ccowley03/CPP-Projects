#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    char *first_name= NULL;
    char *last_name =NULL;
    char *whole_name = NULL;
    int first_name_length = 0;
    int last_name_length = 0;
    int whole_name_length = 0;
    
    strcpy(first_name,"Bjarne");
    
    strcpy(last_name,"Stroustrup");
    
    strcpy(whole_name,first_name);
    strcat(whole_name,last_name);
    
    first_name_length = strlen(first_name);
    
    last_name_length = strlen(last_name);
    
    whole_name_length = strlen(whole_name);
    
    cout << "The length of the first name, " << first_name << ", is " << first_name_length << " letters long and the length of the last name, " << last_name << ", is " << last_name_length << " letters long. This means that the length of the whole name must be " << whole_name_length << " letters long."<<endl;
    return 0;
}
