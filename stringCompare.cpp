#include <iostream>
#include <string>
#include <cstring>

int main() {

    char str1[] = "Hello";
    char str2[6] = "Hello";
    char str3[9] = "notHello";
    char aCopy[10] = "Something";
    std::string str4 = "The name";

    std::cout << "Str1: " << str1 << std::endl;
    std::cout << "Str2: " << str2 << std::endl;
    std::cout << "Str3: " << str3 << std::endl;

    strcpy(aCopy, str1);
    std::cout << "Strcpy aCopy of str1: " << aCopy << std::endl;
    
    int result = strcmp(str1, str2); //result == 0 means they are the same
    std::cout << "Strcmp str1 and str2: " << result << std::endl;
    result = strcmp(str1, str3); //result == -1 means they are not the same
    std::cout << "Strcmp str1 and str3: " << result << std::endl;

    strcat(str1,str2);
    std::cout << "strcat str1 and str2: " << str1 << std::endl;

    int len = strlen(aCopy); //is now 'Hello' from the strcpy, length 5
    std::cout << "strlen of aCopy: " << len << std::endl;
    
    len = str4.size();
    std::cout << "strlen of str4: " << len << std::endl;


    return 0;
}