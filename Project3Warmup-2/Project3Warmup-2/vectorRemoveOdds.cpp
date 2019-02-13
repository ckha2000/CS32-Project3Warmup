//
//  main.cpp
//  Project3Warmup-2
//
//  Created by christopher kha on 2/13/19.
//  Copyright © 2019 christopher kha. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

// Remove the odd integers from v.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original vector.
void removeOdds(vector<int>& v){
    vector<int>::iterator it = v.begin();
    
    while(it != v.end()){
        if((*it)%2 == 1){
            vector<int>::iterator killMe = it;
            cout << "removing: " << (*killMe) << endl;
            v.erase(killMe);                                // when you erase values in vectors, the values
                                                            // after shift to the right
                                                            // you don't have to iterate "it" if you erase
        }else{
            cout << "not removing: " << (*it) << endl;
            it++;
        }
    }
}

void test()
{
    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
    vector<int> x(a, a+8);  // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = { 2, 4, 6, 8 };
    for (int k = 0; k < 4; k++)
        assert(x[k] == expect[k]);
}

int main()
{
    test();
    cout << "Passed" << endl;
}
