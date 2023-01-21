#define _CRT_SECURE_NO_WARNINGS 1

char* addBinary(char* a, char* b)
{
    int upadate;
    int lenA = strlen(a);
    int lenB = strlen(b);

    if (lenA == 0 && lenB == 0)
    {
        return a;
    }

    char* merger;

    int mergerlen;
    if (lenA >= lenB)
    {
        merger = (char*)malloc(sizeof(char) * lenA);
        mergerlen = lenA;
    }
    else
    {
        merger = (char*)malloc(sizeof(char) * lenB);
        mergerlen = lenB;
    }

    upadate = 0;
    int indexA = lenA - 1;
    int indexB = lenB - 1;
    int indexM = mergerlen - 1;

    while (indexA >= 0 || indexB >= 0)
    {
        if ((indexA >= 0) && (indexB >= 0))
        {
            if (upadate)
            {
                if (a[indexA] == '1' && b[indexB] == '1')
                {
                    upadate = 1;
                    merger[indexM] = '1';
                }
                else if (a[indexA] == '1' || b[indexB] == '1')
                {
                    upadate = 1;
                    merger[indexM] = '0';
                }
                else
                {
                    upadate = 0;
                    merger[indexM] = '1';
                }

            }
            else
            {
                if (a[indexA] == '1' && b[indexB] == '1')
                {
                    upadate = 1;
                    merger[indexM] = '0';
                }
                else if (a[indexA] == '1' || b[indexB] == '1')
                {
                    merger[indexM] = '1';
                }
                else
                {
                    merger[indexM] = '0';
                }

            }
            indexA--;
            indexB--;
        }
        else if (indexA >= 0)
        {
            if (upadate)
            {
                if (a[indexA] == '1')
                {
                    merger[indexM] = '0';
                    upadate = 1;
                }
                else
                {
                    merger[indexM] = '1';
                    upadate = 0;
                }
            }
            else if (a[indexA] == '1')
            {
                merger[indexM] = '1';
            }
            else
            {
                merger[indexM] = '0';
            }
            indexA--;
        }
        else
        {
            if (upadate)
            {
                if (b[indexB] == '1')
                {
                    merger[indexM] = '0';
                    upadate = 1;
                }
                else
                {
                    merger[indexM] = '1';
                    upadate = 0;
                }
            }
            else if (b[indexB] == '1')
            {
                merger[indexM] = '1';
            }
            else
            {
                merger[indexM] = '0';
            }
            indexB--;
        }
        indexM--;
    }

    int i;
    char* new_merger = (char*)malloc(sizeof(char) * 1000);
    if (upadate)
    {
        for (i = 0; i < mergerlen; i++)
        {
            new_merger[i + 1] = merger[i];
        }
        new_merger[0] = '1';
        new_merger[mergerlen + 1] = '\0';
    }
    else
    {
        for (i = 0; i < mergerlen; i++)
        {
            new_merger[i] = merger[i];
        }
        new_merger[mergerlen] = '\0';
    }
    return new_merger;
}