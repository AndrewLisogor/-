#include "curl/curl.h"
#include "Wget.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"curllib-bcb.lib") // Для C++Builder
//#pragma comment(lib,"curllib.lib")    // для VC++






int main() {

     Wget A;
    A.download();

    /**/

    getchar();
    return 0;
}
