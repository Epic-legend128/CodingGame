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
        int n = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());
        string[][] inputs = new string[n][];
        string[][] outputs = new string[m][];
        for (int i = 0; i < n; i++)
        {
            inputs[i] = Console.ReadLine().Split(' ');
            string inputName = inputs[i][0];
            string inputSignal = inputs[i][1];
        }
        for (int i = 0; i < m; i++)
        {
            outputs[i] = Console.ReadLine().Split(' ');
            string outputName = outputs[i][0];
            string type = outputs[i][1];
            string inputName1 = outputs[i][2];
            string inputName2 = outputs[i][3];
        }
        for (int i = 0; i < m; i++)
        {
            string outputSignal = "";
            string first = "";
            string second = "";
            for (int k = 0; k<n; k++) {
                if (first != "" && second != "") {
                    break;
                }
                else {
                    if (inputs[k][0] == outputs[i][2]) {
                        first = inputs[k][1];
                    }
                    if (inputs[k][0] == outputs[i][3]) {
                        second = inputs[k][1];
                    }
                }
            }
            for (int j = 0; j<inputs[0][1].Length; j++) {
                bool result;
                byte[] bytes = Encoding.ASCII.GetBytes(outputs[i][2]);
                byte[] bytes2 = Encoding.ASCII.GetBytes(outputs[i][3]);
                char a = first[j];
                char b = second[j];

                if (outputs[i][1] == "AND") {
                    result = a == '-' && b == '-';
                }
                else if (outputs[i][1] == "OR") {
                    result = a == '-' || b == '-';
                }
                else if (outputs[i][1] == "XOR") {
                    result = (a == '-' && b == '_') || (a == '_' && b == '-');
                }
                else if (outputs[i][1] == "NAND") {
                    result = !(a == '-' && b == '-');
                }
                else if (outputs[i][1] == "NOR") {
                    result = !(a == '-' || b == '-');
                }
                else {
                    result = (a == '-' && b == '-') || (a == '_' && b == '_');
                }

                if (result) {
                    outputSignal += '-';
                }
                else {
                    outputSignal += '_';
                }
            }
            Console.WriteLine(outputs[i][0]+" "+outputSignal);
        }
    }
}
