# arch1-Personal Management System-- Eulalio Garcia #


--To compile:

     $ make

--To test/run program:
   
   $ ./project

--To delete binaries:

   $ make clean


# Description #

This program main functionallity is to add, remove and read names from an external file text. After doing all this steps
the program should install the names into a Binary Search Tree.
--This program is intended to allow the user to add names into an employee list.
--The program will allow user to remove names from the external file by using the User Interface.
-- The program will allow the user to read names in the order they user inserts the names and also
   it will allow the user to read the names after they have being inserted into the BST in alphabetical order.


My approach of the Binary Search Tree was different because instead of inserting all the names directly into the BST,
I tried to implemented them directly into the file. After being stored in the file, the Binary search tree would insert
only if the user makes the command in the User Interface. For example, if the user wanted to delete the name from the BST he
would just delete the name directly from the external file with the remove name method instead of using a delete node method
that was not implemented in this program. The insert method is made with a bst struct and will insert every name in the BST after
being selected.



# References #
For the duration of this project I use and refer to several websites that help us understand how the user could add names into an
external file and on how to insert them into the BST. Also I would like to mentioned that I shared ideas not any code with my peer
Guillermo Ramirez on how there are different ways of making this system work appropiately.

