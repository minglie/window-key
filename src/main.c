#include<windows.h>
#include<stdio.h>
#include<time.h>

/**
先用 WinSpy.exe 找到窗口,然后命令脚本
命令行输入 这个刷新浏览器
 a.exe "index - Google Chrome" 116
**/
int main(int argc,char *argv[]){
//argv[1]  window
//argv[2]  key
//int aa=atoi("234");
//printf("VK_F5=%d,aa=%d\n",VK_F5,atoi("123"));
		HWND window;
        if(argc!=3){
           	printf("need input 3 param\n");
           	return 0;
        }
        char* p_window=argv[1];
        char* p_key=argv[2];
        printf("p_window=%s\n", p_window);
        printf("p_key=%s\n", p_key);
		window = FindWindow(NULL,p_window);
		SwitchToThisWindow(window, TRUE);
		keybd_event(atoi(p_key),0,0,0);//按下
		keybd_event(atoi(p_key),0,KEYEVENTF_KEYUP,0);//弹起
        return 0;
}
