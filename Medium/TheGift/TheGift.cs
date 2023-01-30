using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int C = int.Parse(Console.ReadLine());
        int[] budgets = new int[N];
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            int B = int.Parse(Console.ReadLine());
            budgets[i] = B;
            sum += B;
        }
        if (sum > C) {
            Array.Sort(budgets);

            int avg = C/N;
            Console.Error.WriteLine(avg);
            int c = C;
            for (int i = 0; i<N; i++) {
                if (budgets[i] >= avg) {
                    budgets[i] = avg;
                    c -= avg;
                }
                else {
                    c -= budgets[i];
                }
                if (i != N-1) {
                    avg = c/(N-i-1);
                }
            }

            for (int i = 0; i<N; i++) {
                Console.WriteLine(budgets[i]);
            }
        }
        else {
            Console.WriteLine("IMPOSSIBLE");
        }
    }
}
