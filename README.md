
# File Analyzer

File Analyzer is a command-line tool developed in C that provides statistics on text files, such as the number of lines, words, and characters. It is designed to help users quickly understand the content metrics of their files and can also display the file contents directly in the terminal.

![File Analyzer Usage Example](./analyzer.cana.jpg)

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Options](#options)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- 

## Requirements

- GCC (GNU Compiler Collection)
- Linux/Unix-based operating system

## Installation

To compile and install File Analyzer, follow these steps:

1. **Clone the repository**:

    ```bash
    git clone https://github.com/Abdullah-Badawy1/analyzer.git
    cd analyzer
    ```

2. **Compile the source code**:

    ```bash
    gcc -o analyzer analyzer.c
    ```

3. **Install the executable**:

    You can make the program accessible system-wide by moving the compiled executable to a directory included in your system's PATH:

    ```bash
    sudo mv analyzer /usr/local/bin/
    ```

## Compilation

The project can be compiled using GCC. Run the following command in the terminal where your source file is located:

```bash
gcc -o analyzer analyzer.c
```

This command compiles `main.c` and creates an executable named `analyzer`.

## Usage

```bash
analyzer [options] <filename1> [filename2 ...]
```

## Options

- `-d` : Display the contents of the files along with the analysis.
- `-h` : Show the help message and usage instructions.

## Examples

To analyze a single file and display its contents:

```bash
analyzer -d example.txt
```

To just get the file statistics without displaying content:

```bash
analyzer example.txt
```

For help on command usage:

```bash
analyzer -h
```

## Contributing

Contributions are welcome. If you have suggestions or improvements, please fork the repository and submit a pull request.

1. **Fork the Repository**
2. **Create your Feature Branch** (`git checkout -b feature/AmazingFeature`)
3. **Commit your Changes** (`git commit -m 'Add some AmazingFeature'`)
4. **Push to the Branch** (`git push origin feature/AmazingFeature`)
5. **Open a Pull Request**

## License

Distributed under the MIT License. See `LICENSE` for more information.

