using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    class Program
    {
        static void Main(string[] args)
        {
            string sentence;
            sentence = Console.ReadLine();
            string s = " ,:;'!.";
            string[] StringArray = sentence.Split(s.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            string Longest = "", Shortest = "1111111111111", FirstAlphabet = "Z", LastAlphabet = "A";
            foreach (string str in StringArray)
            { 
                Longest       = str.Length > Longest.Length      ? str : Longest;
                Shortest      = str.Length < Shortest.Length     ? str : Shortest;
                FirstAlphabet = str.CompareTo(FirstAlphabet) < 0 ? str : FirstAlphabet;
                LastAlphabet  = str.CompareTo(LastAlphabet)  > 0 ? str : LastAlphabet;
            }
            Console.WriteLine($"Longest word is { Longest}, Shortest word is {Shortest}" +
                $", FirstAlphabet word is {FirstAlphabet}, LastAlphabet word is {LastAlphabet}" );

        }
    }
}
