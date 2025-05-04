class LinearProbingHashTable:
    def __init__(self, size=100):
        self.size = size
        self.table = [-1] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        index = self.hash_function(key)
        original_index = index
        while self.table[index] != -1:
            index = (index + 1) % self.size
            if index == original_index:
                print("Hash table is full!")
                return
        self.table[index] = key
        print(f"Inserted {key} at index {index}")

    def search(self, key):
        index = self.hash_function(key)
        original_index = index
        while self.table[index] != -1:
            if self.table[index] == key:
                print(f"Element {key} found at index {index}")
                return index
            index = (index + 1) % self.size
            if index == original_index:
                break
        print(f"Element {key} not found")
        return -1

    def display(self):
        print("Hash Table:", self.table)


def linear_probing_menu():
    ht = LinearProbingHashTable()
    while True:
        print("\nLinear Probing Menu:")
        print("1. Insert a 10-digit integer")
        print("2. Search for a 10-digit integer")
        print("3. Display the hash table")
        print("4. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            key = int(input("Enter the 10-digit integer to insert: "))
            ht.insert(key)
        elif choice == 2:
            key = int(input("Enter the 10-digit integer to search: "))
            ht.search(key)
        elif choice == 3:
            ht.display()
        elif choice == 4:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")


class QuadraticProbingHashTable:
    def __init__(self, size=100):
        self.size = size
        self.table = [-1] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        index = self.hash_function(key)
        i = 1
        original_index = index
        while self.table[index] != -1:
            index = (original_index + i ** 2) % self.size
            if index == original_index:
                print("Hash table is full!")
                return
            i += 1
        self.table[index] = key
        print(f"Inserted {key} at index {index}")

    def search(self, key):
        index = self.hash_function(key)
        i = 1
        original_index = index
        while self.table[index] != -1:
            if self.table[index] == key:
                print(f"Element {key} found at index {index}")
                return index
            index = (original_index + i ** 2) % self.size
            if index == original_index:
                break
            i += 1
        print(f"Element {key} not found")
        return -1

    def display(self):
        print("Hash Table:", self.table)


def quadratic_probing_menu():
    ht = QuadraticProbingHashTable()
    while True:
        print("\nQuadratic Probing Menu:")
        print("1. Insert a 10-digit integer")
        print("2. Search for a 10-digit integer")
        print("3. Display the hash table")
        print("4. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            key = int(input("Enter the 10-digit integer to insert: "))
            ht.insert(key)
        elif choice == 2:
            key = int(input("Enter the 10-digit integer to search: "))
            ht.search(key)
        elif choice == 3:
            ht.display()
        elif choice == 4:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")







###
          1. Linear Probing
If a collision happens (index already filled), go to the next index (index + 1).

Keep going until an empty spot is found.

Searching also works the same way — go forward until you find the number or loop back.

🔹 2. Quadratic Probing
If a collision happens, instead of checking next index, it checks using a formula:

New Index
=
(
original index
+
𝑖
2
)
%
size
New Index=(original index+i 
2
 )%size
So it checks at gaps like: +1^2, +2^2, +3^2, etc.

This reduces clustering compared to linear probing.  


   PART 1: Linear Probing Hash Table
python
Copy
Edit
class LinearProbingHashTable:
➡️ This defines a class named LinearProbingHashTable.

python
Copy
Edit
    def __init__(self, size=100):
        self.size = size
        self.table = [-1] * size
➡️ The constructor (__init__) initializes a hash table with 100 slots, all set to -1 (meaning empty).

python
Copy
Edit
    def hash_function(self, key):
        return key % self.size
➡️ The hash function calculates index using key % size.

python
Copy
Edit
    def insert(self, key):
        index = self.hash_function(key)
        original_index = index
➡️ Calculates the index using hash function. original_index stores the first position.

python
Copy
Edit
        while self.table[index] != -1:
            index = (index + 1) % self.size
            if index == original_index:
                print("Hash table is full!")
                return
➡️ If the slot is already taken, it goes to the next index (Linear Probing).
➡️ If it comes back to the start, table is full.

python
Copy
Edit
        self.table[index] = key
        print(f"Inserted {key} at index {index}")
➡️ Once an empty index is found, insert the key.

python
Copy
Edit
    def search(self, key):
        index = self.hash_function(key)
        original_index = index
➡️ Begin search from hash index.

python
Copy
Edit
        while self.table[index] != -1:
            if self.table[index] == key:
                print(f"Element {key} found at index {index}")
                return index
            index = (index + 1) % self.size
            if index == original_index:
                break
➡️ Keep checking next positions until:

Key is found

Empty slot is hit

You return to the start (looped through table)

python
Copy
Edit
        print(f"Element {key} not found")
        return -1
➡️ If not found, print message and return -1.

python
Copy
Edit
    def display(self):
        print("Hash Table:", self.table)
➡️ Display the entire hash table.

python
Copy
Edit
def linear_probing_menu():
    ht = LinearProbingHashTable()
➡️ Create object of the class.

python
Copy
Edit
    while True:
        print("\nLinear Probing Menu:")
        print("1. Insert a 10-digit integer")
        print("2. Search for a 10-digit integer")
        print("3. Display the hash table")
        print("4. Exit")
➡️ Display menu for user interaction.

python
Copy
Edit
        choice = int(input("Enter your choice: "))
➡️ Take user’s choice.

python
Copy
Edit
        if choice == 1:
            key = int(input("Enter the 10-digit integer to insert: "))
            ht.insert(key)
        elif choice == 2:
            key = int(input("Enter the 10-digit integer to search: "))
            ht.search(key)
        elif choice == 3:
            ht.display()
        elif choice == 4:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")
➡️ Based on choice, perform:

Insert

Search

Display

Exit

✅ PART 2: Quadratic Probing Hash Table
python
Copy
Edit
class QuadraticProbingHashTable:
➡️ Define a new class for quadratic probing.

python
Copy
Edit
    def __init__(self, size=100):
        self.size = size
        self.table = [-1] * size
➡️ Create table with 100 slots initialized to -1.

python
Copy
Edit
    def hash_function(self, key):
        return key % self.size
➡️ Same hash function used as before.

python
Copy
Edit
    def insert(self, key):
        index = self.hash_function(key)
        i = 1
        original_index = index
➡️ Start probing with step size i = 1.

python
Copy
Edit
        while self.table[index] != -1:
            index = (original_index + i**2) % self.size
            if index == original_index:
                print("Hash table is full!")
                return
            i += 1
➡️ Instead of moving +1, we use +i² steps. This reduces clustering.

python
Copy
Edit
        self.table[index] = key
        print(f"Inserted {key} at index {index}")
➡️ Insert key at the empty spot.

python
Copy
Edit
    def search(self, key):
        index = self.hash_function(key)
        i = 1
        original_index = index
➡️ Start search with same formula.

python
Copy
Edit
        while self.table[index] != -1:
            if self.table[index] == key:
                print(f"Element {key} found at index {index}")
                return index
            index = (original_index + i**2) % self.size
            if index == original_index:
                break
            i += 1
➡️ Probe using +i² steps to search.

python
Copy
Edit
        print(f"Element {key} not found")
        return -1
➡️ If not found, return -1.

python
Copy
Edit
    def display(self):
        print("Hash Table:", self.table)
➡️ Display the hash table.

python
Copy
Edit
def quadratic_probing_menu():
    ht = QuadraticProbingHashTable()
➡️ Create object for quadratic probing.

python
Copy
Edit
    while True:
        print("\nQuadratic Probing Menu:")
        print("1. Insert a 10-digit integer")
        print("2. Search for a 10-digit integer")
        print("3. Display the hash table")
        print("4. Exit")
➡️ Show user menu.

python
Copy
Edit
        choice = int(input("Enter your choice: "))
        if choice == 1:
            key = int(input("Enter the 10-digit integer to insert: "))
            ht.insert(key)
        elif choice == 2:
            key = int(input("Enter the 10-digit integer to search: "))
            ht.search(key)
        elif choice == 3:
            ht.display()
        elif choice == 4:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")
➡️ Based on user's choice, call corresponding function.


          ###
          
