#include <stdio.h>

#include <curl/curl.h>
#include <curl/types.h>

#include <curl/easy.h>



struct FtpFile   //定义一个结构为了传递给my_fwrite函数.可用curl_easy_setopt的CURLOPT_WRITEDATA选项传递

{

        char *filename;

        FILE *stream;

};



int my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream)

{

        struct FtpFile *out=(struct FtpFile *)stream;  // stream指针其实就是 指向struct FtpFile ftpfile的

        if(out && !out->stream)

        {

                out->stream=fopen(out->filename, "wb"); //没有这个流的话就创建一个 名字是out->filename.

                if(!out->stream){
				printf("OPEN OPEN::%s\n",out->filename);
			}else{
				printf("OPEN OPEN::%s\n",out->filename);
			}

                return -1;

        }

        return fwrite(buffer, size, nmemb, out->stream);

}



int main(int argc, char *argv[])

{

        CURL *curl;

        CURLcode res;

        struct FtpFile ftpfile={argv[2],NULL};  //初始化一个FtpFile结构 

        curl_global_init(CURL_GLOBAL_DEFAULT);



        curl = curl_easy_init();

        if(curl)

        {
                curl_easy_setopt(curl,CURLOPT_URL,argv[1]);

                curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, my_fwrite);

                curl_easy_setopt(curl,CURLOPT_WRITEDATA, &ftpfile);  //给相关函数的第四个参数 传递一个结构体的指针

                curl_easy_setopt(curl,CURLOPT_VERBOSE,1L);  //CURLOPT_VERBOSE 这个选项很常用 用来在屏幕上显示对服务器相关操作返回的信息



                res = curl_easy_perform(curl);

                curl_easy_cleanup(curl);



                if(CURLE_OK != res)

                        fprintf(stderr, "curl told us %d/n", res);

        }

        if(ftpfile.stream)

        fclose(ftpfile.stream);

        curl_global_cleanup();



        return 0;

}
