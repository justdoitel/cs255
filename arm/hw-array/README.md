# Array in ARM   

This code is written in ARM Assembly language. Starting at the i<sup>th</sup> index, we sum the values of arr up until (but not including) the len<sup>th</sup> index. Because we are using sum to store this sum, if sum originally has value, that value would be summed with the other values. At the end, the result gets stored in sum.     

In this instance, the sum would be 49 since -4+9+12+15+11+5+1 = 49. -4 is the original value of sum. since i is 2, we start with the second index (which is 9) and we sum it up until the 8th index (which is 1). The answer, which is 49, is then stored in sum