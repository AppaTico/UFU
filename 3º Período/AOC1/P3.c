int main (int argc, char *argv[])
{
    int M[4][4] =
    {16,3,2,13,5,10,11,8,9,6,7,12,4,15,14,1};
    int n = 4, i, j, magico = 1;
    int soma1 = 0, soma2 = 0, soma3 = 0;

    for (i=0; i<n; i++) 
    {
        soma1 = soma1 + M[i][i];
        soma2 = soma2 + M[i][n-1-i];
    }

    if (soma1 != soma2) magico = 0;
    else 
    {
        for (i=0; i<n; i++)
        {
            soma2 = 0;
            soma3 = 0;
            
            for (j=0; j<n; j++)
            {
                soma2 = soma2 + M[i][j];
                soma3 = soma3 + M[j][i];
            }

            if(soma2 != soma3) magico = 0;
            else if(soma1 != soma2) magico = 0;
        }
    }
}
