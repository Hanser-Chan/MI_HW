#include <stdio.h>

FILE *fl;

int main()
{

    fl = fopen("/Users/CJJ/Documents/mi_hw/Day03/exercise3/text.txt", "a+");
    if (fl == NULL)
    {
        printf("文件打开失败");
        return 1;
    }

    // char input[] = {'c', 'h', 'e', 'n', 'j', 'i', 'n', 'j', 'i', 'a', 'n'};

    // printf("请输入要写入文件的内容（最多100个字符）：\n");
    // fgets(input, sizeof(input), stdin);
    // fputs(input, fl);
    fputs("-chenjinjian\n", fl);

    printf("内容已成功写入文件。\n");

    char ch;
    printf("文件内容：\n");
    while ((ch = fgetc(fl)) != EOF)
    {
        putchar(ch);
    }

    fclose(fl);
}