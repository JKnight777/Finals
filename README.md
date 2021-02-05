# Finals
Finals from El Co classes
Made by Justice Pankey-Thompson
    ID: 2529360
    ALGORITHM: 
    A) Upon starting the program, the computer starts by creating the Struct Student. In the main, the program creates a new student called NewStudent, an ifstream called inFS, and a string called filename, which is then inputted and used to open the file named after it.
    B) The main then uses the function openFile to check if the file is valid and open. If it isn't, then it will error and stop the program. If it passes, then the main checks to see if the file is blank by peeking to see if it returns the EOF off the bat. If the file is not empty, it then calls Read_info with the student as it's parameters.
    C) The Read_info function works by reading through the file, and assigning the values inside to variables in the student. Since we didn't know what the number of courses taken would be when we made the student, I instead made it so that Read_info has it's own unique vectors that have the same length as the 
    file demands, while the student's original vectors remain null. Then after using a for loop to read and write all info to the Read_info vectors, it then copies the vectors from Read_info to the ones in Student making them the same now. After closing the file, it then returns to the main.
    D) Back in the main, the program checks to see if the student name was changed at all, for if it wasn't, then that means that the file must be bad. After checking that, the program then calls the GPA calculator function.
    E) The GPA_Calculator function uses for loops and vectors to calculate how many credits were earned by the student, how many were there to earn, and the GPA of the student. After writing these to the student struct, it returns to the main.
    F) Lastly, before returning 0, the program calls Print_info_one which uses all the info written in Student to make a neat table with coluumns and rows that output the way Zybooks's output example wanted. After outputting the information, the program returns to the main one last time. 
    G) After all is said and done, the program returns 0, which ends the program all together.
