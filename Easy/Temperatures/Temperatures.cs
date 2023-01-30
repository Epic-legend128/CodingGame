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
        int n = int.Parse(Console.ReadLine()); // the number of temperatures to analyse
        string[] inputs = Console.ReadLine().Split(' ');
        int mn;
        if (n == 0) {
            mn = 0;
        }
        else {
            mn = int.Parse(inputs[0]);// a temperature expressed as an integer ranging from -273 to 5526
        }
        for (int i = 1; i < n; i++)
        {
            int t = int.Parse(inputs[i]);// a temperature expressed as an integer ranging from -273 to 5526
            if (t == 0) {
                mn = 0;
                break;
            }
            else if (Math.Abs(mn) == Math.Abs(t) && mn < 0) {
                mn = t;
            }
            else if (Math.Abs(mn) > Math.Abs(t)) {
                mn = t;
            }
        }
        
        Console.WriteLine(mn);
    }
}
