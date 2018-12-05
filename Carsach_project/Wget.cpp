//
// Created by Andrew on 12/8/17.
//
#pragma once
#include "Wget.h"

    Wget::Wget() {}
    void Wget::download() {

        if (parametr == 'a') {
            memset(wr_buf, BUF_SIZE + 1, 0); // заполняем буфер нулями.

            CURL *curl_handle = curl_easy_init();
            if (curl_handle) {
                curl_easy_setopt(curl_handle, CURLOPT_URL, writable);

                curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, wr_buf);
                curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

                CURLcode res = curl_easy_perform(curl_handle);
                if (res == CURLE_OK) {
                    printf("%s\n Done!", wr_buf); // выводим буфер в консоль.
                } else printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

                std::cout << curl_handle << std::endl;
                int j = 0;
                std::cout << "Do you want to automaticly refer to this page (press 1)?" << std::endl;
                std::cin >> j;
                if (j == 1) {
                    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);

                }

            }
        } else if (parametr == 'b') {

            std::ofstream fout(
                    file_name); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
            if (fout.is_open()) {

                memset(wr_buf, BUF_SIZE + 1, 0); // заполняем буфер нулями.

                CURL *curl_handle = curl_easy_init();
                if (curl_handle) {
                    curl_easy_setopt(curl_handle, CURLOPT_URL, writable);

                    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, wr_buf);
                    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

                    CURLcode res = curl_easy_perform(curl_handle);
                    if (res == CURLE_OK) {
                        //printf("%s\n Done!", wr_buf); // выводим буфер в консоль.
                        fout << wr_buf; // запись строки в файл
                    } else printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

                    std::cout << curl_handle << std::endl;

                }
            } else {
                std::cout << "Incorrect file!";
            }
        } else if (parametr == 'c') {
            CURL *curl;
            CURLcode res;

            curl_global_init(CURL_GLOBAL_DEFAULT);

            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, writable);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
                res = curl_easy_perform(curl);
                if (res != CURLE_OK)
                    fprintf(stderr, "curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));

                curl_easy_cleanup(curl);
            }
        } else if (parametr == 'd') {
            CURL *curl_handle = curl_easy_init();
            if (curl_handle) {
                curl_easy_setopt(curl_handle, CURLOPT_URL, writable);
                curl_easy_setopt(curl_handle, CURLOPT_ENCODING, "gzip,deflate");

                CURLcode res = curl_easy_perform(curl_handle);
                if (res != CURLE_OK)
                    std::cout << "Error #" << res << " " << curl_easy_strerror(res) << std::endl;

                curl_easy_cleanup(curl_handle);
            }

            std::cout << std::endl << "Done!";
        }

    }




