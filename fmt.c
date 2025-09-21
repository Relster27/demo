#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];
    char* s = "%p,%p,%p,%p,";
    puts("[VULN]");
    printf("Writing %s onto buffer\n", s);
    snprintf(buffer, 42, s);
    for (int i = 0; i < 50; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n============================================\n");
    
    puts("[SAFE]");
    memset(buffer, 0, 50);
    printf("Writing %s onto buffer\n", s);
    snprintf(buffer, 42, "%s\n", s);
    for (int i = 0; i < 50; i++) {
        printf("%c", buffer[i]);
    }

    printf("\n============================================\n");
    return 0;
}

/*
  Vuln source code : https://github.com/php/php-src/blob/php-7.0.0RC1/Zend/zend_execute_API.c#L211
  Safe source code : https://github.com/php/php-src/blob/php-7.0.0/Zend/zend_execute_API.c#L212
  Fix commit       : https://github.com/php/php-src/commit/327b8bf79c5762101ac99930129e2b3e13157c60
*/
