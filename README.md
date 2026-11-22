# Log Detective – C Log Analyzer

A terminal-based log analysis tool built using C. Log Detective reads log files, identifies different severity levels, searches for specific keywords, detects repeated error messages, and generates an analysis report.

## Features

- **Log Analysis:** Counts total log entries and categorizes them into INFO, WARNING, and ERROR.
- **Log Filtering:** Displays log entries based on their severity level.
- **Keyword Search:** Searches the log file for user-specified keywords.
- **Error Detection:** Extracts error messages and identifies repeated errors.
- **Report Generation:** Creates a text report containing log statistics and a summary of unique error messages.

## Technologies Used

- C Programming Language
- Standard C Libraries (`stdio.h`, `string.h`)
- File Handling
- String Manipulation

## Project Structure

```text
log_detector/
├── main.c
├── logs/
│   └── sample.log
└── reports/
    └── analysis_report.txt
```

## How to Run

1. Clone this repository:

   ```bash
   git clone <repository-url>
   ```

2. Navigate to the project directory:

   ```bash
   cd log_detector
   ```

3. Compile the program:

   ```bash
   gcc main.c -o main
   ```

4. Run the program:

   ```bash
   ./main
   ```

   On Windows PowerShell:

   ```powershell
   .\main.exe
   ```

## Sample Analysis

For the included sample log file, the program identifies:

| Category | Count |
|---|---:|
| Total entries | 10 |
| INFO | 5 |
| WARNING | 2 |
| ERROR | 3 |

It also identifies repeated error messages, such as:

```text
Database connection failed : 2
File not found : 1
```

The generated analysis report is saved in the `reports/` directory.

## Learning Outcomes

This project provided practical experience with:

- Pointers and functions
- Arrays and loops
- File reading and writing
- String handling and comparison
- Conditional statements
- Basic log analysis and report generation

## Future Improvements

- Support for additional log severity levels.
- Handle larger numbers of unique error messages.
- Allow users to specify different log files.

---

**Developed as a C programming project.**