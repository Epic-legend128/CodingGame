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
        string[] inputs;
        inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]); // width of the building.
        int H = int.Parse(inputs[1]); // height of the building.
        int N = int.Parse(Console.ReadLine()); // maximum number of turns before game over.
        inputs = Console.ReadLine().Split(' ');
        int X0 = int.Parse(inputs[0]);
        int Y0 = int.Parse(inputs[1]);
        int bottomX = 0;
        int upX = W;
        int bottomY = 0;
        int upY = H;

        // game loop
        while (true)
        {
            string bombDiread = Console.ReadLine(); // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
            if (bombDiread[0] == 'U') {
                upY = Y0;
                Y0 = (upY+bottomY)/2;
            }
            else if (bombDiread[0] == 'D') {
                bottomY = Y0;
                Y0 = Y0 + ((upY - bottomY)/2);
            }
            else if (bombDiread[0] == 'L') {
                upX = X0;
                X0 = (upX+bottomX)/2;
            }
            else {
                bottomX = X0;
                X0 = bottomX + ((upX - X0)/2);
            }
            if (bombDiread.Length > 1) {
                if (bombDiread[1] == 'L') {
                    upX = X0;
                    X0 = (upX+bottomX)/2;
                }
                else {
                    bottomX = X0;
                    X0 = bottomX + ((upX - X0)/2);
                }
            }
            Console.WriteLine(X0 + " " + Y0);
        }
    }
}
