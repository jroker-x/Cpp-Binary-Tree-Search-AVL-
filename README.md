# AVL Tree in Modern C++

A self-balancing Binary Search Tree (AVL Tree) implemented from scratch in Modern C++ using `std::unique_ptr` for automatic memory management.

This project was built as part of a personal journey to understand tree data structures, recursion, ownership, and balancing algorithms rather than relying on the C++ Standard Library.

---

## Features

- Binary Search Tree insertion
- Self-balancing AVL insertion
- Left and right tree rotations
- Automatic tree rebalancing
- Recursive search (`contains`)
- Recursive node removal
- Height calculation
- Size calculation
- Find minimum node
- Memory-safe implementation using `std::unique_ptr`

---

## Concepts Practiced

- Recursive algorithms
- Binary Search Trees
- AVL Trees
- Balance Factors
- Tree Rotations
- Smart Pointers (`std::unique_ptr`)
- Move Semantics
- Ownership Transfer
- Tree Traversal
- Modern C++ Design

---

## Rotation Cases

The implementation correctly handles all AVL balancing cases:

- LL (Left Left)
- RR (Right Right)
- LR (Left Right)
- RL (Right Left)

using single and double rotations.

---

## Project Structure

```
AVLTree/
│
├── AVLTree.h
├── AVLTree.cpp
├── main.cpp
└── README.md
```

---

## Example

```cpp
AVLTree tree;

tree.insert(10);
tree.insert(20);
tree.insert(30);
tree.insert(25);
tree.insert(5);

std::cout << tree.contains(25);
std::cout << tree.height();
std::cout << tree.size();

tree.remove(20);
```

---

## Learning Outcomes

Through this project I learned:

- How recursive tree algorithms work
- How self-balancing trees maintain logarithmic height
- How AVL rotations preserve BST properties
- How ownership of entire subtrees can be transferred using `std::unique_ptr`
- How move semantics simplify memory-safe tree manipulation
- How recursive insertion and deletion naturally support rebalancing

---

## Future Improvements

- AVL deletion rebalancing
- Iterator support
- Tree traversals (Inorder, Preorder, Postorder)
- Level-order traversal
- Pretty-print tree visualization
- Unit tests
- Benchmark against `std::set`

---

## Technologies

- C++20
- Visual Studio Code
- CMake (optional)

---

## Author

Built from scratch as part of my C++ and Data Structures learning journey.
