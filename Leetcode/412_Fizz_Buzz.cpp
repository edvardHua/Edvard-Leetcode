//
// Created by edvard on 17/02/2017.
//
// Write a program that outputs the string representation of numbers from 1 to n.
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
// For numbers which are multiples of both three and five output “FizzBuzz”.
//

vector<string> fizzBuzz(int n) {
    std::vector<string> v;

    for (int i = 1; i <= n; i++) {

        if(0 == i % 3 && 0 == i % 5){
            v.push_back("FizzBuzz");
            continue;
        }
        if(0 == i % 3){
            v.push_back("Fizz");
            continue;
        }
        if(0 == i % 5){
            v.push_back("Buzz");
            continue;
        }

        v.push_back(to_string(i));

    }
    return v;
}