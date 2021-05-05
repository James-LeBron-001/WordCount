
#include "stdio.h"
#include "string.h"

int main(int argc, char* argv[])
{
    int dcnum = 1, zfnum = 0, blank = 0;//单词数量，字符数量
    FILE* fp = fopen(argv[2], "r");
    while (!feof(fp))
    {
        char c = fgetc(fp);
        if (c == ' ' || c == ',')
        {
            blank = 1;
            zfnum++;
            continue;
        }
        if (blank == 1)
        {
            dcnum++;
            blank = 0;
        }
        if (c == '\n' || c == '\t')
        {
            zfnum++;
            continue;
        }
        zfnum++;
    }
    if (strcmp(argv[1],"-c")==0)
    {
        printf("字符数:%d", zfnum);
    }
    else
    {
        printf("单词数:%d", dcnum);
    }
	return 0;
}
