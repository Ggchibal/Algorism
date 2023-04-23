#include <stdio.h>

#define MAX 3

typedef struct FIFO
{
    int pg_a;
    int no_b;

} FIFO;

int main()
{
    struct FIFO arr[MAX] = {0};

    int cnt = 0, pg = 0, time = 1;

    for (int i = 0; i < MAX; i++)
    {
        arr[i].pg_a = i + 1;
        arr[i].no_b = i + 1;
        printf("%d %d\n", arr[i].no_b, arr[i].pg_a);

        time++;
    }

    int min = 1, temp = 0, buff = 0;
    for (int i = 0; i < MAX * 4; i++)
    {
        scanf("%d", &pg);
        int j = 0;
        for (j; j < MAX; j++)
        {
            if (arr[j].pg_a == pg)
            {
                buff = j;
            }
        }
        if (arr[buff].pg_a != pg)
        {
            for (int k = 0; k < MAX; k++)
            {
                if (arr[k].no_b <= min)
                {
                    temp = k;
                }
            }
            arr[temp].pg_a = pg;
            arr[temp].no_b = time++;
            min++;
        }

        printf("FIFO_IO\n");
        for (int j = 0; j < MAX; j++)
        {
            printf("%d %d\n", arr[j].no_b, arr[j].pg_a);
        }
    }
}

// FIFO_IO(arr, temp, time, buff, pg, min);
// int FIFO_IO(struct FIFO arr[], int temp, int time, int buff, int pg, int min)
// {
//     if (arr[buff].pg_a != pg)
//     {
//         for (int i = 0; i < MAX; i++)
//         {
//             if (arr[i].no_b <= min)
//             {
//                 temp = i;
//                 min = arr[i].no_b;
//             }
//         }
//         buff = temp;

//         arr[buff].pg_a = pg;
//         arr[temp].no_b = time;
//         time++;
//         return arr, buff, temp, time, min;
//     }

//     return buff, temp, time, min;
// }