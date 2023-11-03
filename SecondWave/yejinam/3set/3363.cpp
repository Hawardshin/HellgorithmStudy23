#include "iostream"

using namespace std;

int arr[11];
int main()
{
    int table[3][8];
    char sign[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> table[i][j];
            if (j == 3)
                cin >> sign[i];
        }
        if (sign[i] == '=')
        {
            for (int j = 0; j < 8; j++)
            {
                arr[table[i][j]] = -1;
            }
        }
    }


    int fake = 0;

    for (int i = 1; i <= 10; i++)
    {
        if (arr[i] == -1)
            continue;

        for (int j = 0; j < 3; j++)
        {
            if (sign[j] == '=')
                continue;
            if (sign[j] == '>')
            {
                if (table[j][0] == i || table[j][1] == i
                        || table[j][2] == i || table[j][3] == i )
                {
                    if (arr[i] == 0)
                        arr[i] = 1;
                    else if (arr[i] == 2)
                    {
                        arr[i] = -1;
                        break;
                    }
                }
                else if (table[j][4] == i || table[j][5] == i
                        || table[j][6] == i || table[j][7] == i )
                {
                    if (arr[i] == 0)
                        arr[i] = 2;
                    else if (arr[i] == 1)
                    {
                        arr[i] = -1;
                        break;
                    }
                }
                else
                {
                    arr[i] = -1;
                    break;
                }
            }
            else
            {
                if (table[j][0] == i || table[j][1] == i
                        || table[j][2] == i || table[j][3] == i )
                {
                    if (arr[i] == 0)
                        arr[i] = 2;
                    else if (arr[i] == 1)
                    {
                        arr[i] = -1;
                        break;
                    }
                }
                else if (table[j][4] == i || table[j][5] == i
                        || table[j][6] == i || table[j][7] == i )
                {
                    if (arr[i] == 0)
                        arr[i] = 1;
                    else if (arr[i] == 2)
                    {
                        arr[i] = -1;
                        break;
                    }
                }
                else
                {
                    arr[i] = -1;
                    break;
                }

            }

        }
    }
    
    int ans;

    for (int i = 1; i <= 10; i++)
    {
        cout << arr[i] << " "; 
        if (arr[i] != -1)
        {
            fake++;
            ans = i;
        }
    }

    if (fake == 0)
        cout << "impossible";
    else if (fake != 1)
        cout << "indefinite";
    else
    {
        cout << ans;
        if (arr[ans] == 1)
            cout << "+";
        else
            cout << "-";
    }


}
