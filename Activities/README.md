📦 Data Structure Design

Each entry in the virtual heap has two fields:

Field	Description
elem	Stores the airport code (e.g., "JFK")
next	Stores the index of the next node if a collision occurs (-1 if none)

There are two tables:

Hash Table (size 10): Stores indexes of elements based on hash results.

Virtual Heap (array): Stores all the elements with elem and next values.

🔁 Insertion Logic (Progressive Overflow)

Compute the hash index of the airport code.

If the hash table slot is empty → insert it directly.

If the slot is occupied →

Find the next available slot in the virtual heap.

Link the existing element’s next field to that new index.

Insert the new code there.

This technique is known as Progressive Overflow, where collisions are handled by chaining to the next available node in the virtual heap.

💾 Sample Input
Set A = {"JFK", "LAX", "SFO", "CDG", "LHR",
          "NRT", "ATL", "DXB", "PEK", "MIA",
          "SYD", "ORD"}

🧠 Program Output

At the end of execution, the program shows:

Hash index of each airport code.

Final virtual heap state, showing:

Each element (elem)

Its next index (next)

Available pointer (Avail)

Example (illustrative only):

Index | Elem | Next
-------------------
0     | JFK  | -1
1     | LAX  | 12
...
Avail = 17

⚙️ How to Compile and Run
1. Save the code

Save your main file as closed_hashing.c.

2. Compile it
gcc closed_hashing.c -o closed_hashing

3. Run it
./closed_hashing

🧾 Notes for Understanding

Closed Hashing means all data stays inside a fixed-size table (no external linked lists).

Progressive Overflow ensures that even if two codes share the same hash, both are stored using a link chain.

The Cursor-Based approach is used instead of dynamic memory allocation, meaning the program simulates pointers using array indexes.

The Avail pointer acts like a free list pointer that tracks which slot in the heap is available next.

🧩 Key Concepts
Concept	Explanation
Hashing	Converts a key (airport code) into a number used as an index
Collision	When two keys hash to the same index
Overflow Area	Extra space in the virtual heap for resolving collisions
Cursor Implementation	Using array indexes instead of memory addresses to represent links