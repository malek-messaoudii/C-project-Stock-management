# Stock Management System - Product Tracking

A comprehensive stock management system implemented in C, featuring category management, product types, inventory items, and sales statistics.

## Key Features

- **Hierarchical Management** :
  - Categories → Types → Products
- **CRUD Operations** :
  - Add/Remove categories, types and products
- **Smart Sales System** :
  - Product sales by expiration date (FIFO)
- **Statistics** :
  - Monthly/annual sales
  - Category analysis
- **Data Persistence** :
  - Transaction logging in `trace.txt`


## Code Structure
 gestion_stock/
 
├── src/

│ ├── main.c # Main program

│ └── bib.h  # Declarations and functions

├── data/

│ └── trace.txt # Sales log file

└── README.md


## Installation

### Prerequisites

- C compiler (gcc recommended)

### Compilation
```
gcc -o gestion_stock src/main.c
```
### Execution
```
gestion_stock.exe
```

