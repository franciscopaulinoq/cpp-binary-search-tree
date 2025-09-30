#include <iostream>
#include <BinarySearchTree.hpp>

using namespace std;

int main() {
    cout << "--- 1. Criacao da Binary Search Tree (BST) ---\n";
    BinarySearchTree<int> bstA;
    bstA.insert(20);
    bstA.insert(10);
    bstA.insert(21);
    bstA.insert(23);
    bstA.insert(15);

    cout << "Imprimindo valores em ordem da BST A: " << endl;
    bstA.inorder();

    cout << "\n--- 2. Verificar ocorrencia de valores ---\n";
    cout << "Existe valor 5? " << 
                        (bstA.search(5) ? "sim" : "nao") << endl;
    cout << "Existe valor 21? " << 
                        (bstA.search(21) ? "sim" : "nao") << endl;
    
    cout << "\n--- 3. Remocao de no folha ---\n";
    bstA.inorder();
    bstA.remove(23);
    bstA.inorder();
    
    cout << "\n--- 4. Remocao de no com um filho ---\n";
    bstA.inorder();
    bstA.remove(10);
    bstA.inorder();

    cout << "\n--- 5. Remocao de no com dois filhos ---\n";
    bstA.inorder();
    bstA.remove(20);
    bstA.inorder();
    
    return 0;
}