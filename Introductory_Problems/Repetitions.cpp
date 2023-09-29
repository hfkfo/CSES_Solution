#include<iostream>
using namespace std;
int main()
{
    string DNA;
    char now_char;
    cin >> DNA;
    int time = 0,temp = 0,i = 0;
    now_char = DNA[i];
    while (DNA[i] != '\0')
    {
        if(now_char == DNA[i])
        {
            temp++;
            i++;
        }
        else
        {
            if(time < temp)
            {
                time = temp;
            }
            now_char = DNA[i];
            temp = 0;
        }
    }
    if(time < temp)
    {
        time = temp;
    }
    cout << time << endl;
 
}
