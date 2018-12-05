//
// Created by Andrew on 12/8/17.
//

#ifndef EXAMPLE_WGET_H
#define EXAMPLE_WGET_H
#include "URL.h"
#include "Param.h"
#include "File.h"
#include "curl/curl.h"
#include <sys/stat.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"curllib-bcb.lib") // Для C++Builder
//#pragma comment(lib,"curllib.lib")    // для VC++

const size_t BUF_SIZE = 5000000;
char wr_buf[BUF_SIZE + 1]; // char*   wr_buf[BUF_SIZE+1];
size_t wr_index = 0;
//---------------------------------------------------------------------------
static size_t write_data(char * ptr, size_t size, size_t nmemb, char * data) {
    if (data == NULL || wr_index + size * nmemb > BUF_SIZE) return 0; // Если выход за размеры буфера - ошибка

    memcpy( & data[wr_index], ptr, size * nmemb); // дописываем данные в конец
    wr_index += size * nmemb; // изменяем  текущее положение

    return size * nmemb;
}
//---------------------------------------------------------------------------
class Wget: public URL, public Param, public File {

public:
    Wget();
    void download();
};

#endif //EXAMPLE_WGET_H