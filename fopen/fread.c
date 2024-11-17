#include <stdlib.h>
#include <stdio.h>
#include "data_for_fread.h"

int main()
{

    const char *binary_file = "data.bin";
    const char *text_file = "data.txt";

    // 寫入文件
    write_binary_file(binary_file);
    write_text_file(text_file);

    // 讀取文件
    read_binary_file(binary_file);
    read_text_file_fscanf(text_file);
    read_text_file_fgets(text_file);

    return 0;
}