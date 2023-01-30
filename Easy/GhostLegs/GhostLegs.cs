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
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        int amount = (W+2)/3;
        int[] column = new int[amount+1];
        string[] temp = Console.ReadLine().Split("  ");
        for (int i = 1; i<(amount)+1; i++) {
            column[i] = i;
        }

        for (int i = 0; i < H-2; i++)
        {
            string line = Console.ReadLine();
            int counter = 1;
            for (int j = 1; j<W; j+=3) {
                if (line[j] == '-') {
                    for (int w = 1; w<amount+1; w++) {
                        if (column[w] == counter) {
                            column[w] += 1;
                        }
                        else if (w <= amount) {
                            if (column[w] == counter+1) {
                                column[w] -= 1;
                            }
                        }
                    }
                 }
                 counter++;
            }
        }
        string[] last = Console.ReadLine().Split("  ");
        
        for (int i = 0; i<amount; i++) {
            Console.WriteLine(temp[i]+""+last[column[i+1]-1]);
        }
    }
}
