# Data Structures

- physical data structures
- logical ata structures

## Physical Data Structures

They are called physical because they define how the data is allocated and organized.

They are used for storing the data.

- array
- linked list

### Array

Static data structure: collection of **contiguous** memory locations with **fixed size**.

Can be created either on the stack or on the heap

### Linked List

Dynamic data structure: collection of **nodes**, each node is composed of a value and a reference to another node address, with a **variable length**, the length of this list can grow or reduce dynamically.

Always created in the heap.

## Logical Data Structures

How the data will be added, removed, searched, updated: what is the discipline adopted with the collection of data.

This data structures are implemented using the physical data structures. They are the data structures that are used in algorithms for particular problem solving.

- linear data structures: 
  - stack: LIFO
  - queues: FIFO
- non-linear data structures:
  - trees: hierarchical structure 
  - graph: relational structure
- tabular data structure (sort of linear):
  - hash table

## Abstract Data Type (ADT)

This term is related to object oriented programming, we define a class, which is a non-primitive data type, and define its operations. On consuming this class, we simply instantiate it and use its operations, we don't need to know how they are implemented.

When we define a class, we are defining an *abstract data type*. We define it's representation and the operations we can perform on it.

### Data Type
  
  - Representation of data: how the data is represented, how it is stored
  - Operation on data: what are the allowed operations on the data

ex with a primitive data type:

**integer**:

- representation: 2 bytes, using one bit for the sign and 15 bits fr the value

<style>
table, th, td {
  border: 3px solid black;
}
</style>
|  sign |  value  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
|:-----:|:-------:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0/1   | 0/1     | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 | 0/1 |
| 1 bit | 15 bits |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| b1    | b1      | b1  | b1  | b1  | b1  | b1  | b1  | b0  | b0  | b0  | b0  | b0  | b0  | b0  | b0  |

- operations: sum(+), subtraction(-), multiplication(*), division(/), modulus (%), increment(++), decrement(--), etc. (we also have here relational operations, like greater than, lesser than, and etc.)

When using an integer, we simply instantiate it and perform any operation it implements.

### Abstract

For any data type, primitive or not, and it's operations, we don't need to know how things are implemented and operated inside the memory in their binary forms.

The internal details are abstracted from us.