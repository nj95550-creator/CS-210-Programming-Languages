# CS 210 Programming Languages

## Corner Grocer Project

### Project Summary

The Corner Grocer project is a C++ console application that analyzes a grocery store’s daily purchase records. It reads each item from an input file, counts how many times the item was purchased, and stores those results in a map. The user can search for one item, display a complete list of item frequencies, or view the results as a histogram. The program also creates `frequency.dat` as a backup of the calculated totals.

### What I Did Well

I organized the program around a `GroceryTracker` class so the purchase data and related functions remain together. Each function has one clear responsibility, such as loading purchases, saving the backup, searching for an item, or displaying a report. I also used a map because it efficiently connects each item name with its purchase count while keeping the output alphabetized. The program checks for file errors and handles invalid menu input without crashing.

### Opportunities for Improvement

I could improve the search by making it case-insensitive so entries such as `Apples` and `apples` are treated as the same item. I could also separate the `GroceryTracker` class into header and implementation files and add automated tests for its individual functions. These changes would make the program easier to expand, test, and maintain while reducing the chance of incorrect search results.

### Challenges and Resources

The most challenging part was making sure the search, complete frequency list, histogram, and backup file all used the same accurate set of purchase counts. Input validation also required careful handling so an invalid entry would not stop the program. I worked through these challenges by dividing the program into smaller functions and testing every menu option with valid and invalid input. Visual Studio’s compiler messages and debugger, course materials, C++ documentation, and GitHub are useful resources that I can continue using for future projects.

### Transferable Skills

This project strengthened my understanding of classes, maps, file input and output, loops, functions, input validation, and error handling. It also gave me more experience breaking a larger problem into smaller parts and testing each part separately. These skills will transfer directly to future coursework and software projects that need to process data or provide a menu-driven interface.

### Maintainability and Adaptability

I used descriptive names, focused functions, professional comments, private class data, and constants for file information to keep the code readable and organized. Because each major task is separated into its own function, changes can be made without rewriting the entire program. Additional reports, new input sources, or different output formats could be added to the class later without changing the program’s basic structure.
