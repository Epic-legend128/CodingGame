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
        int width = int.Parse(Console.ReadLine()); // the number of cells on the X axis
        int height = int.Parse(Console.ReadLine()); // the number of cells on the Y axis
        string[] grid = new string[height];
        for (int i = 0; i < height; i++)
        {
            string line = Console.ReadLine(); // width characters, each either 0 or .
            grid[i] = line;
        }

        for (int i = 0; i<width; i++) {
            for (int j = 0; j<height; j++) {
                if (grid[j][i] != '.') {
                    string current = Convert.ToString(i)+' '+Convert.ToString(j);
                    string right; string bottom;
                    if (i < width-1) {
                        right = "-1 -1";
                        for (int k = i+1; k<width; k++) {
                            if (grid[j][k] == '0') {
                                right = Convert.ToString(k)+' '+Convert.ToString(j);
                                break;
                            }
                        }
                    }
                    else {
                        right = "-1 -1";
                    }
                    if (j < height-1) {
                        bottom = "-1 -1";
                        for (int k = j+1; k<height; k++) {
                            if (grid[k][i] == '0') {
                                bottom = Convert.ToString(i)+' '+Convert.ToString(k);
                                break;
                            }
                        }
                    }
                    else {
                        bottom = "-1 -1";
                    }
                    Console.WriteLine(current+" "+right+" "+bottom);
                }
            }
        }
    }
}
