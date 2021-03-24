# HW1_Problem_7
By Y.S.

HW1__Problem_7
For this problem I’ve used Vector class, List class and Deque class from Standard Library to time operations for adding elements, searching for an element and 
sorting the elements. I used a templated timing function for timing each operation.
In my program I assumed List would take the longest to search and to sort since it is built like a chain of links and access to each element
would always require traversing element one by one, whereas in vector access times are much faster. I wasn’t sure about a deque but I 
assumed it would be faster than a List since Deque could’ve been implemented as an array. 
When I ran the program List was indeed slowest for every operation that I have performed. The size of all my ADT’s was a million variables
so the differences in speed where apparent. 
Among noticeable differences was that sorting a vector class was the fastest, followed by deque and then List, which was much slower
than vector and deque. It made sense since sorting a linked list would require a lot of time to find and move nodes in the list, while
in vector class the operation for swapping elements would be much faster.
