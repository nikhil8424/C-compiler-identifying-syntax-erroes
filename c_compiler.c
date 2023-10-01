#include <stdio.h>
#include <string.h>

int main() {
    char errorCodes[100][100]; // Array to store error codes
    int errorCodeCount = 0;
    int maxLines = 100; // Maximum number of lines to read

    printf("Enter source code (up to %d lines) or 'exit' to stop:\n", maxLines);

    while (errorCodeCount < maxLines) {
        printf("Line %d: ", errorCodeCount + 1);
        fgets(errorCodes[errorCodeCount], sizeof(errorCodes[errorCodeCount]), stdin);
        errorCodes[errorCodeCount][strcspn(errorCodes[errorCodeCount], "\n")] = '\0'; // Remove newline character

        if (strcmp(errorCodes[errorCodeCount], "exit") == 0) {
            break;
        }

        errorCodeCount++;
    }

    for (int i = 0; i < errorCodeCount; i++) {
        char *sourceCode = errorCodes[i];

        printf("Checking Line %d:\n", i + 1);

   // 1.Check for 'int main' 
       if(i+1==1)
   {
    
        if (strstr(sourceCode, "int main")!= NULL&&strstr(sourceCode, "void main") == NULL) 
        {
            if (strstr(sourceCode, "int main()") == NULL) 
        {
            printf("Error in Line %d: Missing 'int main()' function.\n", i + 1);
        }
        }
  //2.check for 'void main'
         if (strstr(sourceCode, "int main")== NULL&&strstr(sourceCode, "void main") !=NULL) 
        {
            if (strstr(sourceCode, "void main()") == NULL) 
        {
            printf("Error in Line %d: Missing 'void main()' function.\n", i + 1);
        }
        }
    
    }
//3.return function
 if (strstr(sourceCode, "int main")!= NULL&&strstr(sourceCode, "return") == NULL)
 {
      printf("Error in Line %d: Missing 'return' function.\n", i + 1);
 }


   //4. Check for missing semicolons
        if (i != 0 && i != 1 && i != errorCodeCount - 1) {
            if (strstr(sourceCode, ";") == NULL) {
                printf("Error in Line %d: Missing semicolon ';'.\n", i + 1);
            }
        }
   // 5.open curly brackets
	if(i+1==errorCodeCount)
	{
       if ( strstr(sourceCode, "}") == NULL) {
            printf("Error in Line %d: Missing  closing curly brace.\n", i + 1);
        }
     
	}

         
   //6.closing curly brackets
	if(i+1==2)
	{
       if (strstr(sourceCode, "{") == NULL) {
            printf("Error in Line %d: Missing opening  curly brace.\n", i + 1);
        }
	}

  
   // 7. Check inverted commas of "printf"
        
        char* printfPos = strstr(sourceCode, "printf");
        if (printfPos != NULL) {
            // Check for the presence of inverted commas
            char* firstQuote = strchr(printfPos, '\"');
            char* lastQuote = strrchr(printfPos, '\"');

            if (firstQuote != NULL && lastQuote != NULL && lastQuote > firstQuote) {
                continue;
            } else {
                printf("Error in Line %d:missing inverted commas in printf.\n", i + 1);
            }
        } 
    //8. Check for 'scanf' errors
        char *scanfPos = strstr(sourceCode, "scanf");
        if (scanfPos != NULL) {
            // Check for the presence of inverted commas
            char *firstQuote = strchr(scanfPos, '\"');
            char *lastQuote = strrchr(scanfPos, '\"');

            if (firstQuote == NULL || lastQuote == NULL || lastQuote <= firstQuote) {
                printf("Error in Line %d: The 'scanf' statement is missing inverted commas.\n", i + 1);
            }
        }

    //9. Check for 'for' loop errors
        char *forPos = strstr(sourceCode, "for");
        if (forPos != NULL) {
            // Check for the presence of parenthesis
            char *firstParen = strchr(forPos, '(');
            char *lastParen = strrchr(forPos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'for' loop is missing parenthesis.\n", i + 1);
            }
        }

    // 10.Check for 'while' loop errors
        char *whilePos = strstr(sourceCode, "while");
        if (whilePos != NULL) {
            // Check for the presence of parenthesis
            char *firstParen = strchr(whilePos, '(');
            char *lastParen = strrchr(whilePos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'while' loop is missing parenthesis.\n", i + 1);
            }
        }

    // 11.Check for 'do-while' loop errors
        char *doWhilePos = strstr(sourceCode, "do");
        if (doWhilePos != NULL) {
            // Check for the presence of parenthesis
            char *firstParen = strchr(doWhilePos, '(');
            char *lastParen = strrchr(doWhilePos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'do-while' loop is missing parenthesis.\n", i + 1);
            }
        }

        //12. Check for 'if' statement errors
        char *ifPos = strstr(sourceCode, "if");
        if (ifPos != NULL) {
            // Check for the presence of parenthesis
            char *firstParen = strchr(ifPos, '(');
            char *lastParen = strrchr(ifPos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'if' statement is missing parenthesis.\n", i + 1);
            }
        }

        //13. Check for 'switch' statement errors
        char *switchPos = strstr(sourceCode, "switch");
        if (switchPos != NULL) {
            // Check for the presence of braces
            char *firstBrace = strchr(switchPos, '{');
            char *lastBrace = strrchr(switchPos, '}');

            if (firstBrace == NULL || lastBrace == NULL || lastBrace <= firstBrace) {
                printf("Error in Line %d: Missing Brackets.\n", i + 1);
            }
        }

        //14. Check for array declaration errors
        char *arrayPos = strstr(sourceCode, "[");
        if (arrayPos != NULL) {
            // Check for the presence of array name
            char *arrayName = strchr(arrayPos, ']');

            if (arrayName == NULL) {
                printf("Error in Line %d: The array declaration is missing an array name.\n", i + 1);
            }
        }
//15. Check for 'else if' statement errors
        char *elseifPos = strstr(sourceCode, "else if");
        if (ifPos != NULL) {
            // Check for the presence of parenthesis
            char *firstParen = strchr(elseifPos, '(');
            char *lastParen = strrchr(elseifPos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'else if' statement is missing parenthesis.\n", i + 1);
            }
        }
        // 16.Check for 'printf paranthesis()' errors
        char *printfbracketPos = strstr(sourceCode, "printf");
        if (printfPos != NULL) {
            // Check for the presence of inverted commas
            char *firstParen = strchr(printfbracketPos, '(');
            char *lastParen = strrchr(printfbracketPos, ')');

            if (firstParen == NULL || lastParen == NULL || lastParen <= firstParen) {
                printf("Error in Line %d: The 'printf' statement is missing parenthesis.\n", i + 1);
            }
        }

    }

    return 0;
}