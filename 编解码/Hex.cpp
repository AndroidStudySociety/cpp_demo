//
// Created by Jesson on 2019/12/27.
//

#include "Hex.h"
#include <iostream>
using namespace std;
/***
 * 在这里主要给大家补充一些基础的编码知识 就是你很怕的 看的头疼的那些代码 那些最基础的代码 加油
 */

int main(){
    char sztext[1024] = "-A123400中国我爱你";
    int nRead = strlen(sztext);

    char sz2[1024] = "";
    for (int i = 0;i < nRead;++i)
    {
        int nind = 0;
        // 将字符编码转转换为16进制编码
        if(sztext[i] < 0)
            nind = sztext[i] + 256;
        else
            nind = sztext[i];

        char szTemp[10]="";
        // 16进制用小写表示，格式化串用“%02x”
        // 16进制用大写表示，格式化串用“%02X”
        sprintf(szTemp,"%02X ",nind);
        strcat(sz2,szTemp);
    }
    printf("%s\n",sz2);

    // 待输出的字符串（16进制编码表示）
    char sztext_cp[1024] = "\x2D\x41\x31\x32"
                           "\x33\x34\x30\x30\xE4\xB8\xAD\xE5"
                           "\x9B\xBD\xE6\x88\x91\xE7\x88\xB1"
                           "\xE4\xBD\xA0";
    //2D 41 31 32 33 34 30 30 E4 B8 AD E5 9B BD E6 88 91 E7 88 B1 E4 BD A0
    int nRead_cp = strlen(sztext);
    // 存储还原后的字符串
    char sz2_cp[1024] = "";
    for (int i = 0;i < nRead_cp;++i)
    {
        // 将16进制编码还原字符串
        if(sztext_cp[i] < 0)
            sz2_cp[i] = sztext_cp[i] - 256;
        else
            sz2_cp[i] = sztext_cp[i];
    }
    // 输出还原后的字符串
    printf("%s\n",sz2_cp);
}


//学习上mian

/***
 *
 * @param data
 * @param n
 * @param hex
 * @return
 */
int HexEncoder(const unsigned char* data,int n,char* hex){
    int count = 0;
}


int HexDecoder(const unsigned char* data,int n,char* hex){
    int count = 0;
}
