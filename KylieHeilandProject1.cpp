/* This program requires the student to write 3 functions described in
 * Program project 4 (Page 535) and Program Project 6 (Page 536).
 * The student also need to add a print function to print out an array.
 * The student may watch video notes on MyProgrammingLab to get the idea
 * on how to write the main function and three of these four functions
 *
 * Author: Kylie Heiland
 * Version: 1-28-2022
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void sentenceReverse();
// Precondition: User inputs a sentence that is put into a C-string. Uses the reverse() function to swap
//               the letters in the sentence.
// Post-condition: The sentence is reversed in that what would have been the first letter is now the last
//                one.

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Post-condition: The C-string is reversed

void makeList();
// Precondition: User chooses to create a list. It is then edited using functions addEntry and deleteEntry.
// Post-condition: An array that has 11 list entries is created and filled.

string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to an array of strings with give size,
//               newEntry is a string
// Post-condition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to an array of strings with give size,
//               newEntry is a string
// Post-condition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to an array of strings with give size,
// Post-condition: The elements in dynamic array will be print out. One
//                element per line followed by its index

void menu();
// Post-condition: The menu is presented to the user to choose from.

typedef string* arrayPointer;


int main() {
    int choice;

    cout << "Welcome to Kylie Heiland's program!\n";

    do
    {
        menu(); // calls the menu item to ask what the user would like to choose to do.
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                sentenceReverse(); // User inputs a sentence/string, it then uses reverse function to reverse the string.
                break;
            }
            case 2: {
                makeList(); // User creates a list of 10 states, adds two, removes one, leaving a list of 11 states to be outputted.
                break;
            }
            case 3: {
                cout << "Thanks for using my program! Have a great day!\n";
                break;
            }
            default: {
                cout << "Wrong choice. Please choose from menu: ";
                break;
            }
        }

    }while(choice != 3);
    return 0;
}

void sentenceReverse(){
    char sentence[100];
    char *rear, *front;

    string sentence2;
    cout << "Welcome to the program!\n" << "Please enter a sentence that you would like to be reversed: ";
    cin.ignore();
    cin.getline(sentence, 100);
    cout << "You entered: " << sentence << endl;

    front = &sentence[0];
    cout << "The front is: " << *front << endl;

    rear = &sentence[strlen(sentence) - 1];
    cout << "The rear is: " << *rear << endl;

    reverse(front, rear);

    cout << "The sentence is now: " << sentence << endl;

}

void reverse(char* front, char* rear){
    while(rear >= front && front <= rear){
        if(*front != *rear) {
            char temp;
            temp = *front;
            *front = *rear;
            *rear = temp;
        }
        front++;
        rear--;
    }

}

void makeList(){
    int size = 10;
    arrayPointer states;
    states = new string[size];
    string newEntry, removeEntry;


    cout << "Now that you have reversed a sentence, let's do something different...!\n" << "Let's create a list of "
    << "U.S. states.\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered "
        << i << " out of 10 states so far: ";
        cin >> states[i];
        cout << "You entered: " << states[i] << endl;
    }

    cout << "Good job! Your list of 10 states is: " << endl;

    print(states, size);

    /* ADDS TWO ENTRIES TO LIST */
    cout << "Now enter two more states (only spell states that have one word): ";
    cin >> newEntry;

    states = addEntry(states, size, newEntry);

    cout << "You entered: " << newEntry << ".\n Now enter another state: ";
    cin >> newEntry;

    states = addEntry(states, size, newEntry);

    print(states, size);

    cout << "Great! Now, this list is a little too long to my liking. Let's make this have 11 entries!" << endl
         << "Choose an entry you would like to delete (Keep is mind, this program is case-sensitive): ";

    cin >> removeEntry;

    /* REMOVES TWO ENTRIES FROM LIST */

    cout << "You chose to delete: " << removeEntry << ".\n" << "Good, that state was kind of bad..!" << endl << "Your list "
    << "is now: \n";

    states = deleteEntry(states, size, removeEntry);

    print(states, size);
}

void print(const string* dynamicArray, int size){
  for(int i = 0; i < size; i++)
  {
       cout << "The " << i + 1 << " element of the dynamic array is: " << dynamicArray[i]
       << ". It is located at index " << i << "." << endl;
   }
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    arrayPointer newArray;
    newArray = new string[size - 1];
    int j = 0, indexFound = -1; // j used to keep track of what index newArray is at,
                                // indexFound determines if the entry is in the array or not.

    // Loops through the dynamicArray's contents. It is "size - 1" because I wanted i to start as index 0 rather than 1.
    // If I had not subtracted size by 1, the for loop would have not gone through the final entity.
    // The <= is used to ensure that the for loop goes through all contents, but does not loop past the contents of the
    // array.
    for (int i = 0; i <= size - 1; i++) {

            // If the entry we are wanting to delete is in this index of dynamicArray,
            // we skip over it and do not add it to newArray.
            if (dynamicArray[i] == entryToDelete)
            {
                indexFound = 0;
                continue;
            }
            // If the entry is not in this particular place in the array, this is executed.
            else if (dynamicArray[i] != entryToDelete)
            {
                // If it is the final entity in the array, the newArray copies it over from dynamicArray.
                if((size - 1) == i)
                {
                    // if the entry has been found in the array, and we've reached the end, the newArray will be returned.
                    if(indexFound == 0)
                    {
                        newArray[j] = dynamicArray[i];
                    }
                    else
                    {
                        // If the entry has NOT been found in the array, the original array is returned.
                        return dynamicArray;
                    }
                }
                // If it is NOT the final entity in the array, the newArray copies the dynamicArray's content, then the
                // newArray's index is incremented, so that another item can be added in the next loop.
                else
                {
                    newArray[j] = dynamicArray[i];
                    j++;
                }

            }

    }
    size--;
    delete[] dynamicArray;
    return newArray;
}

string* addEntry(string* dynamicArray, int& size, string newEntry){
    // A new dynamic array is created, and is one larger than the original dynamic array.
    arrayPointer newArray;
    newArray = new string[size+1];

    // Sets the i in the for loop to be less than or equal to size. This is to allocate an extra loop to add the
    // new entry for newArray.
    for(int i = 0; i <= size; i++)
    {
        // As long as the index is not at the equal to size (as this is where we will add newEntry), all contents from
        // dynamicArray are copied into newArray.
        if (i != size)
        {
            newArray[i] = dynamicArray[i];
        }
        // Once all the contents are copied over from dynamicArray to newArray, the newEntry is added, then the
        // loop ends.
        else
        {
            newArray[i] = newEntry;
        }
    }
    size++;
    delete[] dynamicArray;
    return newArray;
}

void menu()
{
    int i;
    for(i = 0; i < 40; i++) { // so I did not have to type out 40 individual asterisks!
        cout << '*';
    }
    cout << endl << '*' << " Menu " << '*' << endl
         << '*' << " 1. Reverse a sentence of your choosing " << '*' << endl
         << '*' << " 2. Create a list of states, and then add/remove entries. " << '*' << endl
         << '*' << " 3. Quit " << '*' << endl;
    for(i = 0; i < 40; i++) { // so I did not have to type out 40 individual asterisks!
        cout << '*';
    }
    cout << endl;
}

/* OUTPUT
Welcome to the program!
Please enter a sentence that you would like to be reversed:Going outside is fun, but video games...!
 You entered: Going outside is fun, but video games...!
The front is: G
The rear is: !
The sentence is now: !...semag oediv tub ,nuf si edistuo gnioG


****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:1
 Welcome to the program!
Please enter a sentence that you would like to be reversed:"Feels like I just might've broken the best thing that I had."
 You entered: "Feels like I just might've broken the best thi
ng that I had."
The front is: "
The rear is: "
The sentence is now: ".dah I taht gniht tseb eht nekorb ev'thgim tsuj I ekil sleeF"


****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:1
 Welcome to the program!
Please enter a sentence that you would like to be reversed:Hey there!
 You entered: Hey there!
The front is: H
The rear is: !
The sentence is now: !ereht yeH


 ****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:2
 Now that you have reversed a sentence, let's do something different...!
Let's create a list of U.S. states.
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 0 out of 10 states so
far:Utah
 You entered: Utah
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 1 out of 10 states so
far:Nevada
 You entered: Nevada
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 2 out of 10 states so
far:Nebraska
 You entered: Nebraska
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 3 out of 10 states so
far:Iowa
 You entered: Iowa
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 4 out of 10 states so
far:Ohio
 You entered: Ohio
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 5 out of 10 states so
far:Kansas
 You entered: Kansas
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 6 out of 10 states so
far:Kentucky
 You entered: Kentucky
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 7 out of 10 states so
far:Massachusetts
 You entered: Massachusetts
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 8 out of 10 states so
far:Texas
 You entered: Texas
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 9 out of 10 states so
far:Oregon
 You entered: Oregon
Good job! Your list of 10 states is:
The 1 element of the dynamic array is: Utah. It is located at index 0.
The 2 element of the dynamic array is: Nevada. It is located at index 1.
The 3 element of the dynamic array is: Nebraska. It is located at index 2.
The 4 element of the dynamic array is: Iowa. It is located at index 3.
The 5 element of the dynamic array is: Ohio. It is located at index 4.
The 6 element of the dynamic array is: Kansas. It is located at index 5.
The 7 element of the dynamic array is: Kentucky. It is located at index 6.
The 8 element of the dynamic array is: Massachusetts. It is located at index 7.
The 9 element of the dynamic array is: Texas. It is located at index 8.
The 10 element of the dynamic array is: Oregon. It is located at index 9.
Now enter two more states (only spell states that have one word):Louisiana
 You entered: Louisiana.
 Now enter another state:Washington
 The 1 element of the dynamic array is: Utah. It is located at index 0.
The 2 element of the dynamic array is: Nevada. It is located at index 1.
The 3 element of the dynamic array is: Nebraska. It is located at index 2.
The 4 element of the dynamic array is: Iowa. It is located at index 3.
The 5 element of the dynamic array is: Ohio. It is located at index 4.
The 6 element of the dynamic array is: Kansas. It is located at index 5.
The 7 element of the dynamic array is: Kentucky. It is located at index 6.
The 8 element of the dynamic array is: Massachusetts. It is located at index 7.
The 9 element of the dynamic array is: Texas. It is located at index 8.
The 10 element of the dynamic array is: Oregon. It is located at index 9.
The 11 element of the dynamic array is: Louisiana. It is located at index 10.
The 12 element of the dynamic array is: Washington. It is located at index 11.
Great! Now, this list is a little too long to my liking. Let's make this have 11 entries!
Choose an entry you would like to delete (Keep is mind, this program is case sensitive):Utah
 You chose to delete: Utah.
 Good, that state was kind of bad..!
Your list is now:
The 1 element of the dynamic array is: Nevada. It is located at index 0.
The 2 element of the dynamic array is: Nebraska. It is located at index 1.
The 3 element of the dynamic array is: Iowa. It is located at index 2.
The 4 element of the dynamic array is: Ohio. It is located at index 3.
The 5 element of the dynamic array is: Kansas. It is located at index 4.
The 6 element of the dynamic array is: Kentucky. It is located at index 5.
The 7 element of the dynamic array is: Massachusetts. It is located at index 6.
The 8 element of the dynamic array is: Texas. It is located at index 7.
The 9 element of the dynamic array is: Oregon. It is located at index 8.
The 10 element of the dynamic array is: Louisiana. It is located at index 9.
The 11 element of the dynamic array is: Washington. It is located at index 10.

 ****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:2
 Now that you have reversed a sentence, let's do something different...!
Let's create a list of U.S. states.
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 0 out of 10 states so
far:AL
 You entered: AL
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 1 out of 10 states so
far:AK
 You entered: AK
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 2 out of 10 states so
far:AZ
 You entered: AZ
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 3 out of 10 states so
far:AR
 You entered: AR
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 4 out of 10 states so
far:CA
 You entered: CA
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 5 out of 10 states so
far:CO
 You entered: CO
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 6 out of 10 states so
far:GA
 You entered: GA
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 7 out of 10 states so
far:NJ
 You entered: NJ
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 8 out of 10 states so
far:OH
 You entered: OH
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 9 out of 10 states so
far:UT
 You entered: UT
Good job! Your list of 10 states is:
The 1 element of the dynamic array is: AL. It is located at index 0.
The 2 element of the dynamic array is: AK. It is located at index 1.
The 3 element of the dynamic array is: AZ. It is located at index 2.
The 4 element of the dynamic array is: AR. It is located at index 3.
The 5 element of the dynamic array is: CA. It is located at index 4.
The 6 element of the dynamic array is: CO. It is located at index 5.
The 7 element of the dynamic array is: GA. It is located at index 6.
The 8 element of the dynamic array is: NJ. It is located at index 7.
The 9 element of the dynamic array is: OH. It is located at index 8.
The 10 element of the dynamic array is: UT. It is located at index 9.
Now enter two more states (only spell states that have one word):TN
 You entered: TN.
 Now enter another state:SD
 The 1 element of the dynamic array is: AL. It is located at index 0.
The 2 element of the dynamic array is: AK. It is located at index 1.
The 3 element of the dynamic array is: AZ. It is located at index 2.
The 4 element of the dynamic array is: AR. It is located at index 3.
The 5 element of the dynamic array is: CA. It is located at index 4.
The 6 element of the dynamic array is: CO. It is located at index 5.
The 7 element of the dynamic array is: GA. It is located at index 6.
The 8 element of the dynamic array is: NJ. It is located at index 7.
The 9 element of the dynamic array is: OH. It is located at index 8.
The 10 element of the dynamic array is: UT. It is located at index 9.
The 11 element of the dynamic array is: TN. It is located at index 10.
The 12 element of the dynamic array is: SD. It is located at index 11.
Great! Now, this list is a little too long to my liking. Let's make this have 11 entries!
Choose an entry you would like to delete (Keep is mind, this program is case-sensitive):SD
 You chose to delete: SD.
Good, that state was kind of bad..!
Your list is now:
The 1 element of the dynamic array is: AL. It is located at index 0.
The 2 element of the dynamic array is: AK. It is located at index 1.
The 3 element of the dynamic array is: AZ. It is located at index 2.
The 4 element of the dynamic array is: AR. It is located at index 3.
The 5 element of the dynamic array is: CA. It is located at index 4.
The 6 element of the dynamic array is: CO. It is located at index 5.
The 7 element of the dynamic array is: GA. It is located at index 6.
The 8 element of the dynamic array is: NJ. It is located at index 7.
The 9 element of the dynamic array is: OH. It is located at index 8.
The 10 element of the dynamic array is: UT. It is located at index 9.
The 11 element of the dynamic array is: TN. It is located at index 10.

****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:2
 Now that you have reversed a sentence, let's do something different...!
Let's create a list of U.S. states.
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 0 out of 10 states so
far:Nebraska
 You entered: Nebraska
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 1 out of 10 states so
far:Missouri
 You entered: Missouri
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 2 out of 10 states so
far:Nevada
 You entered: Nevada
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 3 out of 10 states so
far:NH
 You entered: NH
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 4 out of 10 states so
far:NY
 You entered: NY
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 5 out of 10 states so
far:Washington
 You entered: Washington
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 6 out of 10 states so
far:Wyoming
 You entered: Wyoming
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 7 out of 10 states so
far:Nebraska
 You entered: Nebraska
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 8 out of 10 states so
far:Kansas
 You entered: Kansas
Enter a state that is spelt with one word (Note: the program is case-sensitive). You have entered 9 out of 10 states so
far:Oklahoma
 You entered: Oklahoma
Good job! Your list of 10 states is:
The 1 element of the dynamic array is: Nebraska. It is located at index 0.
The 2 element of the dynamic array is: Missouri. It is located at index 1.
The 3 element of the dynamic array is: Nevada. It is located at index 2.
The 4 element of the dynamic array is: NH. It is located at index 3.
The 5 element of the dynamic array is: NY. It is located at index 4.
The 6 element of the dynamic array is: Washington. It is located at index 5.
The 7 element of the dynamic array is: Wyoming. It is located at index 6.
The 8 element of the dynamic array is: Nebraska. It is located at index 7.
The 9 element of the dynamic array is: Kansas. It is located at index 8.
The 10 element of the dynamic array is: Oklahoma. It is located at index 9.
Now enter two more states (only spell states that have one word):Texas
 You entered: Texas.
 Now enter another state:Tennessee
 The 1 element of the dynamic array is: Nebraska. It is located at index 0.
The 2 element of the dynamic array is: Missouri. It is located at index 1.
The 3 element of the dynamic array is: Nevada. It is located at index 2.
The 4 element of the dynamic array is: NH. It is located at index 3.
The 5 element of the dynamic array is: NY. It is located at index 4.
The 6 element of the dynamic array is: Washington. It is located at index 5.
The 7 element of the dynamic array is: Wyoming. It is located at index 6.
The 8 element of the dynamic array is: Nebraska. It is located at index 7.
The 9 element of the dynamic array is: Kansas. It is located at index 8.
The 10 element of the dynamic array is: Oklahoma. It is located at index 9.
The 11 element of the dynamic array is: Texas. It is located at index 10.
The 12 element of the dynamic array is: Tennessee. It is located at index 11.
Great! Now, this list is a little too long to my liking. Let's make this have 11 entries!
Choose an entry you would like to delete (Keep is mind, this program is case sensitive):Boston
 You chose to delete: Boston.
Good, that state was kind of bad..!
Your list is now:
The 1 element of the dynamic array is: Nebraska. It is located at index 0.
The 2 element of the dynamic array is: Missouri. It is located at index 1.
The 3 element of the dynamic array is: Nevada. It is located at index 2.
The 4 element of the dynamic array is: NH. It is located at index 3.
The 5 element of the dynamic array is: NY. It is located at index 4.
The 6 element of the dynamic array is: Washington. It is located at index 5.
The 7 element of the dynamic array is: Wyoming. It is located at index 6.
The 8 element of the dynamic array is: Nebraska. It is located at index 7.
The 9 element of the dynamic array is: Kansas. It is located at index 8.
The 10 element of the dynamic array is: Oklahoma. It is located at index 9.
The 11 element of the dynamic array is: Texas. It is located at index 10.
The 12 element of the dynamic array is: Tennessee. It is located at index 11.

 ****************************************
* Menu *
* 1. Reverse a sentence of your choosing *
* 2. Create a list of states, and then add/remove entries. *
* 3. Quit *
****************************************
Enter your choice:3
 Thanks for using my program! Have a great day!
*/