#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 17      // total cells (primary + overflow)
#define PRIMARY_SIZE 10    // indices 0..9 are primary
#define OVERFLOW_START PRIMARY_SIZE // 10
#define CODE_LEN 4         // 3 letters + null

/* Data arrays: elem holds airport codes (3-letter strings),
   next holds the "cursor" (index) to the next element in the chain,
   avail is head of free-list of overflow cells. */
char elem[TABLE_SIZE][CODE_LEN];
int next_idx[TABLE_SIZE];
int avail;

/* Hash function as given:
   hash(code) = ((c0-'A')*26*26 + (c1-'A')*26 + (c2-'A')) % 10
*/
int hash_code(const char *code) {
    int a = code[0] - 'A';
    int b = code[1] - 'A';
    int c = code[2] - 'A';
    int val = (a * 26 * 26 + b * 26 + c) % PRIMARY_SIZE;
    return val;
}

/* Initialize table:
   - clear strings (empty = element not used)
   - set next pointers to -1
   - build free list for overflow cells: 10 -> 11 -> ... -> 16 -> -1
*/
void init_table() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        elem[i][0] = '\0';
        next_idx[i] = -1;
    }
    // create free list for overflow area
    for (int i = OVERFLOW_START; i < TABLE_SIZE - 1; ++i) {
        next_idx[i] = i + 1;
    }
    next_idx[TABLE_SIZE - 1] = -1;
    avail = OVERFLOW_START;
}

/* Allocate one overflow node from free list; return -1 if no free node. */
int alloc_node() {
    if (avail == -1) return -1;        // overflow full
    int p = avail;
    avail = next_idx[avail];           // pop head of free list
    next_idx[p] = -1;                  // will be used as chain node
    return p;
}

/* Free an overflow node (push it back to free list). */
void free_node(int idx) {
    elem[idx][0] = '\0';
    next_idx[idx] = avail;
    avail = idx;
}

/* Insert code into table using progressive overflow:
   - if primary slot empty -> place there
   - else allocate overflow cell and append to end of chain for that primary index
*/
void insert_code(const char *code) {
    int idx = hash_code(code);

    if (elem[idx][0] == '\0') {
        // empty primary slot
        strcpy(elem[idx], code);
        next_idx[idx] = -1;
        printf("Insert %s at primary index %d\n", code, idx);
        return;
    }

    // collision: need overflow node
    int newidx = alloc_node();
    if (newidx == -1) {
        printf("ERROR: overflow area full. Cannot insert %s\n", code);
        return;
    }
    strcpy(elem[newidx], code);
    next_idx[newidx] = -1;

    // append to end of chain starting at idx
    int p = idx;
    while (next_idx[p] != -1) p = next_idx[p];
    next_idx[p] = newidx;
    printf("Collision for %s at %d, placed at overflow %d (prev %d)\n", code, idx, newidx, p);
}

/* Search: return index if found, -1 otherwise. */
int search_code(const char *code) {
    int idx = hash_code(code);
    int p = idx;
    while (p != -1) {
        if (elem[p][0] != '\0' && strcmp(elem[p], code) == 0) return p;
        p = next_idx[p];
    }
    return -1;
}

/* Delete: remove one occurrence of code if present.
   If the element is at the primary slot and has a chain, we copy the next node's data
   into the primary slot and free the overflow node (usual cursor-list head-deletion trick).
*/
void delete_code(const char *code) {
    int idx = hash_code(code);
    int p = idx, prev = -1;
    while (p != -1 && !(elem[p][0] != '\0' && strcmp(elem[p], code) == 0)) {
        prev = p;
        p = next_idx[p];
    }
    if (p == -1) {
        printf("%s not found; nothing deleted.\n", code);
        return;
    }

    if (p == idx) {
        // found at primary slot (head)
        if (next_idx[p] == -1) {
            // no chain, simply clear
            elem[p][0] = '\0';
            printf("Deleted %s from primary index %d (no chain)\n", code, p);
        } else {
            // replace head with next node's data, free next node
            int moved = next_idx[p];
            strcpy(elem[p], elem[moved]);
            next_idx[p] = next_idx[moved];
            free_node(moved);
            printf("Deleted %s from primary index %d by moving %s from overflow %d\n", code, p, elem[p], moved);
        }
    } else {
        // found in overflow chain at p, prev points to predecessor
        next_idx[prev] = next_idx[p];
        free_node(p);
        printf("Deleted %s from overflow index %d (prev %d now points to %d)\n", code, p, prev, next_idx[prev]);
    }
}

/* Pretty print the virtual heap (elem + next arrays) and avail pointer. */
void print_table_state() {
    printf("\nVirtual heap state (index : elem -> next):\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("%2d : %3s  -> %d\n", i, (elem[i][0] ? elem[i] : "---"), next_idx[i]);
    }
    printf("Avail = %d\n", avail);
}

/* Print hash index for a list of codes */
void print_hashes(const char *codes[], int n) {
    printf("\nHash indices:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s -> %d\n", codes[i], hash_code(codes[i]));
    }
}

int main() {
    init_table();

    const char *setA[] = {"JFK","LAX","SFO","CDG","LHR","NRT","ATL","DXB","PEK","MIA","SYD","ORD"};
    int n = sizeof(setA) / sizeof(setA[0]);

    
    for (int i = 0; i < n; ++i) insert_code(setA[i]);

   
    print_table_state();
    print_hashes(setA, n);

   

    return 0;
}
