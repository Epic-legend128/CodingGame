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
        int[] distances = new int[N];
        for (int i = 0; i < N; i++)
        {
            int pi = int.Parse(Console.ReadLine());
            distances[i] = pi;
        }
        Array.Sort(distances);
        int mn = distances[distances.Length-1]+1;
        for (int i = 0; i<distances.Length-1; i++) {
            mn = Math.Min(distances[i+1]-distances[i], mn);
        }

        Console.WriteLine(mn);
    }
}
