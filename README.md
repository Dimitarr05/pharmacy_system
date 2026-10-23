# Pharmacy System

A simple C++ console application for managing a pharmacy.

## About the Project

The project is focused on managing medicines, available quantities and sales in a pharmacy.

The system supports two types of medicines:
- Over-the-counter medicines
- Prescription medicines

It also includes checks for expiration dates, available stock and prescription information.

## Features

- Add and manage medicines
- Check available quantities
- Register sales and update stock
- Validate expiration dates
- Control prescription medicine sales
- Generate receipts
- Save and load data from files

## Technologies

- C++
- OOP Principles
- File Handling

## Compilation and Run

Make sure you have a C++ compiler installed, such as GCC.

Compile the project from the root directory:

```bash
g++ -std=c++17 src/*.cpp -o pharmacy
```

Run the application on macOS or Linux:

```bash
./pharmacy
```

On Windows, run:

```powershell
.\pharmacy.exe
```