#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
    std::vector<int> v {2, 7, 1, 6, 2, -2, 4, 0 };

// count how many entries have the target value of 2

    int twos = 0;
    int const target = 2; // using magic number is never good idea life have such impact that you will change later one too many or one not enough.

    for (size_t i = 0; i < v.size(); i++){
        if (v.at(i) == target){
            twos++;
        }
    }
    twos = std::count(v.begin(), v.end(), target);
    twos = std::count(std::begin(v), std::end(v), target);

    // count how many entries are odd(std::begin(v), std::end(v),
    [](auto elem){ return elem % 2 != 0;} );
    int odds = 0;
    for (auto elem : v){
        if (elem % 2 != 0) {
            odds++;
        }
    }
    // same result can be achieved with the following algorithm

    odds = std::count_if(std::begin(v), std::end(v), [](auto elem) { return elem % 2 != 0; });


    std::map<int, int> month_lengths{{1,31},{2,28}, {3,31},{4,30}, {5,31}, {6,30}, {7,31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    // if I want to know how many long months there is I can call this function
    int long_months = std::count_if(std::begin(month_lengths), std::end(month_lengths), [](auto elem) { return elem.second == 31;});
   // we are calling count_if and this algorithm will provide us an answer to this question

    std::cout << long_months << '\n';

    int mid_months = std::count_if(std::begin(month_lengths), std::end(month_lengths), [](auto elem) { return elem.second == 30;});

    std::cout << mid_months << '\n';

    int short_months = std::count_if(std::begin(month_lengths), std::end(month_lengths), [](auto elem) { return elem.second == 28;});

    std::cout << short_months << '\n';


    bool all_ofb, none_ofb, any_ofb;
    all_ofb = (odds == v.size()); // if number of odd elements in collection are same as size then all the values are odd
    none_ofb = (odds == 0); // if number of odd elements is 0 then all elements are even
    any_ofb = (odds > 0);  // if any element is greater then 0 then any values are odd.

    // same can be done with this functions

    all_ofb = std::all_of(std::begin(v), std::end(v),
                         [](auto elem){ return elem % 2 != 0;} );

    none_ofb = std::none_of(std::begin(v), std::end(v),
                         [](auto elem){ return elem % 2 != 0;} );

    any_ofb = std::any_of(std::begin(v), std::end(v),
                          [](auto elem){ return elem % 2 != 0;} );



    return 0;
}