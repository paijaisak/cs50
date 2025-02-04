#include "encipher.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        string res = encipher("abc", "def");

        printf("%s", res);

        return 0;
}
