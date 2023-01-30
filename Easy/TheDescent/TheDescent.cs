using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Player
{
    static void Main(string[] args)
    {

        // game loop
        while (true)
        {
            int index = 0;
            int mx;
            mx = int.Parse(Console.ReadLine()); // represents the height of one mountain.;
            for (int i = 1; i < 8; i++)
            {
                int current = int.Parse(Console.ReadLine()); // represents the height of one mountain.
                if (current > mx) {
                    index = i;
                    mx = current;
                }
            }

            Console.WriteLine(index); // The index of the mountain to fire on.

        }
    }
}
