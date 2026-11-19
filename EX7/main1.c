#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int lotto[5][7];
    int i, j, k;
    int num;
    FILE *fp;

    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透：");
    scanf("%d", &n);

    if (n < 1 || n > 5)
    {
        printf("請輸入 1 ~ 5 組！\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            num = rand() % 69 + 1;

            for (k = 0; k < j; k++)
            {
                if (lotto[i][k] == num)
                {
                    break;
                }
            }

            if (k == j)
            {
                lotto[i][j] = num;
            }
            else
            {
                j--;
            }
        }
    }

    fp = fopen("lotto.txt", "w");

    if (fp == NULL)
    {
        printf("檔案開啟失敗！\n");
        return 0;
    }

    time_t now = time(NULL);

    fprintf(fp, "========== lotto649 ==========\n");
    fprintf(fp, "= %s", ctime(&now));
    
    fprintf(fp, "N = %d\n", n);

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "[%d]: ", i + 1);

        for (j = 0; j < 7; j++)
        {
            fprintf(fp, "%02d ", lotto[i][j]);
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "========== csie@CGU ==========\n");

    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
