#include<bits/stdc++.h>
using namespace std;
int main()
{
    string qus;
    cin >> qus;
    int letter[30] = {0};
    int length = 0, num =1;
    while (qus[length] != '\0')
    {
        letter[qus[length] - 'a']++;
        length++;
        num *= length;
        num = num / letter[qus[length - 1] - 'a'];
    }
    cout << num << endl;
    sort(qus.begin(),qus.end());
    cout << qus << endl;
    for(int i = 1; i < num ; i++)
    {
        int j;
        for( j = length - 2 ; j >= 0 ; j--)
        {
            if(qus[j] < qus[j + 1])
            {
                break;
            }
        }
        int min = -1;
        for( int k = j +1 ; k < length ; k++)
        {
            if( min == -1 && qus[k] > qus[j])
            {
                min = k;
            }
            else if( min != -1 && qus[k] > qus[j] && qus[k] <= qus[min])
            {
                min = k;
            }
        }
        char temp = qus[j];
        qus[j] = qus[min];
        qus[min] = temp;
        int change = 1;
        while( j + change <= length - change )
        {
            temp = qus[j + change];
            qus[j + change] = qus[length - change];
            qus[length - change] = temp;
            change++;
        }
        cout << qus << endl;
    }
}
