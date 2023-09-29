#include<bits/stdc++.h>
using namespace std;
int main()
{
    string qus;
    char ans[1000000];
    int letter[30]={0};
    cin >> qus;
    int length = 0,i;
    while(qus[length] != '\0')
    {
        letter[ qus[length] - 'A']++;
        length++;
    }
    i = 0;
    for(int j = 0 ; j < 26 ; j++)
    {
        if(letter[j] % 2 == 1)
        {
            i++;
        }
    }
    if(i > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if(length % 2 == 0 && i == 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if ( i == 0)
    {
        int set1 = 0;
        for(int  j = 0 ; j < 26 ; j++)
        {
            while(letter[j] % 2 == 0 && letter[j] != 0)
            {
                ans[set1] = 'A' + j;
                ans[length - 1 -set1] = 'A' + j;
                letter[j] -= 2;
                set1++;
            }
        }
        ans[length] = '\0';
    }
    else if( i == 1)
    {
        int set1 = 0,middle;
        for(int  j = 0 ; j < 26 ; j++)
        {
            if(letter[j] % 2 == 1)
            {
                middle = j;
                letter[j]--;
            }
            while(letter[j] % 2 == 0 && letter[j] != 0)
            {
                ans[set1] = 'A' + j;
                ans[length - 1 -set1] = 'A' + j;
                letter[j] -= 2;
                set1++;
            }
        }
        ans[set1] = 'A' + middle;
        set1++;
        ans[length] = '\0';
    }
 
    cout << ans << endl;
}
