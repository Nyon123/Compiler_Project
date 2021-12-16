#include <iostream>
using namespace std;

void removeSpaces(string &prgm)
{

    int n = prgm.length();
    int i = 0, j = -1;
    bool spaceFound = false;

    while (++j < n && prgm[j] == ' ');
    while (j < n)
    {

        if (prgm[j] != ' ')
        {

            if ((prgm[j] == '.' || prgm[j] == ',' ||
                 prgm[j] == '?') && i - 1 >= 0 &&
                 prgm[i - 1] == ' ')
                prgm[i - 1] = prgm[j++];

            else

                prgm[i++] = prgm[j++];

            spaceFound = false;
        }

        else if (prgm[j++] == ' ')
        {

            if (!spaceFound)
            {
                prgm[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    if (i <= 1)
        prgm.erase(prgm.begin() + i, prgm.end());
    else
        prgm.erase(prgm.begin() + i - 1, prgm.end());
}
string removemacros(string prgm)
{
    int n = prgm.length();
    string res;

    bool s_cmt = false;
    bool m_cmt = false;

    for (int i=0; i<n; i++)
    {
        if (s_cmt == true && prgm[i] == '\n')
            s_cmt = false;

        else if  (m_cmt == true && prgm[i] == '#' && prgm[i+1] == 'd')
            m_cmt = false,  i++;

        else if (s_cmt || m_cmt)
            continue;

        else if (prgm[i] == '#' && prgm[i+1] == 'd')
            s_cmt = true, i++;
        else if (prgm[i] == '#' && prgm[i+1] == 'd')
            m_cmt = true,  i++;
        else  res += prgm[i];
    }
    return res;
}
int main()
{
    string prgm;
    string new_prgm;
    string rem_macros;
    getline(std::cin,prgm,'^');
    cout << " Modified Program \n";
    new_prgm = removeComments(prgm);;
    removeSpaces(new_prgm);
    rem_macros = removemacros(new_prgm);
    cout << rem_macros;
    return 0;
}
