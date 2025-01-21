# Inverted_Search

# Inverted Search Using Hash Algorithms

## Overview
This project implements an **Inverted Index Search System** using **Hash Algorithms** to enable efficient full-text retrieval across multiple documents. The project focuses on indexing and querying functionalities for document retrieval systems, similar to those used in modern search engines.

## Features
- **Forward Indexing**: Parses documents to create a word-to-document mapping using **hashing**.
- **Inverted Indexing**: Transforms the forward index into a sorted structure for optimized searching.
- **Querying Functionalities**: Allows users to input search terms and quickly retrieve documents containing those terms.
- Optimized for **time complexity** and **storage efficiency**.

## Technical Details
1. **Indexing**:
   - Creates a database file containing an index of all words in the input files.
   - Stores file details (e.g., filenames or URLs) where each word appears.
   - Utilizes **hashing** or **sorted linked lists** to ensure fast indexing and retrieval.
   - Dynamically updates the index when files are added or removed.

2. **Querying**:
   - Accepts user input to search for specific words.
   - Parses the input into individual words and searches the index.
   - Retrieves results based on word matches across documents.

## Data Structures Used
- **Hash Tables**: For efficient mapping and retrieval of word-to-document associations.
- **Sorted Linked Lists**: Used to maintain words in sorted order during indexing for faster querying.

## How It Works
### Indexing
- Input: A set of text files to be indexed.
- Process:
  - Parse each file to extract individual words.
  - Map each word to the list of files in which it appears.
  - Store the mapping in a structured database file.

### Querying
- Input: Search query (a word or phrase).
- Process:
  - Parse the query into words.
  - Search for each word in the indexed database.
  - Return a ranked list of documents containing the search terms.

## Example Workflow
1. Provide a set of text files for indexing.
2. Run the program to create the indexed database.
3. Input search queries to retrieve matching documents.

## Requirements
- Programming Language: C
- Compiler: GCC or any standard C compiler
- Text files to be indexed

## Advantages
- **Fast Full-Text Search**: Efficiently retrieves documents containing specific words or phrases.
- **Dynamic Indexing**: Supports the addition or removal of files without re-indexing the entire dataset.
- **Scalable**: Optimized for large datasets using efficient data structures.

## Applications
- Document Retrieval Systems
- Search Engines
- Information Retrieval Projects

## Acknowledgments
This project was designed to demonstrate the use of data structures like hash tables and linked lists for building an inverted index system. Special thanks to mentors and resources that guided the project development.

## Contact
For more information, feel free to contact me via LinkedIn or email.
