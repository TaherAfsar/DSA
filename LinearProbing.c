#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure to represent a key-value pair
struct KeyValuePair
{
    int key;
    int value;
};

// Structure to represent a hash table
struct HashTable
{
    struct KeyValuePair *table[SIZE];
};

// Function to initialize the hash table
void initializeHashTable(struct HashTable *hashtable)
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable->table[i] = NULL;
    }
}

// Function to calculate the hash value
int hashFunction(int key)
{
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table using linear probing
void insert(struct HashTable *hashtable, int key, int value)
{
    int index = hashFunction(key);

    while (hashtable->table[index] != NULL)
    {
        // Linear probing: move to the next index if collision occurs
        index = (index + 1) % SIZE;
    }

    // Allocate memory for the key-value pair
    struct KeyValuePair *newPair = (struct KeyValuePair *)malloc(sizeof(struct KeyValuePair));
    newPair->key = key;
    newPair->value = value;

    // Insert the pair into the hash table
    hashtable->table[index] = newPair;
}

// Function to retrieve the value associated with a key from the hash table
int search(struct HashTable *hashtable, int key)
{
    int index = hashFunction(key);

    while (hashtable->table[index] != NULL)
    {
        if (hashtable->table[index]->key == key)
        {
            return hashtable->table[index]->value; // Key found
        }

        // Linear probing: move to the next index if key is not found
        index = (index + 1) % SIZE;
    }

    return -1; // Key not found
}

// Function to display the contents of the hash table
void displayHashTable(struct HashTable *hashtable)
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable->table[i] != NULL)
        {
            printf("[%d] -> Key: %d, Value: %d\n", i, hashtable->table[i]->key, hashtable->table[i]->value);
        }
        else
        {
            printf("[%d] -> NULL\n", i);
        }
    }
}

// Main function for testing
int main()
{
    struct HashTable myHashTable;
    initializeHashTable(&myHashTable);

    insert(&myHashTable, 5, 100);
    insert(&myHashTable, 15, 200);
    insert(&myHashTable, 25, 300);
    insert(&myHashTable, 35, 400);

    displayHashTable(&myHashTable);

    int searchKey = 15;
    int result = search(&myHashTable, searchKey);

    if (result != -1)
    {
        printf("Value for key %d: %d\n", searchKey, result);
    }
    else
    {
        printf("Key %d not found in the hash table\n", searchKey);
    }

    return 0;
}
