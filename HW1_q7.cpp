/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <list>
#include <deque>
#include <chrono>
using namespace std;
using chrono::system_clock;
using chrono::steady_clock;
using chrono::duration_cast;
using chrono::seconds;
using chrono::milliseconds;


/*
search
build
sort

*/


//test how fast vector builds the array
//and adds elements 
void BuildVector(vector<int> &vec, int size){

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % 100 + 1);
    }

}

//test how fast list is built
//and elements are added
void BuildList(list<int> &list1, int size){

    for (int i = 0; i < size; i++)
    {
        list1.push_back(rand() % 100 + 1);
    }
}

//test how fast deque builds the list
//and adds elements 
void BuildDeque(deque<int> &deq, int size){

    for (int i = 0; i < size; i++)
    {
        deq.push_front(rand() % 100 + 1);
    }
}

//test how fast vector searches an array
//for a particular element 
void SearchVector(vector<int> vec, int size){

    //random number to search 
    int x = rand() % 100 + 1;
   if (find(vec.begin(), vec.end(), x) != vec.end() )    
        cout << "Found element: " << x <<endl; 

}


//test how fast a list is searched
//for a particular element 
void SearchList(list<int> list1, int size){

    //random number to search 
    int x = rand() % 100 + 1;
   if (find(list1.begin(), list1.end(), x) != list1.end() )     
        cout << "Found element: " << x <<endl; 
}


//test how fast deque is searched 
//for a particular element 
void SearchDeque(deque<int> deq, int size){

    //random number to search 
    int x = rand() % 100 + 1;
   if (find(deq.begin(), deq.end(), x) != deq.end() )     
        cout << "Found element: " << x <<endl; 

}

//test how fast vector searches an array
//for a particular element 
void SortVector(vector<int> vec, int size){

    sort(vec.begin(), vec.end());

}


//test how fast a list is sorted
void SortList(list<int> list1, int size){

    list1.sort();
}


//test how fast deque is sorted 
void SortDeque(deque<int> deq, int size){

    sort(deq.begin(), deq.end());

}

//a timing function which takes a lambda function
//and times it's duarion
//a very convenient way to pass any function to be tested
//in the process
template <typename func>
long long TimeFunc(func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}

int main()
{


    int const size = 1000000;

	vector<int> v;
	v.push_back(0);

	list<int> l;
	l.push_back(0);

    deque<int> d;
    d.push_front(0);

    //Time how fast we can build
    //Vector, list, queue
    auto vectormilliseconds = TimeFunc([&]() {BuildVector(v, size); });
    auto listmilliseconds = TimeFunc([&]() {BuildList(l, size); });
    auto dequemilliseconds = TimeFunc([&]() {BuildDeque(d, size); });


    cout<<"Vector build time: " << vectormilliseconds << endl;
    cout<<"List build time: "<< listmilliseconds << endl;
    cout<<"Deque build time: "<< dequemilliseconds << endl;


    //Time how fast we can search
    //Vector, list, queue
    vectormilliseconds = TimeFunc([&]() {SearchVector(v, size); });
    listmilliseconds = TimeFunc([&]() {SearchList(l, size); });
    dequemilliseconds = TimeFunc([&]() {SearchDeque(d, size); });


    cout<<"Vector search time: " << vectormilliseconds << endl;
    cout<<"List search time: "<< listmilliseconds << endl;
    cout<<"Deque search time: "<< dequemilliseconds << endl;

    //Time how fast we can delete
    //Vector, list, queue
    vectormilliseconds = TimeFunc([&]() {SortVector(v, size); });
    listmilliseconds = TimeFunc([&]() {SortList(l, size); });
    dequemilliseconds = TimeFunc([&]() {SortDeque(d, size); });

    cout<<"Vector Sort time: " << vectormilliseconds << endl;
    cout<<"List Sort time: "<< listmilliseconds << endl;
    cout<<"Deque Sort time: "<< dequemilliseconds << endl;








}
