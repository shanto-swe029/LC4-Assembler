# LC4 Assembler

This project is an LC4 Assembler programmed in C, which reads an assembly language file and generates its machine code equivalent in binary format. The assembler handles file I/O operations, parsing instructions, and converting them into their binary equivalents.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Conclusion](#conclusion)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Description
The LC4 Assembler reads in a .ASM text file containing assembly instructions intended for PennSim and outputs a .OBJ binary file. This project demonstrates handling strings, multidimensional arrays, and file I/O in C.

## Features
- Reads assembly instructions from a text file
- Converts instructions to their binary equivalents
- Outputs the binary code to a .OBJ file
- Error handling for file I/O and instruction parsing

## Technologies Used
- C programming language
- clang compiler

## Installation
1. **Compile the program:**
    ```sh
    clang assembler.c asm_parser.c -o assembler
    ```

## Usage
1. **Run the assembler:**
    ```sh
    ./assembler <assembly_file.asm>
    ```
   Replace `<assembly_file.asm>` with the name of your assembly file.

2. **Example:**
    ```sh
    ./assembler test.asm
    ```

## Conclusion:

Through the development of my mini LC4 Assembler, this project offered me an opportunity to deepen my understanding of file I/O, string manipulation, and multidimensional arrays in C programming. By successfully completing this project, I not only enhanced my proficiency in C programming but also gained practical experience in working with assembly language and binary file formats.

## Contributing
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -m 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Open a Pull Request

## License
This project is licensed under the MIT License.

## Contact
For any questions or support, please contact [dev.shanto.bd@gmail.com](mailto:dev.shanto.bd@gmail.com).

---

Feel free to use this adjusted version to reflect the completion of your project!
