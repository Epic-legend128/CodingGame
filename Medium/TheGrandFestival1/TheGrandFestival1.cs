using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;


class Solution
{
    static public int find(int[] sums, int r, int start, int n, int[] mxs) {
        if (r >= n-start+1) {
            return sums[n] - sums[start-1];
        }
        else if (n == start) {
            return sums[n]-sums[start-1];
        }
        else if (mxs[start] != -1) {
            return mxs[start];
        }
        else {
            int mx = -1;
            for (int i = 1; i<=r; i++) {
                if (start+i+1 <= n) {
                    mx = Math.Max(mx, (find(sums, r, start+i+1, n, mxs)+sums[start+i-1]-sums[start-1]));
                }
            }
            mxs[start] = mx;
            return mx;
        }
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int R = int.Parse(Console.ReadLine());
        int[] prizes = new int[N+1];
        int[] sums = new int[N+1];
        int[] mxs = new int[N+1];
        prizes[0] = 0;
        sums[0] = 0;
        mxs[0] = -1;
        for (int i = 1; i <= N; i++)
        {
            mxs[i] = -1;
            int PRIZE = int.Parse(Console.ReadLine());
            sums[i] = sums[i-1] + PRIZE;
            prizes[i] = PRIZE;
        }
        int result = find(sums, R, 1, N, mxs);
        Console.WriteLine(result);
    }
}
