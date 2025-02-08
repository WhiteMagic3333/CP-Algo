using System;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        string input = Console.ReadLine();
            
        // Clean the input by removing curly braces and extra spaces
        input = input.Trim().Trim('{', '}').Trim();
        
        // Convert input to an integer array
        int[] arr = Array.ConvertAll(input.Split(','), s => int.Parse(s.Trim()));

        // Check if the input has less than 2 elements
        if (arr.Length < 2)
        {
            Console.WriteLine("No pairs found");
            return;
        }

        List<string> result = new List<string>();

        // Loop through the array to find pairs with even sums
        for (int i = 0; i < arr.Length - 1; i++)
        {
            if ((arr[i] + arr[i + 1]) % 2 == 0)
            {
                result.Add($"Index: {i}, {i + 1} | Values: {arr[i]}, {arr[i + 1]}");
                i++; // Skip the next element since it is already paired
            }
        }

        foreach (var pair in result)
        {
            Console.WriteLine(pair);
        }
    }
}
