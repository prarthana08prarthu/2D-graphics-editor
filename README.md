# 2D Graphics Editor

A command-line 2D graphics editor that allows users to draw, modify, and manage graphical objects using ASCII characters (`*` and `_`).

## 📋 Project Description

This project implements a 2D graphics editor with the following capabilities:
- Draw basic shapes: **circle**, **rectangle**, **line**, and **triangle**
- **Add** objects to the canvas
- **Delete** objects from the canvas
- **Modify** existing objects
- **Display** the complete picture on screen
- Interactive menu system (with optional ncurses support)

## 🎯 Features

### Core Drawing Functions
- ✅ **Circle**: Draw circles of various sizes
- ✅ **Rectangle**: Draw rectangles with custom dimensions
- ✅ **Line**: Draw horizontal and vertical lines
- ✅ **Triangle**: Draw triangles

### Canvas Management
- ✅ 2D array of characters to store the picture
- ✅ Add new objects to the picture
- ✅ Delete objects from the picture
- ✅ Modify existing objects
- ✅ Display/render the complete picture

### User Interface
- ✅ Interactive menu system
- 🔄 Optional: Enhanced UI with ncurses library

## 🛠️ Technologies Used

- **Language**: C/C++
- **Libraries**: 
  - Standard C Library (stdio.h, stdlib.h, string.h)
  - Optional: ncurses (for enhanced menu system)

## 📦 Project Structure

```
2D-graphics-editor/
├── README.md           # This file
├── main.c              # Main program entry point
├── graphics.h          # Header file with function declarations
├── graphics.c          # Shape drawing functions
├── canvas.h            # Canvas management header
├── canvas.c            # Canvas operations (add, delete, modify, display)
├── Makefile            # Build instructions (optional)
└── .gitignore          # Git ignore file
```

## 🚀 Getting Started

### Prerequisites
- GCC/Clang compiler (for C)
- Make (optional)
- ncurses development library (optional, for enhanced menu)

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/prarthana08prarthu/2D-graphics-editor.git
cd 2D-graphics-editor
```

2. **Compile the program**
```bash
# Using GCC
gcc -o graphics_editor main.c graphics.c canvas.c

# Or with Makefile (if available)
make
```

3. **Run the program**
```bash
./graphics_editor
```

## 📖 Usage

### Main Menu
```
=== 2D Graphics Editor ===
1. Draw Circle
2. Draw Rectangle
3. Draw Line
4. Draw Triangle
5. Delete Object
6. Modify Object
7. Display Picture
8. Clear Canvas
9. Exit
```

### Example: Drawing a Circle
```
Enter circle center X coordinate: 5
Enter circle center Y coordinate: 5
Enter circle radius: 3
```

### Example: Drawing a Rectangle
```
Enter top-left X coordinate: 2
Enter top-left Y coordinate: 2
Enter width: 8
Enter height: 4
```

## 📝 Implementation Details

### Canvas Representation
- Uses a 2D character array to store the drawing
- Default canvas size: 20x20 (customizable)
- Empty cells represented by space character
- Objects drawn with `*` and `_` characters

### Data Structure
```c
typedef struct {
    char canvas[MAX_HEIGHT][MAX_WIDTH];
    int width;
    int height;
} Canvas;
```

### Shape Algorithms
- **Line**: Bresenham's or simple line algorithm
- **Circle**: Midpoint circle algorithm
- **Rectangle**: Boundary drawing
- **Triangle**: Edge drawing with line algorithm

## ✅ Evaluation Rubrics

| Criteria | Marks |
|----------|-------|
| Original Complete | 5 |
| Original Almost Complete | 4 |
| Original Partially Complete | 3 |
| Copied | 2 |
| No Submission | 1 |
| Copied Caught | 0 |

## 📅 Development Progress

- [ ] Project setup and repository creation
- [ ] Basic canvas implementation
- [ ] Line drawing function
- [ ] Circle drawing function
- [ ] Rectangle drawing function
- [ ] Triangle drawing function
- [ ] Add object functionality
- [ ] Delete object functionality
- [ ] Modify object functionality
- [ ] Display function
- [ ] Menu system implementation
- [ ] Testing and debugging
- [ ] Optional: ncurses integration

## 🔄 Git Workflow

Daily commits are mandatory. Example workflow:
```bash
# Make changes to your code
# Stage changes
git add .

# Commit with descriptive message
git commit -m "Add circle drawing function"

# Push to GitHub
git push origin main
```

## 📚 Resources

- [Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm)
- [Midpoint Circle Algorithm](https://en.wikipedia.org/wiki/Midpoint_circle_algorithm)
- [ncurses Programming Guide](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/) (optional)

## 🤝 Contributing

This is a personal academic project. All code should be original work.

## 📧 Support

For questions or issues with the project, please refer to the assignment guidelines or contact your instructor.

---

**Status**: Under Development  
**Last Updated**: 2026-06-08  
**Author**: prarthana08prarthu
