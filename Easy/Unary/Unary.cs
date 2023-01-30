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
        string MESSAGE = Console.ReadLine();
        string final = "";
        string whole = "";
        for (int i = 0; i<MESSAGE.Length; i++) {
            string character = Convert.ToString(MESSAGE[i], 2);
            if (character.Length < 7) {
                while(character.Length < 7) {
                    character  = '0' + character;
                }
            }
            whole += character;
        }
        string result = "";
        int current = 0;
        char temp;
        while (current < whole.Length) {
            if (whole[current] == '0') {
                result += "00 ";
                temp = '0';
            }
            else {
                result += "0 ";
                temp = '1';
            }
            for (int a = current; a<whole.Length; a++) {
                if (whole[a] == temp) {
                    result += "0";
                }
                else {
                    result += " ";
                    break;
                }
                current = a;
            }
            current++;
        }
        final += result;
        final.Remove(final.Length-1);
        Console.WriteLine(final);
    }
}
