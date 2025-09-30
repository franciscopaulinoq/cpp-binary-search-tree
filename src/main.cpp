#include <iostream>
#include <BinarySearchTree.hpp>
#include <string>

using namespace std;

int main()
{
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
    cout << "Existe valor 5? " << (bstA.search(5) ? "sim" : "nao") << endl;
    cout << "Existe valor 21? " << (bstA.search(21) ? "sim" : "nao") << endl;

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

    cout << "\n--- 6. Altura da Arvore ---\n";
    BinarySearchTree<int> bstB;
    bstB.insert(20);
    bstB.insert(10);
    bstB.insert(21);
    bstB.insert(23);
    bstB.insert(15);
    bstB.insert(13);
    bstB.insert(18);
    bstB.insert(16);

    cout << "Altura da arvore bstB: " << bstB.height() << endl;

    cout << "\n--- 7. Nos da Arvore ---\n";

    cout << "Quantidade de nos da arvore bstB: " << bstB.countNodes() << endl;

    cout << "\n--- 8. Folhas da Arvore ---\n";

    cout << "Quantidade de folhas da arvore bstB: " << bstB.countLeaves() << endl;

    cout << "\n--- 9. Similaridade de arvores ---\n";

    BinarySearchTree<int> bstC;
    bstC.insert(20);
    bstC.insert(10);
    bstC.insert(21);

    BinarySearchTree<int> bstD;
    bstD.insert(15);
    bstD.insert(16);
    bstD.insert(18);

    cout << "A arvore bstC e similar a bstD? " << (bstC.isSimilar(bstD) ? "sim" : "nao") << endl;

    cout << "\n--- 10. Arvore estritamente binaria ---\n";

    BinarySearchTree<int> bstE;
    bstE.insert(20);
    bstE.insert(10);
    bstE.insert(21);
    bstE.insert(15);
    bstE.insert(9);
    bstE.insert(25);

    cout << "A arvore bstE e estritamente binaria? " << (bstE.isStrictlyBinary() ? "sim" : "nao") << endl;

    cout << "\n--- 11. Comparacao de arvores ---\n";

    BinarySearchTree<int> bstX;
    bstX.insert(20);
    bstX.insert(10);
    bstX.insert(21);

    BinarySearchTree<int> bstY;
    bstY.insert(20);
    bstY.insert(10);
    bstY.insert(21);

    cout << "A arvore bstX e igual a bstY? " << (bstX.equals(bstY) ? "sim" : "nao") << endl;

    return 0;
}