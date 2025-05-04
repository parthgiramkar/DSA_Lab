# Define the class SetADT to represent a Set using a list
class SetADT:
    # Constructor to initialize an empty list as the internal set
    def __init__(self):
        self._set = []

    # Method to add an element if it does not already exist
    def add(self, element):
        """Add a new element to the set if it doesn't already exist."""
        if element not in self._set:       # Check for duplicates
            self._set.append(element)      # Append only if new

    # Method to remove an element from the set
    def remove(self, element):
        """Remove an element from the set if it exists."""
        if element in self._set:           # Check if element exists
            self._set.remove(element)      # Remove it
        else:
            print(f"Element {element} not found in the set.")  # Error message

    # Method to check if the set contains a given element
    def contains(self, element):
        """Check if the set contains the element."""
        return element in self._set        # Returns True/False

    # Method to return the number of elements in the set
    def size(self):
        """Return the number of elements in the set."""
        return len(self._set)              # Count of elements

    # Method to get an iterator to loop over the set
    def iterator(self):
        """Return an iterator for the set."""
        return iter(self._set)             # Return iterator object

    # Method to find intersection of this set with another set
    def intersection(self, other_set):
        """Return the intersection of two sets."""
        return [elem for elem in self._set if elem in other_set._set]

    # Method to find union of this set with another set
    def union(self, other_set):
        """Return the union of two sets."""
        union_set = self._set.copy()           # Copy current set
        for elem in other_set._set:            # Traverse second set
            if elem not in union_set:
                union_set.append(elem)         # Add only if not present
        return union_set

    # Method to find elements in this set not in the other set
    def difference(self, other_set):
        """Return the difference between two sets (elements in this set but not in the other)."""
        return [elem for elem in self._set if elem not in other_set._set]

    # Method to check if this set is a subset of the other set
    def is_subset(self, other_set):
        """Check if this set is a subset of another set."""
        return all(elem in other_set._set for elem in self._set)

# Menu-driven interface starts here
def main():
    set1 = SetADT()     # Create object for Set 1
    set2 = SetADT()     # Create object for Set 2

    # Infinite loop for menu options
    while True:
        print("\nMenu:")
        print("1. Add element to Set 1")
        print("2. Add element to Set 2")
        print("3. Remove element from Set 1")
        print("4. Remove element from Set 2")
        print("5. Check if an element exists in Set 1")
        print("6. Check if an element exists in Set 2")
        print("7. Get size of Set 1")
        print("8. Get size of Set 2")
        print("9. Intersection of Set 1 and Set 2")
        print("10. Union of Set 1 and Set 2")
        print("11. Difference (Set 1 - Set 2)")
        print("12. Check if Set 1 is a subset of Set 2")
        print("13. Display Set 1")
        print("14. Display Set 2")
        print("15. Exit")

        # Take user choice
        choice = input("Enter your choice: ")

        # Handle user choice
        if choice == '1':
            element = input("Enter element to add to Set 1: ")
            set1.add(element)
            print(f"Added {element} to Set 1.")

        elif choice == '2':
            element = input("Enter element to add to Set 2: ")
            set2.add(element)
            print(f"Added {element} to Set 2.")

        elif choice == '3':
            element = input("Enter element to remove from Set 1: ")
            set1.remove(element)

        elif choice == '4':
            element = input("Enter element to remove from Set 2: ")
            set2.remove(element)

        elif choice == '5':
            element = input("Enter element to check in Set 1: ")
            if set1.contains(element):
                print(f"Set 1 contains {element}.")
            else:
                print(f"Set 1 does not contain {element}.")

        elif choice == '6':
            element = input("Enter element to check in Set 2: ")
            if set2.contains(element):
                print(f"Set 2 contains {element}.")
            else:
                print(f"Set 2 does not contain {element}.")

        elif choice == '7':
            print(f"Size of Set 1: {set1.size()}")

        elif choice == '8':
            print(f"Size of Set 2: {set2.size()}")

        elif choice == '9':
            print("Intersection of Set 1 and Set 2:", set1.intersection(set2))

        elif choice == '10':
            print("Union of Set 1 and Set 2:", set1.union(set2))

        elif choice == '11':
            print("Difference (Set 1 - Set 2):", set1.difference(set2))

        elif choice == '12':
            if set1.is_subset(set2):
                print("Set 1 is a subset of Set 2.")
            else:
                print("Set 1 is not a subset of Set 2.")

        elif choice == '13':
            print("Set 1:", set1._set)

        elif choice == '14':
            print("Set 2:", set2._set)

        elif choice == '15':
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please try again.")

# Check if the file is being run directly
if __name__ == "__main__":
    main()













### 
SetADT Class Definition
python
Copy
Edit
# Define the class SetADT to represent a Set using a list
class SetADT:
This line defines a class named SetADT which will simulate the behavior of a set using a Python list internally.

python
Copy
Edit
    # Constructor to initialize an empty list as the internal set
    def __init__(self):
        self._set = []
__init__ is a constructor method.

self._set creates an empty list to store set elements.

The underscore _set indicates it's meant for internal use.

python
Copy
Edit
    # Method to add an element if it does not already exist
    def add(self, element):
        """Add a new element to the set if it doesn't already exist."""
        if element not in self._set:
            self._set.append(element)
Adds an element to the set only if it doesn't already exist (to avoid duplicates).

python
Copy
Edit
    # Method to remove an element from the set
    def remove(self, element):
        """Remove an element from the set if it exists."""
        if element in self._set:
            self._set.remove(element)
        else:
            print(f"Element {element} not found in the set.")
Removes an element if present; else prints a message saying it's not found.

python
Copy
Edit
    # Method to check if the set contains a given element
    def contains(self, element):
        """Check if the set contains the element."""
        return element in self._set
Returns True if element is in the set, otherwise False.

python
Copy
Edit
    # Method to return the number of elements in the set
    def size(self):
        """Return the number of elements in the set."""
        return len(self._set)
Returns the number of elements in the set using len().

python
Copy
Edit
    # Method to get an iterator to loop over the set
    def iterator(self):
        """Return an iterator for the set."""
        return iter(self._set)
Returns an iterator object that can be used in a for loop.

python
Copy
Edit
    # Method to find intersection of this set with another set
    def intersection(self, other_set):
        """Return the intersection of two sets."""
        return [elem for elem in self._set if elem in other_set._set]
Returns a new list of elements that exist in both sets.

python
Copy
Edit
    # Method to find union of this set with another set
    def union(self, other_set):
        """Return the union of two sets."""
        union_set = self._set.copy()
        for elem in other_set._set:
            if elem not in union_set:
                union_set.append(elem)
        return union_set
Returns a new list with all unique elements from both sets.

python
Copy
Edit
    # Method to find elements in this set not in the other set
    def difference(self, other_set):
        """Return the difference between two sets (elements in this set but not in the other)."""
        return [elem for elem in self._set if elem not in other_set._set]
Returns elements that are in this set but not in the other.

python
Copy
Edit
    # Method to check if this set is a subset of the other set
    def is_subset(self, other_set):
        """Check if this set is a subset of another set."""
        return all(elem in other_set._set for elem in self._set)
Checks if every element of this set exists in the other set. Returns True or False.

🔹 Menu-Driven Interface Starts
python
Copy
Edit
def main():
    set1 = SetADT()
    set2 = SetADT()
Creates two objects set1 and set2 using the SetADT class.

python
Copy
Edit
    # Infinite loop for menu options
    while True:
Begins an infinite loop to show menu repeatedly until user chooses to exit.

python
Copy
Edit
        print("\nMenu:")
        print("1. Add element to Set 1")
        ...
        print("15. Exit")
Displays the list of menu options for the user.

python
Copy
Edit
        # Take user choice
        choice = input("Enter your choice: ")
Accepts input from the user (as a string) to choose an option.

python
Copy
Edit
        # Handle user choice
        if choice == '1':
            element = input("Enter element to add to Set 1: ")
            set1.add(element)
            print(f"Added {element} to Set 1.")
If user enters 1, takes an element as input and adds it to Set 1 using add().

python
Copy
Edit
        elif choice == '2':
            ...
Each elif handles the other options in the same way:

Add/remove elements

Check existence

Get size

Perform union/intersection/difference

Check subset

Display sets

python
Copy
Edit
        elif choice == '15':
            print("Exiting program.")
            break
If user selects option 15, the loop is broken and the program ends.

python
Copy
Edit
        else:
            print("Invalid choice. Please try again.")
If user enters any invalid option, it displays an error message.

🔹 This code runs only if it's the main program file
python
Copy
Edit
# Check if the file is being run directly
if __name__ == "__main__":
    main()
Ensures the main() function runs only when this file is executed directly and not  
### 
