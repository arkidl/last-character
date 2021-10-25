# last-character
EXPLANATIONS
----

To solve this exercise, we will use CLA, command line arguments. In order to copy the content of one file to another file, we will need of course the input file, and we will create the new file with the name output, but we won’t also forget .txt in each of the names when we put them as parameters from the CMD. But before the names of the files, we call the name of the program, which in this case I have named as CopyContent. So in the CLA, we will put as input:

We will use the CLA even for our last exercise of the CEN 110 assignments <\3
We first see what we have to do. We will read words which will be separated by space or even a new line, then we will sort the last characters of each of the words in ascending order alphabetically, so from z to a. We will get as parameters in our main function, then, the number of arguments, and the arguments themselves, where the first one is the executable. Then we will have the names of the files of the input and of the output. In the CLA we will put:

LastChar input.txt output.txt

Since we know that there will be 3 parameters, we just check in the beginning of the program whether or not we have 3 inputs. If so, we continue with the program.
We will have some functions to use. One to read the data from the file and then store the last chars of the words in a string. Then we want to sort these chars the way we said in the beginning. Then we will have 2 functions, one to print to the user as an output, and another one to just write in the file the same output. For the printings then, we will just use the string with the characters.

Then we call the function to read the data with arguments which are the element in index 1 of argv, since it is the name of the input file. But we also put as a parameter the char array in which we will store the last chars of the words. readFromFile(argv[1],str);

In the function we will have a pointer of a file, we open the file with the name which was given as an argument and also check whether it is opened or not. Then we want to read the data. The way we will do it is by reading 2 chars one by one. One will be as the current char (c2) and the other one will always be the char before (ch1). Through a while loop which will continue until we have gone to the end of file, we read the char 2, then if it is the space char or the newline char, that means one word just ended, so we assign the value of c1 to the element in index i of the string which will store these chars. I was initialized with 0 and is increased each time a new char is stored in the array since we don’t care how long the words are. We just want the ending letter of each one. Then we just assign the value of c2 to c1 and then read the new char and store it in c2. After we get out of the loop, we know that there is one more word which we shouldn’t forget, the last word, so we also store the value of c1 to str[i] out of the while loop, increment i, and then make the ith element the end of the string, so then str[i]=’\0’; This is the end of this function.

Then, we want to sort the chars, so we will use 2 nested for loops, one to keep one char fixed and the other one to iterate through the following chars of the string, and if we find a char which is ‘bigger’ than the char in the minIndex(which has initially the index of the fixed char each time the outer loop is repeated and the fixed char is changed), we store this index in the minIndex, and after we get out of this inner loop, we swap the values of str[i] with str[minIndex] through a temp char.

for(int i=0; i<n-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(str[minIndex]<str[j])
                minIndex = j;
        }
        char temp = str[i];
        str[i]= str[minIndex];
        str[minIndex] = temp;
    }

Now we have the array sorted so we just printf the elements one by one with a space to the user, and for the other function, we open a file with the name that will be given as a parameter, and then print the elements from the array type char which is also given as a parameter. We check if the filename given points to nothing then if not, we create a pointer which will point to our file, we open the file in write mode since we will be writing the data now, and say:

outfile = fopen(filename, "w");
    int n = strlen(str);
    for(int i=0; i<n; i++)
    {
        fprintf(outfile, "%c ", str[i]);
    }

We see that we also print a space char each time we go to the other element of the array str, and after this is done, we printf("\nDone Successfully!\n"); and consider our last exercise of this semester for the course CEN 110 to be finished successfully. Until we meet again, we just return 0 to our main function.



